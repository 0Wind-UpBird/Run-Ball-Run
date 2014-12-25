#include <SFML/Graphics.hpp>
#include "App.h"

#include "Jugador.h"
#include "ItemsMenu.h"
#include "Plataformas.h"

#include "EscenarioMenuPrincipal.h"
#include "EscenaJuego.h"

int main()
{
	// Create the main window y configuracion...
	sf::ContextSettings setting;
	setting.antialiasingLevel = 8;

	sf::RenderWindow win(sf::VideoMode(CApp::W_SCREEN, CApp::H_SCREEN, 32), "Run Ball Run 2", sf::Style::Default, setting);
	win.setVerticalSyncEnabled(true);

	//Definimos los sprites:
	CBounce bounce;
	CItemsMenu menu;
	CPlataformas plataformas;

	//Definimos los escenario:
	CEscenarioMenuPrincipal menuPrincipal;
	menuPrincipal.addSprite(&menu);

	CEscenaJuego escenaJuego;
	escenaJuego.addSprite(&bounce);
	escenaJuego.addSprite(&plataformas);

	//Cargamos los Escenarios al Cordinador
	CCordinador cordinador;

	cordinador.addEscenario(&menuPrincipal);
	cordinador.addEscenario(&escenaJuego);
	
	//seteamos la escena inicial
	cordinador.setEscenarioActual(ESCENA_MENU_PRINCIPAL);

	//Le damos al App el cordinador
	CApp app(&win);
	app.setCordinador(&cordinador);

	//Empezamos el juego
	app.loopGame();

	return 0;
}