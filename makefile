CC = gcc
CFLAGS = -Wall -ansi 
OBJFILES = src/construction.o src/sauvegarde.o src/parcours.c src/annexe.o src/main.o
TARGET = lexique

all : $(TARGET)

$(TARGET): $(OBJFILES)
		$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES)

clean:
	rm -f $(OBJFILES) $(TARGET) *~