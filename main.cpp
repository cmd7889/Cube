#include "Cube.h"
#include <windows.h>


bool OpenANSIControlChar()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) { return false; }

    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode)) { return false; }

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(hOut, dwMode)) { return false; }
    return true;
}

int main() {

    OpenANSIControlChar();

    Cube cube;

    std::string input;
    std::string command;

    while (std::getline(std::cin, input)) {
        std::stringstream inputStream(input);
        inputStream >> command;
        if (command == "show") {
            if (!inputStream.eof())
                throw std::logic_error("You can enter only one command");
            std::cout << cube << '\n';

        } else if (command == "solve") {
            if (!inputStream.eof())
                throw std::logic_error("You can enter only one command");
            std::cout << cube.solve() << '\n';

        } else if (command == "check") {
            if (!inputStream.eof())
                throw std::logic_error("You can enter only one command");
            std::cout << cube.check() << '\n';

        } else if (command == "save") {
            if (inputStream.eof())
                throw std::logic_error("File destination expected");
            std::string path;
            inputStream >> path;
            if (!inputStream.eof())
                throw std::logic_error("You can enter only two command");
            cube.save(path);

        } else if (command == "load") {
            if (inputStream.eof())
                throw std::logic_error("File destination expected");
            std::string path;
            inputStream >> path;
            if (!inputStream.eof())
                throw std::logic_error("You can enter only one command");
            cube.load(path);

        } else if (command == "rotate") {
            cube.rotateByStream(inputStream);
            std::cout << "Result scramble:\n\n" << cube;

        } else if (command == "generate") {
            if (!inputStream.eof())
                throw std::logic_error("You can enter only one command");
            cube.randomize();
            std::cout << cube << '\n';

        } else if (command == "reset") {
            if (!inputStream.eof())
                throw std::logic_error("You can enter only one command");
            cube.reset();

        } else if (command == "exit") {
            break;

        } else {
            std::cerr << "There is no such command\n";

        }
        command.clear();
    }
    return 0;
}