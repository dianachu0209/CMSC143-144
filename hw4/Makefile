.PHONY: clean
test: hw4.h hw4.c test_hw4.c
	clang -Wall -o test hw4.c test_hw4.c -L/opt/homebrew/lib -lcriterion -I/opt/homebrew/include
clean:
	rm -rf a.out test
