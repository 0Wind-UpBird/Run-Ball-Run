#ifndef App_h
#define App_h
#include <SFML\Graphics.hpp>

#include <Cordinador.h>

namespace tr
{


	class CApp
	{
	public:
		CApp(sf::RenderWindow *widows);

		/*Parte del siclo de vida del juego*/
		void loopGame();
		void catchEvent();
		void clearScreen();

		void updateEvent(sf::Event); //actalizo por evento
		void updateBeforeEvent(); //actualizo algo del sprite antes de notar un evento
		void updateAfterEvent(); //actualizo algo del sprite despues de actualizar el evento

		void draw();
		void displayWindows();

		/*Armado del juego*/	
		static sf::RenderWindow *window;
		static float fps;
		static int W_SCREEN;
		static int H_SCREEN;
		static sf::Time currentTimeInLoop;

		void setCordinador(CCordinador *c) { this->cordinador = c; }
	private:	
		CCordinador *cordinador;
		sf::Clock clock;
	};
}
#endif