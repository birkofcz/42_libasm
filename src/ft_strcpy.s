;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_strcpy.s                                        :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: sbenes <sbenes@student.42.fr>              +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2024/06/17 16:33:50 by sbenes            #+#    #+#             ;;
;;   Updated: 2024/06/17 16:33:50 by sbenes           ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

;  char *strcpy(char *dest, const char *src);

; register usage:
; rdi - char *dest (first param)
; rsi - char *src (second param)

section .text
global ft_strcpy

ft_strcpy:
    xor rax, rax            ; initial clean of rax to 0, to be used for return value
    xor rcx, rcx            ; initial clean of rcx to 0, to be used as a counter   

_loop:
    mov byte[rdi + rcx], byte[rsi + rcx]    ;moves the first char to dest (rsi)
    cmp byte[rdi + rcx], 0
    je  _return                            ;if end of string, jump to return
    inc rcx                             ;rcx++
    jmp _loop                              ;jump to loop

_return:
    mov rax, rdi
    ret