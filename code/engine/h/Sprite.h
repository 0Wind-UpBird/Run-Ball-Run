#ifndef Sprite_h
#define Sprite_h
#include <SFML\Graphics.hpp>

#include <Colisiometro.h>
#include <Chocante.h>

namespace tr
{
	class CSprite : protected CChocante
	{
	public:
		CSprite();
		~CSprite();

		virtual void updateEvent(sf::Event);
		virtual void updateAfterEvent();
		virtual void updateBeforeEvent();

		virtual void draw();
		virtual void initDraw();	

		virtual void huboChoque(CChoqueInfo inf);
		float getZIndex() const;
		char* getKey() const;
	protected:

		char* key;
		sf::Clock clock;
		float zindex;
	};
}
#endif