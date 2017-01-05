CC= g++
CFLAGS= -g -c -Wall -stdlib=libc++ -std=c++0x
LDFLAGS=
SOURCES= main.cpp ../src/Argument.cpp ../src/ArgumentRegistry.cpp
INCLUDES= -I.
OBJECTS= $(SOURCES:.cpp=.o)
TARGET= bin/commander-example

all: $(SOURCES) $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	rm -rf $(OBJECTS) $(TARGET)

run: $(TARGET)
	$(TARGET) test --verbose -i --name=test -b=omg simple-value
	$(TARGET) test subtest --verbose -i --name=test
	$(TARGET) --without-command

