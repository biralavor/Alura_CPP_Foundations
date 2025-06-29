#include "GuessTheNumber.hpp"

const int SECRET_NBR = random_nbr_generator(GAME_MIN_NBR, GAME_MAX_NBR);

int main ()
{
    int user_nbr = 0;
    int user_tries = 0;
    
    title_printer();
    number_hint_printer();
    while (user_tries < TOTAL_TRIES)
    {
        user_nbr = update_user_number(user_nbr, &user_tries);
        if (does_user_won(user_nbr, SECRET_NBR))
        {
            std::cout << CYAN;
            std::cout << "Congratulations! You WON!" << std::endl;
            std::cout << RESET;
            exit(0);
        }
        if (user_nbr < SECRET_NBR)
        std::cout << "The number is greater than " << user_nbr << "." << std::endl;
        else if (user_nbr > SECRET_NBR)
        std::cout << "The number is less than " << user_nbr << "." << std::endl;
        remaining_attempts_printer(TOTAL_TRIES, user_tries);
    }
    std::cout << RED;
    std::cout << "You ran out of attempts." << std::endl;
    std::cout << RESET;
    secret_nbr_printer(SECRET_NBR);
    exit(0);
}
