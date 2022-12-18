# EDIT START
TARGET:=hello
SRCS:=main.c
INCS:=#test.h
ifeq ($(OS),Windows_NT)
	CFLAGS:=-I. -IC:\lib\tcl8.6\include -g -Wall -Werror -O2
	LIBS:=-LC:\lib\tk8.6\include -ltcl8.6 -ltk8.6
else
	CFLAGS:=-I. -I/usr/include/tcl -g -Wall -Werror -O2
	LIBS:=-L/usr/lib/tcltk -ltcl8.6 -ltk8.6
endif
# EDIT END

CC := gcc
OBJS = $(SRCS:%.c=%.o)
ifeq ($(OS),Windows_NT)
	EXEEXT := .exe
endif

%.o: %.c $(INCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET)$(EXEEXT): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -rf $(TARGET)$(EXEEXT) *.o
