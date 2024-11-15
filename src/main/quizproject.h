#ifndef QUIZPROJECT_H
#define QUIZPROJECT_H

void play_quizgame(void);
void play_milliongame(void);
void displayWelcomeMessage(void);
void displayGameInstructions(void);
void displayLifelineInstructions(void);
void displayInstructions(void);
void displayGoodLuckMessage(void);
void ask_questions(void);
void ask_hard_questions(void);
void fifty_fifty(int);
void hint(int);
void correct(int);
void wrong(int);
int score = 0;
void printOutOption(char [][100], char [][100],char [], int, int, int[] );
void looping(char [][100], char [][100], char [], int []);
void displayThankYouMessage(void);
int* randomNumber();
void hintForHardQuestions(int);
void feedbackForm(void); 
void displayCredits(void);
void progress_bar(int percentage);
void v_progress_bar(int argc, char *argv[]);
void million_instructions();
void million_exit(int million_a);

//Header Fact or Lie
void v_factorlie(void);
void v_play_factorlie(void);

//Header Guess The Number
void v_guessTheNumber(void);
void v_play_guessTheNumber(void);

//Header Guess The Word 
void v_guessTheWord(char word[], char guessed[]);
void v_play_guessTheWord(void);

//Header Rock Paper Scissors 
void v_play_rockpapersciss(void);

//Header Horoscope Game 
void v_horoscope(int day, int month);
void v_play_horoscope(void);

//Header AllAboutSpace 
void v_allaboutspace(void);
void v_play_allaboutspace(void);

//------Math_quiz_header_begin----- 

void math_choose_question(int);
int math_answer(int);
void math_display_choice();
void math_enter_game();
void e_math_ques(void);
void e_math_print(char [][140], char [][140], char [], char [][100], int []);
void math_instruction(void);
void math_choose_game(void);

//------Math_quiz_header_end-------




//----smart_brain_header_begin-----

//void e_press_key_start(void);
void e_display_instruction(void);
void e_t_f_printQuestions(char [][100],char [], int []);
void e_ask_questions(void);
void e_smart_brain(void);
bool e_true_false(char); 
void e_usr_answr(char [][100], char [], int, int,int []);
void e_questions_r3(void);
void e_printout_r3 (char [][100], char [][100]);
int track_r2_score = 0;
void guess_word_questions(void);
void print_guess_word_question (char [][100], char [][100],char [][100], int []);
void e_printout(char [][100], char [][100], int []);
void e_anagram_questions(void);
void hint_anagram(int);
//----smart_brain_header_end-------

//Epic Game Headers
void B_displayWelcomeMessage(void);
void B_username(void);
void b_entertostart(void);
void B_sayhello(char name[]);
void B_userinfo(void);
void B_displayGameInstructions(void);
void B_show_time(void);
int B_testround(void);
int B_round1(void);
int B_round2(void);
int B_round3(void);
int B_round4(void);
int B_round5(void);
int B_round6(void);
int B_round7(void);
int B_round8(void);
int B_round9(void);
int B_round10(void);
void B_saythankyou(void);
void rate(void);
void B_write_review(void);

//Geography quiz headers
void b_WelcomeMessage();
int b_askQuestion(int questionNumber, char* question, char* answer);
void b_displayResults(int correctAnswers);
void b_play_geography();

//Guess animal Game Headers
void b_guess_animal();

//Basketball Quiz Headers
void b_basketballQuiz();

//Guess Birth Year Headers
void b_guessbirthyear();

//Germany Quiz Headers
void b_germanyquiz();

//Breaking Bad Quiz Headers
void b_BreakingBquiz();

//Crossword Headers
void b_crossword();

//Gambling Game Headers
void b_gamble();

//History Game Headers
void b_historyevents();

//Personality Quiz Headers
void b_personality();
int introverted;
int energetic;
int optimistic;
int empathetic;

//Guess the celebrity headers
void b_celebrity();
char celebrity[20];
char answer;

//Hangman Headers
void b_hangman();

//Football Quiz Headers
void b_football();

//-------brain_whiz_header_begin------------

void for_loop_print_question(char [][140], char [][140], char []);
void math_question2();
void compare_answer(char, char);
void math_introduction();
void math_fact_lie(int);
void math_fact_lie_solutions(int);
void math_fact_lie_print();
void math_quiz_option();
void math_solution(char [][10], int);
void goodbye_message();
void final_score();
int* randomNumber1();
//-------brain_whiz_header_end-------------



#define NUM_QUESTIONS 5
#define NUM_ROUNDS 15
#define MAX_LIVES 10
#define MAX_WORD_LENGTH 20
#define ROCK 1
#define PAPER 2
#define SCISSORS 3
#define MAX_LEN 30
#define MAX_GUESSES 6

#endif
