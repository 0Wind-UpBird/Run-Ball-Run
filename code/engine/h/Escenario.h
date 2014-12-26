#ifndef Escenario_h
#define Escenario_h

#include <iostream>
#include <SFML\Graphics.hpp>
#include <algorithm>

#include <Sprite.h>
namespace tr{

	class CEscenario
	{
	public:
		CEscenario();
		~CEscenario();

		void addSprite(CSprite*);
		void clearSprites();
		void deleteSprite(const char* key);
		void ordenarSprites();

		virtual bool isEndEscena(sf::Event);
		virtual std::string getKeyOfNextEscena();

		void updateEventSprites(sf::Event);
		void updateBeforeSprites();
		void updateAfterSprites();

		void drawSprites();

		char* getKey();

		CSprite* getSprite(const char *key);
	protected:
		std::vector<CSprite*> sprites;
		char* key;
	};
}
#endif