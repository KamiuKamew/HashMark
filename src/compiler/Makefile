# 气急败坏.jpg

.PHONY:all
all:
	bison --yacc -dv parser.y
	flex lexer.l 
	gcc -c -o y.tab.o y.tab.c
	gcc -c -o lex.yy.o lex.yy.c
	gcc -c -o var.o var.c 
	gcc -c -o yyerror.o yyerror.c 
	g++ -c -o ExpressionResults.o ExpressionResults.cpp
	g++ -o test y.tab.o lex.yy.o var.o yyerror.o ExpressionResults.o


# .PHONY : all clean run

# all: $(TARGET)

# CC			=	gcc
# CXX			=	g++
# CCFLAGS		=	-Wall
# CXXFLAGS	=	-Wall
# TARGET 		:= 	test

# LEXER 		:= lexer
# PARSER 		:= parser

# y.tab.c y.tab.h: $(PARSER).y
# 	bison --yacc -dv $<
# lex.yy.c : $(LEXER).l
# 	flex $<

# SRC_C		=	$(wildcard *.c)
# SRC_CPP		=	$(wildcard *.cpp)
# SRC			=	$(SRC_C) $(SRC_CPP)
# OBJ_C		=	$(SRC_C:.c=.o)
# OBJ_CPP		=	$(SRC_CPP:.cpp=.o)
# OBJ			=	$(OBJ_C) $(OBJ_CPP)


# $(OBJ_C)	:	%.o: %.c | y.tab.c
# 	$(CC) $(CCFLAGS) -c $< -o $@

# $(OBJ_CPP)	:	%.o: %.cpp
# 	$(CXX) $(CXXFLAGS) -c $< -o $@

# $(TARGET)	:	$(OBJ)
# 	$(CXX) $^ -o $@

# clean: $(OBJ) 
# 	del $^

# run:
# 	.\$(TARGET)