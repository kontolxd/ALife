#pragma once
#include "Forms/consoleform.h"

class ConsoleManager
{
private:
    ConsoleManager();
    ConsoleForm *console;
    static ConsoleManager *self;
public:
    static ConsoleManager* get();
    static void init(ConsoleForm*);
    void sendError(std::string message);
    void sendWarning(std::string message);
    void sendMessage(std::string message);
};
