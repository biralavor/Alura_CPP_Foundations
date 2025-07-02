#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <ctime>

extern const std::string database_filename;
extern const int TOTAL_TRIES;
extern std::map<char, bool> guessed_letters;
extern std::vector<char> wrong_inputs;
extern std::vector<std::string> all_secret_words;

//DatabaseInit.cpp
bool secret_words_database_loader();
std::string random_secret_word_picker();

//Validators.cpp
bool letter_checker(char user_input, const std::string& actual_secret_word);
bool is_word_disclosed(const std::string& actual_secret_word);

//Printers.cpp
void title_printer();
void wrong_inputs_printer();
void hangman_printer(int user_tries);
void secret_word_slots_printer(const std::string& actual_secret_word);

//Managers.cpp
void game_manager(int user_tries, const std::string &actual_secret_word);
char user_input_manager();
void guessed_letter_manager(char user_input, int *user_tries, \
    const std::string &actual_secret_word);
