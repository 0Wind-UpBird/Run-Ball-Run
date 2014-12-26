#ifndef Log_h
#define Log_h

//falta comparar que si es debug, incluya la iostram, si es realease, use archivos
#include <iostream>

namespace tr
{
	static class CLog
	{
	public:
		CLog();
		~CLog();

		static void logOutput(const char *);

	private:

	};
}
#endif