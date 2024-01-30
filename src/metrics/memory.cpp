#include "memory.h"
#include <fstream>
#include <iostream>
#include <string>
#include <regex>
#include <chrono>
#include <thread>

void readMemoryInfo(std::string attribute)
{
    std::ifstream memInfoFile{PROCMEMINFOFILE};

    if (!memInfoFile)
    {
        std::cerr << PROCMEMINFOFILE << " could not be opened\n";
    }

    std::regex linePattern{attribute};
    std::smatch matches;

    while (memInfoFile)
    {
        std::string memInfoLine;
        std::getline(memInfoFile, memInfoLine);

        if (std::regex_search(memInfoLine, matches, linePattern))
        {
            std::cout << '\r' << memInfoLine << std::flush;
        }
    }
}

void pollMemoryInfo()
{
    while (true)
    {
        // readMemoryInfo("MemTotal");
        readMemoryInfo("MemFree");
        // readMemoryInfo("MemAvailable");
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
