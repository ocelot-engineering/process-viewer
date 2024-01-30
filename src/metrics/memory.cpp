#include "memory.h"
#include <fstream>
#include <iostream>
#include <string>

void readMemoryInfo()
{
    std::ifstream memInfoFile{PROCMEMINFOFILE};

    if (!memInfoFile)
    {
        std::cerr << PROCMEMINFOFILE << " could not be opened\n";
    }

    while (memInfoFile)
    {
        std::string memInfo;
        std::getline(memInfoFile, memInfo);
        std::cout << memInfo << '\n';
    }
}
