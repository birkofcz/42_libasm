;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_strlen.s                                        :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: sbenes <sbenes@student.42.fr>              +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2024/06/16 13:10:14 by sbenes            #+#    #+#             ;;
;;   Updated: 2024/06/16 13:10:14 by sbenes           ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

;; Register usage:
; rax: return value
; rdi: char *str (rdi is the register used by default for the first argument 
;                the argument is pushed to the stack in the beginning of the function 
;                and is then popped into rdi)

section .text                   ; Start of the text (code) section
global ft_strlen                ; Make the function ft_strlen global (accessible from other files)

ft_strlen:                      ; Function label
    xor rax, rax                ; Set rax to 0 (length counter). xor is faster than mov (xor with itself is 0 and it is a 2 byte instruction, mov is 5 bytes)
    
_loop:                        
    cmp byte[rdi + rax], 0      ; Compare the byte-sized value (char) at the address rdi (* to the str[0]) + rax (couter initialy on 0) with 0(\0 - end of string). Pointer arithmetics.
    je _return                  ; je - jump if equal = if the byte is 0, return
    inc rax                     ; Increment the counter if the byte is not 0
    jmp _loop                   ; Jump back to the loop

_return:
    ret



; original C code for reference:
; size_t ft_strlen(char *str)
; {
;     int i;
;     i = 0;                 // rax = 0
;     while (str[i] != '\0')
;         i++;               // rax++
;     return (i);            // return rax