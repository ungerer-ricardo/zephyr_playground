cmake_minimum_required(VERSION 3.20.0)
set(BOARD rpi_pico/rp2040/w)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(zephyr_playground)

target_sources(app PRIVATE src/main.cpp)
