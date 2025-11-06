//
// Created by Kye Nelson on 10/16/25.
//

#include <iostream>
#include <filesystem>

#include <ZunoEngine.h>

#include "Engine.h"

#define RED "\033[31m"

static void PrintUsage()
{
    std::cout << "Usage: \n" << std::endl;
    std::cout << "  zuno <path-to-scene-file>" << std::endl;
    std::cout << "\n";
    std::cout << "Specify a lua file as an entrypoint to your game." << std::endl;
}

static void ProcessArgs(int argc, char* argv[], int& retValue, std::filesystem::path& entryPath)
{
    if (argc <= 1)
    {
        std::cerr << RED << "Zuno error: no lua file provided. Use --help for list of commands" << std::endl;
        retValue = 1;
        return;
    }
    if (strcmp(argv[1], "--help") == 0)
    {
        PrintUsage();
        retValue = 0;
        return;
    }
    entryPath = argv[1];
    entryPath = std::filesystem::weakly_canonical(std::filesystem::current_path() / entryPath);
    if (!std::filesystem::exists(entryPath))
    {
        std::cerr << RED << "Zuno error: Cannot find file at: " << entryPath << std::endl;
        retValue = 1;
        return;
    }
    if (entryPath.extension() != ".lua")
    {
        std::cerr << RED << "Zuno error: Entrypoint must be a .lua file: " << entryPath << std::endl;
        retValue = 1;
        return;
    }
}

int main(int argc, char* argv[])
{
    // Process command line args
    std::filesystem::path entrypointPath;
    int retValue = -1;
    ProcessArgs(argc, argv, retValue, entrypointPath);
    if (retValue != -1)
        return retValue;

    Zuno::Engine engine("Zuno", 640, 480);
    engine.LoadEntrypoint(entrypointPath);
    engine.Run();

    return 0;
}
