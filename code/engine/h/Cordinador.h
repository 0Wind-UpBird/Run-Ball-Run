#ifndef Cordinador_h
#define Cordinador_h

#include <vector>
#include <cstring>
#include <Escenario.h>

class CCordinador
{
public:
	void addEscenario(CEscenario*);
	void clearEscenarios();
	void deleteEscenario(const char *key);

	CEscenario* getEscenario();	
	static CEscenario* getAEscenario(const char* key);
	
	void setEscenarioActual(const char*key);
	
	void nextEscenario(const char*key);
	void nextEscenario(std::string &key);
private:
	static std::vector<CEscenario* > escenarios;
	CEscenario *escenarioActual;	
};

#endif
