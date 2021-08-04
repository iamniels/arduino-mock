include ../../../Makefile.defs

.PHONY: clean install

# Target
TARGET = libarduino-mock.a

# Compilador
CC = g++

# Carpetas con includes
INCLUDES += \
	-I$(INSTALLPATH)/usr/local/include/ \
	$(TEST_INCLUDES)

# Codigo fuente
SRCS = src/ArduinoMockAll.cc

# Headers
HDRS = $(wildcard include/arduino-mock/*.h)

# Codigo objeto
OBJS = $(SRCS:.cc=.o)

# Flags al compilador
CPPFLAGS += \
 -c -Wall -g -std=c++11 \
 $(INCLUDES)

# Flags al linker
LDFLAGS += -g \

# Librerias
LIBS += \
 -lm \

$(TARGET): $(OBJS)
	ar cr $(TARGET) $(OBJS)

%.o: %.cc
	$(CC) $(CPPFLAGS) $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

install_hdr:
	for hdr in $(HDRS); do install -D $$hdr $(INSTALLPATH)/usr/local/include/`basename $$hdr`; done

install_lib:
	install -D $(TARGET) $(INSTALLPATH)/usr/local/lib/$(TARGET)
