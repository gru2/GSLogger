#ifndef __GS_LOGGER_H
#define __GS_LOGGER_H

#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>

class GSLogger
{
public:
	enum VerboseLevel { VL_ERROR = 0, VL_WARNING = 1, VL_INFO = 2,
		VL_VERBOSE = 3, VL_DEBUG = 4 };
	enum OutputMode { OM_STDOUT, OM_FILE, OM_MEMORY };

	GSLogger();
	~GSLogger();
	bool openFile(const std::string &fileName);
	void openMemory();
	void openStdout();
	void close();
	bool dumpLogsToFile(const std::string &fileName);
	void log(VerboseLevel level, const std::string &msg);
	void error(const std::string &msg);
	void warning(const std::string &msg);
	void info(const std::string &msg);
	void verboseInfo(const std::string &msg);
	void debug(const std::string &msg);
	std::string format(const std::string &msg);

	VerboseLevel currentVerboseLevel;
	OutputMode outputMode;
	bool logTime;
	bool logDeltaTime;
	int maxEntries;
	std::vector<std::string> data;
	FILE *file;
};

#endif
