# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 16:42:04 by smazouz           #+#    #+#              #
#    Updated: 2022/02/27 18:45:07 by smazouz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCM = pipex.c utils/ft_split.c utils/ft_find_C_path.c utils/ft_strlcpy.c utils/ft_pipex_main.c utils/ft_lstnew.c utils/ft_lstadd_back.c utils/ft_lstlast.c utils/ft_free.c utils/ft_error.c \
		utils/ft_putstr.c utils/pipex_utils.c
SRCB = pipex_bonus.c utils_bonus/ft_find_C_path.c utils_bonus/ft_split.c utils_bonus/ft_lstnew.c utils_bonus/ft_lstadd_back.c utils_bonus/ft_lstlast.c utils_bonus/ft_strlcpy.c \
		utils_bonus/ft_pipex_main.c utils_bonus/ft_strcmp.c utils_bonus/ft_strdup.c utils_bonus/ft_putstr_fd.c utils_bonus/ft_strlen.c utils_bonus/ft_free.c utils_bonus/ft_error.c utils_bonus/ft_putstr.c \
		utils_bonus/ft_alpha_numeric.c utils_bonus/here_doc_utils.c utils_bonus/here_doc_utils_2.c utils_bonus/pipex_bonus_utils.c

OBJM = $(SRCM:.c=.o)
OBJB = $(SRCB:.c=.o)

NAME = pipex

CFLAGS = -Wall -Wextra -Werror -g

all : $(NAME)
$(NAME) : ${OBJM} pipex.h
	@$(CC)  ${OBJM} $(CFLAGS) -o ${NAME}
	@echo ────────────────────────────────────────────────────────────────────────────
	@echo ─██████████████─██████████─██████████████─██████████████─████████──████████─
	@echo ─██░░░░░░░░░░██─██░░░░░░██─██░░░░░░░░░░██─██░░░░░░░░░░██─██░░░░██──██░░░░██─
	@echo ─██░░██████░░██─████░░████─██░░██████░░██─██░░██████████─████░░██──██░░████─
	@echo ─██░░██──██░░██───██░░██───██░░██──██░░██─██░░██───────────██░░░░██░░░░██───
	@echo ─██░░██████░░██───██░░██───██░░██████░░██─██░░██████████───████░░░░░░████───
	@echo ─██░░░░░░░░░░██───██░░██───██░░░░░░░░░░██─██░░░░░░░░░░██─────██░░░░░░██─────
	@echo ─██░░██████████───██░░██───██░░██████████─██░░██████████───████░░░░░░████───
	@echo ─██░░██───────────██░░██───██░░██─────────██░░██───────────██░░░░██░░░░██───
	@echo ─██░░██─────────████░░████─██░░██─────────██░░██████████─████░░██──██░░████─
	@echo ─██░░██─────────██░░░░░░██─██░░██─────────██░░░░░░░░░░██─██░░░░██──██░░░░██─
	@echo ─██████─────────██████████─██████─────────██████████████─████████──████████─
	@echo ────────────────────────────────────────────────────────────────────────────
clean :
	$(RM) $(OBJM) $(OBJB)

fclean : clean
	$(RM) pipex pipex_bonus

re : fclean all

bonus :${OBJB} pipex_bonus.h
	@$(CC)  $(CFLAGS) ${OBJB} -o pipex_bonus
	@echo ██████╗░██╗██████╗░███████╗██╗░░██╗  ██████╗░░█████╗░███╗░░██╗██╗░░░██╗░██████╗
	@echo ██╔══██╗██║██╔══██╗██╔════╝╚██╗██╔╝  ██╔══██╗██╔══██╗████╗░██║██║░░░██║██╔════╝
	@echo ██████╔╝██║██████╔╝█████╗░░░╚███╔╝░  ██████╦╝██║░░██║██╔██╗██║██║░░░██║╚█████╗░
	@echo ██╔═══╝░██║██╔═══╝░██╔══╝░░░██╔██╗░  ██╔══██╗██║░░██║██║╚████║██║░░░██║░╚═══██╗
	@echo ██║░░░░░██║██║░░░░░███████╗██╔╝╚██╗  ██████╦╝╚█████╔╝██║░╚███║╚██████╔╝██████╔╝
	@echo ╚═╝░░░░░╚═╝╚═╝░░░░░╚══════╝╚═╝░░╚═╝  ╚═════╝░░╚════╝░╚═╝░░╚══╝░╚═════╝░╚═════╝░