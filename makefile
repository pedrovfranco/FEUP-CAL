CXX		 = g++
CXXFLAGS = -std=c++11 -g
LDFLAGS  =
DEPS	 = main.cpp Client.cpp Client.h Data.cpp Data.h Delivery.cpp Delivery.h DeliveryNetwork.cpp DeliveryNetwork.h GPS.cpp GPS.h Graph.h Item.cpp Item.h Supermarket.cpp Supermarket.h makefile
OBJFILES = main.o Client.o Data.o Delivery.o DeliveryNetwork.o GPS.o Item.o Supermarket.o
TARGET	 = main

all: $(TARGET)

$(TARGET): $(OBJFILES) $(DEPS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)


clean:
	rm -f $(OBJFILES) $(TARGET) *~
