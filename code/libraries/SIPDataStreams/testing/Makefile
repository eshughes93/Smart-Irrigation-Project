# Adapted from http://mrbook.org/tutorials/make/

EXECUTABLE= test_me_executable
TESTFILE=stt_data_point_testing.cpp
#TESTFILE=data_stream_testing.cpp
SOURCES=${TESTFILE} ../generic_data_stream.h ../array_data_stream.h ../stt_data_point.h

CC=g++
CFLAGS=-c -Wall
OBJECTS=$(SOURCES:.cpp=.o)


all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

