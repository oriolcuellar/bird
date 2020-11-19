all:snake

snake:main.cpp
	g++ main.cc -o bird.exe -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -f *.o
