FROM ghcr.io/zephyrproject-rtos/zephyr-build:latest

USER root

RUN apt update && apt install -y \
    usbutils \
    udev \
    automake \
    autoconf \
    build-essential \
    texinfo \
    libtool \
    libftdi-dev \
    libusb-1.0-0-dev

RUN \
    cd /opt && \
    git clone "https://github.com/raspberrypi/openocd.git" -b rp2040-v0.12.0 --depth=1 && \
    cd openocd && \
    ./bootstrap && \
    ./configure --enable-ftdi --enable-sysfsgpio --enable-bcm2835gpio --enable-picoprobe && \
    make -j $(nproc) && \
    sudo make install && \
    cd .. && \
    rm -rf openocd

RUN usermod -aG dialout user
USER user

CMD ["/bin/bash"]
