#!/bin/bash
printf "[BITS 64]\n" > tmp.asm
nano tmp.asm

nasm tmp.asm
xxd -g 1 tmp

rm -rf tmp tmp.asm
