path = chinko_bot/dscript

all:
	make compil
	./cmake/chinko_bot

compil: $(path)/parser.y $(path)/lexer.l
	bison -d $(path)/parser.y --defines=$(path)/products/parser.tab.h -o $(path)/products/parser.tab.cpp
	flex $(path)/lexer.l
	cd cmake && $(MAKE)
	