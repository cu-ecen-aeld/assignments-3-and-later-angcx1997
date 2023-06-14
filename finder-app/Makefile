#CROSS_COMPILE?=aarch64-none-linux-gnu-
CC=${CROSS_COMPILE}gcc
SOURCES=writer.cpp
TARGET_EXEC=writer

writer: writer.c 
	$(CC) -o $@ $<

clean:
	rm -rf *.o $(TARGET_EXEC)
		

