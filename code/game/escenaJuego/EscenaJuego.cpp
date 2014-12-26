#include "EscenaJuego.h"

CEscenaJuego::CEscenaJuego(void)
{
	this->key = ESCENA_JUEGO;
}

CEscenaJuego::~CEscenaJuego(void)
{

}

bool CEscenaJuego::isEndEscena(sf::Event)
{
	return false;
}
					  
std::string CEscenaJuego::getKeyOfNextEscena()
{
	std::string str = "";
	return str;
}