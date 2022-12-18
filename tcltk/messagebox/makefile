# EDIT START
SRCS:=main.c
CFLAGS:=-I. -I/usr/include/tcl -g -Wall -Werror -O2
INCS:=#test.h
LIBS:=-L/usr/lib/tcltk -ltcl8.6 -ltk8.6
TARGET:=hello.exe
# EDIT END

CC := gcc
OBJS = $(SRCS:%.c=%.o)

%.o: %.c $(INCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -rf $(TARGET) *.o
