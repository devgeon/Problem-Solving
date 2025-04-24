; BOJ-16462 / '나교수' 교수님의 악필
; devgeon, 2025.04.23, Assembly (32bit)
; https://www.acmicpc.net/problem/16462

section .data
    format db "%d", 0

section .text
    global main
    extern getchar
    extern printf

main:
    push ebp
    mov ebp, esp
    sub esp, 8
    push ebx

    mov ebx, 0
input_n:
    call getchar
    cmp eax, 10
    je break_n
    sub eax, '0'
    imul ebx, ebx, 10
    add ebx, eax
    jmp input_n

break_n:
    mov [ebp - 4], ebx
    mov dword [ebp - 8], 0

    mov ecx, ebx
    mov ebx, 0
input_score:
    push ecx
    call getchar
    pop ecx
    cmp eax, 10
    je break_score
    sub eax, '0'
    cmp eax, 0
    je replace_06
    cmp eax, 6
    je replace_06
continue_score:
    imul ebx, ebx, 10
    add ebx, eax
    jmp input_score

replace_06:
    mov eax, 9
    jmp continue_score

break_score:
    cmp ebx, 100
    jle sum_score
    mov ebx, 100
sum_score:
    add [ebp - 8], ebx
    mov ebx, 0
    loop input_score

    mov eax, [ebp - 8]
    mov ebx, [ebp - 4]
    mov edx, 0
    idiv ebx
    inc ebx
    sar ebx, 1
    cmp edx, ebx
    jl print
    inc eax

print:
    push eax
    push format
    call printf
    add esp, 8

    mov eax, 0
    pop ebx
    leave
    ret
