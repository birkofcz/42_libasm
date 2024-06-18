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
    xor rax, rax                ;initial clean of rax to 0, to be used for return value. xor (bitwise eclusive OR) is faster than mov rax, 0. xor with itself is always 0.
    xor rcx, rcx                ;initial clean of rcx to 0, to be used as a counter   

_loop:
    mov al, byte[rsi + rcx]     ;moves the first char to al. al is the first byte (8-bit) portion of 64bits rax register. You need the same operand sizes.
                                ;we also cannot do mov byte[rdi + rcx], byte[rsi + rcx] - The x86-64 instruction set does not support direct memory-to-memory moves,
                                ;you have to use a register as an intermediary.

    mov byte[rdi + rcx], al     ;transfer from al to memory position on destination (dest[0]).
    cmp al, 0                   ;test for EOS
    je  _return                 ;if EOS, jump to return
    inc rcx                     ;rcx++
    jmp _loop                   ;jump to loop

_return:
    mov rax, rdi                ;set the *dest into rax register for return
    ret