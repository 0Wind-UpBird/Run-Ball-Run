#ifndef Jugador_h
#define Jugador_h

#include <SFML/Graphics.hpp>

#include <App.h>
#include <Sprite.h>

#include "EscenaJuego.h"

const int STEP_UPDATE = 1;
const int STEP_UPDATE_BEFORE = 2;
const int STEP_UPDATE_AFTER = 3;

#define SPRITE_BOUNCE "SPRITE_BOUNCE"
class CBounce : public tr::CSprite
{
public:
	CBounce();
	~CBounce();

	void updateEvent(sf::Event);
	void updateAfterEvent();
	void updateBeforeEvent();

	void draw();
	void initDraw();

	void movePelota(int key);
	
	bool chocaConPlataforma();
	void huboChoque(tr::CChoqueInfo);

	void PelotaCae();

private:
	sf::CircleShape pelota;
	float pixelForSec;
	float velocidadDeCaida; //dado en pixel por segundos

	bool continueMoveToLeft;
	bool continueMoveToRigth;

	int stepOfEvent; //entra en After, pone 1, entra en evento 2, despues de evento 3

	int limitX;
	int limitY;
};
#endif