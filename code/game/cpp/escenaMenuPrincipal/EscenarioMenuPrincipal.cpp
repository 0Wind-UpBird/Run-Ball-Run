#include "EscenarioMenuPrincipal.h"
			
CEscenarioMenuPrincipal::CEscenarioMenuPrincipal()
{
	this->key = ESCENA_MENU_PRINCIPAL;
}
CEscenarioMenuPrincipal::~CEscenarioMenuPrincipal()
{

}	 	  

bool CEscenarioMenuPrincipal::isEndEscena(sf::Event evento)
{	
	if (evento.type == sf::Event::KeyPressed)
	{
		if(evento.key.code == sf::Keyboard::Return)
		{
			return true;
		}
	}
	return false;
}

std::string CEscenarioMenuPrincipal::getKeyOfNextEscena()
{
	std::string str;
	switch (CItemsMenu::opcion)
	{
	case EOpcion::Configuracion:
		str = "";
		break;
	case EOpcion::JugarSolo:
		str = ESCENA_JUEGO;
		break;
	case EOpcion::Unirce:
		str = "";
		break;
	case EOpcion::Salir:
		exit(0);
		break;
	default:
		str = this->key;
		break;
	}

	return str;
}
