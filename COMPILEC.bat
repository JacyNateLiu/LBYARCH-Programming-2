nasm -f win64 saxpy.asm
gcc -c C_Version.c -o C_Version.obj -m64
gcc C_Version.obj saxpy.obj -o C_Version.exe -m64