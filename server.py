import socket, os, threading

def hand(client):
    rec = client.recv(1024)
    print(rec)
    
    if rec != b'connect_success':
        client.close()
        client.send(b'connect_fail')
        return 'connection error'
    client.send(b'connect_success') 

    things = client.recv(1024)
    try:
        #找到文件路径中最后一个/
        file_path = things.rindex(b'/')
        #用切片截取文件名
        file_name = things[file_path+1:]
    except:
        file_name = things

    saved_file = '/home/neon/files/upload/' + file_name.decode('utf-8')
    if os.path.isfile(saved_file):
        client.send(b'%s is exist!!!' %file_name)
        client.close()
        print("%s is exist!!!")
        return "the file you want to upload is exist!"

    client.send(b'new_file')
    try:
        fopen = open(saved_file, 'wb')
    except:
        client.send(b'cannot_wtite_file')
        client.close()
        print("cannot write file")
        return "cannot write file!"
    client.send(b'open file success!')
    rec = b''
    try:
        while rec != b'end_of_load':
            fopen.write(rec)
            rec = client.recv(1024)
        fopen.close()
        client.send(b'Complete!')
    except:
        client.send(b'Something wrong!')
    client.close()

# 创建套接字
my_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
my_socket.bind(('172.19.64.36', 56889))
# 监听
my_socket.listen(6) 

while True:
    client = my_socket.accept() 
    # 为一个客户端的访问创建一个线程
    threading.Thread(target = hand, args=(client[0],)).start()


