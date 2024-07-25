;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_strcmp.s                                        :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: sbenes <sbenes@student.42.fr>              +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2024/06/20 15:45:01 by sbenes            #+#    #+#             ;;
;;   Updated: 2024/06/20 15:45:01 by sbenes           ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

;int ft_strcmp(const char *s1, const char *s2);


;register usage:
; rdi = char *s1
; rsi = char *s2
; rax = return value
; rdx = use for tmp
; rbx (bl) = temp for cmp
; rcx (cl) = temp for cmp

section .text
global ft_strcmp

ft_strcmp:
    xor rax, rax               ;setting return value to 0
    xor rdx, rdx               ;setting the conter to 0

_loop:

    mov bl, byte[rdi]         ;move the first char of s1 to bl (byte[rdi] is the same as s1[0], bl is the lower 8 bits of rbx)
    mov cl, byte[rsi]         ;move the first char of s2 to cl (byte[rsi] is the same as s2[0], cl is the lower 8 bits of rcx)
    cmp bl, cl                ;compare the two chars                                            
    jne _return               ;if they are not equal, jump to return routine
    cmp bl, 0                 ;check if the char in bl is EOS (End Of String)
    je _return                ;if it is, jump to return routine   
    cmp cl, 0                 ;check if the char in cl is EOS (End Of String)
    je _return                ;if it is, jump to return routine
    inc rdi                   ;increment the pointer to s1
    inc rsi                   ;increment the pointer to s2
    jmp _loop                 ;jump to loop

_return:
    movzx rax, bl             ;move the value of bl to rax (movzx is mov with zero extend - makes 64 bit from 8 bit of bl)
    movzx rdx, cl             ;move the value of cl to rdx (zero extend)
    sub rax, rdx              ;subtract the value of rdx from rax
    ret                       ;return
