CC				:=	g++
CPPFLAGS		:=	-I./include -Wall -Wextra -MMD -MP -g3

# Directories
SRC_DIR			:=	src
OBJ_DIR			:=	obj

# Source files
SRCS			:=	$(shell find $(SRC_DIR) -type f -name "*.cpp")
OBJS			:=	$(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEPS			:=	$(OBJS:.o=.d)  # Gestion des fichiers de dépendances

# Target
TARGET			:=	computer

# Targets
all: $(TARGET)

$(TARGET): $(OBJS)
	@echo "\n\033[1;34mLinking...\033[0m"
	@$(CC) $^ -o $@
	@echo "\033[1;32mDone linking: $(TARGET)\033[0m"

# Compilation des fichiers objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@echo "\033[1;34mCompiling: $<\033[0m"
	@$(CC) $(CPPFLAGS) -c $< -o $@

# Création du dossier obj
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Clean
clean:
	@echo "\033[1;31mRemoving object files: $(OBJ_DIR)\033[0m"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "\033[1;31mRemoving executable: $(TARGET)\033[0m\n"
	@rm -f $(TARGET)

re: fclean all

# Gestion des dépendances
-include $(DEPS)

.PHONY: all clean fclean re