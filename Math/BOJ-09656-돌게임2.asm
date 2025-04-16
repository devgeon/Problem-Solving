; BOJ-09656 / 돌 게임 2
; devgeon, 2025.04.16, Assembly (32bit)
; https://www.acmicpc.net/problem/9656

section .data
    format db "%d", 0
    sk db "SK", 10, 0
    cy db "CY", 10, 0

section .text
    global main
    extern scanf
    extern printf

main:
    push ebp
    mov ebp, esp
    sub esp, 4

    lea eax, [ebp - 4]
    push eax
    push format
    call scanf
    add esp, 8

    mov eax, [ebp - 4]
    and eax, 1
    cmp eax, 1
    je odd
    jmp even
odd:
    push cy
    jmp print
even:
    push sk
print:
    call printf
    add esp, 4

    mov eax, 0
    leave
    ret
