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
