path = chinko_bot/dscript

all:
	make compilbl
	cd cmake && $(MAKE)
	./cmake/chinko_bot

compilbl: $(path)/parser.y $(path)/lexer.l
	bison -d $(path)/parser.y --defines=$(path)/products/parser.tab.h -o $(path)/products/parser.tab.cpp
	flex -o $(path)/products/lexer.cpp $(path)/lexer.l
	