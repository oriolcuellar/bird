
#include "persona.hpp"
#include "barrera.hpp"


void niveles(barreras &obstaculos){
	window.clear();
	bool escoger=false;
	Text text;
	Font font;
	font.loadFromFile("DroidSans.ttf");
	text.setCharacterSize(40);
	text.setPosition(dim_x/3, 100);
	text.setFont(font);
	text.setFillColor(Color::White);
	text.setString(" NIVEL 1 \n \n NIVEL 2 \n \n NIVEL 3 \n \n ");
	window.draw(text);
	window.display();
	while (escoger ==false){
		if (Keyboard::isKeyPressed(Keyboard:: Num1)){
			obstaculos.nivel(1);
			escoger=true;
		}
		if (Keyboard::isKeyPressed(Keyboard:: Num2)){
			obstaculos.nivel(2);
			escoger=true;
		}
		if (Keyboard::isKeyPressed(Keyboard:: Num3)){
			obstaculos.nivel(3);
			escoger=true;
		}
	}
}
void menu(){
	Text text;
	Font font;
	font.loadFromFile("DroidSans.ttf");
	text.setCharacterSize(40);
	text.setPosition(dim_x/3, 100);
	text.setFont(font);
	text.setFillColor(Color::White);
	text.setString(" ENTER CONTINUAR \n \n ESC SALIR \n \n M MENU");
	window.draw(text);
	window.display();
}
void contador(barreras obstaculos){
	int puntuacion;
	Text text;
	Font font;
	font.loadFromFile("DroidSans.ttf");
	text.setCharacterSize(40);
	text.setPosition(10, 10);
	text.setFont(font);
	text.setFillColor(Color::Yellow);
			puntuacion=obstaculos.contador();
			string cont=to_string(puntuacion);
			cont="puntuacion "+cont;
			text.setString(cont);
	window.draw(text);
}

int main()
{
	RectangleShape suelo;
	suelo.setPosition(0, dim_y);
	suelo.setFillColor(Color::White);
	suelo.setSize(Vector2f(1400, 100));
	Event event;
		window.setFramerateLimit(60);
		persona oriol;
		barreras obstaculos;
	niveles(obstaculos);
		while (window.isOpen())
		{
			window.clear();
		    while (window.pollEvent(event))
		    {
		        if (event.type == Event::Closed or Keyboard::isKeyPressed(Keyboard:: Escape)){
		            window.close();
				}

				if (event.type==Event::KeyPressed){
					if (Keyboard::isKeyPressed(Keyboard:: Left)){
					oriol.izquierda();
					}
					if (Keyboard::isKeyPressed(Keyboard:: Right)){
					oriol.derecha();
					}
					if (Keyboard::isKeyPressed(Keyboard:: Up)){
					oriol.arriba();
					}
					if (Keyboard::isKeyPressed(Keyboard:: Down)){
					oriol.abajo();
					}
					if (Keyboard::isKeyPressed(Keyboard:: Space)){
					oriol.arriba();
					oriol.saltar();
					}

				}
		    }
			
			oriol.fisica();
			oriol.dibuja();
			obstaculos.mas_barreras();
			obstaculos.fisica();
			obstaculos.dibuja(oriol);
			contador(obstaculos);
			window.draw(suelo);
			while (not obstaculos.estoy_vivo()){
				menu();
				if (Keyboard::isKeyPressed(Keyboard:: Return)){
					obstaculos.revivir();
				}
				if (Keyboard::isKeyPressed(Keyboard:: Escape)){
					window.close();
					break;
				}
				if (Keyboard::isKeyPressed(Keyboard:: M)){
					niveles(obstaculos);
					obstaculos.revivir();
				}
			}
		    window.display();
		}


    return 0;
}

