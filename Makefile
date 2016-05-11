CXX=g++
GL=
CFLAGS=-Wall -Wextra -L/System/Library/Frameworks $(GL)
DEBUG=-g
VERBOSE=-v
SOURCE=$(shell ls src)

OS=$(shell uname -s)
ifeq ($(OS),Darwin)
	GL += -framework GLUT -framework OpenGL
else
	GL += -lglut -lGLU -lGL -lm
endif

main :
	$(CXX) -o bin/main src/$(SOURCE) $(CFLAGS) $(DEBUG) $(VERBOSE)

clean :
	rm -rf bin/*