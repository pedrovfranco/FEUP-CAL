CXX		 = g++
CXXFLAGS = -std=c++11 -g
LDFLAGS  =
DEPS	 = FichaJUNG.cpp connection.cpp connection.h edgetype.h graphviewer.cpp graphviewer.h makefile
OBJFILES = FichaJUNG.o connection.o graphviewer.o
TARGET	 = main

all: $(TARGET)

$(TARGET): $(OBJFILES) $(DEPS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)


clean:
	rm -f $(OBJFILES) $(TARGET) *~
