# EDIT START
TARGET := main
SRCS := microsec.c
INCS := #test.h
CFLAGS := -I. -g -Wall -Werror -Wextra -O2
#LIBS :=
ifeq ($(OS),Windows_NT)
	CFLAGS := -I. -g -Wall -Werror -Wextra -O2
	#LIBS :=
endif
# EDIT END

CC := gcc
OBJS = $(SRCS:%.c=%$(EXEEXT).o)
RM := rm -f
ifeq ($(OS),Windows_NT)
	EXEEXT := .exe
	RM := cmd.exe /C del
endif

%$(EXEEXT).o: %.c $(INCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET)$(EXEEXT): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
	$(RM) $(TARGET)$(EXEEXT) *$(EXEEXT).o
