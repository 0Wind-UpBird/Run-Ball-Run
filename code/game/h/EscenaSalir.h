#ifndef EscenaSalir_h
#define EscenaSalir_h

#include <SFML/Graphics.hpp>

#include "App.h"
#include "Sprite.h"
#include "Escenario.h"

#define ESCENA_SALIR "ESCENA_SALIR"
class CEscenaSalir : public CEscenario
{
public:
	CEscenaSalir();
	~CEscenaSalir();

	bool isEndEscena(sf::Event);
	std::string getKeyOfNextEscena();
private:
};

#endif