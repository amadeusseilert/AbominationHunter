CC = gcc
CFLAGS  = -Werror -Wall
LDLIBS = -lglut -lGLU -lGL -lm
OBJECTS = hunter.o weapon.o world.o
TARGET = main

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) $(LDLIBS) -o $(TARGET) $(TARGET).c $(OBJECTS)

clean:
	$(RM) $(TARGET)
