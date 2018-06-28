CPP_SOURCES = $(wildcard *.cpp)
CPP_SOURCES += $(wildcard Core/*.cpp)
CPP_SOURCES += $(wildcard fix/*.cpp)
CPP_SOURCES += $(wildcard util/*.cpp)
HEADERS = $(wildcard *.h)
HEADERS += $(wildcard Core/*.h)
HEADERS += $(wildcard fix/*.h)
HEADERS += $(wildcard util/*.h)

OBJS = ${CPP_SOURCES:.cpp=.o}

TARGET = elf32fixer

CC = g++
CFLAGS = -g -std=c++11 -Wformat=0


$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)