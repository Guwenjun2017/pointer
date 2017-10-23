#解决manjaro linux的中文输入
#pacman -S fcitx fcitx-libpinyin kcm-fcitx
#然后修改 .xprofile
cat xprofile >> ~/.xprofile

#配置.vimrc
cat vimrc >> ~/.vimrc

#man手册显示 source .bashrc立即生效
cat manrc >> ~/.bashrc

