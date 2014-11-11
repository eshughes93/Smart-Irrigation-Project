# Adapted from http://mrbook.org/tutorials/make/

EXECUTABLE= test_me
SOURCES=testing.cpp ../generic_data_stream.h ../data_streams.h ../data_streams.cpp
#ARDUINODIR=/home/alex/hacking/arduino-1.0.6/hardware/arduino/cores/arduino

CC=g++
CFLAGS=-c -Wall# -I$(ARDUINODIR)
OBJECTS=$(SOURCES:.cpp=.o)


all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

