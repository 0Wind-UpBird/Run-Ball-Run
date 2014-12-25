#include "Sprite.h"

CSprite::CSprite()
{
	this->zindex = 0;
}

CSprite::~CSprite()
{

}

char* CSprite::getKey() const
{
	return key;
}

float CSprite::getZIndex() const
{
	return this->zindex;
}

void CSprite::draw()
{

}

void CSprite::initDraw()
{

}

void CSprite::updateEvent(sf::Event)
{

}

void CSprite::updateBeforeEvent()
{

}

void CSprite::updateAfterEvent()
{

}

bool CSprite::hayColision(sf::Transformable *obj1, sf::Transformable *obj2)
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