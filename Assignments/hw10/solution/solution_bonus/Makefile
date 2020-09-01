CC = g++
CFLAGS = -Wall -o
TARGETS = Activity

all: $(TARGETS)

Activity: testActivity.cpp Activity.cpp Activity.h
	$(CC) $(CFLAGS) activity testActivity.cpp Activity.cpp

run: activity
	./activity

clean:
	rm activity