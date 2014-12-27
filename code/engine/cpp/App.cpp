#include <App.h>

sf::RenderWindow* tr::CApp::window;
float tr::CApp::fps;
int tr::CApp::W_SCREEN = 400;
int tr::CApp::H_SCREEN = 600;
sf::Time tr::CApp::currentTimeInLoop;
tr::CCordinador* tr::CApp::cordinador;

tr::CApp::CApp(sf::RenderWindow* _window)
{
	this->window = _window;
	this->window->setFramerateLimit(60);
}


void tr::CApp::loopGame()
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


void tr::CApp::catchEvent()
{
	sf::Event evento;
	this->updateBeforeEvent();
	while ((*window).pollEvent(evento))
	{
		this->updateEvent(evento);
	}
	this->updateAfterEvent();
}

				
void tr::CApp::updateAfterEvent()
{
	this->cordinador->getEscenario()->updateAfterSprites();
}

void tr::CApp::updateBeforeEvent()
{
	this->cordinador->getEscenario()->updateBeforeSprites();
}

void tr::CApp::updateEvent(sf::Event evento)
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

void tr::CApp::clearScreen()
{
	this->window->clear(sf::Color(104, 151, 155));
}

void tr::CApp::draw()
{
	this->cordinador->getEscenario()->drawSprites();
}

void tr::CApp::displayWindows()
{
	this->window->display();
}

tr::CCordinador* tr::CApp::getCordinador()
{
	return CApp::cordinador;
}