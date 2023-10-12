#include <iostream>
#include <fstream>
#include <ctime>
#include "lib/rlutil.h"

int Option();
void GeneratePassword(int, const std::string &);
void CheckFilePassword();
void Delete(const std::string &);
void error();

int main()
{
    Option();
    return 0;
}

int Option()
{
    int option, large;
    std::string belong;

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
        std::cout << "------------------------------" << std::endl;
        rlutil::locate(21, 12);
        std::cin >> option;
        std::cin.ignore();
        switch (option)
        {
        case 1:
            rlutil::cls();
            std::cout << "------------------------------------------------" << std::endl;
            std::cout << "| Type a belong for password:                  |" << std::endl;
            std::cout << "------------------------------------------------" << std::endl;
            rlutil::locate(31, 2);
            std::getline(std::cin, belong);
            std::cout << "------------------------------------------------" << std::endl;
            std::cout << "| Type a large for password:                   |" << std::endl;
            std::cout << "------------------------------------------------" << std::endl;
            rlutil::locate(29, 4);
            std::cin >> large;
            std::cin.ignore();
            if (large > 0)
            {
                GeneratePassword(large, belong);
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
            rlutil::cls();
            std::cout << "------------------------------------------------" << std::endl;
            std::cout << "| Write the name to which the password belongs:|" << std::endl;
            std::cout << "------------------------------------------------" << std::endl;
            rlutil::locate(40, 2);
            std::getline(std::cin, belong);
            Delete(belong);
            break;
        case 4:
            rlutil::cls();
            std::cout << "------------------------------" << std::endl;
            std::cout << "|            Exit            |" << std::endl;
            std::cout << "------------------------------" << std::endl;
            break;
        default:
            error();
            break;
        }
        getch();
        rlutil::cls();
    } while (option != 4);
}

void GeneratePassword(int large, const std::string &belong)
{
    std::ofstream file("passwords.txt", std::ios::app);
    char character[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=";
    int numberofchar = sizeof(character) - 1;
    std::srand(std::time(nullptr));

    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "|      Password Generator:                     |" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;

    if (!file)
    {
        error();
        exit(1);
    }

    file << belong << ": ";
    for (int i = 0; i < large; i++)
    {
        int randomindex = std::rand() % numberofchar;
        char randomchracter = character[randomindex];
        std::cout << randomchracter;
        file << randomchracter;
    }
    file << std::endl;
    file.close();
    std::cout << std::endl;
}

void CheckFilePassword()
{
    std::ifstream file("passwords.txt");
    if (!file)
    {
        error();
        exit(1);
    }

    std::string passwords;
    while (std::getline(file, passwords))
    {
        std::cout << passwords << std::endl;
    }
}

void Delete(const std::string &password)
{
    std::ifstream file("passwords.txt");
    std::ofstream temp("temp.txt");
    std::string aux;
    aux = password;

    if (!file || !temp)
    {
        error();
        exit(1);
    }

    std::string line;
    bool deleted = false;

    while (std::getline(file, line))
    {
        if (line.find(aux) == 0)
        {
            std::cout << "Password deleted" << std::endl;
            deleted = true;
        }
        else
        {
            temp << line << std::endl;
        }
    }

    if (!deleted)
    {
        std::cout << "Password not found" << std::endl;
    }

    file.close();
    temp.close();

    std::remove("passwords.txt");
    std::rename("temp.txt", "passwords.txt");
}

void error()
{
    std::cout << "----------------------" << std::endl;
    std::cout << "|       Error        |" << std::endl;
    std::cout << "----------------------" << std::endl;
}
