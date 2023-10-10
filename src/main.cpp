#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <conio.h>
#include <fstream>
#include "lib/rlutil.h"

int Option();
void GeneratePassword(int, int);
void CheckFilePassword();
void error();

int main(int argc, char const *argv[])
{
    Option();
    return 0;
}

int Option()
{
    int option, large, counter = 0;
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
        rlutil::locate(21, 12);
        std::cin >> option;
        std::cout << "------------------------------" << std::endl;
        switch (option)
        {
        case 1:
            rlutil::cls();
            std::cout << "Type a large for password: ";
            std::cin >> large;
            if (large > 0)
            {
                counter++;
                GeneratePassword(large, counter);
            }
            else
            {
                error();
                return 1;
            }
            break;
        case 2:
            rlutil::cls();
            CheckFilePassword();
            break;
        case 3:
            CheckFilePassword();
            break;
        case 4:
            CheckFilePassword();
            break;
        default:
            error();
            break;
        }
        getch();
        rlutil::cls();
    } while (option != 4);
}

void GeneratePassword(int large, int counter)
{
    std::ofstream file;
    char character[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=";
    int numberofchar = sizeof(character) - 1;

    // std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::srand(std::time(nullptr));

    std::cout << "Password Generate: " << std::endl;
    file.open("passwords.txt", std::ios::app);
    if (file.fail())
    {
        error();
        exit(1);
    }
    else
    {
        file << counter << ".- ";
        for (int i = 0; i < large; i++)
        {
            int randomindex = std::rand() % numberofchar;
            char randomchracter = character[randomindex];
            std::cout << randomchracter;
            file << counter << randomchracter;
        }
        file << std::endl;
        file.close();
        std::cout << std::endl;
    }
}

void CheckFilePassword()
{
    std::ifstream file;
    std::string passwords;
    file.open("passwords.txt", std::ios::in);
    if (file.fail())
    {
        error();
        exit(1);
    }
    while (!file.eof())
    {
        std::getline(file, passwords);
        std::cout << passwords << std::endl;
    }
}

void Delete()
{
}

void error()
{
    std::cout << "----------------------" << std::endl;
    std::cout << "|       Error        |" << std::endl;
    std::cout << "----------------------" << std::endl;
}
