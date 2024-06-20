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

;int ft_strcmp(char *s1, char *s2)
;{
;	int i = 0;
;
;	while((s1[i] == s2[i]) && s1[i] && s2[i])
;		i++;
;	return (s1[i]-s2[i]);
;}

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
    xor rax, rax                    ;setting return value to 0
    xor rdx, rdx                    ;setting the conter to 0

_loop:

    mov bl, byte[rdi]
    mov cl, byte[rsi]
    cmp bl, cl
    jne _return
    cmp bl, 0
    je _return
    cmp cl, 0 
    je _return
    inc rdi
    inc rsi
    jmp _loop

_return:

    movzx rax, bl
    movzx rdx, cl
    sub rax, rdx
    rets
