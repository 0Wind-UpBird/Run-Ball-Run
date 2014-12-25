#ifndef ItemsMenu_h
#define ItemsMenu_h

#include <SFML/Graphics.hpp>

#include "App.h"
#include "Sprite.h"


enum class EOpcion {JugarSolo, Unirce, Configuracion, Salir};
#define SPRITE_ITEM_MENU "SPRITE_ITEM_MENU"
class CItemsMenu : public CSprite
{
public:
	CItemsMenu();
	~CItemsMenu();

	void updateEvent(sf::Event);
	void updateAfterEvent();
	void updateBeforeEvent();

	void draw();

	static int opcion;
private:	
	int maxOption;

	sf::CircleShape* selector;
	sf::Font fuente;
	sf::Text texto;
};

#endif