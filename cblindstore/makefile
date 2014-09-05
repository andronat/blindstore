OBJS = Keychain.o KeyGenerator.o main.o Utils.o VDGHV.o
CC = clang++
LFLAGS = -Wall -lgmpxx -I /opt/local/include -lgmp -L /opt/local/lib
CFLAGS = -Wall -I /opt/local/include -c

blindstore : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o blindstore

Keychain.o : Keychain.cpp Keychain.h
	$(CC) $(CFLAGS) Keychain.cpp

KeyGenerator.o : KeyGenerator.h KeyGenerator.cpp Keychain.h Utils.h
	$(CC) $(CFLAGS) KeyGenerator.cpp

main.o : main.cpp KeyGenerator.h 
	$(CC) $(CFLAGS) main.cpp

Utils.o : Utils.h Utils.cpp
	$(CC) $(CFLAGS) Utils.cpp

VDGHV.o : VDGHV.h VDGHV.cpp Keychain.h
	$(CC) $(CFLAGS) VDGHV.cpp

clean:
	\rm *.o *~ blindstore
