##
## EPITECH PROJECT, 2023
## B-YEP-400-BDX-4-1-zappy-johanna.bureau
## File description:
## Global Zappy Makefile
##

SERVER				= 			Server/
GUI					=			Gui/

SERVER_BINARY		=			zappy_server
GUI_BINARY			=			zappy_gui

all: server gui

server:
	@echo "Building Server..."
	@$(MAKE) -C $(SERVER)
	@mv $(SERVER)$(SERVER_BINARY) .

gui:
	@echo "Building Gui..."
	@$(MAKE) -C $(GUI)
	@mv $(GUI)$(GUI_BINARY) .

guir:
	@echo "Building Gui..."
	@$(MAKE) re -C $(GUI)
	@mv $(GUI)$(GUI_BINARY) .

clean:
	@echo "Cleaning Server..."
	@$(MAKE) -C $(SERVER) clean
	@echo "Cleaning Gui..."
	@$(MAKE) -C $(GUI) clean

fclean: clean
	@echo "Fcleaning Server..."
	@$(MAKE) -C $(SERVER) fclean
	@echo "Fcleaning Gui..."
	@$(MAKE) -C $(GUI) fclean
	@rm -f $(SERVER_BINARY) $(GUI_BINARY)

re: fclean all

debug:
	make debug -C $(GUI)

.PHONY: all server gui clean fclean re
