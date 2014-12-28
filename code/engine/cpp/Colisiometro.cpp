#include <Colisiometro.h>

tr::CColisiometro::CColisiometro()
{
}

tr::CColisiometro::~CColisiometro()
{

}

bool tr::CColisiometro::chocar_Rectangulo_Rectangulo(tr::CChocante obj1, tr::CChocante obj2, tr::CChocante* objAAvisar = nullptr)
{
	return false;
}

bool tr::CColisiometro::chocar_Rectangulo_Circulo(tr::CChocante obj_rec, tr::CChocante obj_cir, tr::CChocante* objAAvisar = nullptr)
{
	sf::RectangleShape RectInterseccion;
	tr::CChoqueInfo info;
	bool retorno = false;
	auto br1 = obj_rec.getBoundingRectangles();
	for(auto rect1 : br1 )
	{
		for (auto rect2 : obj_cir.getBoundingCircles())
		{
			if (tr::CColisiometro::Interseccion(*rect1, *rect2, &RectInterseccion) == true)
			{
				info.choque.push_back(RectInterseccion);
				info.idChocador_1 = obj_rec.getIdChocador();
				info.idChocador_2 = obj_cir.getIdChocador();

				retorno = true;
			}
		}
	}	

	if (retorno && objAAvisar != nullptr)
		objAAvisar->huboChoque(info);
	return retorno;
}

bool tr::CColisiometro::Interseccion(sf::RectangleShape obj1, sf::RectangleShape obj2, sf::RectangleShape* choque = nullptr)
{
	sf::FloatRect rect2 = obj2.getGlobalBounds();
	sf::FloatRect rect1 = obj1.getGlobalBounds();

	if (rect2.intersects(rect1))
	{
		return true;
	}else
	{
		return false;
	}
}

bool tr::CColisiometro::Interseccion(sf::RectangleShape rectangle, sf::CircleShape circle, sf::RectangleShape* choque = nullptr)
{	
	sf::FloatRect rect2 = rectangle.getGlobalBounds();
	sf::FloatRect rect1 = circle.getGlobalBounds();
	sf::FloatRect intersection;

	if (rect2.intersects(rect1, intersection))
	{
		if (choque != nullptr)
		{
			//le regreso la zona del choque			
			choque->setPosition(sf::Vector2f(intersection.left, intersection.top));
			choque->setSize(sf::Vector2f(intersection.width,intersection.height));			
		}
		return true;
	}else
	{
		return false;
	}
}

bool tr::CColisiometro::Interseccion(sf::CircleShape, sf::CircleShape, sf::RectangleShape* choque = nullptr)
{
	return false;
}