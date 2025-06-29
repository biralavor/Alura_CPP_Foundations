#include <iostream>
#include <random>
#include <ctime>

const int TOTAL_TRIES = 5;
const int GAME_MIN_NBR = 1;
const int GAME_MAX_NBR = 100;
extern const int SECRET_NBR;

extern const char *RED;
extern const char *GREEN;
extern const char *YELLOW;
extern const char *BLUE;
extern const char *PURPLE;
extern const char *CYAN;
extern const char *ORANGE;
extern const char *MAGENTA;
extern const char *RESET;

void title_printer();
void secret_nbr_printer(int secret_nbr);
void remaining_attempts_printer(int total_tries, int user_tries);
void number_hint_printer();

bool is_nbr_valid(int user_nbr);
bool does_user_won(int user_nbr, int secret_nbr);

int random_nbr_generator(const int GAME_MIN_NBR, const int GAME_MAX_NBR);
int update_user_number(int user_nbr, int *user_tries);