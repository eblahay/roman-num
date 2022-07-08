CXX = g++
CXXFLAGS = -Iinclude -std=c++17
AR = ar

APP_TARGET = bin/roman-num
LIB_TARGET = bin/roman-num.a

all: $(APP_TARGET)

$(APP_TARGET): build/main.o $(LIB_TARGET)
	g++ -o $(APP_TARGET) build/main.o $(LIB_TARGET)

$(LIB_TARGET): build/roman-num.o
	ar -crs $(LIB_TARGET) build/roman-num.o

build/main.o:
	g++ $(CXXFLAGS) -c -o build/main.o src/main.cxx

build/roman-num.o:
	g++ $(CXXFLAGS) -c -o build/roman-num.o src/roman-num.cxx

clean:
	rm build/* $(LIB_TARGET) $(APP_TARGET)

.PHONY: clean