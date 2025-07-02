#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <ctime>

const std::string database_filename = "secret_words.txt";
const int TOTAL_TRIES = 5;
std::map<char, bool> guessed_letters;
std::vector<char> wrong_inputs;
std::vector<std::string> all_secret_words;

bool secret_words_database_loader()
{
    std::ifstream file(database_filename);
    std::string line;
    int words_count = 0;

    if (!file)
    {
        std::cerr << "\nError opening the database file: " << database_filename << std::endl;
        return false;
    }
    while(std::getline(file, line)) {
        all_secret_words.push_back(line);
        words_count++;
    }
    if (words_count == 0)
    {
        std::cerr << "\nThe database file is empty. Adding a default word." << std::endl;
        all_secret_words.push_back("LINUX");
    }
    else
        std::cout << "\nThere are " << words_count << " secret words in the database." << std::endl;
    file.close();
    return true;
}

std::string secret_word_randomizer()
{
    std::string actual_secret_word;

    srand(time(0));
    actual_secret_word = all_secret_words[rand() % all_secret_words.size()];
    return actual_secret_word;
}

bool letter_checker(char user_input, const std::string& actual_secret_word)
{
    for (int idx = 0; idx < actual_secret_word.size(); idx++)
    {
        if (user_input == actual_secret_word[idx])
            return (true);
    }
    return (false);
}

void secret_word_slots_printer(std::string actual_secret_word)
{
    for (int idx = 0; idx < actual_secret_word.size(); idx++)
    {
        if(guessed_letters.find(actual_secret_word[idx]) != guessed_letters.end())
            std::cout << actual_secret_word[idx] << " ";
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

bool is_word_disclosed(std::string actual_secret_word)
{
    for (int idx = 0; idx < actual_secret_word.size(); idx++)
    {
        if (guessed_letters.find(actual_secret_word[idx]) == guessed_letters.end())
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

void guessed_letter_manager(char user_input, int *user_tries, std::string actual_secret_word)
{
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

int main()
{
    std::string actual_secret_word;
    
    if (secret_words_database_loader())
    {
        title_printer();
        actual_secret_word = secret_word_randomizer();
        char user_input;
        int user_tries = 0;
        while (user_tries < TOTAL_TRIES && !is_word_disclosed(actual_secret_word))
        {
            hangman_printer(user_tries);
            secret_word_slots_printer(actual_secret_word);
            wrong_inputs_printer();
            user_input = user_input_catcher();
            guessed_letters[user_input] = true;
            guessed_letter_manager(user_input, &user_tries, actual_secret_word);
        }
        if (is_word_disclosed(actual_secret_word))
            std::cout << "Congratulations! You guessed the word: " << actual_secret_word << std::endl;
        else
        {
            std::cout << "You ran out of attempts." << std::endl;
            std::cout << "You lose! The secret word was: " << actual_secret_word << std::endl;
            hangman_printer(user_tries);
        }
        std::cout << "Thanks for playing!" << std::endl;
        exit(0);
    }
    else
    {
        std::cerr << "Failed to load the secret words database. Exiting the game." << std::endl;
        exit(1);
    }
}
