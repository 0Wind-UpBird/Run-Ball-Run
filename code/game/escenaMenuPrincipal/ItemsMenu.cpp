#include "ItemsMenu.h"

CItemsMenu::CItemsMenu()
{
	this->opcion =(int)EOpcion::JugarSolo;
	this->maxOption = 3;

	this->fuente.loadFromFile("font/telegrama_render.otf");
	
	this->texto.setFont(this->fuente);
	this->texto.setCharacterSize(30);
	this->texto.setColor(sf::Color::White);

	this->selector = new sf::CircleShape(15, 4);
	this->selector->setPosition(50, 100);
}

CItemsMenu::~CItemsMenu()
{
	delete this->selector;
}

int CItemsMenu::opcion;


void CItemsMenu::updateAfterEvent()
{

}

void CItemsMenu::updateBeforeEvent()
{

}

void CItemsMenu::updateEvent(sf::Event evento)
{
	float offsetX = 50.0f;
	if (evento.type == sf::Event::KeyPressed)
	{		
		switch (evento.key.code)
		{
		case sf::Keyboard::Up:
			this->opcion --;
			if (this->opcion < 0)
			{
				this->opcion = 0;
			}
			this->selector->setPosition(offsetX, (float)(this->opcion*50)+100);
			break;
		case sf::Keyboard::Down:
			this->opcion ++;
			if (this->opcion > this->maxOption)
			{
				this->opcion = this->maxOption;
			}
			this->selector->setPosition(offsetX, (float)(this->opcion*50)+100);
			break;
		}		
	}	
}

void CItemsMenu::draw()
{
	this->texto.setString("Jugar Solo");
	this->texto.setPosition(100, 100);
	tr::CApp::window->draw(this->texto);

	this->texto.setString("Unirce a servidor");
	this->texto.setPosition(100, 150);
	tr::CApp::window->draw(this->texto);

	this->texto.setString("Opciones");
	this->texto.setPosition(100, 200);
	tr::CApp::window->draw(this->texto);

	this->texto.setString("Salir");
	this->texto.setPosition(100, 250);
	tr::CApp::window->draw(this->texto);

	tr::CApp::window->draw(*this->selector);	
}