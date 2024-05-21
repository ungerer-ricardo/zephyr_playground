FROM ghcr.io/zephyrproject-rtos/zephyr-build:latest

RUN sudo apt update && sudo apt install -y \
    usbutils \
    udev

RUN cd /opt && \
    sudo wget https://raw.githubusercontent.com/raspberrypi/pico-setup/master/pico_setup.sh && \
    sudo SKIP_VSCODE=1 SKIP_UART=1 bash ./pico_setup.sh && \
    sudo rm pico_setup.sh
