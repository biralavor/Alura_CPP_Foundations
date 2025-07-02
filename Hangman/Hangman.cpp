#include "Hangman.hpp"

const std::string database_filename = "secret_words.txt";
const int TOTAL_TRIES = 5;
std::map<char, bool> guessed_letters;
std::vector<char> wrong_inputs;
std::vector<std::string> all_secret_words;

int main()
{
    std::string actual_secret_word;
    
    if (secret_words_database_loader())
    {
        title_printer();
        actual_secret_word = random_secret_word_picker();
        char user_input;
        int user_tries = 0;
        while (user_tries < TOTAL_TRIES && !is_word_disclosed(actual_secret_word))
        {
            hangman_printer(user_tries);
            secret_word_slots_printer(actual_secret_word);
            wrong_inputs_printer();
            user_input = user_input_manager();
            guessed_letters[user_input] = true;
            guessed_letter_manager(user_input, &user_tries, actual_secret_word);
        }
        if (is_word_disclosed(actual_secret_word))
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
        return 0;
    }
    else
    {
        std::cerr
        << "Failed to load the secret words database. Exiting the game."
        << std::endl;
        return 1;
    }
}
