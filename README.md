### Setting Up Development Environment for Cross-compiling

1. Setup schroot
  1. `$ sudo apt install schroot`
  1. create `/etc/schroot/chroot.d/jessie.conf` file with lines
  
        [jessie]
        description Debian Jessie (stable)
        type=directory
        directory=/srv/chroot/jessie
        users=clint
        root-users=clint
        root-groups=root
        aliases=stable,default

1. create Debian Jessie chroot

        $ sudo apt install debootstrap
        $ sudo debootstrap jessie /srv/chroot/jessie http://httpredir.debian.org/debian

1. schroot into and configure chroot

        $ schroot -c jessie -u root
        # apt update && apt install curl
        # dpkg --add-architecture armhf
        # tee "deb http://emdebian.org/tools/debian jessie main" /etc/apt/sources.list.d/crosstools.list"
        # curl http://emdebian.org/tools/debian/emdebian-toolchain-archive.key | apt-key add -
        # apt update
        # apt install crossbuild-essential-armhf cmake
        # logoff
        
1. test schroot toolchain

        $ schroot -c jessie
        $ arm-linux-gnueabihf-gcc --version  # should be 4.9

1. create user-editable project folder

        $ schroot -c jessie -u root
        # mkdir /project
        # chown clint:clint /project
        # logoff
        $ git clone https://github.com/clintliddick/b4 /srv/chroot/jessie/projects/b4
