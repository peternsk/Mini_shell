#--- BASIC ---#

NAME        = minishell
CC          = gcc
# FLAGS       = -Wall -Wextra -Werror -g #-fsanitize=address
FLAGS     = -Wall -Wextra -fsanitize=address
# FLAGS     = -Wall -Werror -Wextra -g
RM          = rm -rf

#--- LIBFT ---#

LIBFT_DIR = libft
LIBFT_LIB = ${LIBFT_DIR}/libft.a

#--- GROUP ---#

SRCS_DIR    = 	src
OBJS_DIR    = 	obj

BUILTIN     =   ft_pwd ft_cd addEnvp printEnvp ft_echo ft_export check_duplicate is_same_key is_add_envp size ft_unset is_same_key_value ft_env ft_exit copy_value is_key

BUILDER     =   ft_removeQuotes set_cmdLst ft_buildCmdArr merge_token ft_buildRedlst

EXECUTION   =   init_cmds add_cmds cout_cmds_pipes add_files type_cmd run_commands get_envp_path get_cmd_path single_command commands wait_childs execute_command which_files  ft_append change_stdint change_stdout handel_builtin init_manage_fd is_files_valide ft_here_doc is_there_here_doc pipe_connect_and_files std_one_commande check_absolute_path file_here_doc

EXT_STATUS  =   createList

ENV         =   set_env findVarEnv exp_split ft_expend list2tab extra_find_var

# HERE_DOC  =   here_doc set_here_lst here_pars here_pars1 send_2_tmp

HERE_DOC    =   here_doc set_here_lst here_pars here_pars1 send_2_tmp run_all_heredoc unlink_lst create_file_unlnk

GARBAGE     =   add_address free_garb_lst

LEXER       =   quotes tokenizer reg_cmd ft_ascii_font meta type

PARSER      =   ft_parsing set_file print_real_list

SIGNALS     =   manage_signal

UTILS       =   struct node ft_strncpy ft_trim ft_strcmp ft_combine ft_endToken free_function ft_search_char ft_int_to_asc

MAIN        =   build_and_exec main

SRCS        =   $(addsuffix .c, $(addprefix $(SRCS_DIR)/builtin/, $(BUILTIN))) \
                $(addsuffix .c, $(addprefix $(SRCS_DIR)/execution/, $(EXECUTION))) \
                $(addsuffix .c, $(addprefix $(SRCS_DIR)/exitStatus/, $(EXT_STATUS))) \
                $(addsuffix .c, $(addprefix $(SRCS_DIR)/env/, $(ENV))) \
                $(addsuffix .c, $(addprefix $(SRCS_DIR)/garbage/, $(GARBAGE))) \
                $(addsuffix .c, $(addprefix $(SRCS_DIR)/lexer/, $(LEXER))) \
                $(addsuffix .c, $(addprefix $(SRCS_DIR)/parser/, $(PARSER))) \
                $(addsuffix .c, $(addprefix $(SRCS_DIR)/builder/, $(BUILDER))) \
                $(addsuffix .c, $(addprefix $(SRCS_DIR)/signals/, $(SIGNALS))) \
                $(addsuffix .c, $(addprefix $(SRCS_DIR)/utils/, $(UTILS))) \
                $(addsuffix .c, $(addprefix $(SRCS_DIR)/hereDocument/, $(HERE_DOC))) \
                $(addsuffix .c, $(addprefix $(SRCS_DIR)/main/, $(MAIN))) 

OBJS        =   $(addprefix ${OBJS_DIR}/, $(subst src/,,$(SRCS:.c=.o)))

#--- COLOR ---#

BLACK       =   \033[90;1m
RESET       =   \033[0m
GREEN       =   \033[0;32m
RED         =   \033[0;31m
YELLOW      =   \033[0;33m

#--- TARGET ---#

#--- readline ---#

LIBRLINE        = readline-8.2
LIBRLINE_DIR    = include/readline
LIBRD           = $(LIBRLINE_DIR)/bin/libreadline.a $(LIBRLINE_DIR)/bin/libhistory.a
LIBS            = $(LIBFT_LIB) -lreadline -lcurses $(LIBRD)

all: ${NAME}

${LIBFT_LIB}:
	@make -C ${LIBFT_DIR}

$(LIBRD):
	curl -O https://ftp.gnu.org/gnu/readline/$(LIBRLINE).tar.gz
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

${NAME}: ${LIBRD} ${LIBFT_LIB} ${OBJS}
	@${CC} ${FLAGS} -I ${OBJS_DIR} $^ -o ${NAME} ${LIBS}
	@echo "Compilation terminé avec succès!"

leaks:
	@valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --trace-children=yes --suppressions=./$(NAME).sup ./$(NAME)

clean:
	@echo "$(YELLOW)Nettoyage en cours ... !"
	@make clean -C ${LIBFT_DIR}
	@${RM} ${OBJS_DIR}
    # @${RM} ${OBJS_DIR} ${LIBFT_LIB} $(LIBRLINE_DIR)
	@echo "$(BLACK)Nettoyage effectué avec succès !"

fclean: clean

	@${RM} ${NAME}
	@make clean -C ${LIBFT_DIR}

re: fclean all

.PHONY: all clean fclean re

#---  make && valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --trace-children=yes --suppressions=sup.txt ./minishell ---#