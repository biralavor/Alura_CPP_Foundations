#include "Hangman.hpp"

const std::string database_filename = "secret_words.txt";
const int TOTAL_TRIES = 5;
std::map<char, bool> guessed_letters;
std::vector<char> wrong_inputs;
std::vector<std::string> all_secret_words;

int main()
{
    std::string actual_secret_word;
    int user_tries = 0;

    if (secret_words_database_loader())
    {
        title_printer();
        actual_secret_word = random_secret_word_picker();
        game_manager(user_tries, actual_secret_word);
    }
    else
    {
        std::cerr
        << "Failed to load the secret words database. Exiting the game."
        << std::endl;
        return 1;
    }
    return 0;
}
