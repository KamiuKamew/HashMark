DIR_COMPILER	:=	src/compiler
DIR_GUI			:=	src/GUI

# 默认目标
all: compiler

# 编译器模块
compiler:
	$(MAKE) -C $(DIR_COMPILER)

# 伪目标声明
.PHONY: all run

run:
	.\src/compiler/test.exe