#ifndef FpsView_h
#define FpsView_h

#include <App.h>
#include <Sprite.h>
#include <cstring>

namespace tr
{
	class CFpsView : public CSprite
	{
	public:
		CFpsView();
		void update(sf::Event);
		void draw();
	private:
		sf::Font fuente;
		sf::Text texto;
	};
}
#endif