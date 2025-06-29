#include "GuessTheNumber.hpp"

void title_printer()
{
    std::cout << "============================================" << std::endl;
    std::cout << "              Guess The Number              " << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << "Try to guess the number I'm thinking of!" << std::endl;
    std::cout << "You have " << YELLOW << "5 attempts." << RESET << std::endl;
    std::cout << "Good luck!" << std::endl;
    std::cout << "////////////////////////////////////////////" << std::endl;
}

void secret_nbr_printer(int secret_nbr)
{
    std::cout
    << ">>> The secret number was: " << YELLOW
    << secret_nbr << "." << RESET
    << std::endl;
}

void remaining_attempts_printer(int total_tries, int user_tries)
{
    std::cout
    << "You have " << YELLOW
    << total_tries - user_tries
    << " attempts left." << RESET
    << std::endl;
}

void number_hint_printer()
{
    std::cout << MAGENTA
    << "The secret number is between "
    << GAME_MIN_NBR << " and " << GAME_MAX_NBR << "." << RESET
    << std::endl;
}
