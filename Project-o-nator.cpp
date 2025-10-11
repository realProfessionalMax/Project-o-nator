// Project-o-nator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <string>
//#include "Functions.cpp" :(


int UserChoice{};//used to select the actions
bool repeated{false};// Boolean for when the user enters an incorrect input.

//Global variables^^

int ideaCommittor() {
    repeated = false;//As they use the same variable, we need to reset it as this is a new function. 
    std::cout << "Welcome to the ideaCommittor(tm)!\nWhat would you like to do?" << std::endl;
    std::cout << "1) Add Idea" << std::endl;
    std::cout << "2) Remove Idea" << std::endl;
    std::cout << "3) Exit" << std::endl;
    std::cout << "Enter a number: ";
    std::cin >> UserChoice;
    std::cout << std::endl;
    //User interface/interaction^^
    if (isdigit(UserChoice) == true) {
        switch (UserChoice)
        {
        case(1): {
            break;
        }
        case(2): {
            break;
        }
        case(3): {
            std::cout << "Exiting..." << std::endl;
            break;
        }
        default: {
            std::cout << "Sorry, your input was not recognized." << std::endl;
            break;
        }
        }
    }
    else {
        std::cout << "Please put a number, not a string." << std::endl;//No, I don't know why when you exit it does this.
    }
    //switch case^^
    return 0;
}

int ideaGenertor() {
    repeated = false;//As they use the same variable, we need to reset it as this is a new function. 
    int choice{};
    std::cout << "Welcome to the ideaGenerator(tm)!\n What would you like to specify?" << std::endl;
    std::cout << "1) Coding Language" << std::endl;
    std::cout << "2) Difficulty" << std::endl;
    std::cout << "3) Random Idea" << std::endl;
    std::cout << "4) Exit" << std::endl;
    std::cout << "Enter a number: ";
    std::cin >> UserChoice;
    std::cout << std::endl;
    //User interface/interaction^^
    switch (UserChoice)
    {
        case(1): { //select a coding language
            std::cin.ignore();
            std::string language;
            std::cout << "Select a language" << std::endl;
            std::cout << "1) Python" << std::endl;
            std::cout << "2) Html,CSS,JS" << std::endl;
            std::cout << "3) p5 JS" << std::endl;
            std::cout << "4) C++" << std::endl;
            std::cout << "5) Other" << std::endl;
            std::cin >> UserChoice;
            break;
        }
        case(2): {// Selects the Difficulty
            std::cin.ignore();
            std::cout << "Select the Difficulty." << std::endl;
            std::cout << "1" << std::endl;
            std::cout << "2" << std::endl;
            std::cout << "3" << std::endl;
            std::cout << "4" << std::endl;
            std::cout << "5" << std::endl;
            std::cin >> UserChoice;
            break;
        }
        case(3): {// Generate an Idea with no restrictions.
            std::cout << "Sorry, This has not been made/or finsihed yet." << std::endl;
            break;
        }
        case(4): {
            std::cout << "Exiting..." << std::endl;
            break;
        }
        default: {
            std::cout << "Sorry, your input was not recognized." << std::endl;
            break;
        }
    }
    //switch case^^
    return 0;
}

int Menu() {
    
    //when things need to be run before the rest of the code ^^
    if (repeated == false) {
        std::cout << "What would you like to do?" << std::endl;
        std::cout << "1) Edit Ideas" << std::endl;
        std::cout << "2) Generate Ideas" << std::endl;
        std::cout << "3) Exit" << std::endl;
    }
    //no else statement as the rest of the code is shared anyways
    std::cout << "Enter a number: ";
    std::cin >> UserChoice;
    std::cout << std::endl;
    //User interface/interaction^^
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();
        //Clears the input and ignores the characters.^^
        std::cout << "Please, enter an integer, not a character." << std::endl << std::endl;
        repeated = false;
        //Repeated as punishment for entering a character.
        Menu();
        //Makes it like a while loop.
    }//If
    else
    {
        switch (UserChoice)
        {
            case(1): {
                ideaCommittor();
                Menu();
                break;
            }
            case(2): {
                ideaGenertor();
                Menu();
                break;
            }
            case(3): {
                std::cout << "Exiting..." << std::endl;
                break;
            }
            default: {
                std::cout << "Sorry, your input was not recognized." << std::endl;
                repeated = true;
                Menu();
                break;
            }//default
        }//switch
    }//Else
    //User input recognizer^^
    return 0;
}

int main()
{
    //test();
    std::cout << "Welcome, To Max's glorious Project-o-Nator(tm)!" << std::endl;
    Menu();
    std::string txtTest{};


    //-----Variables^^-----
    std::fstream Ideas("Ideas.txt", std::ios_base::app);
    Ideas << std::endl << "Did this update?" << std::endl << "Did this update2?";
    Ideas.close();
    //Update file ^^
    std::fstream ReadFile("Ideas.txt");

    while (getline(ReadFile, txtTest)) {
        // Output the text from the file
        std::cout << txtTest << std::endl;
    }
    //read and output file^^
    Ideas.close();
    //Don't mind, used for refereance.


}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
