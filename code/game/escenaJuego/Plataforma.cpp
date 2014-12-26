#include "Plataforma.h"

CPlataforma::CPlataforma(int _direccionHuecoMovil) :
	limitX(tr::CApp::W_SCREEN),
	limitY(tr::CApp::H_SCREEN),
	plataforma(sf::Vector2f((float)tr::CApp::W_SCREEN, 20.0f)),
	hueco(sf::Vector2f(55.0f, 20.0f)),
	direccionHuecoMovil(_direccionHuecoMovil),
	pixelForSecond(200.0f)
{

	this->plataforma.setPosition(0, (float)tr::CApp::H_SCREEN);
	this->plataforma.setFillColor(sf::Color::Black);

	this->hueco.setPosition(0, (float)tr::CApp::H_SCREEN);
	this->hueco.setFillColor(sf::Color::White);

	this->key = "plataforma";
	this->zindex = 5.0f;
}

CPlataforma::~CPlataforma()
{

}

void CPlataforma::updateEvent(sf::Event)
{

}

void CPlataforma::updateAfterEvent()
{

}

void CPlataforma::updateBeforeEvent()
{
	if (this->plataforma.getPosition().y <= 0)
	{
		this->movePlataformaY((float)tr::CApp::H_SCREEN);
	}else
	{
		float moveY = this->clock.getElapsedTime().asSeconds() * this->pixelForSecond;
		this->clock.restart();

		this->movePlataformaY(-moveY);
	}
}

void CPlataforma::draw()
{
	tr::CApp::window->draw(this->plataforma);
	tr::CApp::window->draw(this->hueco);
}

void CPlataforma::initDraw()
{

}

void CPlataforma::setHuecoPositionX(float newPositionX)
{
	this->hueco.setPosition(newPositionX, this->plataforma.getPosition().y);
}

void CPlataforma::movePlataformaY(float moveY)
{
	this->plataforma.move(0.0f, moveY);
	this->hueco.move(0.0f, moveY);
}

sf::Vector2f CPlataforma::getHuecoPostion()
{
	return this->hueco.getPosition();
}

sf::Vector2f CPlataforma::getPlataformaPosition()
{
	return this->plataforma.getPosition();
}

sf::Transformable CPlataforma::getHueco()
{
	return this->hueco;
}


sf::Transformable CPlataforma::getPlataforma()
{
	return this->plataforma;
}