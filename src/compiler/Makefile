LEXER 		:= test_lexer
LEXER_C 	:= lex.yy.c
PARSER 		:= test_parser
PARSER_C 	:= y.tab.c
PARSER_H 	:= y.tab.h
TARGET_EXE 	:= test.exe

all: build clean run

$(PARSER_C) $(PARSER_H): $(PARSER).y
	bison --yacc -dv $<

$(LEXER_C) : $(LEXER).l
	flex $<

$(TARGET_EXE) : $(PARSER_C) $(LEXER_C)
	gcc -o $@ $^

build: $(TARGET_EXE)

clean: $(LEXER_C) $(PARSER_C) $(PARSER_H)
	del $^

run:
	.\$(TARGET_EXE)