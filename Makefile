CC = g++
CFLAGS = -Wall -pedantic -ansi -Wshadow -g
LIBS = -lm
OUT = megusta

SRCS = main.cpp glutWrapper.cpp
OBJS = $(SRCS:.cpp=.o)

ifeq ($(shell uname), Darwin)
	LIBS+= -framework OpenGL -framework GLUT
else
	LIBS+= -lglut
endif

demo: $(OBJS)
	$(CC) $(CFLAGS) $(LIBS) $(OBJS) -o $(OUT)

.cpp.o: 
	$(CC) $(CFLAGS) $(LIBS) -c -o $@ $<

cube:
	$(CC) $(CFLAGS) $(LIBS) simplecube.cpp -o cube

cleanCube:
	rm cube

clean:
	rm $(OUT)
	rm *.o

depend:
	makedepend -- $(CFLAGS) -- $(SRCS)	
# DO NOT DELETE

main.o: /usr/include/stdio.h /usr/include/sys/cdefs.h
main.o: /usr/include/sys/_symbol_aliasing.h
main.o: /usr/include/sys/_posix_availability.h /usr/include/Availability.h
main.o: /usr/include/AvailabilityInternal.h /usr/include/_types.h
main.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
main.o: /usr/include/i386/_types.h /usr/include/secure/_stdio.h
main.o: /usr/include/secure/_common.h /usr/include/stdlib.h
main.o: /usr/include/sys/wait.h /usr/include/sys/signal.h
main.o: /usr/include/sys/appleapiopts.h /usr/include/machine/signal.h
main.o: /usr/include/i386/signal.h /usr/include/i386/_structs.h
main.o: /usr/include/sys/_structs.h /usr/include/machine/_structs.h
main.o: /usr/include/sys/resource.h /usr/include/machine/endian.h
main.o: /usr/include/i386/endian.h /usr/include/sys/_endian.h
main.o: /usr/include/libkern/_OSByteOrder.h
main.o: /usr/include/libkern/i386/_OSByteOrder.h /usr/include/alloca.h
main.o: /usr/include/machine/types.h /usr/include/i386/types.h meGustaGL.h
