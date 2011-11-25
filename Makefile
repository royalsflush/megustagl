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

test:
	$(CC) $(CFLAGS) $(LIBS) vector.cpp glTest.cpp -o glTest

cleanCube:
	rm cube

clean:
	rm $(OUT)
	rm *.o

depend:
	makedepend -- $(CFLAGS) -- $(SRCS)
