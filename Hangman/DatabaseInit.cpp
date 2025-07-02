#include "Hangman.hpp"

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

std::string random_secret_word_picker()
{
    std::string actual_secret_word;

    srand(time(0));
    actual_secret_word = all_secret_words[rand() % all_secret_words.size()];
    return actual_secret_word;
}
