#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstdlib>

const std::string SECRET_WORD = "WATERMELON";
const int TOTAL_TRIES = 5;
std::map<char, bool> guessed_letters;
std::vector<char> wrong_inputs;

bool letter_checker(char user_input)
{
    for (int idx = 0; idx < SECRET_WORD.size(); idx++)
    {
        if (user_input == SECRET_WORD[idx])
            return (true);
    }
    return (false);
}

void secret_word_slots_printer()
{
    for (int idx = 0; idx < SECRET_WORD.size(); idx++)
    {
        if(guessed_letters.find(SECRET_WORD[idx]) != guessed_letters.end())
            std::cout << SECRET_WORD[idx] << " ";
        else
            std::cout << "_ ";
    }
    std::cout << std::endl;
}

void hangman_printer(int user_tries)
{
    std::cout << "  +---+" << std::endl;
    std::cout << "  |   |" << std::endl;
    // Head
    if (user_tries >= 1)
        std::cout << "  O   |" << std::endl;
    else
        std::cout << "      |" << std::endl;
    // Body and Arms
    if (user_tries >= 4)
        std::cout << " /|\\  |" << std::endl;
    else if (user_tries >= 3)
        std::cout << " /|   |" << std::endl;
    else if (user_tries >= 2)
        std::cout << "  |   |" << std::endl;
    else
        std::cout << "      |" << std::endl;
    // Legs
    if (user_tries >= 5)
        std::cout << " /    |" << std::endl;
    else
        std::cout << "      |" << std::endl;
    std::cout << "      |" << std::endl;
    std::cout << "=========" << std::endl << std::endl;
}

void wrong_inputs_printer()
{
    if (wrong_inputs.empty())
        return;
    std::cout << "Your wrong guesses: ";
    for (int idx = 0; idx < wrong_inputs.size(); idx++)
        std::cout << wrong_inputs[idx] << ", ";
    std::cout << std::endl;
}

bool is_word_disclosed()
{
    for (int idx = 0; idx < SECRET_WORD.size(); idx++)
    {
        if (guessed_letters.find(SECRET_WORD[idx]) == guessed_letters.end())
            return false;
    }
    return true;
}

void title_printer()
{
    std::cout << "\n---------------------------------------------" << std::endl;
    std::cout << "------------- Welcome to Hangman! -----------" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "Try to guess the secret word letter by letter." << std::endl;
    std::cout << "You have " << TOTAL_TRIES << " tries to guess the word." << std::endl;
    std::cout << "Good luck!\n" << std::endl;
}

char user_input_catcher()
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

void guessed_letter_manager(char user_input, int *user_tries)
{
    if (letter_checker(user_input))
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

int main()
{
    title_printer();
    char user_input;
    int user_tries = 0;
    while (user_tries < TOTAL_TRIES && !is_word_disclosed())
    {
        hangman_printer(user_tries);
        secret_word_slots_printer();
        wrong_inputs_printer();
        user_input = user_input_catcher();
        guessed_letters[user_input] = true;
        guessed_letter_manager(user_input, &user_tries);
    }
    if (is_word_disclosed())
        std::cout << "Congratulations! You guessed the word: " << SECRET_WORD << std::endl;
    else
    {
        std::cout << "You ran out of attempts." << std::endl;
        std::cout << "You lose! The secret word was: " << SECRET_WORD << std::endl;
        hangman_printer(user_tries);
    }
    std::cout << "Thanks for playing!" << std::endl;
    exit(0);
}
