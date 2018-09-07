#!/bin/sh

cd ..

tar -zcvf ../MiCoder.macOS.tar.gz --exclude=MiCoder/compiler/*/Linux64 --exclude=MiCoder/compiler/*/Win32  --exclude=*.DS_Store MiCoder
tar -zcvf ../MiCoder.Linux.tar.gz --exclude=MiCoder/compiler/*/OSX --exclude=MiCoder/compiler/*/Win32  --exclude=*.DS_Store MiCoder
zip -r ../MiCoder.Win32.zip  MiCoder -x /MiCoder/compiler/*/Linux64/* /MiCoder/compiler/*/OSX/* *.DS_Store

