; BOJ-02557 / Hello World
; devgeon, 2025.04.11, Assembly (32bit)
; https://www.acmicpc.net/problem/2557

section .data
    text db "Hello World!", 10, 0
    size equ $ - text

section .text
    global main

main:
    push ebp
    mov ebp, esp
    push ebx

    mov eax, 4
    mov ebx, 1
    mov ecx, text
    mov edx, 13
    int 0x80

    pop ebx
    mov eax, 0
    leave
    ret
