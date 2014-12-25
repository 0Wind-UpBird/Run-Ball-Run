#include "Escenario.h"

CEscenario::CEscenario(){}

CEscenario::~CEscenario(){}

bool CEscenario::isEndEscena(sf::Event)
{ 
	return true; 
}

std::string CEscenario::getKeyOfNextEscena()
{
	return this->key;
}

char* CEscenario::getKey()
{
	return this->key;
}

void CEscenario::updateEventSprites(sf::Event evento)
{
	int i = 0;
	for (int i = 0; i < int(this->sprites.size()); i++)
	{
		this->sprites[i]->updateEvent(evento);
	}
}


void CEscenario::updateAfterSprites()
{
	int i = 0;
	for (int i = 0; i < int(this->sprites.size()); i++)
	{
		this->sprites[i]->updateAfterEvent();
	}
}

void CEscenario::updateBeforeSprites()
{
	int i = 0;
	for (int i = 0; i < int(this->sprites.size()); i++)
	{
		this->sprites[i]->updateBeforeEvent();
	}
}

void CEscenario::addSprite(CSprite* newSprite)
{
	this->sprites.push_back(newSprite);
	this->ordenarSprites();
}

void CEscenario::deleteSprite(const char* key)
{
	int i = 0;
	for (int i = 0; i < int(this->sprites.size()); i++)
	{
		if (std::strcmp(this->sprites[i]->getKey(), key) == 0)
		{
			this->sprites.erase(this->sprites.begin() + i);
			return;
		}
	}
}

void CEscenario::clearSprites()
{
	this->sprites.clear();
}

void CEscenario::drawSprites()
{
	int i = 0;
	for (int i = 0; i < int(this->sprites.size()); i++)
	{
		this->sprites[i]->draw();
	}
}

CSprite* CEscenario::getSprite(const char *key)
{
	int i = 0;
	for (int i = 0; i < int(this->sprites.size()); i++)
	{
		if (strcmp(this->sprites[i]->getKey(), key) == 0)
		{
			return this->sprites[i];
		}
	}
	return nullptr;
}

void CEscenario::ordenarSprites()
{
	std::sort(this->sprites.begin(), this->sprites.end(), 
		[](const CSprite *_dataA,const CSprite *_dataB) -> bool 
	{		
		return (_dataA->getZIndex() < _dataB->getZIndex());
	});
}