; JOL-06141 / 별찍기 정복 1
; devgeon, 2026.09.22, NASM(64bit)
; https://jungol.co.kr/problem/6141

section .data
    char db 'o'

section .text
    global _start

_start:
    call input_int
    push rax
    call print_letter_o
    add rsp, 8
    jmp exit_program

input_int:
    push rbx
    mov rbx, 0
    sub rsp, 8    ; reserve on stack
    jmp input_digit

input_digit:
    mov rax, 0    ; syscall read
    mov rdi, 0    ; stdin
    mov rsi, rsp  ; buffer
    mov rdx, 1    ; count
    syscall
    cmp rax, 0
    je input_done
    movzx rax, byte [rsp]
    cmp rax, 10
    je input_done
    sub rax, '0'
    imul rbx, 10
    add rbx, rax
    jmp input_digit

input_done:
    mov rax, rbx
    add rsp, 8
    pop rbx
    ret

print_letter_o:
    push rbx
    mov rbx, [rsp+16]
    jmp print_loop

print_loop:
    cmp rbx, 0
    je print_done
    mov rax, 1     ; syscall write
    mov rdi, 1     ; stdout
    mov rsi, char  ; buffer
    mov rdx, 1     ; count
    syscall
    
    sub rbx, 1
    jmp print_loop

print_done:
    pop rbx
    ret

exit_program:
    mov rax, 60
    mov rdi, 0
    syscall
