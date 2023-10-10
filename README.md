# General description

This project is a Password Generator that allows users to generate random passwords, verify the generated passwords, delete specific passwords, and exit the program. The program runs on the command line and provides a simple interface to perform these actions.

## Compilation

To compile the project, make sure you have a C++ compiler installed on your system. Then, follow these steps:

Open a terminal in the directory where the main.cpp source code file is located

Run the following command to compile the program:

```shell
g++ main.cpp -o main
```

This will create an executable called main.exe.

## Use of the Program

To run the program, use the following command:

```shell
./main
```

The program will display a menu of options:

Password Generator - Main Menu

1. Generate Password
2. Check The Password File
3. Delete a password
4. Exit

Select an option (1/2/3/4):

Here's how to use each option:

## 1. Generate Password

This option allows you to generate a new random password. You must enter the desired password length and then a password will be generated and stored in a file.

## 2. Check Generated Passwords

This option allows you to view all previously generated passwords. The program will display a list of passwords stored in the file.

## 3. Delete Generated Password

You can select this option to remove a specific password from previously generated passwords. You must enter the password you want to delete and the program will search for it and delete it from the file.

## 4. Exit

This option allows you to exit the program.

## Example of Use

Below is an example of how to use the program:

1. Run the program.

2. Select the "Generate Password" option.

3. Enter the length of the password (for example, 10).

4. The program will generate a random password and store it in the file.

5. Return to the main menu and select "Check Generated Passwords" to view the list of stored passwords.

6. If you want to remove a specific password, select "Delete Generated Password" and follow the instructions.

7. You can select the "Exit" option to exit the program when you are done.

## Additional notes

- The generated passwords are stored in a file called "passwords.txt".

- If you have problems with compilation or execution, make sure that you have a C++ compiler installed and that the source code file (main.cpp) is in the same directory as the generated executable.
