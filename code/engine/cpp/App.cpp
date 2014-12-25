#include "App.h"


sf::RenderWindow* CApp::window;
float CApp::fps;
int CApp::W_SCREEN = 400;
int CApp::H_SCREEN = 600;
sf::Time CApp::currentTimeInLoop;

CApp::CApp(sf::RenderWindow* _window)
{
	this->window = _window;
	this->window->setFramerateLimit(60);
}


void CApp::loopGame()
{	

	while ((*window).isOpen())
	{
		this->clock.restart();		

		this->catchEvent();	
		this->clearScreen();
		this->draw();
		this->displayWindows();

		this->currentTimeInLoop = this->clock.getElapsedTime();
	}
}


void CApp::catchEvent()
{
	sf::Event evento;
	this->updateBeforeEvent();
	while ((*window).pollEvent(evento))
	{
		this->updateEvent(evento);
	}
	this->updateAfterEvent();
}

				
void CApp::updateAfterEvent()
{
	this->cordinador->getEscenario()->updateAfterSprites();
}

void CApp::updateBeforeEvent()
{
	this->cordinador->getEscenario()->updateBeforeSprites();
}

void CApp::updateEvent(sf::Event evento)
{
	if (evento.type == sf::Event::Closed)
	{
		this->window->close();
		return;
	}

	if (this->cordinador->getEscenario()->isEndEscena(evento))
	{
		//Un momento del juego termino y pasa al siguiente
		//ej: menues, niveles, etc	
		std::string str = this->cordinador->getEscenario()->getKeyOfNextEscena();

		if (strcmp(str.c_str(), "")!=0)
			this->cordinador->nextEscenario(str);
		else
			exit(0);
	}

	this->cordinador->getEscenario()->updateEventSprites(evento);
}

void CApp::clearScreen()
{
	this->window->clear(sf::Color::Blue);
}

void CApp::draw()
{
	this->cordinador->getEscenario()->drawSprites();
}

void CApp::displayWindows()
{
	this->window->display();
}