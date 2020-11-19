#ifndef PERSONA_HPP
#define PERSONA_HPP

#include "data.hpp"


class persona{
	public:
	//constructores
		persona(){
			x=dim_x/4;
			y=dim_y/2;
			acceleracion=0;
			x_ant=0;
			y_ant=0;
		}
		persona(int posx, int posy){
			x=posx;
			y=posy;
			acceleracion=0;
			x_ant=0;
			y_ant=0;
		}
	//consultores
		bool estoy_volando(){
			if (x==x_ant and y==y_ant){
				return false;
			}
			return true;
		}
		CircleShape pos_bola(){
			CircleShape redonda(20);
			redonda.setPosition(x, y);
			return redonda;
		}
	//movimiento
		void go_to(int posx, int posy){
			x=posx;
			y=posy;
		}
		void derecha(){
			x+=5;
		}
		void abajo(){
			y+=5;
		}
		void izquierda(){
			x-=5;
		}
		void arriba(){
			y-=5;
		}
		void saltar(){
			acceleracion=-20;
		}
	//dibuja
		void dibuja(){
			CircleShape shape(20);
			shape.setPosition(x,y);
			shape.setFillColor(Color::Cyan);
			window.draw(shape);

			 
		}

	//fisica
		void fisica(){
			if (y<dim_y-40 and acceleracion<60){
				acceleracion=acceleracion+1;
				y+=acceleracion;
			}
			if (y<0){
				y=0;
				acceleracion=0;
			}
			if (y>dim_y-40){
				acceleracion=0;
				y=dim_y-40;
			}
			
		}
	private:
		int x;
		int y;
		int x_ant;
		int y_ant;
		float acceleracion;
};
#endif
