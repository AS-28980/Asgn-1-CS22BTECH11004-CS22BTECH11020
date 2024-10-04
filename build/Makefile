# Directory variables
SRC_DIR = ../src
BUILD_DIR = .
TEST_INPUT_DIR = ../test/input
TOKENS_DIR = ../test/tokens

# Default target
all: exe

# Target to compile the lexer
lexer:
	flex $(SRC_DIR)/lexer.l

# Target to compile the parser
parser:
	yacc -d $(SRC_DIR)/parser.y

# Target to create the executable
exe: lexer parser
	gcc y.tab.c -o $(BUILD_DIR)/exe

# Run command to execute the parser with user-defined parameters
run: exe
	@echo "Running parser with input file $(input_file) and token log file $(token_file)..."
	./$(BUILD_DIR)/exe $(TEST_INPUT_DIR)/$(input_file) $(TOKENS_DIR)/$(token_file)

# Clean up generated files
clean:
	rm -f lex.yy.c y.tab.c y.tab.h
	rm -f $(BUILD_DIR)/exe
