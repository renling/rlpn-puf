CXX = g++ 
SRC = test.cpp 
INC = -I. -I../flint-2.4.5/ -I../gmp-6.0.0/ -I../mpfr-3.1.2/src/ 

PARAM = -O3 $(INC) -lflint -lgmp 

TARGET = test

all: $(TARGET) 
$(TARGET): $(SRC)
	$(CXX) -o $(TARGET) $(SRC) $(PARAM) 
clean:
	rm $(TARGET)
