# https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html#creating
CC = g++
CFLAGS = -Wall -std=c++14
TARGET = builder_facets

all : ${TARGET}

${TARGET} : person.o personbuilder.o facets.o 
	${CC} ${CFLAGS} -o ${TARGET} facets.o person.o personbuilder.o

facets.o : Facets.cpp Person.h PersonBuilder.h PersonAddressBuilder.h PersonJobBuilder.h
	${CC} ${CFLAGS} -c Facets.cpp

person.o : Person.cpp Person.h PersonBuilder.h
	${CC} ${CFLAGS} -c Person.cpp

personbuilder.o : PersonBuilder.cpp PersonBuilder.h PersonAddressBuilder.h PersonJobBuilder.h
	${CC} ${CFLAGS} -c PersonBuilder.cpp


.PHONY: clean
clean:
	rm -f ${TARGET} *.o *~



# countwords program 
# 	scanner module 
# 	counter module