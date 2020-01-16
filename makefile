

test.exe: FORCE
	g++ -std=c++11 -c passserver.cpp
	g++ -std=c++11 -c proj5.cpp
	g++ -std=c++11  proj5.o passserver.o -lcrypt -o proj5.x
FORCE:

test: #was used during development in order to run syntax checking
	g++ -std=c++11 -c hashtable.h
	g++ -std=c++11 -c passserver.h

clean:
	rm *.o
