#ifndef EscenarioMenuPrincipal_h
#define EscenarioMenuPrincipal_h

#include <SFML/Graphics.hpp>

#include <App.h>
#include <Sprite.h>
#include <Escenario.h>

#include "../escenaJuego/EscenaJuego.h"
#include "ItemsMenu.h"


#define ESCENA_MENU_PRINCIPAL "ESCENA_MENU_PRINCIPAL"
class CEscenarioMenuPrincipal : public CEscenario
{
public:
	CEscenarioMenuPrincipal();
	~CEscenarioMenuPrincipal();
	  
	bool isEndEscena(sf::Event);
	std::string getKeyOfNextEscena();
};

#endif