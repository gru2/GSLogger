#include <GSLogger.h>
#include <iostream>

int main()
{
	GSLogger logger;
	logger.info("Hello World");
	logger.warning("This is some warning.");
	return 0;
}
