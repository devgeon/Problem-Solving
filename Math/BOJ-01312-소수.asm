; BOJ-01312 / 소수
; devgeon, 2025.04.26, Assembly (32bit)
; https://www.acmicpc.net/problem/1312

section .data
    input db "%d %d %d", 0
    output db "%d", 10, 0

section .text
    global main
    extern scanf
    extern printf

main:
    push ebp
    mov ebp, esp
    sub esp, 12
    push ebx
    push edi

    lea edi, [ebp - 12]  ; N
    push edi
    lea edi, [ebp - 8]  ; B
    push edi
    lea edi, [ebp - 4]  ; A
    push edi
    push input
    call scanf
    add esp, 16

    mov eax, [ebp - 4]
    mov ebx, [ebp - 8]
    mov ecx, [ebp - 12]
    mov edx, 0
    div ebx

div:
    imul eax, edx, 10
    mov edx, 0
    div ebx
    loop div

    push eax
    push output
    call printf
    add esp, 8

    mov eax, 0
    pop edi
    pop ebx
    leave
    ret
