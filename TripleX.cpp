/**
 * This is a program built following the C++/Unreal Udemy course at https://www.udemy.com/unrealcourse
 * The user guesses a digit using clues given by the program
 */

#include <iostream>
#include <ctime>

void PrintIntro(int Difficulty)
{
    // Print welcome message to the terminal
    std::cout << "You are a secret agent breaking into a level " << Difficulty << " ";
    std::cout << "server room. You need to enter the correct codes to continue...";
    std::cout << std::endl; // Another Way to add a line
}

bool PlayGame(int Difficulty)
{
    std::cout << std::endl;
    PrintIntro(Difficulty);

    int DifficultyModifier = rand() % Difficulty + Difficulty; 

    // Declaration for the three number code
    const int CodeA = rand() % DifficultyModifier;
    const int CodeB = rand() % DifficultyModifier;
    const int CodeC = rand() % DifficultyModifier;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << std::endl; 
    std::cout << "+ There are 3 numbers in the code.\n"; 
    std::cout << "+ The codes add up to: " << CodeSum << std::endl; 
    std::cout << "+ The product of the 3 numbers is: " << CodeProduct << std::endl; 

    // Take the player's guess
    
    int GuessA, GuessB, GuessC;
    
    std::cout << std::endl; 
    std::cout << "Please enter the correct code: "; 
    std::cin >> GuessA  >> GuessB >> GuessC;
    std::cout << "You entered: " << GuessA << GuessB << GuessC << std::endl;   

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nCorrect! Now try the next level\n"; 
        return true;
    }else
    {
        std::cout << "\nWRONG, BITCH! TRY AGAIN\n"; 
        return false;
    }

    return false;
}


int main()
{
    srand(time(NULL)); // Create a new random sequence based on the time of day
    
    int LevelDifficulty = 1;
    const int  MaxLevel = 5;

    while (LevelDifficulty <= MaxLevel) // Loop Game untill all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();  // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }

    std::cout << "\nOMG you did it! I didn't believe in you but you did it!\n"; 
    
    return 0;
}