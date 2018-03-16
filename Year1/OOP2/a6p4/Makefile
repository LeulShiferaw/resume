CC=g++
TAGS=-Wall

run-test-all: test-all
	./ari
	./excep
	./iotest
	./relation

test-all: relational inputoutput exception arithmetic

run-arithmetic: arithmetic
	./ari
run-exception: exception
	./excep
run-inputoutput: inputoutput
	./iotest
run-relational: relational
	./relation

relational: fraction.cpp relational.cpp
	$(CC) $(TAGS) fraction.cpp relational.cpp -o relation
inputoutput: fraction.cpp iotest.cpp
	$(CC) $(TAGS) fraction.cpp iotest.cpp -o iotest
exception: fraction.cpp exceptiontest.cpp
	$(CC) $(TAGS) fraction.cpp exceptiontest.cpp -o excep
arithmetic: arithmetic.cpp
	$(CC) $(TAGS) fraction.cpp arithmetic.cpp -o ari
clean:
	rm ari
	rm excep
	rm iotest
	rm relation
