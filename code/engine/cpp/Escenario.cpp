#include <Escenario.h>

tr::CEscenario::CEscenario(){}

tr::CEscenario::~CEscenario(){}

bool tr::CEscenario::isEndEscena(sf::Event)
{ 
	return true; 
}

std::string tr::CEscenario::getKeyOfNextEscena()
{
	return this->key;
}

char* tr::CEscenario::getKey()
{
	return this->key;
}

void tr::CEscenario::updateEventSprites(sf::Event evento)
{
	int i = 0;
	for (int i = 0; i < int(this->sprites.size()); i++)
	{
		this->sprites[i]->updateEvent(evento);
	}
}


void tr::CEscenario::updateAfterSprites()
{
	int i = 0;
	for (int i = 0; i < int(this->sprites.size()); i++)
	{
		this->sprites[i]->updateAfterEvent();
	}
}

void tr::CEscenario::updateBeforeSprites()
{
	int i = 0;
	for (int i = 0; i < int(this->sprites.size()); i++)
	{
		this->sprites[i]->updateBeforeEvent();
	}
}

void tr::CEscenario::addSprite(CSprite* newSprite)
{
	this->sprites.push_back(newSprite);
	this->ordenarSprites();
}

void tr::CEscenario::deleteSprite(const char* key)
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

void tr::CEscenario::clearSprites()
{
	this->sprites.clear();
}

void tr::CEscenario::drawSprites()
{
	int i = 0;
	for (int i = 0; i < int(this->sprites.size()); i++)
	{
		this->sprites[i]->draw();
	}
}

tr::CSprite* tr::CEscenario::getSprite(const char *key)
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

void tr::CEscenario::ordenarSprites()
{
	std::sort(this->sprites.begin(), this->sprites.end(), 
		[](const CSprite *_dataA,const CSprite *_dataB) -> bool 
	{		
		return (_dataA->getZIndex() < _dataB->getZIndex());
	});
}