#include <Sprite.h>

tr::CSprite::CSprite()
{
	this->zindex = 0;
}

tr::CSprite::~CSprite()
{

}

void tr::CSprite::huboChoque(tr::CChoqueInfo)
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