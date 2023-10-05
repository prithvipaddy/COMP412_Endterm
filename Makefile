
final1_main.exe : final1_main.o final1.o
	g++ -o final1_main.exe final1_main.o final1.o

final1_main.o : final1_main.cpp
	g++ -c final1_main.cpp

final1.o : final1.cpp
	g++ -c final1.cpp

