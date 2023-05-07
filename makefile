OBJS	= AVL.o teste.o
SOURCE	= AVL.cpp, teste.cpp
HEADER	= Pessoa.h, AVL.h,
OUT	= teste.exe
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

AVL.o: AVL.cpp,
	$(CC) $(FLAGS) AVL.cpp, 

teste.o: teste.cpp
	$(CC) $(FLAGS) teste.cpp 


clean:
	rm -f $(OBJS) $(OUT)