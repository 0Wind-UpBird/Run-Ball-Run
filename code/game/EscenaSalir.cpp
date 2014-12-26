#include "EscenaSalir.h"

CEscenaSalir::CEscenaSalir()
{
	this->key = ESCENA_SALIR;
}

CEscenaSalir::~CEscenaSalir()
{
}

bool CEscenaSalir::isEndEscena(sf::Event)
{
	return true;
}
					  
std::string CEscenaSalir::getKeyOfNextEscena()
{
	std::string str = "";
	return str;
}