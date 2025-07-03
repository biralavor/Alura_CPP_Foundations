#include "Hangman.hpp"

void game_manager(int user_tries, const std::string &actual_secret_word)
{
    std::vector<char> wrong_inputs;
    std::map<char, bool> guessed_letters;

    while (user_tries < TOTAL_TRIES && !is_word_disclosed(actual_secret_word, guessed_letters))
    {
        hangman_printer(user_tries);
        secret_word_slots_printer(actual_secret_word, guessed_letters);
        wrong_inputs_printer(wrong_inputs);
        guessed_letter_manager(&user_tries, actual_secret_word, guessed_letters, wrong_inputs);
    }
    if (is_word_disclosed(actual_secret_word, guessed_letters))
    {
        std::cout << "Congratulations! You guessed the word: "
        << actual_secret_word << std::endl;
    }
    else
    {
        std::cout << "You ran out of attempts." << std::endl;
        std::cout << "You lose! The secret word was: "<< actual_secret_word
        << std::endl;
        hangman_printer(user_tries);
    }
        std::cout << "Thanks for playing!" << std::endl;
}

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

void guessed_letter_manager(int *user_tries, const std::string &actual_secret_word,
    std::map<char, bool> &guessed_letters, std::vector<char> &wrong_inputs)
{
    char user_input;

    user_input = user_input_manager();
    guessed_letters[user_input] = true;
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
