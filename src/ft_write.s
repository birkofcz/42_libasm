;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_write.s                                         :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: sbenes <sbenes@student.42.fr>              +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2024/07/08 17:09:15 by sbenes            #+#    #+#             ;;
;;   Updated: 2024/07/08 17:09:15 by sbenes           ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

; ssize_t write(int fd, const void *buf, size_t count);
; success - attempts write up to count bytes to file descriptor fd from the buffer starting at *buf
;           Number of bytes written is returned
; failure - -1 is returned, errno is set to indicate the error
section .data
extern __errno_location

section .text
global ft_write


ft_write:
    mov rax, 1                  ;1 is syscall for write
    syscall                     ;makes the syscall for write
    cmp rax, 0                  ;is return zero?
    jl  _error                  ;if the rax is lower than 0, it is an error
    ret                         ;if is 0 or more, returns the rax value

_error:
    mov rdi, rax                ;save the return value in rbi - it contains errno value
    neg rdi                     ;negate the value to make it positive
    call __errno_location       ;get the address of errno in rax
    mov [rax], rdi              ;set the errno to the value in rdi (rax is the *address of errno)

    mov rax, -1                 ;set rax to -1 to indicate an error for return.
    ret                         ;returns -1