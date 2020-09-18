# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlen.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fulldemo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/01 12:03:01 by fulldemo          #+#    #+#              #
#    Updated: 2020/02/01 12:03:05 by fulldemo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


.text:
	global _ft_strlen

_ft_strlen:
	mov rax, 0
	_start_loop:
		cmp	byte [rdi + rax], 0
		jz	_end_loop
		inc rax
		jmp	_start_loop
	_end_loop:
	ret
