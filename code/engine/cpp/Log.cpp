#include <Log.h>


tr::CLog::CLog()
{

}
tr::CLog::~CLog()
{

}


void tr::CLog::logOutput(const char* file, int line, const char* function, const char* msg, int mode)
{	
	if(mode = 1)
		std::cout << "DEBUG: " << file << " Linea: "  << line << " => " << function << ": " << msg << std::endl;
}