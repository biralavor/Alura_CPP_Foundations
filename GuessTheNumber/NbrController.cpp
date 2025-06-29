#include "GuessTheNumber.hpp"

int random_nbr_generator(const int GAME_MIN_NBR, const int GAME_MAX_NBR)
{
    int secret_nbr;

    srand(time(0));
    secret_nbr = rand() % (GAME_MAX_NBR - GAME_MIN_NBR + 1) + GAME_MIN_NBR;
    return secret_nbr;
}

int update_user_number(int user_nbr, int *user_tries)
{
    (*user_tries)++;
    std::cout << "Enter a number (or 'exit' to quit the game): ";
    std::string input_str;
    std::cin >> (input_str);
    
    if (!does_user_wanna_quit(input_str))
    {
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
            return (update_user_number(user_nbr, user_tries));
        }
    }
    if (!is_nbr_valid(user_nbr))
        user_nbr = update_user_number(user_nbr, user_tries);
    return user_nbr;
}
