#ifndef Sprite_h
#define Sprite_h
#include <SFML\Graphics.hpp>


class CSprite
{
public:
	CSprite();
	~CSprite();

	virtual void updateEvent(sf::Event);
	virtual void updateAfterEvent();
	virtual void updateBeforeEvent();

	virtual void draw();
	virtual void initDraw();	
	
	float getZIndex() const;
	char* getKey() const;	

	static bool hayColision(sf::Transformable *obj1, sf::Transformable *obj2);
protected:
	char* key;
	sf::Sprite sprite;
	sf::Texture textura;
	
	sf::Clock clock;

	float zindex;
};

#endif