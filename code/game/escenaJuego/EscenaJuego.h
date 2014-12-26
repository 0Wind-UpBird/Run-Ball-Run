#ifndef EscenaJuego_h
#define EscenaJuego_h

#include <SFML/Graphics.hpp>

#include <App.h>
#include <Sprite.h>
#include <Escenario.h>

#define ESCENA_JUEGO "ESCENA_JUEGO"
class CEscenaJuego : public CEscenario
{
public:
	CEscenaJuego(void);
	~CEscenaJuego(void);

	bool isEndEscena(sf::Event);
	std::string getKeyOfNextEscena();

private:

};

#endif