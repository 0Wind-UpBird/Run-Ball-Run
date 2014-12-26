#include <Cordinador.h>

std::vector<tr::CEscenario* > tr::CCordinador::escenarios;

tr::CEscenario* tr::CCordinador::getEscenario()
{
	return escenarioActual;
}

tr::CEscenario* tr::CCordinador::getAEscenario(const char*key)
{
	for (int i = 0; i < int(CCordinador::escenarios.size()); i++)
	{
		if (std::strcmp(CCordinador::escenarios[i]->getKey(), key)==0)
		{
			return CCordinador::escenarios[i];
		}
	}
	return nullptr;
}


void tr::CCordinador::addEscenario(CEscenario* newEscenario)
{
	this->escenarios.push_back(newEscenario);
	this->escenarioActual = newEscenario;
}

void tr::CCordinador::deleteEscenario(const char* key)
{
	int i = 0;
	for (int i = 0; i < int(this->escenarios.size()); i++)
	{
		if (std::strcmp(this->escenarios[i]->getKey(), key) == 0)
		{
			this->escenarios.erase(this->escenarios.begin() + i);
			return;
		}
	}
}

void tr::CCordinador::clearEscenarios()
{
	this->escenarios.clear();
}

void tr::CCordinador::setEscenarioActual(const char* key)
{
	for (int i = 0; i < int(this->escenarios.size()); i++)
	{
		if (std::strcmp(this->escenarios[i]->getKey(), key)==0)
		{
			this->escenarioActual = this->escenarios[i];
		}
	}	
}

void tr::CCordinador::nextEscenario(const char*key)
{
	this->setEscenarioActual(key);
}

void tr::CCordinador::nextEscenario(std::string &key)
{
	this->setEscenarioActual(key.c_str());
}