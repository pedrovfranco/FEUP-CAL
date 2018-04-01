CXX		 = g++
CXXFLAGS = -std=c++11 -g
LDFLAGS  =
DEPS	 = main.cpp Client.cpp Client.h Data.cpp Data.h Delivery.cpp Delivery.h DeliveryNetwork.cpp DeliveryNetwork.h GPS.cpp GPS.h Graph.cpp Graph.h Item.cpp Item.h Supermarket.cpp Supermarket.h connection.cpp connection.h edgetype.h graphviewer.cpp graphviewer.h makefile
OBJFILES = main.o Client.o Data.o Delivery.o DeliveryNetwork.o GPS.o Graph.o Item.o Supermarket.o connection.o graphviewer.o
TARGET	 = main

all: $(TARGET)

$(TARGET): $(OBJFILES) $(DEPS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)


clean:
	rm -f $(OBJFILES) $(TARGET) *~
