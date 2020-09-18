# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_write.s                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fulldemo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/01 16:15:04 by fulldemo          #+#    #+#              #
#    Updated: 2020/02/01 16:15:08 by fulldemo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.text:
	global _ft_write

_ft_write:
	mov rax, 0x2000004	; rdi(fd), rsi(buff), rdx(nbytes)
	syscall
	jc err
	ret 

err:
	mov rax, -1
	ret