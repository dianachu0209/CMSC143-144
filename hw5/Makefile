.PHONY: clean
test: hw5.h hw5.c test_hw5.c
	clang -Wall -o test hw5.c test_hw5.c -L/opt/homebrew/lib -lcriterion -I/opt/homebrew/include
clean:
	rm -rf a.out test
