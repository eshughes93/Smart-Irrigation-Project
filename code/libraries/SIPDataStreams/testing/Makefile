# Adapted from http://mrbook.org/tutorials/make/

EXECUTABLE= test_me_executable
ARRAY_DATASTREAM_TEST_FILES=data_stream_testing.cpp ../array_data_stream.h 
STT_TEST_FILES=stt_data_point_testing.cpp ../stt_data_point.h

SOURCES=../generic_data_stream.h ${ARRAY_DATASTREAM_TEST_FILES}
//SOURCES=../generic_data_stream.h ${STT_TEST_FILES}

CC=g++
CFLAGS=-c -Wall
OBJECTS=$(SOURCES:.cpp=.o)


all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

