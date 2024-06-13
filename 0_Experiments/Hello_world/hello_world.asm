section .data
    hello db 'Hello, World!',0   ; Null-terminated string, "hello" is a pointer to it

section .text
    global _start

_start:
    ; write syscall: sys_write (1)
    ; int 0x80 is the interrupt that switches to kernel mode
    mov rax, 1      ; syscall number for sys_write
    mov rdi, 1      ; file descriptor: 1 is stdout
    mov rsi, hello  ; pointer to our string
    mov rdx, 13     ; length of our string
    syscall         ; make the syscall

    ; exit syscall: sys_exit (60)
    mov rax, 60     ; syscall number for sys_exit
    xor rdi, rdi    ; exit code 0
    syscall         ; make the syscall
