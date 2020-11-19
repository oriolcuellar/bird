#include "data.hpp"

struct barrera{
//hay dos barreras
		int x1;
		int y1;
		int x2;
		int y2;
};

class barreras{
	public:
		barreras(){
		//inicializa barreras
			barrera b;
			b.x1=dim_x+ 100;
			b.y1=(rand()%(dim_y-150))+150;
			b.x2=dim_x+100;
			b.y2=b.y1-1100+(rand()%50);
			vect.push_back(b);
			vel=-5;
			cont=0;
			acum=0;
			vivo=true;
		}
		void mas_barreras(){
		//crea las nuevas barreras
			int i=vect.size();
			int x=rand()%10;
			if (vect[i-1].x1<dim_x-400+x){
				barrera b;
				b.x1=dim_x+ 10;
				b.y1=(rand()%(dim_y-150))+150;
				b.x2=dim_x+10;
				b.y2=b.y1-1100+(rand()%50);
				vect.push_back(b);
			}
		}
		void nivel(int n){
		//define el nivel
			vel=-4-(2*n);
		}
		bool estoy_vivo(){
			return vivo;
		}
		void revivir(){
		//reinicia posiciones y contadores
			cont=0;
			acum=0;
			vector <barrera> aux;
			vect=aux;
			barrera b;
			b.x1=dim_x+ 100;
			b.y1=(rand()%(dim_y-150))+150;
			b.x2=dim_x+100;
			b.y2=b.y1-1100+(rand()%50);
			vect.push_back(b);
			vivo=true;
		}
		void dibuja(persona pers){//dibuja / suma puntos / elimina / colisiones
			cont=acum;
			for (int i=0;i<vect.size();i++){
				RectangleShape shape1;
				RectangleShape shape2;
				int x1=vect[i].x1;
				int y1=vect[i].y1;
				int x2=vect[i].x2;
				int y2=vect[i].y2;
				shape1.setSize(Vector2f(50, 800));
				shape2.setSize(Vector2f(50, 800));
				shape1.setPosition(x1,y1);
				shape2.setPosition(x2,y2);
				shape1.setFillColor(Color::Green);
				shape2.setFillColor(Color::Blue);
				window.draw(shape1);
				window.draw(shape2);
			//suma puntos
				if (x1<dim_x/4){
					cont+=1;
				}
			//colisiones
				FloatRect barr1=shape1.getGlobalBounds();
				FloatRect barr2=shape2.getGlobalBounds();
				CircleShape redonda(20);
				redonda=pers.pos_bola();
  				if(redonda.getGlobalBounds().intersects(barr1) or redonda.getGlobalBounds().intersects(barr2)){//volver a empezar
					vivo=false;
				}
			}
			//elimina
			vector <barrera> nou;
			if (vect[0].x1<(-50)){
				for (int i=1;i<vect.size();i++){
					nou.push_back(vect[i]);
				}
			acum++;
			vect=nou;
			}
		}
		void fisica(){
			//movimiento
			for (int i=0;i<vect.size();i++){
				vect[i].x1+=vel;
				vect[i].x2+=vel;
			}
		}
		int contador(){
			return cont;
		}
	private:
		int vel;
		vector <barrera> vect;
		int cont;
		int acum;
		bool vivo;
};
