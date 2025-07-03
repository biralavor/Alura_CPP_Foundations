#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <ctime>

const int TOTAL_TRIES = 5;

//DatabaseInit.cpp
bool secret_words_database_loader(std::vector<std::string> &all_secret_words);
std::string random_secret_word_picker(std::vector<std::string> &all_secret_words);

//Validators.cpp
bool letter_checker(char user_input, const std::string& actual_secret_word);
bool is_word_disclosed(const std::string &actual_secret_word, \
    std::map<char, bool> &guessed_letters);

//Printers.cpp
void title_printer();
void wrong_inputs_printer(const std::vector<char> &wrong_inputs);
void hangman_printer(int user_tries);
void secret_word_slots_printer(const std::string &actual_secret_word, \
    std::map<char, bool> &guessed_letters);

//Managers.cpp
void game_manager(int user_tries, const std::string &actual_secret_word);
char user_input_manager();
void guessed_letter_manager(int *user_tries, const std::string &actual_secret_word, \
    std::map<char, bool> &guessed_letters, std::vector<char> &wrong_inputs);
