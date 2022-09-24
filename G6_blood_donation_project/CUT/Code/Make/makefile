OBJS = main.o
CO = g++ -o
CC = g++ -c
PT = -lpthread
RM = rm *.o

test : $(OBJS)
	$(CO) test $(OBJS) $(PT)

main.o : main.cpp
	$(CC) main.cpp

clean : 
	$(RM)

