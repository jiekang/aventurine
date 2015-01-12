SRCDIR=src
BUILDDIR=build
TARGET=bin/aventurine

CC=clang++
CX=clang++ -c

CFLAGS=-g -Wall
CTFLAGS=-std=c++11 -pthread

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

RM=rm -f

$(TARGET) : $(OBJECTS)
	$(CC) $^ -o $(TARGET) $(CTFLAGS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) $(CTFLAGS) -c -o $@ $<

clean:
	$(RM) -r $(BUILDDIR) $(TARGET)

.PHONY: clean
