CC = g++
CFLAGS = -Wall -o
TARGETS = Stack Queue

all: $(TARGETS)

Stack: testStack.cpp Stack.h
	$(CC) $(CFLAGS) stack testStack.cpp

Queue: testQueue.cpp Stack.h Queue.h
	$(CC) $(CFLAGS) queue testQueue.cpp

clean:
	rm $(TARGETS)