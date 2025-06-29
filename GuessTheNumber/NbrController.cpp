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
    std::string input_str;

    (*user_tries)++;
    std::cout << YELLOW
    << "Enter a number "<< B_GRAY
    << "(or 'exit' to quit the game): " << GREEN;
    std::cin >> (input_str);
    std::cout << RESET;
    if (!does_user_wanna_quit(input_str))
    {
        if (is_input_not_a_nbr(input_str, user_tries))
            return (update_user_number(user_nbr, user_tries));
        else
            user_nbr = std::stoi(input_str);
    }
    if (!is_nbr_valid(user_nbr))
        user_nbr = update_user_number(user_nbr, user_tries);
    return user_nbr;
}
