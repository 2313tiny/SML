SOURCES := matrix.cpp vector.cpp main.cpp test.cpp
OBJECTS := $(patsubst %.cpp,%.o,$(SOURCES))

all: program run

program :$(OBJECTS)
	@clear
	@g++ $(OBJECTS) -o smd

test.o:
	g++ -c test.cpp -o test.o

matrix.o:
	g++ -c matrix.cpp -o matrix.o

vector.o:
	g++ -c vector.cpp -o vector.o

main.o:
	g++ -c main.cpp -o main.o

matrix.dep:
	@g++ -MM matrix.cpp \
		-MT "matrix.dep matrix.o" -o matrix.dep
vector.dep:
	@g++ -MM vector.cpp \
	  -MT "vector.dep vector.o" -o vector.dep
main.dep:
	@g++ -MM main.cpp \
	 -MT "main.dep main.o" -o main.dep
	 	
test.dep:
	g++ -MM test.cpp \
	 -MT "test.dep test.o" -o test.dep 

-include matrix.dep vector.dep main.dep test.dep

run:
	./smd
	@ctags -R .

clean:
	rm -r *.o *.dep tags smd

