#include <GSLogger.h>

GSLogger::GSLogger()
{
	currentVerboseLevel = VL_INFO;
	outputMode = OM_STDOUT;
	logTime = false;
	logDeltaTime = false;
	maxEntries = 1000000;
	file = 0;
}

GSLogger::~GSLogger()
{
	close();
}

bool GSLogger::openFile(const std::string &fileName)
{
	close();
	outputMode = OM_FILE;
	file = fopen(fileName.c_str(), "wb");
	if (file)
		return true;
	return false;
}

void GSLogger::openMemory()
{
	close();
	outputMode = OM_MEMORY;
}

void GSLogger::openStdout()
{
	close();
	outputMode = OM_STDOUT;
}

void GSLogger::close()
{
	if (file)
	{
		fclose(file);
		file = 0;
	}
	data.clear();
}

bool GSLogger::dumpLogsToFile(const std::string &fileName)
{
	FILE *tempFile = fopen(fileName.c_str(), "wb");
	if (!tempFile)
		return false;
	int n = data.size();
	for (int i = 0; i < n; i++)
	{
		const std::string &s = data[i];
		fwrite(s.c_str(), 1, s.size() ,file);
		fwrite("\n", 1, 1 ,file);
	}
	return true;
}

void GSLogger::log(GSLogger::VerboseLevel level, const std::string &msg)
{
	if (level > currentVerboseLevel)
		return;

	std::string s = format(msg);
	if (outputMode == OM_STDOUT)
	{
		std::cout << s << std::endl;
		return;
	}
	if (outputMode == OM_FILE)
	{
		if (!file)
			return;
		fwrite(s.c_str(), 1, s.size() ,file);
		fwrite("\n", 1, 1 ,file);
		return;
	}
	if (outputMode == OM_MEMORY)
	{
		data.push_back(s);
		return;
	}
}

void GSLogger::error(const std::string &msg)
{
	log(VL_ERROR, "error:" + msg);
}

void GSLogger::warning(const std::string &msg)
{
	log(VL_WARNING, "warning:" + msg);
}

void GSLogger::info(const std::string &msg)
{
	log(VL_INFO, msg);
}

void GSLogger::verboseInfo(const std::string &msg)
{
	log(VL_VERBOSE, msg);
}

void GSLogger::debug(const std::string &msg)
{
	log(VL_DEBUG, msg);
}

std::string GSLogger::format(const std::string &msg)
{
	return msg;
}
