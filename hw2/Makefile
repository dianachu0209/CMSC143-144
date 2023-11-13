.PHONY: clean
test: hw2.h hw2.c test_hw2.c
	clang -Wall -o test hw2.c test_hw2.c -L/opt/homebrew/lib -lcriterion -I/opt/homebrew/include
clean:
	rm -rf a.out test
