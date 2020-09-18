# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcpy.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fulldemo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/01 12:05:04 by fulldemo          #+#    #+#              #
#    Updated: 2020/02/01 12:05:08 by fulldemo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.text:
	global _ft_strcpy

_ft_strcpy:
	mov rax, 0
	cmp rsi, byte 0
	jz _end
	_loop:
		mov dl, byte [rsi + rax]
		mov byte [rdi + rax], dl
		cmp [rsi + rax], byte 0
		jz _end
		inc rax
		jmp _loop
_end:
	mov rax, rsi
	ret