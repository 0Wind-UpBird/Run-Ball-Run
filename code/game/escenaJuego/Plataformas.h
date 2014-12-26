#ifndef Plataformas_h
#define Plataformas_h
#include <math.h>
#include <SFML/Graphics.hpp>

#include <App.h>
#include <Sprite.h>

#include "Plataforma.h"

#define SPRITE_PLATAFORMAS "SPRITE_PLATAFORMAS"
class CPlataformas : public tr::CSprite
{
public:
	CPlataformas();
	~CPlataformas();

	void updateEvent(sf::Event);
	void updateAfterEvent();
	void updateBeforeEvent();

	void draw();
	void initDraw();
private:
	CPlataforma *plataformas;
	
	int separacionEntrePlataformas;
	int countPlataformas;
};

#endif