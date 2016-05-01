CC=gcc
CFLAGS=-Wall 

FILES := $(shell ls | grep .c)
OBJ := $(FILES:%.c=%)

all: $(OBJ)

%:%.c
	$(CC) $(CFLAGS) $? -o $@


clean: 
	rm -f *~ $(OBJ)