#--- BASIC ---#

NAME    	= minishell
CC      	= gcc
FLAGS   	= -Wall -Werror -Wextra -g -fsanitize=address
RM      	= rm -rf


#--- LIBFT ---#

LIBFT_DIR = libft
LIBFT_LIB = ${LIBFT_DIR}/libft.a

#--- GROUP ---#

SRCS_DIR 	= src
OBJS_DIR	= obj


BUILTIN		=

EXECUTION	=

PARSING		=	quotes tokenizer reg_cmd ft_ascii_font meta type

SIGNALS		=

UTILS		=	struct node ft_strncpy ft_strlen_

SRCS		= 	$(addsuffix .c, $(addprefix $(SRCS_DIR)/builtin/, $(BUILTIN))) \
				$(addsuffix .c, $(addprefix $(SRCS_DIR)/execution/, $(EXECUTION))) \
				$(addsuffix .c, $(addprefix $(SRCS_DIR)/parsing/, $(PARSING))) \
				$(addsuffix .c, $(addprefix $(SRCS_DIR)/signals/, $(SIGNALS))) \
				$(addsuffix .c, $(addprefix $(SRCS_DIR)/utils/, $(UTILS))) \
				$(addsuffix .c, main) 
				

OBJS 		= 	$(addprefix ${OBJS_DIR}/, $(subst src/,,$(SRCS:.c=.o))) 

#--- COLOR ---#
BLACK 		=	\033[90;1m
RESET 		=	\033[0m
GREEN		=	\033[0;32m
RED			=	\033[0;31m
YELLOW		=	\033[0;33m

#--- TARGET ---#

#--- readline ---#

LIBRLINE	 	= readline-8.2
LIBRLINE_DIR 	= include/readline
LIBRD 			= $(LIBRLINE_DIR)/bin/libreadline.a $(LIBRLINE_DIR)/bin/libhistory.a
LIBS 			= -lreadline -lcurses $(LIBRD)

all: ${NAME} ${LIBFT_LIB}

${LIBFT_LIB}:
	@make -C ${LIBFT_DIR}


$(LIBRD):
	curl -O ftp://ftp.cwru.edu/pub/bash/$(LIBRLINE).tar.gz
	tar -zxvf $(LIBRLINE).tar.gz
	@rm -rf $(LIBRLINE).tar.gz
	@cd $(LIBRLINE) && bash configure && make
	@mkdir -p $(LIBRLINE_DIR)/bin
	@mv ./$(LIBRLINE)/*.h $(LIBRLINE_DIR)
	@mv ./$(LIBRLINE)/*.a $(LIBRLINE_DIR)/bin
	@rm -rf $(LIBRLINE)

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	@mkdir -p ${@D}
	@${CC} ${FLAGS} -I include -c $< -o $@
	@echo "$(BLACK)Compiling: $< "

${NAME}: ${LIBRD} ${OBJS}
	@${CC} ${FLAGS} -I ${OBJS_DIR} $^ -o ${NAME} ${LIBS}
	@echo "$(GREEN)Compilation terminé avec succès!"


clean:
	@echo "$(YELLOW)Nettoyage en cours ... !"
	@make clean -C ${LIBFT_DIR}
	@${RM} ${OBJS_DIR} ${LIBFT_LIB} $(LIBRLINE_DIR)
	@echo "$(BLACK)Nettoyage effectué avec succès !"

fclean: clean
	@${RM} ${NAME} 
	@make clean -C ${LIBFT_DIR}

re: fclean all

.PHONY: all clean fclean re
