#include "Hangman.hpp"

char user_input_manager()
{
    char user_input;

    std::cout << "\nEnter a letter (or type '!' to quit the game): ";
    std::cin >> user_input;
    if (user_input == '!')
    {
        std::cout << "You chose to quit the game. Goodbye!" << std::endl;
        exit(0);
    }
    return toupper(user_input);
}

void guessed_letter_manager(char user_input, int *user_tries, const std::string &actual_secret_word)
{
    if (letter_checker(user_input, actual_secret_word))
        std::cout << user_input << " is in the word!" << std::endl;
    else
    {
        (*user_tries)++;
        wrong_inputs.push_back(user_input);
        std::cout
        << "Sorry, that letter is not in the word. You have "
        << TOTAL_TRIES - (*user_tries) << " tries left."
        << std::endl;
    }
    std::cout << std::endl;
}
