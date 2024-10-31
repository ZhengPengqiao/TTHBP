# [TTHBP]_0_0_编译烧录

> 创建时间:20240425 17:05:00

## MCU Linux开发环境

```bash
sudo dpkg -i mcu8051ide-1.4.10-all.deb
sudo apt-get install -f
```

## 交叉编译工具链

```bash
sudo apt install sdcc
```

## 下载烧录工具【一直找不到MCU】


* 依赖环境

    ```bash
    sudo apt install gawk
    sudo aptitude install libvte-dev
    sudo mv /usr/include/vte-0.0/vte /usr/include/vte
    ```

* gSTCISP
  * https://github.com/ELE-Clouds/gSTC-ISP

* 进入gSTC-ISP目录，进行以下操作：

    ```bash
    sudo ./configure
    sudo make
    sudo make install
    ```

## 另外一个下载烧录工具[MCU先断电，运行指令，再给MCU上电]

* 安装指令

    ```bash
    pip3 install stcgal
    ```

* 烧录指令

    ```bash
    stcgal -P stc89 -p /dev/ttyUSB0 main.bin
    ```

