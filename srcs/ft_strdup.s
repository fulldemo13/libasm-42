# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strdup.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fulldemo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/01 17:14:33 by fulldemo          #+#    #+#              #
#    Updated: 2020/02/01 17:14:35 by fulldemo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.text:
	global _ft_strdup
	extern _ft_strlen
	extern _malloc
	extern _ft_strcpy

_ft_strdup:
	cmp rdi, 0
	jz _error
	call _ft_strlen			;call directly funciton because it use rdi register
	push rdi				;save rdi
	mov rdi, rax			;put rax in rdi for malloc
	call _malloc			
	cmp rax, 0
	jz _error
	pop rdi					;recover rdi content
	mov rsi, rdi			;ft_strcpy use rsi register like "src" and rdi like "dst"
	mov rdi, rax			;interchange values
	call _ft_strcpy			;copy in rdi which content is rax, rsi which content is rdi
	mov rax, rdi			;restore rax with the content
	ret

_error:
	mov rax, 0
	ret