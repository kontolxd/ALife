#include "Managers/ConsoleManager.h"

ConsoleManager* ConsoleManager::self = nullptr;

ConsoleManager::ConsoleManager()
{

}

ConsoleManager* ConsoleManager::get()
{
    if(self == nullptr)
        self = new ConsoleManager();
    return self;
}

void ConsoleManager::init(ConsoleForm *console)
{
    if(self == nullptr)
        self = get();
    self->console = console;
}

void ConsoleManager::sendError(std::string message)
{
    console->sendError(message);
}

void ConsoleManager::sendWarning(std::string message)
{
    console->sendWarning(message);
}

void ConsoleManager::sendMessage(std::string message)
{
    console->sendMessage(message);
}
