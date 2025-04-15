; BOJ-10870 / 피보나치 수 5
; devgeon, 2025.04.15, Assembly (32bit)
; https://www.acmicpc.net/problem/10870

section .data
    format db "%d", 0

section .text
    global main
    extern scanf
    extern printf

main:
    push ebp
    mov ebp, esp
    sub esp, 4
    push ebx

    lea eax, [ebp - 4]
    push eax
    push format
    call scanf
    add esp, 8

    mov ecx, [ebp - 4]
    mov eax, 0
    mov ebx, 1

    cmp ecx, 0
    jz main_print

main_loop:
    mov edx, ebx
    add ebx, eax
    mov eax, edx
    loop main_loop

main_print:
    push eax
    push format
    call printf
    add esp, 8

    mov eax, 0
    pop ebx
    leave
    ret
