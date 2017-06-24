CC = gcc

LIBS =  

CFLAGS = -g -Wall -DLOG_LEVEL=0
LDFLAGS = $(LIBS)

TARGET = parse_csv
OBJS   = main.o parse_csv.o 

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)
