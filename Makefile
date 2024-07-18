#Makefile

TARGET = add_nob

all: $(TARGET)

$(TARGET): main.o add_nob.o
	g++ -o $(TARGET) main.o add_nob.o

main.o: main.cpp add_nob.h
	g++ -c -o main.o main.cpp

add_nob.o: add_nob.cpp add_nob.h
	g++ -c -o add_nob.o add_nob.cpp

clean:
	rm -f $(TARGET)
	rm -f *.o
