; BOJ-17201 / 자석 체인
; devgeon, 2025.04.14, Assembly (32bit)
; https://www.acmicpc.net/problem/17201

section .data
    yes db "Yes", 10, 0
    no db "No", 10, 0

section .text
    global main
    extern getchar
    extern printf

main:
    push ebp
    mov ebp, esp
    sub esp, 4

    call getchar
    sub eax, '0'
    sal eax, 1

    push eax
    call getchar
    pop ecx
    mov dword [ebp - 4], '0'

main_loop:
    push ecx
    call getchar
    pop ecx

    cmp eax, [ebp - 4]
    je invalid

    mov [ebp - 4], eax
    loop main_loop

    push yes
    jmp print
invalid:
    push no
print:
    call printf

    mov eax, 0
    leave
    ret
