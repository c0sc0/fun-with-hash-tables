project4: main.o djb2HashTable.o sdbmHashTable.o LList.o
	g++ -O main.o djb2HashTable.o sdbmHashTable.o LList.o -o project4
	
main.o: main.cpp
	g++ -O -c main.cpp
    
djb2HashTable.o: djb2HashTable.h djb2HashTable.cpp
	g++ -O -c djb2HashTable.cpp
    
sdbmHashTable.o: sdbmHashTable.h sdbmHashTable.cpp
	g++ -O -c sdbmHashTable.cpp
    
LList.o: LList.cpp LList.h Lnode.h
	g++ -O -c LList.cpp
	
clean:
	rm *.o