#ifndef Plataforma_h
#define Plataforma_h

#include <SFML/Graphics.hpp>

#include <App.h>

enum class tipoHueco {QUIETO, DERECHA_CONTINUO, IZQUIERDA_CONTINUO, PENDULO_DERECHA, PENDULO_IZQUIERDA, HERRATICO};
class CPlataforma
{
public:
	CPlataforma(int _direccionHuecoMovil = 0);
	~CPlataforma();

	void updateEvent(sf::Event);
	void updateAfterEvent();
	void updateBeforeEvent();

	void setHuecoPositionX(float newPositionX);
	void movePlataformaY(float moveY);

	sf::Vector2f getHuecoPostion();
	sf::Vector2f getPlataformaPosition();

	sf::RectangleShape* getHueco();
	sf::RectangleShape* getPlataforma();

	void draw();
	void initDraw();
private:
	sf::RectangleShape plataforma;
	sf::RectangleShape hueco;

	int limitX;
	int limitY;

	float pixelForSecond;

	//0 quieto; < 0 izq; > 0 der
	int direccionHuecoMovil;

	char* key;
	sf::Clock clock;
	float zindex;
};

#endif