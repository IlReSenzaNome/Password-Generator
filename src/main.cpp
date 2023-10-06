#include <iostream>
#include <time.h>
#include <conio.h>
#include <fstream>

int Option();
std::string GeneratePassword(int);
void CheckFilePassword();

int main(int argc, char const *argv[])
{
    Option();
    getch();
    return 0;
}

int Option()
{
    int option, large;
    do
    {
        std::cout << "------------------------------" << std::endl;
        std::cout << "|      Password Generator    |" << std::endl;
        std::cout << "------------------------------" << std::endl;
        std::cout << "|> 1. Generator New Password |" << std::endl;
        std::cout << "|> 2. Check File Password    |" << std::endl;
        std::cout << "|> 3. Delete a last Password |" << std::endl;
        std::cout << "|> 4. Exit                   |" << std::endl;
        std::cout << "------------------------------" << std::endl;
        std::cout << "|> Select a option:          |" << std::endl;
        std::cin >> option;
        std::cout << "------------------------------" << std::endl;

        switch (option)
        {
        case 1:
            GeneratePassword(large);
            break;
        case 2:
            CheckFilePassword();
            break;
        case 3:
            CheckFilePassword();
            break;
        case 4:
            CheckFilePassword();
            break;
        default:
            std::cout << "----------------------" << std::endl;
            std::cout << "|       Error        |" << std::endl;
            std::cout << "----------------------" << std::endl;
            break;
        }
    } while (option != 4);
}

std::string GeneratePassword(int large)
{
    std::cout << "end" << std::endl;
}

void CheckFilePassword()
{
    std::cout << "test" << std::endl;
}