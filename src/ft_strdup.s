;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_strdup.s                                        :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: sbenes <sbenes@student.42.fr>              +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2024/07/08 16:13:18 by sbenes            #+#    #+#             ;;
;;   Updated: 2024/07/08 16:13:18 by sbenes           ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

;char *ft_strdup(const char *s)
; success: returns a pointer to a new string (exact copy of the source)
; failure: returns NULL if the malloced memory is unsufficient (errno is set to indicate)

; Initial registers:
; rdi = char *s
; rax = return value
; rsi = used for second argument for char *ft_strcpy(char *dest, char *src)

; General overview:
; 1. Calculate the length of the source string - uses ft_strlen
; 2. Allocate memory for the new string - calls malloc
; 3. Copy the source string to the new string - uses ft_strcpy
; 4. Return the new string

extern malloc
extern ft_strlen
extern ft_strcpy

section .text
global ft_strdup

ft_strdup:
    push    rdi                 ;parks the source (first arg) to the stack for later use, clears rdi for usage in helper functions

_len:                           ;; calculates the len of the source, adds one for null terminator ;;
    call    ft_strlen           ;ft_strlen is called, returns the lenght in rax
    inc      rax

_malloc:
    mov     rdi, rax            ;rax at this point - len of the required memory - send to rdi, used as argument for malloc
    call    malloc              ;malloc - takes rdi (len) as argument
    cmp     rax, 0              ;protect malloc - check if rax return value is zero
    je      _error              ; malloc fails == jump to _error routine

_copy:
    mov     rdi, rax            ;rax at this point - pointer to memory allocated by malloc - send to rdi, used as argument for ft_strcpy
    pop     rsi                 ;takes the original string from the stack parking - saves it to rsi (second argument)
    call    ft_strcpy           ;makes a copy using rdi as destination and rsi as source
    ret                         ;returns destination as result

_error:
    pop     rdi                 ;clears the stack if malloc fails.
    xor     rax, rax            ;sets return to 0
    ret                         ;return
