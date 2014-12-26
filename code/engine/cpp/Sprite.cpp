#include <Sprite.h>

tr::CSprite::CSprite()
{
	this->zindex = 0;
}

tr::CSprite::~CSprite()
{

}

char* tr::CSprite::getKey() const
{
	return key;
}

float tr::CSprite::getZIndex() const
{
	return this->zindex;
}

void tr::CSprite::draw()
{

}

void tr::CSprite::initDraw()
{

}

void tr::CSprite::updateEvent(sf::Event)
{

}

void tr::CSprite::updateBeforeEvent()
{

}

void tr::CSprite::updateAfterEvent()
{

}

bool tr::CSprite::hayColision(sf::Transformable *obj1, sf::Transformable *obj2)
{
	if (obj1->getPosition().x >= obj2->getPosition().x && 
		obj1->getPosition().x <= obj2->getPosition().x + obj2->getScale().x &&
		obj1->getPosition().y >= obj2->getPosition().y &&
		obj1->getPosition().y <= obj2->getPosition().y + obj2->getScale().y)
	{
		return true;
	}else
	{
		return false;
	}
}