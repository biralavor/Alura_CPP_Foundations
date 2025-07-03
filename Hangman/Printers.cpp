#include "Hangman.hpp"

void title_printer()
{
    std::cout << "\n---------------------------------------------" << std::endl;
    std::cout << "------------- Welcome to Hangman! -----------" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "Try to guess the secret word letter by letter." << std::endl;
    std::cout << "You have " << TOTAL_TRIES << " tries to guess the word." << std::endl;
    std::cout << "Good luck!\n" << std::endl;
}

void wrong_inputs_printer(const std::vector<char> &wrong_inputs)
{
    if (wrong_inputs.empty())
        return;
    std::cout << "Your wrong guesses: ";
    for (int idx = 0; idx < wrong_inputs.size(); idx++)
        std::cout << wrong_inputs[idx] << ", ";
    std::cout << std::endl;
}

void hangman_printer(int user_tries)
{
    std::cout << "  +---+" << std::endl;
    std::cout << "  |   |" << std::endl;
    // Head
    if (user_tries >= 1)
        std::cout << "  O   |" << std::endl;
    else
        std::cout << "      |" << std::endl;
    // Body and Arms
    if (user_tries >= 4)
        std::cout << " /|\\  |" << std::endl;
    else if (user_tries >= 3)
        std::cout << " /|   |" << std::endl;
    else if (user_tries >= 2)
        std::cout << "  |   |" << std::endl;
    else
        std::cout << "      |" << std::endl;
    // Legs
    if (user_tries >= 5)
        std::cout << " /    |" << std::endl;
    else
        std::cout << "      |" << std::endl;
    std::cout << "      |" << std::endl;
    std::cout << "=========" << std::endl << std::endl;
}

void secret_word_slots_printer(const std::string &actual_secret_word,
    const std::map<char, bool> &guessed_letters)
{
    for (int idx = 0; idx < actual_secret_word.size(); idx++)
    {
        if(guessed_letters.find(actual_secret_word[idx]) != guessed_letters.end())
            std::cout << actual_secret_word[idx] << " ";
        else
            std::cout << "_ ";
    }
    std::cout << std::endl;
}
