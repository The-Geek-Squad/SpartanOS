#!/bin/sh
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/SpartanOS.kernel isodir/boot/SpartanOS.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "SpartanOS" {
	multiboot /boot/SpartanOS.kernel
}
EOF
grub-mkrescue -o SpartanOS.iso isodir
