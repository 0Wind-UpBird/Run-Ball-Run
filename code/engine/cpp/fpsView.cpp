#include <fpsView.h>

tr::CFpsView::CFpsView()
{
	this->fuente.loadFromFile("font/arial.ttf");
	this->texto.setFont(this->fuente);
	this->texto.setCharacterSize(15);
	this->texto.setColor(sf::Color::Black);
}

void tr::CFpsView::draw()
{
	CApp::window->draw(this->texto);
}

void tr::CFpsView::update(sf::Event evento)
{
	this->texto.setString("FPS: " + std::to_string(CApp::fps));
}