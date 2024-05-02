# 默认目标
all: compiler

# 编译器模块
compiler:
	$(MAKE) -C src/compiler

# 清理项目
clean:
	$(MAKE) -C src/compiler clean

# 伪目标声明
.PHONY: all compiler clean
