all:sfml

sfml:main.cc
	g++ main.cc -o bird.exe -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -f *.o
