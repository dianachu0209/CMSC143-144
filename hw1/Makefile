.PHONY: clean
test: hw1.h hw1.c test_hw1.c
	clang -Wall -o test hw1.c test_hw1.c -L/opt/homebrew/lib -lcriterion -I/opt/homebrew/include -lm
clean:
	rm -rf a.out test
