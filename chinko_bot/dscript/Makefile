object = dscript
#object = $@

# all: src/$(object).y src/$(object)_flex.l
# 	bison src/$(object).y --defines=products/$(object).h -o products/$(object).c
# 	gcc -Wall -o products/$(object).o -c products/$(object).c
# 	flex -o products/$(object)_flex.c src/$(object)_flex.l
# 	gcc -Wall -o products/$(object)_flex.o -c products/$(object)_flex.c
# 	gcc -Wall -o products/gramm_funcs.o -c src/gramm_funcs.c
#	gcc -Wall products/$(object).o products/$(object)_flex.o products/gramm_funcs.o -o $(object) -lm

all:
	#bison -d src/parser.y
	bison -d src/parser.y --defines=products/parser.h -o products/parser.c
	flex -o products/lexer.c src/lexer.l
	g++ -g -Wall products/lexer.c products/parser.c src/gramm_funcs.cpp src/main.cpp -o base


# all: src/$(object).y src/$(object)_flex.l
# 	bison --verbose src/$(object).y --defines=products/$(object).h -o products/$(object).cpp
# 	g++ -Wall -o products/$(object).o -c products/$(object).cpp
# 	flex --c++ -o products/$(object)_flex.cpp src/$(object)_flex.l
# 	g++ -Wall -o products/$(object)_flex.o -c products/$(object)_flex.cpp
# 	g++ -Wall -o products/gramm_funcs.o -c src/gramm_funcs.cpp
# 	g++ -Wall products/$(object).o products/$(object)_flex.o products/gramm_funcs.o -o $(object) -lm


clean:
	rm products/*