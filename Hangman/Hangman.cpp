#include "Hangman.hpp"

int main(void)
{
    std::string actual_secret_word;
    std::vector<std::string> all_secret_words;
    int user_tries = 0;

    if (secret_words_database_loader(all_secret_words))
    {
        title_printer();
        actual_secret_word = random_secret_word_picker(all_secret_words);
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
