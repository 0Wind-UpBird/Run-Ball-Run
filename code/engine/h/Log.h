#ifndef Log_h
#define Log_h

//Macro creada por el proprocesador en las configuracion del proyecto en VS
/*
#ifdef Debug
	
	
#else
	#define ONLY_ON_DEBUG 0
#endif
	*/
#define ONLY_ON_DEBUG 1
#include <iostream>

namespace tr
{
	class CLog
	{
	public:
		CLog();
		~CLog();

		//ejemplo tr::CLog::logOutput(__FILE__, __LINE__, __FUNCTION__, "mesanje", ONLY_ON_DEBUG);
		static void logOutput(const char* , int , const char* , const char* , int );

	};
}
#endif