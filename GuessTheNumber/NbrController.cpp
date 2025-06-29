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
    std::cout << "Enter a number: ";
    std::cin >> user_nbr;
    // if (user_nbr == "exit")
    //     exit(0);
    if (!is_nbr_valid(user_nbr))
        user_nbr = update_user_number(user_nbr, user_tries);
    return user_nbr;
}
