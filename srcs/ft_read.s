# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_read.s                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fulldemo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/01 16:43:51 by fulldemo          #+#    #+#              #
#    Updated: 2020/02/01 16:43:54 by fulldemo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.text:
	global _ft_read

_ft_read:
		mov rax, 0x2000003	; rdi(fd), rsi(buff), rdx(nbytes)
		syscall
        jc err
        ret
err:
        mov rax, -1
        ret