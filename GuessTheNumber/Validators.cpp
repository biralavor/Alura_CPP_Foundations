#include "GuessTheNumber.hpp"

bool is_nbr_valid(int user_nbr)
{
    if (user_nbr < 1 || user_nbr > 100)
    {
        std::cout
        << "The number must be between "
        << YELLOW << GAME_MIN_NBR << " and " << GAME_MAX_NBR << "."
        << RESET << std::endl;
        return false;
    }
    return true;
}

bool does_user_won(int user_nbr, int secret_nbr)
{
    return user_nbr == secret_nbr;
}

bool does_user_wanna_quit(std::string input_str)
{
    if (input_str == "exit" || input_str == "quit" || input_str == "q")
    {
        std::cout << ORANGE
        << "Exiting the game. Goodbye!"
        << RESET << std::endl;
        exit(0);
    }
    return false;
}

bool is_input_not_a_nbr(std::string input_str, int *user_tries)
{
    int user_nbr;

    try
    {
        user_nbr = std::stoi(input_str);
    }
    catch (const std::exception& error)
    {
        std::cout << RED
        << "Invalid input. Please enter a valid number."
        << RESET << std::endl;
        (*user_tries)--;
        return true;
    }
    return false;
}
