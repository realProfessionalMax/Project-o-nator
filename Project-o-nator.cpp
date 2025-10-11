// Project-o-nator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <string>


int x{};//used to select the actions
bool repeted{false};

//Global variables^^

int ideaCommittor() {
    repeted = false;//As they use the same variable, we need to reset it as this is a new function. 
    std::cout << "Welcome to the ideaCommittor(tm)!\n what would you like to do?" << std::endl;
    std::cout << "1) Add Idea" << std::endl;
    std::cout << "2) Remove Idea" << std::endl;
    std::cout << "3) Exit" << std::endl;
    std::cout << "Enter a number: ";
    std::cin >> x;
    //User interface/interaction^^
    if (isdigit(x) == true) {
        switch (x)
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
            std::cout << "Sorry, your input was not recognized.2" << std::endl;
            break;
        }
        }
    }
    else {
        std::cout << "Please put a number, not a string." << std::endl;
    }
    //switch case^^
    return 0;
}

int ideaGenertor() {
    //User interface/interaction^^
    switch (x)
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
        std::cout << "Sorry, your input was not recognized.3" << std::endl;
        break;
    }
    }
    //switch case^^
    return 0;
}

int Menu() {
    
    //when things need to be run before the rest of the code ^^
    if (repeted == false) {
        std::cout << "What would you like to do?" << std::endl;
        std::cout << "1) Edit Ideas" << std::endl;
        std::cout << "2) Generate Ideas" << std::endl;
        std::cout << "3) Exit" << std::endl;
    }
    //no else statement as the rest of the code is shared anyways
    std::cout << "Enter a number: ";
    std::cin >> x;
    //User interface/interaction^^
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();
        //Clears the input and ignores the characters.^^
        std::cout << "Please, enter an integer, not a character." << std::endl << std::endl;
        repeted = false;
        //Repeted as punishment for entering a character.
        Menu();
        //Makes it like a while loop.
    }//If
    else
    {
        switch (x)
        {
            case(1): {
                ideaCommittor();
                break;
            }
            case(2): {
                ideaGenertor();
                break;
            }
            case(3): {
                std::cout << "Exiting..." << std::endl;
                break;
            }
            default: {
                std::cout << "Sorry, your input was not recognized." << std::endl;
                repeted = true;
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
    Menu();
    std::string txtTest{};



    //-----Variables^^-----
    std::fstream Ideas("Ideas.txt");
    Ideas << "Did this update?" << std::endl << "Did this update2?";
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
