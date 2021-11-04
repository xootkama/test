#!/usr/bin/bash 

if [[ -d "out" ]]
then 
cd out && make clean && make distclean && make mrproper && cd  ..
else 
  mkdir -p out
  fi
  
  make O=out ARCH=arm64 X00TD_defconfig
sattire=`find / -type d -name "gcc" 2>/dev/null`

PATH="$sattire/bin:$PATH" \
 
  make                O=out \
                      ARCH=arm64 \
                      CC=clang \
                      CROSS_COMPILE=aarch64-linux-android- \
                      CROSS_COMPILE_ARM32=arm-linux-gnueabi- \
                      -j8
                      
