; BOJ-05347 / LCM
; devgeon, 2025.04.12, Assembly (32bit)
; https://www.acmicpc.net/problem/5347

section .data
    input1 db "%d", 0
    input2 db "%d %d", 0
    output db "%lld", 10, 0

section .text
    global main
    extern scanf
    extern printf

main:
    push ebp
    mov ebp, esp
    sub esp, 4

    lea edx, [ebp - 4]
    push edx
    push input1
    call scanf
    add esp, 8
    mov ecx, [ebp - 4]

main_loop:
    push ecx
    call solve
    pop ecx
    loop main_loop

    mov eax, 0
    leave
    ret

solve:
    push ebp
    mov ebp, esp
    sub esp, 8
    push ebx

    lea ecx, [ebp - 4]
    lea edx, [ebp - 8]
    push edx
    push ecx
    push input2
    call scanf
    add esp, 12
    
    mov ecx, [ebp - 4]
    mov edx, [ebp - 8]
    cmp ecx, edx
    jl solve_less
    push ecx
    push edx
    jmp solve_continue
solve_less:
    push edx
    push ecx

solve_continue:
    call gcd
    add esp, 8

    mov ebx, eax
    mov eax, [ebp - 4]
    mul dword [ebp - 8]
    push edx
    push eax
    mov eax, edx
    cdq
    div ebx
    push eax
    mov eax, [esp + 4]
    div ebx
    mov edx, [esp]
    add esp, 12
    
    push edx
    push eax
    push output
    call printf
    add esp, 12

    pop ebx
    leave
    ret

gcd:
    push ebp
    mov ebp, esp
    push ebx
    
    mov eax, [ebp + 8]
    mov ebx, [ebp + 12]
    cdq
    idiv ebx
    
    cmp edx, 0
    je gcd_mod_zero
    push edx
    push ebx
    call gcd
    add esp, 8
    jmp gcd_continue
gcd_mod_zero:
    mov eax, ebx

gcd_continue:
    pop ebx
    leave
    ret
