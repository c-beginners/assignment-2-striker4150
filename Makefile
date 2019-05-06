CPP = g++
CPPFLAGS = -g
PROGS = chars.exe

# Cross-OS clean
ifdef OS
	RM = del /Q
else
	RM = rm -f
endif

.PHONY: all clean

all: $(PROGS)

chars.exe: chars.cpp
	$(CPP) $(CPPFLAGS) -o chars.exe chars.cpp

clean:
	$(RM) $(PROGS)