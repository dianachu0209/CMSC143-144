.PHONY: clean
test: hw3.h hw3.c test_hw3.c
	clang -Wall -o test hw3.c test_hw3.c -L/opt/homebrew/lib -lcriterion -I/opt/homebrew/include
clean:
	rm -rf a.out test
