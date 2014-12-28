#include "Plataformas.h"


CPlataformas::CPlataformas()	
{
	std::vector<sf::RectangleShape* > v;

	this->separacionEntrePlataformas = 100;
	this->countPlataformas = 6;
	this->plataformas = new CPlataforma[this->countPlataformas];	
	this->key = SPRITE_PLATAFORMAS;
	this->setIdChocador(this->key);

	for (int i = 0; i < this->countPlataformas; i++)
	{
		this->plataformas[i].movePlataformaY((float)100*i);
		this->addNewRectanglesShapes(this->plataformas[i].getPlataforma());		
	}
}

CPlataformas::~CPlataformas()
{
	delete[this->countPlataformas] this->plataformas;
}


void CPlataformas::updateEvent(sf::Event evento)
{
	for (int i = 0; i < this->countPlataformas; i++)
	{
		this->plataformas[i].updateEvent(evento);
	}
}
void CPlataformas::updateAfterEvent()
{
	for (int i = 0; i < this->countPlataformas; i++)
	{
		this->plataformas[i].updateAfterEvent();
	}
}

void CPlataformas::updateBeforeEvent()
{	
	for (int i = 0; i < this->countPlataformas; i++)
	{
		this->plataformas[i].updateBeforeEvent();
	}
}

void CPlataformas::draw()
{
	for (int i = 0; i < this->countPlataformas; i++)
	{
		this->plataformas[i].draw();
	}
}

void CPlataformas::initDraw()
{

}