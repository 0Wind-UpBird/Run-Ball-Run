#ifndef Chocante_h
#define Chocante_h

#include <SFML\Graphics.hpp>

#include <Log.h>
#include <algorithm>

namespace tr
{
	struct CChoqueInfo
	{
		std::vector<sf::RectangleShape> choque;
		std::string idChocador_1;
		std::string idChocador_2;
	};

	class CChocante
	{
	public:
		CChocante();
		~CChocante();

		std::vector<sf::CircleShape*> getBoundingCircles();
		std::vector<sf::RectangleShape*> getBoundingRectangles();
		std::vector<sf::RectangleShape*> getInversoBoundingRectangles();

		void addNewCirclesShapes(sf::CircleShape*);
		void addNewCirclesShapes(std::vector<sf::CircleShape*>);
		void clearCircleShapes();

		void addNewRectanglesShapes(sf::RectangleShape*);
		void addNewRectanglesShapes(std::vector<sf::RectangleShape*>);
		void clearRectanglesShapes();

		void huboChoque(CChoqueInfo inf);

		void setIdChocador(std::string id);
		std::string getIdChocador();
	private:
		//usa punteros, lo ideal es que sean los mismos shapes que luegos son movidos de lugar
		std::vector<sf::CircleShape*> boundingCircles;
		std::vector<sf::RectangleShape*> boundingRectangles;
		std::string idChocador;
	};
}

#endif