CXX		 = g++
CXXFLAGS = -std=c++11 -g
LDFLAGS  =
DEPS	 = main.cpp Client.cpp Client.h Data.cpp Data.h Delivery.cpp Delivery.h DeliveryNetwork.cpp DeliveryNetwork.h GPS.cpp GPS.h Graph.cpp Graph.h Item.cpp Item.h Supermarket.cpp Supermarket.h Menu.cpp Menu.h connection.cpp connection.h edgetype.h graphviewer.cpp graphviewer.h ui_utilities.cpp ui_utilities.h utilities.cpp utilities.h makefile
OBJFILES = main.o Client.o Data.o Delivery.o DeliveryNetwork.o GPS.o Graph.o Item.o Supermarket.o Menu.o connection.o graphviewer.o ui_utilities.o utilities.o
TARGET	 = main

all: $(TARGET)

$(TARGET): $(OBJFILES) $(DEPS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)


clean:
	rm -f $(OBJFILES) $(TARGET) *~
