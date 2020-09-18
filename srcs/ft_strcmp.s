# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcmp.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fulldemo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/01 13:01:16 by fulldemo          #+#    #+#              #
#    Updated: 2020/02/01 13:01:20 by fulldemo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.text:
	global _ft_strcmp

_ft_strcmp:
	mov rax, 0
	_loop:
		cmp [rdi + rax], byte 0
		jz _rdi_end
		cmp [rsi + rax], byte 0
		jz _ret_sup
		mov dl, byte [rdi + rax]
		cmp dl, byte [rsi + rax]
		jg _ret_sup
		jl _ret_inf
		inc rax
		jmp _loop

_rdi_end:
	cmp [rsi + rax], byte 0
	jz _ret_equal
	jmp _ret_inf
_ret_inf:
	mov rax, -1
	ret
_ret_sup:
	mov rax, 1
	ret
_ret_equal:
	mov rax, 0
	ret