SRC_DIR = ../src
BUILD_DIR = .
TEST_INPUT_DIR = ../test/input
TOKENS_DIR = ../test/tokens
PARSED_DIR = ../test/parsed
OUTPUT_DIR = ../test/output

all: exe

lexer:
	flex $(SRC_DIR)/lexer.l

parser:
	yacc -d $(SRC_DIR)/parser.y

exe: lexer parser
	g++ y.tab.c -o $(BUILD_DIR)/exe

run: exe
	@echo "Running parser with input file $(inp), token log file $(tok), parse log file $(par) and output file $(out)..."
	./$(BUILD_DIR)/exe $(TEST_INPUT_DIR)/$(inp) $(TOKENS_DIR)/$(tok) $(PARSED_DIR)/$(par) $(OUTPUT_DIR)/$(out)

clean:
	rm -f lex.yy.c y.tab.c y.tab.h
	rm -f $(BUILD_DIR)/exe