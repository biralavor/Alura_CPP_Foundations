#include "Hangman.hpp"

bool letter_checker(char user_input, const std::string& actual_secret_word)
{
    for (int idx = 0; idx < actual_secret_word.size(); idx++)
    {
        if (user_input == actual_secret_word[idx])
            return (true);
    }
    return (false);
}

bool is_word_disclosed(const std::string &actual_secret_word, const std::map<char, bool> &guessed_letters)
{
    if (guessed_letters.empty())
        return false;
    for (int idx = 0; idx < actual_secret_word.size(); idx++)
    {
        if (guessed_letters.find(actual_secret_word[idx]) == guessed_letters.end())
            return false;
    }
    return true;
}
