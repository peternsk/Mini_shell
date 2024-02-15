#--- BASIC ---#

NAME    	= minishell
CC      	= gcc
FLAGS   	= -Wall -Werror -Wextra -pthread -g
RM      	= rm -rf

#--- LIBFT ---#

LIBFT_DIR = libft
LIBFT_LIB = ${LIBFT_DIR}/libft.a

#--- GROUP ---#

SRCS_DIR 	= src
OBJS_DIR	= obj


BUILTIN		=

EXECUTION	=

PARSING		=	clt_input main

SIGNALS		=

UTILS		=

SRCS		= 	$(addsuffix .c, $(addprefix $(SRCS_DIR)/builtin/, $(BUILTIN))) \
				$(addsuffix .c, $(addprefix $(SRCS_DIR)/execution/, $(EXECUTION))) \
				$(addsuffix .c, $(addprefix $(SRCS_DIR)/parsing/, $(PARSING))) \
				$(addsuffix .c, $(addprefix $(SRCS_DIR)/signals/, $(SIGNALS))) \
				$(addsuffix .c, $(addprefix $(SRCS_DIR)/utils/, $(UTILS)))

OBJS 		= 	$(addprefix ${OBJS_DIR}/, $(subst src/,,$(SRCS:.c=.o))) 

#--- COLOR ---#
BLACK 		=	\033[90;1m
RESET 		=	\033[0m
GREEN		=	\033[0;32m
RED			=	\033[0;31m
YELLOW		=	\033[0;33m

#--- TARGET ---#

${LIBFT_LIB}:
	@make -C ${LIBFT_DIR}

all: ${NAME} ${LIBFT_LIB}

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c ${LIBFT_LIB}
	@mkdir -p ${@D}
	@${CC} ${FLAGS} -c $< -o $@
	@echo "$(BLACK)Compiling: $< "

${NAME}: ${OBJS}
	@${CC} ${FLAGS} -I ${OBJS_DIR} $^ -o ${NAME} ${LIBFT_LIB}
	@echo "$(GREEN)Compilation terminé avec succès!"

clean:
	@echo "$(YELLOW)Nettoyage en cours ... !"
	@make clean -C ${LIBFT_DIR}
	@${RM} ${OBJS_DIR} ${LIBFT_LIB}
	@echo "$(BLACK)Nettoyage effectué avec succès !"

fclean: clean
	@${RM} ${NAME} 
	@make clean -C ${LIBFT_DIR}

re: fclean all

.PHONY: all clean fclean re
