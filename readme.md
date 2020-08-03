# Modbus C Application

- [Overview](#overview)
    - [Project goal](#project-goal)
    - [System requirements](#system-requirements)
- [libmodbus installation guide](#libmodbus-installation-guide)



## Overview

### Project goal

Introduction into Modbus protocol and creation of simple server-client
application.


### System requirements

* **OS**: Ubuntu 20.04
* **C compiler**: gcc 9.3.0
* **Third party libraries**: [libmodbus](https://github.com/stephane/libmodbus)



## libmodbus installation guide

There are some steps required to perfom before You will be able to compile this
project:

1. Clone the [libmodbus](https://github.com/stephane/libmodbus) Github
    repository.

```sh
$ mkdir -p ~/workspace/third_party && cd ~/workspace/third_party/
$ git clone https://github.com/stephane/libmodbus
```

2. Install `libmodbus` library:

```sh
$ cd libmodbus/
$ ./autogen.sh
$ ./configure && make install
```

3. Create `modbus.conf` file in `/etc/ld.so.conf.d/`:

```sh
$ sudo touch /etc/ld.so.conf.d/modbus.conf
```

Use your favourite text editor (e.g. Vim) and populate it with 
`/usr/local/lib/` (or other path, where `libmodbus.so` is placed):

```sh
$ sudo vi /etc/ld.so.conf.d/modbus.conf
```

Now You should be able to compile the application using attached `Makefile`.

