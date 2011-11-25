CC = g++
CFLAGS = -Wall -pedantic -ansi -Wshadow -g
LIBS = -lm
OUT = megusta

SRCS = main.cpp mggl_glutWrapper.cpp mggl_transforms.cpp \
	matrix.cpp vector.cpp mggl_primitives.cpp mggl_vertexOps.cpp \
	mggl_light.cpp mggl_material.cpp mggl_fragOps.cpp
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

main.o: /usr/include/stdio.h /usr/include/_types.h /usr/include/sys/_types.h
main.o: /usr/include/sys/cdefs.h /usr/include/machine/_types.h
main.o: /usr/include/i386/_types.h /usr/include/secure/_stdio.h
main.o: /usr/include/secure/_common.h /usr/include/stdlib.h
main.o: /usr/include/Availability.h /usr/include/AvailabilityInternal.h
main.o: /usr/include/sys/wait.h /usr/include/sys/signal.h
main.o: /usr/include/sys/appleapiopts.h /usr/include/machine/signal.h
main.o: /usr/include/i386/signal.h /usr/include/i386/_structs.h
main.o: /usr/include/sys/_structs.h /usr/include/machine/_structs.h
main.o: /usr/include/sys/resource.h /usr/include/machine/endian.h
main.o: /usr/include/i386/endian.h /usr/include/sys/_endian.h
main.o: /usr/include/libkern/_OSByteOrder.h
main.o: /usr/include/libkern/i386/_OSByteOrder.h /usr/include/alloca.h
main.o: /usr/include/machine/types.h /usr/include/i386/types.h meGustaGL.h
main.o: vector.h mggl_glutWrapper.h mggl_transforms.h matrix.h
main.o: /usr/include/stdarg.h /usr/include/assert.h mggl_primitives.h
main.o: mggl_light.h mggl_material.h mggl_fragOps.h
mggl_glutWrapper.o: /usr/include/stdlib.h /usr/include/Availability.h
mggl_glutWrapper.o: /usr/include/AvailabilityInternal.h /usr/include/_types.h
mggl_glutWrapper.o: /usr/include/sys/_types.h /usr/include/sys/cdefs.h
mggl_glutWrapper.o: /usr/include/machine/_types.h /usr/include/i386/_types.h
mggl_glutWrapper.o: /usr/include/sys/wait.h /usr/include/sys/signal.h
mggl_glutWrapper.o: /usr/include/sys/appleapiopts.h
mggl_glutWrapper.o: /usr/include/machine/signal.h /usr/include/i386/signal.h
mggl_glutWrapper.o: /usr/include/i386/_structs.h /usr/include/sys/_structs.h
mggl_glutWrapper.o: /usr/include/machine/_structs.h
mggl_glutWrapper.o: /usr/include/sys/resource.h /usr/include/machine/endian.h
mggl_glutWrapper.o: /usr/include/i386/endian.h /usr/include/sys/_endian.h
mggl_glutWrapper.o: /usr/include/libkern/_OSByteOrder.h
mggl_glutWrapper.o: /usr/include/libkern/i386/_OSByteOrder.h
mggl_glutWrapper.o: /usr/include/alloca.h /usr/include/machine/types.h
mggl_glutWrapper.o: /usr/include/i386/types.h mggl_light.h vector.h
mggl_glutWrapper.o: mggl_fragOps.h
mggl_transforms.o: /usr/include/math.h /usr/include/architecture/i386/math.h
mggl_transforms.o: /usr/include/sys/cdefs.h /usr/include/assert.h matrix.h
mggl_transforms.o: /usr/include/stdarg.h /usr/include/stdio.h
mggl_transforms.o: /usr/include/_types.h /usr/include/sys/_types.h
mggl_transforms.o: /usr/include/machine/_types.h /usr/include/i386/_types.h
mggl_transforms.o: /usr/include/secure/_stdio.h /usr/include/secure/_common.h
mggl_transforms.o: vector.h mggl_transforms.h
matrix.o: /usr/include/assert.h /usr/include/sys/cdefs.h
matrix.o: /usr/include/stdarg.h matrix.h /usr/include/stdio.h
matrix.o: /usr/include/_types.h /usr/include/sys/_types.h
matrix.o: /usr/include/machine/_types.h /usr/include/i386/_types.h
matrix.o: /usr/include/secure/_stdio.h /usr/include/secure/_common.h
vector.o: /usr/include/stdio.h /usr/include/_types.h
vector.o: /usr/include/sys/_types.h /usr/include/sys/cdefs.h
vector.o: /usr/include/machine/_types.h /usr/include/i386/_types.h
vector.o: /usr/include/secure/_stdio.h /usr/include/secure/_common.h
vector.o: /usr/include/math.h /usr/include/architecture/i386/math.h vector.h
mggl_primitives.o: vector.h mggl_vertexOps.h mggl_fragOps.h mggl_primitives.h
mggl_vertexOps.o: vector.h mggl_light.h mggl_transforms.h matrix.h
mggl_vertexOps.o: /usr/include/stdarg.h /usr/include/assert.h
mggl_vertexOps.o: /usr/include/sys/cdefs.h /usr/include/stdio.h
mggl_vertexOps.o: /usr/include/_types.h /usr/include/sys/_types.h
mggl_vertexOps.o: /usr/include/machine/_types.h /usr/include/i386/_types.h
mggl_vertexOps.o: /usr/include/secure/_stdio.h /usr/include/secure/_common.h
mggl_vertexOps.o: mggl_vertexOps.h
mggl_light.o: /usr/include/assert.h /usr/include/sys/cdefs.h
mggl_light.o: /usr/include/math.h /usr/include/architecture/i386/math.h
mggl_light.o: vector.h mggl_light.h mggl_material.h mggl_transforms.h
mggl_light.o: matrix.h /usr/include/stdarg.h /usr/include/stdio.h
mggl_light.o: /usr/include/_types.h /usr/include/sys/_types.h
mggl_light.o: /usr/include/machine/_types.h /usr/include/i386/_types.h
mggl_light.o: /usr/include/secure/_stdio.h /usr/include/secure/_common.h
mggl_light.o: mggl_vertexOps.h
mggl_material.o: vector.h mggl_material.h
mggl_fragOps.o: /usr/include/math.h /usr/include/architecture/i386/math.h
mggl_fragOps.o: /usr/include/sys/cdefs.h /usr/include/assert.h
mggl_fragOps.o: /usr/include/stdio.h /usr/include/_types.h
mggl_fragOps.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
mggl_fragOps.o: /usr/include/i386/_types.h /usr/include/secure/_stdio.h
mggl_fragOps.o: /usr/include/secure/_common.h vector.h mggl_fragOps.h
mggl_fragOps.o: mggl_vertexOps.h
