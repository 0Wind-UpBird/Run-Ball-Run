#ifndef Colisiometro_h
#define Colisiometro_h

#include <Chocante.h>

#include <math.h>

namespace tr
{
	class CColisiometro
	{
	public:
		CColisiometro();
		~CColisiometro();

		static bool chocar_Rectangulo_Rectangulo(tr::CChocante, tr::CChocante, tr::CChocante*);
		static bool chocar_Rectangulo_Circulo(tr::CChocante, tr::CChocante, tr::CChocante*);
		static bool chocar_Circulo_Circulo(tr::CChocante, tr::CChocante, tr::CChocante*);
	private:
		static bool Interseccion(sf::RectangleShape, sf::RectangleShape, sf::RectangleShape*);
		static bool Interseccion(sf::RectangleShape, sf::CircleShape, sf::RectangleShape*);
		static bool Interseccion(sf::CircleShape, sf::CircleShape, sf::RectangleShape*);
	};
}

#endif