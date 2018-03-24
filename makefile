CC		 = g++
CFLAGS	 = -std=c++11
LDFLAGS  =
DEPS	 = supermarket.cpp supermarket.h client.cpp client.h GPS.cpp GPS.h item.cpp item.h
OBJFILES = main.o supermarket.o client.o GPS.o item.o
TARGET	 = main

all: $(TARGET)

$(TARGET): $(OBJFILES) $(DEPS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~