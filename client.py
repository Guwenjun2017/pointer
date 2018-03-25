import socket, os, time
c = 0
while c == 0:
    try:
        name = input("Please input name of the file which you want to download: ")
        detail_file = open(name, 'rb')
        c = 1
    except:
        print("No such file!")
        exit()

f_read = detail_file.read()
soc = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
soc.sonnect(('blog.thatis.top', 56889))
message = b'connect_success'
soc.send(message)
time.sleep(1) 

rec = soc.recv(1024)
if rec != b'connect_success':
    print("connect fail!")
    soc.close()
    exit()
print('connect successfully!')
soc.send(name.encode('utf-8'))
rec = soc.recv(1024)
print(rec.decode('utf-8'))
time.sleep(1)

soc.send(f_read)
rec = soc.recv(1024)
print(rec.decode('utf-8'))
if rec == b'Complete':
    print("load complete")
