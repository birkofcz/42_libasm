;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_read.s                                          :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: sbenes <sbenes@student.42.fr>              +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2024/07/08 16:57:58 by sbenes            #+#    #+#             ;;
;;   Updated: 2024/07/08 16:57:58 by sbenes           ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

;ssize_t read(int fd, void *buf, size_t count);
; success - attempts to read up to count bytes from file descriptor fd into the buffer starting at buf.
;           Number of bytes read is returned
; failure - -1 is returned, errno is set approprietly

section .data
extern __errno_location

section .text
global ft_read


ft_read:
    mov rax, 0                  ;0 is syscall for read
    syscall                     ;makes the syscall for read
    cmp rax, 0                  ;is return zero? (no bytes read)
    jl  _error                  ;if the rax is lower than 0, it is an error
    ret                         ;if is 0 or more, returns the rax value

_error:
    mov rdi, rax                ;save the return value in rdi - it contains errno value
    neg rdi                     ;negate the value to make it positive
    call __errno_location       ;get the address of errno in rax
    mov [rax], rdi              ;set the errno to the value in rdi (rax is the *address of errno)

    mov rax, -1                 ;set rax to -1 to indicate an error for return.
    ret                         ;returns -1
