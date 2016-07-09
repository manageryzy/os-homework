#!/bin/sh

insmod driver.ko
mknod /dev/demo c 456 0

