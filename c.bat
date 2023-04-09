@ECHO OFF

gcc -o a.exe collision/*.c constant/*.c coordinate/*.c particle/*.c tests/*.c vector/*.c shape/*.c *.c > out.txt

a.exe