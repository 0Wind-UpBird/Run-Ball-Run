#include <Chocante.h>

tr::CChocante::CChocante()
{

}

tr::CChocante::~CChocante()
{

}

void tr::CChocante::huboChoque(tr::CChoqueInfo inf)
{

}

void tr::CChocante::setIdChocador(std::string id)
{
	this->idChocador = id;
}

std::string tr::CChocante::getIdChocador()
{
	return this->idChocador;
}

std::vector<sf::CircleShape*> tr::CChocante::getBoundingCircles()
{
	return this->boundingCircles;
}
std::vector<sf::RectangleShape*> tr::CChocante::getBoundingRectangles()
{
	return this->boundingRectangles;
}

void tr::CChocante::addNewCirclesShapes(sf::CircleShape* newShape)
{
	this->boundingCircles.push_back(newShape);
}

void tr::CChocante::addNewCirclesShapes(std::vector<sf::CircleShape*> newShape)
{
	for(auto ns : newShape)
	{
		this->boundingCircles.push_back(ns);
	}
}

void tr::CChocante::clearCircleShapes()
{
	this->boundingCircles.clear();
}

void tr::CChocante::addNewRectanglesShapes(sf::RectangleShape* newShape)
{
	this->boundingRectangles.push_back(newShape);
}

void tr::CChocante::addNewRectanglesShapes(std::vector<sf::RectangleShape*> newShape)
{
	for(auto ns : newShape)
	{
		this->boundingRectangles.push_back(ns);
	}
}

void tr::CChocante::clearRectanglesShapes()
{
	this->boundingRectangles.clear();
}