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

;ssize_t write(int fd, const void *buf, size_t count);
; success - attempts write up to count bytes to file descriptor fd from the buffer starting at *buf
;           Number of bytes written is returned
; failure - -1 is returned, errno is set to indicate the error

section .text
global ft_write

ft_read:
    mov rax, 1          ;1 is syscall for write
    syscall             ;makes the syscall for write
    cmp rax, 0          ;is return zero?
    jl  _error          ;if the rax is lower than 0, it is an error
    ret                 ;if is 0 or more, returns the rax value

_error:
    mov rax, -1
    ret                 ;returns -1