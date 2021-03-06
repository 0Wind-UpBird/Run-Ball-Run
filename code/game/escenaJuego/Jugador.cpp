#include "Jugador.h"

CBounce::CBounce() : 
	pelota(25.0f),
	pixelForSec(800.0f),
	velocidadDeCaida(1000.0f)
{
	this->key = "Bounce";
	this->setIdChocador(this->key);

	this->zindex = 5.01f;

	this->pelota.setFillColor(sf::Color::Cyan);
	this->pelota.setOutlineColor(sf::Color::Black);
	this->pelota.setOutlineThickness(1);
	this->pelota.setPosition(100, 200);	
	this->limitX = tr::CApp::W_SCREEN;
	this->limitY = tr::CApp::H_SCREEN;
	this->continueMoveToLeft = this->continueMoveToRigth = false;

	this->addNewCirclesShapes(&this->pelota);	
}

CBounce::~CBounce()
{

}

void CBounce::updateAfterEvent()
{		
	if (this->stepOfEvent == STEP_UPDATE_BEFORE)
	{	
		if (this->continueMoveToLeft == true || this->continueMoveToRigth == true)
		{
			if (this->continueMoveToLeft)
			{
				this->movePelota(sf::Keyboard::Left);
			}else
			{
				this->movePelota(sf::Keyboard::Right);
			}
		}
	}	
	this->stepOfEvent = STEP_UPDATE_AFTER;
} 

void CBounce::updateBeforeEvent()
{
	this->stepOfEvent = STEP_UPDATE_BEFORE;	

	if (!this->chocaConPlataforma())
	{
		this->PelotaCae();
	}
}

void CBounce::updateEvent(sf::Event evento)
{
	this->stepOfEvent = STEP_UPDATE;

	if (evento.type == sf::Event::EventType::KeyPressed)
	{
		this->movePelota(evento.key.code);
	}
}

void CBounce::draw()
{
	tr::CApp::window->draw(this->pelota);
	this->clock.restart();
}
void CBounce::initDraw()
{

}

void CBounce::movePelota(int key)
{	
	//genero aceleracion
	sf::Time time = this->clock.getElapsedTime();
	float pixelMov = pixelForSec * time.asSeconds();

	//switch por tecla presionada
	switch (key)
	{
	case sf::Keyboard::Left:
		this->continueMoveToLeft = true;
		this->continueMoveToRigth = false;

		//limites valido en X
		if (this->pelota.getPosition().x - pixelMov < 0)
		{
			pixelMov = this->pelota.getPosition().x;
		}

		this->pelota.move(-pixelMov, 0);
		break;

	case sf::Keyboard::Right:
		this->continueMoveToLeft = false;
		this->continueMoveToRigth = true;

		//valido limite en X
		if (this->pelota.getPosition().x + this->pelota.getGlobalBounds().width + pixelMov > this->limitX)
		{						
			pixelMov = this->limitX - (this->pelota.getPosition().x + this->pelota.getGlobalBounds().width);
		}
		this->pelota.move(pixelMov,0);
		break;

	default:
		this->continueMoveToLeft = this->continueMoveToRigth = false;		
		break;
	}
}

bool CBounce::chocaConPlataforma()
{
	CChocante* plataforma = tr::CApp::getCordinador()->getEscenario()->getSprite("SPRITE_PLATAFORMAS");
	return tr::CColisiometro::chocar_Rectangulo_Circulo(*plataforma, (CChocante)*this, (CChocante*)this);
}

void CBounce::PelotaCae()
{
	float pixelToMove = this->clock.getElapsedTime().asSeconds() * this->velocidadDeCaida;
	
	if(this->pelota.getPosition().y + this->pelota.getGlobalBounds().height + pixelToMove >= this->limitY)
	{
		pixelToMove = this->limitY - (this->pelota.getPosition().y + this->pelota.getGlobalBounds().height);
	}

	this->pelota.move(0, pixelToMove);
}


void CBounce::huboChoque(tr::CChoqueInfo inf)
{
	if (inf.idChocador_1 == "SPRITE_PLATAFORMAS")
	{
		float posX = this->pelota.getPosition().x;
		float choqueInY = inf.choque[0].getGlobalBounds().top;
		float moveY = std::abs(choqueInY - (this->pelota.getLocalBounds().height + this->pelota.getPosition().y));
		this->pelota.move(0, -moveY);
	}
}