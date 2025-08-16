CC		=	cc
NAME		=	rush01

SRCS		=	./*.c

_GREEN		=	$(shell echo -e "\033[92;5;118m")
_YELLOW		=	$(shell echo -e "\033[93;5;226m")
RED		=	$(shell echo -e "\033[31m")
GREEN		=	$(shell echo -e "\033[32m")
YELLOW		=	$(shell echo -e "\033[33m")
CYAN		=	$(shell echo -e "\033[96m")
RESET		=	$(shell echo -e "\033[0m")
CURSIVE     	=	$(shell echo -e "\033[33;3m")
GRAY        	=	$(shell echo -e "\033[33;2;37m")

FLAGS		= -Wall -Wextra -Werror
LINKERFLAGS	=

RM		=	rm -rf

OBJDIR		=	build
PLIST		=

FRAMEWORKS    	=

OBJS		=	$(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
LDFLAGS       	=

CXXFLAGS     +=

.PHONY: all clean fclean re

all:		$(NAME)

$(NAME):	$(OBJS) 
	@echo -e "\t$(CYAN)[Creating program]$(RESET)"
	@echo -e "\t$(YELLOW) compiling$(_YELLOW)... $(RESET)$(YELLOW)$*.c++$(RESET)"
	@$(CC) $(SRCS) $(FLAGS) -o $(NAME) $(LDFLAGS) $(LINKERFLAGS)
	@echo -e "$(CURSIVE)[Executable created & ready]$(RESET)\n\033[32mCompiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ"
	@echo -e "$(_GREEN)object files were in test$(RESET)"

$(OBJDIR)/%.o: %.c 
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@echo -e "$(GRAY)[cleaning up .out & objects files]$(RESET)"
	@$(RM) $(OBJDIR) $(OBJS)

fclean:		clean
	@printf "$(RED)[cleaning up .out, objects & library files]$(_NC)\n\033[31mDeleting EVERYTHING! ⌐(ಠ۾ಠ)¬\n"
	@$(RM) $(NAME)

re: clean all


