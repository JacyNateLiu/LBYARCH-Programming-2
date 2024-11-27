nasm -f win64 saxpy.asm
gcc -c ASM_Version.c -o ASM_Version.obj -m64
gcc ASM_Version.obj saxpy.obj -o ASM_Version.exe -m64