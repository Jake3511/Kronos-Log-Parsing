CC = g++
CFLAGS = --std=c++17 -Wall -Werror -pedantic -g
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lboost_unit_test_framework -lboost_date_time -lboost_regex
# Your .hpp files
DEPS = 
# Your compiled .o files
OBJECTS = main.o 
# The name of your program
PROGRAM = ps7

.PHONY: all clean lint

all: $(PROGRAM) $(PROGRAM).a

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

$(PROGRAM): main.o $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

$(PROGRAM).a: $(OBJECTS)
	ar rcs $@ $^

clean:
	rm *.o $(PROGRAM) $(PROGRAM).a

lint:
	cpplint *.cpp *.hpp