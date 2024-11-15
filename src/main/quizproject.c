#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include "quizproject.h"

char answers[NUM_QUESTIONS] = {'B', 'A', 'A','B','A'};

int* randomNumber() {
   srand(time(NULL));
   int k = 0, p;
   static int arr[100];
   while(k<100){
       int num =rand()%100;
       for (p = 0; p < k; p++){
           if(arr[p]==num){
               break;
           }
       }
       if(p==k){
           arr[k++]=num;
       }
   }
   return arr;
}

int* randomNumber1() {
   srand(time(NULL));
   int k = 0, p;
   static int arr[32];
   while(k<32){
       int num =rand()%32;
       for (p = 0; p < k; p++){
           if(arr[p]==num){
               break;
           }
       }
       if(p==k){
           arr[k++]=num;
       }
   }
   return arr;
}


//------------Math_quiz_begin------------

void math_instruction(){
    printf("\t\n\n------------------------Instructions-------------------------\n\n");
    printf("\tThere are two Math Quiz Game. The first is Easy-Math and the second is Hard-Math\n");
    printf("\tFor Easy-Math, you can choose a number between 1 and 5 to randomly generate a question.\n");
    printf("\tA wrong answer means, you lose and out of the quiz Game.\n");
    printf("\tIf you choose any other character or number apart from numbers between 1 and 5, you are out of the Game\n");
    printf("\tIn the Hard-Math quiz, You are presented 10 questions\n\n");
    printf("\t\n\n-------------------------------------------------\n\n");
    printf( "\t\n\n !! Wish you all the best !! \n\n " );
    printf("\t......................................................\n" );
    printf( "\n\t  Do you still wish to continue playing ? If yes, then press 1. Else, press 0 :  " );
    int input1;
    scanf("%d", &input1);

    if( input1 == 1 ){
        math_enter_game();
    } else{
     goodbye_message();
    }
}


void math_choose_game() {
    printf("\t\t-------------------------------------------------------\n");
    printf("\t\t          There are Two type of Math quiz\n");
    printf("\t\t          A]. Easy-Math\n");
    printf("\t\t          B]. Hard-Math\n");
    printf("\t\t-------------------------------------------------------\n\n");
    printf("\t\t        Type any key and press enter to exit\n");
    printf("\t\t        Choose either A or B to begin the quiz you want\n");

    char choose;
    scanf(" %c", &choose);
    choose = toupper(choose);
    if (choose == 'A'){
        math_display_choice();
         final_score();
         score = 0;
    } else if(choose == 'B'){
        e_math_ques();
         final_score();
         score = 0;
    } else {
      goodbye_message();
    }

}


void math_choose_question(int num1) {
    char choose [][100] = {
      "what is 1 + 1\n",
      "what is 4 + 3\n",
      "what is 4 * 8\n",
      "what is ((6*8)/4)+2\n",
      "what is 1 + 3\n",
      "what is 5 + 3\n",
      "what is 4 * 10\n",
      "what is ((6*2)/2)+2\n",

      "what is 5-7+12\n", //10
      "what is 4 + 3 * 2\n",//10
      "what is 4 * 8 - 10\n", //22
      "what is ((6*6)/4)+3\n", //12
      "what is 1 + 21\n",//22
      "what is 5 + 75\n",//80
      "what is 4 * 11\n",//44
      "what is 56 * 0\n",// 0

      "what is 1 + 5\n", //6
      "what is 4 + 90\n",//94
      "what is 4 * 4\n",//16
      "what is ((6*4)/4)\n", //6
      "what is 56 + 3\n",//59
      "what is 5 + 5\n",//10
      "what is 4 * 5\n", //20
      "what is ((6*2)/2)+5\n",//11

      "what is 23 + 2\n",//25
      "what is 4 + 23\n",//27
      "what is 3 * 7\n",//21
      "what is ((6*7)/6)\n",//7
      "what is 1 + 85\n",//86
      "what is 5 + 45\n",//50
      "what is 4 * 20\n",//80
      "what is (5/2)*4\n"//10


    };
      int* arr = randomNumber1();
    
    int num2 = arr[num1];
    printf("%s", choose[num2]);
}

int math_answer(int num1) {
    int ans[]= {
        2,
        7,
        32,
        14,
        4,
        8,
        40,
        8,
         10,
        10,
        22,
         12,
        22,
        80,
        44,
        0,
         6,
        94,
        16,
         6,
       59,
        10,
        20,
        11,

        25,
        27,
        21,
        7,
         86,
        50,
        80,
        10
    };
      int* arr = randomNumber1();

    int num2 = arr[num1];
    return ans[num2];
}

void math_display_choice(){
    int user_choice, user_answer,position = 0;
    bool repeat = true;
    printf("Choose a number between 1 and 4(game ends with invalid number or wrong answer): ");
    scanf("%d", &user_choice);
    user_choice = user_choice-1;
    int quiz_answer = math_answer(user_choice);
    while (user_choice != 4 || repeat) {
        quiz_answer = math_answer(user_choice);
    switch(user_choice){
        case 0: case 1: case 2: case 3:
            position++;
            printf("[%d]. ", position);
            math_choose_question(user_choice);
            printf("Answer: ");
            scanf("%d", &user_answer);
            repeat =false;
            break;
        default:
            printf("Invalid choice!\n");
        }    
      
      if(quiz_answer == user_answer){
          score++;
        correct(score);
      } else {
        wrong(score);
       break;
      }
        if (!(repeat)) {
            repeat = true;
            printf("Choose a number between 1 and 4(game ends with invalid number or wrong answer): ");
            scanf("%d", &user_choice);
            user_choice = user_choice-1;
        }             
    
  }

}

void e_math_ques() {
    char e_math[][140] = {
            "What is the value of x if the equation 2x + 3 = 7 is solved for x?",
            "Simplify the expression 4x^2 - 9x + 6.",
            "What is the slope of the line y = 2x + 3?",
            "What is the equation of the line that passes through the points (3,4) and (7,10)?",
            "Simplify the expression 3(2x + 4) - 5",
            "What is the equation of the line that is perpendicular to the line y = 2x + 3 and passes through the point (5,7)?",
            "What is the value of x if the equation x^2 + 4x + 4 = 0 is solved using the quadratic formula?",
            "Simplify the expression 2(x + 3) + 4(x + 2).",
            "What is the equation of the circle with center (3,4) and radius 5?",
            "Solve for x: x + 4 = 10.",
    };

    char e_math_possible[][140] = {
            "[a]. x = 2 [b]. x = 4 [c]. x = 5 [d]. x = 1",
            "[a]. 4x^2 - 4x + 6 [b]. 4x^2 - 3x + 5 [c]. 3x^2 - 3x + 6 [d]. 4x^2 - 3x + 6",
            "[a]. 1 [b]. 2 [c]. 5 [d]. 4",
            "[a].y = 3x - 2. [b]. y = 2x - 1 [c]. y = 3x - 3 [d]. y = 2x - 2",
            "[a]. 3x - 2. [b].  6x + 1 [c].  6x + 7 [d].  2x - 2",
            "[a].y = 0.5x + 8.5 [b]. y = -0.5x + 8.5 [c]. y = 0.5x - 8.5 [d]. y = -0.5x - 8.5",
            "[a].x = -2 or x = -2 [b]. x = -2 or x = 2 [c]. x = 2 or x = 2 [d]. x = -1 or x = -2",
            "[a]. 3x + 2. [b].  6x + 13 [c].  6x + 14 [d].  2x - 2",
            "[a]. (x - 3)^2 + (y - 4)^2 = 2.5 [b].  (x - 2)^2 + (y - 4)^2 = 25 [c].  (x - 3)^2 + (y - 2)^2 = 25 [d].  (x - 3)^2 + (y - 4)^2 = 25",
            "[a]. x = 2 [b]. x = 6 [c]. x = 5 [d]. x = 7",

    };

    char e_math_solution[10] = {
            'A',
            'D',
            'B',
            'D',
            'C',
            'B',
            'A',
            'C',
            'D',
            'B',

    };
    char e_math_statement[][100] = {
            "Solution: x = 2",
            "Solution: 4x^2 - 9x + 6 = 4x^2 - 9x + 6x - 6x + 6 = 4x^2 - 3x + 6",
            "Solution: The slope of the line is 2.",
            "Solution: The equation of the line is y = 2x - 2.",
            "Solution: 3(2x + 4) - 5 = 6x + 12 - 5 = 6x + 7",
            "Solution: The equation of the line is y = -0.5x + 8.5.",
            "Solution: x = -2 or x = -2",
            "Solution: 2(x + 3) + 4(x + 2) = 2x + 6 + 4x + 8 = 6x + 14",
            "Solution: The equation of the circle is (x - 3)^2 + (y - 4)^2 = 25.",
            "Solution: x = 6.",
    };

      int* randArr = randomNumber();
     int arr[10];
        int p = 0;
        for(int i = 0; i < 100; i++){
            if(randArr[i] < 10){
                arr[p] = randArr[i];
                p++;
            }
        }
    e_math_print(e_math, e_math_possible, e_math_solution, e_math_statement, arr);
}

void e_math_print(char e_ques[][140], char e_poss[][140], char e_math_solution[], char e_math_statement[][100], int arr[]){

    int i = 0;

    while(i < 10){
        int arr1 = arr[i];
        printf("[%d]. %s\n", i+1, e_ques[arr1]);
        printf("     %s\n",e_poss[arr1]);
        printf("     Answer: ");
        char user_answer;
        scanf(" %c", &user_answer);
        user_answer = toupper(user_answer);
        if (user_answer == e_math_solution[arr1]) {
            score++;
              correct(score);
        } else {
             wrong(score);
             printf("%s\n\n", e_math_statement[arr1]);
        }
        i++;
    }
}



void math_enter_game() {
    int choice = 0;
    printf("\t\t-------------------------------------------------------\n");
    printf("\t\t          Please press 1 to enter Quiz-game \n ");
    printf("\t\t          Please press 2 to see Instruction\n ");
    printf("\t\t          Please press any key to Exit \n");
    printf("\t\t-------------------------------------------------------\n\n");
    printf("Enter your choice: ");

    scanf("%d", &choice);
    switch (choice){
        // in order to start the game
        case 1:
            math_choose_game();
            break;
        case 2:
            math_instruction();
            break;
        default:
             printf("\t\t-------------------------------------------------------\n");
             printf("\t\t              Sorry to see you go.\n ");
             printf("\t\t-------------------------------------------------------\n\n");
    }

}

//------------Math_quiz_end--------------




//-------smart_brain_quiz_begin----------

void hint_anagram(int hint_num) {
  char hint_questions[][100] = {
            "d_v_l_p_e_t",
            "i_t_r_a_i_nal",
            "p_l__im_ge",
            "o_e__t_on",
            "p_p_la__on",
            "p__g__ss",
            "r__pon__ven__s",
            "char__te___tic",
            "Int__lig__tly",
            "unc__st_t_t_o_al",
            "inco_pr_h_ns__le",
            "env__on__nta__sm",
            "unp__fess__nali__",
            "mu__ic_lt_ra__sm",
            "co__ter__l__ce"
    };
   printf("Here is your hint: %s\n",hint_questions[hint_num]);
}

void e_display_instruction() {
    printf("\t\t-------------------------------------------------------\n");
    printf("\t\t     >>To start this Quiz, here are the instructions<<\n");
    printf("\t\t------------------------------------------------------\n");
    printf("\t\t>>In the first, second Round, you answer True or false questions.<<\n");
    printf("\t\t>>In the third Round, you answer questions which test your General knowledge.<< \n");
    printf("\t\t>>In the fourth Round, you guess the word  by filling in the empty space.<<\n");
    printf("\t\t>>In the fifth Round, you get an anagram and the you have to guess the word.<<\n");
    printf("\t\t-------------------------------------------------------\n\n");
    printf( "\tDo you still wish to continue playing ? If yes, then press 1. Else, press 0 :  " );
}



void e_usr_answr(char question[][100], char ans[], int initial, int end, int randChar[]){
    int i;
    char user_answer;
 for(i = initial; i < end; i++) {
      int rNum = randChar[i];
        printf("[%d]. %s", i + 1, question[rNum]);
                scanf(" %c", &user_answer);
        user_answer = toupper(user_answer);
        while (user_answer != 'T' || user_answer != 'F' ){
            if(user_answer == 'T' || user_answer == 'F') {
                break;
            } else {
                printf("Input is invalid! Enter 'T' for true or 'F' for false [T/F]:\n");
                scanf(" %c", &user_answer);
                user_answer = toupper(user_answer);
            }
        }
        bool ans1 = e_true_false(user_answer);
        if(ans1 == ans[rNum]) {
            score++;
            if(i > 2) {	 
                track_r2_score++;
            }
            
            correct(score);
        } else{
            wrong(score);
        }
    }

}


void e_t_f_printQuestions(char askquestion[][100],char answers[], int charArr[]) {
   int track_rounds = 0;
   while(track_rounds < 1){
    printf("\n\t\t---------------------------Round1-----------------------------\n");
    printf("\t\t   >>In this round you will be presented with 3 questions.<<\n");
    printf("\t\t>>You need to answer 2 questions correctly to move to Round 2<<\n");
    printf("\t\t--------------------------------------------------------------\n\n");
    int init = 0, end = 3;
    e_usr_answr(askquestion,answers, init, end,charArr);

    if(score < 2) {
        break;
    } else {   
    printf("\t\t---------------------------Round2-----------------------------\n");
    printf("\t\t  >>In this round you will be presented with 2 questions.<<\n");
    printf("\t\t>>A false answer to any questions means you lose and out of the Game<<\n");
    printf("\t\t--------------------------------------------------------------\n\n");
    init = 3, end = 5;
    e_usr_answr(askquestion,answers, init, end, charArr);
    }
    track_rounds++;
   }

}

void e_ask_questions(void) {
    char e_t_f_question[][100] = {
            "Mount Everest is the tallest mountain in the world:\n     [T/F]: ",
            "USA has the largest population in the world:\n     [T/F]: ",
            "Russia is the largest country by land size:\n     [T/F]: ",
            "Donald trump is the current president of USA:\n     [T/F]: ",
            "Cheese are made from plants:\n     [T/F]: ",
            "Tomato ist a fruit:\n     [T/F]: ",
            "Men have 2 X chromosomes:\n     [T/F]: "
    };

    char e_t_f_solution[100] = {
            true,
            false,
            true,
            false,
            false,
            true,
            false
    };

         int* randChar = randomNumber();
         int charArr[7];
          int p1 = 0;
         for(int k = 0; k < 100; k++) {
         if (randChar[k] < 7) {
            charArr[p1] = randChar[k];
            p1++;
        }
    }
    e_t_f_printQuestions(e_t_f_question, e_t_f_solution, charArr);
}

bool e_true_false(char choice) {
    if (choice == 'T') {
        return true;
    } else if(choice == 'F') {
        return false;
    } else {
        return -1;
    }
}

void e_questions_r3(void) {

    char questions[][100] ={
            "Which country started WW2?\n",
            "What is the strongest Metal in the world?\n",
            "which holy City do Muslim go on a pilgrimage to? \n"
    };

 char answers [][100] = {
            "germany",
            "tungsten",
            "mecca"
    };

     e_printout_r3 (questions, answers);
}


void e_printout_r3 (char question[][100], char answers[][100]) {
    int i;
    char user_answer[100];
    printf("\t\t---------------------------Round3-----------------------------\n");
    printf("\t\t   >>In this round you will be presented with 3 questions.<<\n");
    printf("\t\t--------------------------------------------------------------\n\n");
    for(i = 0; i < 3; i++) {
        int k = 0;
        printf("[%d]. %s",i+6,question[i]);
        printf("    Your answer: ");
        scanf("%s", user_answer);
        int  num = strlen(user_answer);
        char ans[50];
        for (int j = 0; j < 9; j++) {
            ans[j]  = answers[i][j];
        }

        for (int j = 0; j < strlen(ans); j++) {
            if (ans[j] == tolower(user_answer[j])){
                     k++;
                }
        }
       if (k == strlen(ans) && num == strlen(ans)) {
           score++;
           correct(score);

        } else {
           wrong(score);

       }

    }
}

void guess_word_questions() {
    char guess_words[][100] = {
            "fi__s__d",
            "b__ke_",
            "p__si__",
            "_i__ons__",
            "_vi_e__e",
            "de__l__me__",
            "w___i_e",
            "r___d___e",
            "se_t_em__t",
            "___lia___ta_y",
            "m_n_s__r__s",
            "si__if_ca__e",
            "ch__le_g_"
    };

    char guess_solution [][100] = {
            "nihe",
            "uct",
            "hycs",
            "wscin",
            "ednc",
            "veopnt",
            "ebst",
            "esienc",
            "tlen",
            "parmenr",
            "oateie",
            "gninc",
            "alne"
    };

    char word_guessed[][100] = {
            "finished",
            "bucket",
            "physics",
            "wisconsin",
            "evidence",
            "development",
            "website",
            "residence",
            "settlement",
            "Parliamentary",
            "monasteries",
            "significance",
            "challenge"
    };
    int* randArr0 = randomNumber();
    int arr0[13];
        int p = 0;
        for(int i = 0; i < 100; i++){
            if(randArr0[i] < 13){
                arr0[p] = randArr0[i];
                p++;
            }
        }
    print_guess_word_question (guess_words, guess_solution,word_guessed, arr0);
}


void print_guess_word_question (char guessWord[][100], char guessSolution[][100],char guessedWord[][100], int randArr[]){

    printf("\t\t---------------------------Round4-----------------------------\n\n");
    printf("\t\t      >>You have to  guess what word it is by filling\n");
    printf("                          in the empty space<<\n\n");
    printf("\t\t-------------------------------------------------------------\n\n");


    for (int j = 0; j < 4; j ++) {
         int runNum = randArr[j];
        char usr_ans[100];
        int k = 0;
        printf("[%d]. Guess the word by finding the missing Letters:\n     %s: \n",j+1, guessWord[runNum]);
        printf("     Your answer: ");
        scanf("%s",usr_ans);
        
         char arr[30];	
        for(int p = 0; p < 15; p++) {	
            arr[p] = guessSolution[runNum][p];	
        }	


        for (int i = 0; i < strlen(arr); i++) {	

            if(usr_ans[i] == arr[i]) {	
                k++;	
            }	
        }	

        if (k == strlen(arr)) {
            score++;	
           correct(score);
            printf("You guessed right! The word is rightfully, %s!\n\n", guessedWord[runNum]);	
        } else {	
            wrong(score);
        }

    }
}


void e_printout(char print_out_questn[][100], char questions[][100],int randArr[]) {


    printf("\t\t---------------------------Round5-----------------------------\n\n");
    printf("\t\t      >>You are represented with an Anagram in each question.<<\n");
    printf("                      >>Determine what word it is.<<\n\n");
    printf("\t\t-------------------------------------------------------------\n\n");
       char usr_ans[100];

    for(int i = 0; i < 4; i++) {
      int rNum = randArr[i];
        printf("[%d] Guess the correct word for this anagram: %s\n", i+1, print_out_questn[rNum]);
        printf("Answer(type 'H' to get a hint): ");
        scanf("%s", usr_ans);
         for(int j = 0; j < strlen(usr_ans); j++) {
           if (toupper(usr_ans[j]) == 'H' && strlen(usr_ans) == 1) {
               hint_anagram(rNum);
             printf("Answer: ");
             scanf("%s", usr_ans);
           }
        }
        int p = 0;
        while(p < strlen(usr_ans)) {
           usr_ans[p] = tolower(usr_ans[p]);
          p++;
        }
        int k = 0;
        for (int j = 0; j < strlen(print_out_questn[rNum]); j ++){
            if(usr_ans[j] == questions[rNum][j]) {
                k++;
            }

        }
        if (k == strlen(print_out_questn[rNum]) && strlen(usr_ans) == strlen(print_out_questn[rNum])) {
            score++;
            correct(score);

        } else {
            wrong(score);
            printf("The word is: %s\n", questions[rNum]);
        }
    }
    
}

void e_anagram_questions() {
    char questions[][100] = {
            "development",
            "international",
            "pilgrimage",
            "operation",
            "population",
            "progress",
            "responsiveness",
            "characteristic",
            "Intelligently",
            "unconstitutional",
            "incomprehensible",
            "environmentalism",
            "unprofessionalism",
            "multiculturalism",
            "counterbalance"
    };
 
    char print_questions[100][100];
    int *charNum = randomNumber();
    char arr[100];
    for (int i = 0; i < 15; i++) {
        for(int j = 0; j < 100; j++) {
            arr[j] = questions[i][j];
            if (questions[i][j] == '\0') {
                break;
            }
        }
        //random array to mix letters
        int len = (int)strlen(arr);
        int charArr[len];
        int p = 0;
        for(int l = 0; l < 100; l++) {
            if (charNum[l] < len) {
                charArr[p] = charNum[l];
                p++;
            }
        }
        int randNum, f=0;
        for(int k = 0; k < strlen(arr); k++){
            randNum = charArr[k];
            print_questions[i][f] = arr[randNum];
            f++;
        }
    }
    
      //random geneator for questionmix
     int charArr2[6];
    int p1 = 0;
    for(int l = 0; l < 100; l++) {
        if (charNum[l] < 15) {
            charArr2[p1] = charNum[l];
            p1++;
        }
    }
    
    e_printout(print_questions,questions, charArr2);
}

void final_score(){
    printf("\t\t------------------------------------------\n");
    printf("\t\t         Your final score: %d\n", score);
    printf("\t\t------------------------------------------\n");
}

void e_smart_brain() {
    e_display_instruction();
int input1;
    scanf("%d", &input1);
   if(input1 == 1){
    e_ask_questions();
    if(score >=4 && track_r2_score ==2) {
    e_questions_r3();
    guess_word_questions();
    e_anagram_questions();
    }
    final_score();
    score = 0;
    track_r2_score = 0;
   } else{
       goodbye_message();
   }
}
//-------smart_brain_quiz_end------------

//-------brain_whiz_quiz_begin------------

void math_fact_lie(int question_num) {
  char math_facts_lies [][100] = {
    "The sum of two odd numbers is always even.",
    "The value of pi is equal to exactly 3.14.",
    "The square root of 144 is equal to 12.",
    "The number zero is considered positive.",
    "The number 1 is considered a prime number.",
    "The square root of 9 is 3.",
    "The sum of the angles in a triangle is equal to 180 degrees.",
    "0 is a positive number.",
    "The product of 2 even numbers is always an even number.",
    "The number 1 is a prime number.",
    "Every prime number is odd.",
    "The value of pi (π) is equal to 3.14.",
    "The number 0 is neither positive nor negative.",
    "Every triangle has three sides of equal length.",
    "The sum of the first n positive integers is equal to n(n+1)/2."
  };
  printf("\n%s\n", math_facts_lies[question_num]);
}

void math_fact_lie_solutions(int init) {
   char math_fact_lie_solution [][10] = {
 "fact", "lie", "fact","lie","fact","fact","fact","lie","fact","fact","fact","lie","fact","lie","fact"
};
  math_solution(math_fact_lie_solution,init);
}

void math_solution(char math_solutions[][10], int init1){
           char user_answer[5], fact_answer[5];
           int k = 0;
           scanf("%s", user_answer);    
           for(int j = 0; j < 5; j++){
               fact_answer[j] = math_solutions[init1][j];
           }

           for(int i = 0; i < strlen(fact_answer); i++){
               if (tolower(user_answer[i]) == fact_answer[i]) {
                   k++;
               }
           }

           if(strlen(fact_answer) == k){
               score++;
               correct(score);
           }else {
               wrong(score);
           }  
}

void goodbye_message(){
        printf("\t\t-------------------------------------------------------\n");
        printf("\t\t              Sorry to see you go.\n ");
        printf("\t\t-------------------------------------------------------\n\n");
}

void math_fact_lie_print() {
    printf("\n\t------------------------Instructions-------------------------------\n\n");
    printf("\t\tThis game presents a set of mathematical statements.\n");
    printf("\t\tYou need to determine if each statement is a fact or a lie.\n");
    printf("\t\tChoose the right answer by typing  fact or lie and press enter.\n\n");
    printf("\t-------------------------------------------------------------------\n\n");
    printf( "\t\t           !! Wish you all the best !! \n\n");
    printf("\t     ......................................................\n" );
   
   for(int i = 0; i < 8; i++){
           math_fact_lie(i);
           printf("fact\\lie: ");
           math_fact_lie_solutions(i);
   }

}





void math_question2(){
    char math_question [][140] ={
          "Simplify 5x + 7 - 3x.\n",
          "What is the slope-intercept form of the equation of the line that passes through the points (1,2) and (3,6)?\n",
          "What is the equation of the line that is parallel to the line y = 2x + 3 and passes through the point (4,7)?\n","Solve for x: x^2 + 4x - 21 = 0.\n",
          "Simplify the expression 3x^2 + 5x - 2.\n","What is the equation of the line that passes through the point (1,3) and is perpendicular to the line y = 2x + 1?\n","What is the value of x if the equation 3x - 5 = 12 is solved for x?\n","Simplify the expression 4x + 2(3x + 5).\n", "What is the equation of the line that passes through the point (2,5) and has a slope of 3?\n","Solve for x: 2x + 5 = 11.\n"
    };

    char math_possible_answer[][140] = {
            "[a]. 2x + 7 [b]. x + 5 [c]. 6x + 5 [d]. x + 1",
            "[a]. y = 4x + 0 [b]. 2x + 5 [c]. 2x + 0 [d]. 3x + 6",
            "[a]. y = 2x + 2 [b]. 2x + 1 [c]. 5x + 8 [d]. 4x +6",
            "[a].x = -7 or x = 3 [b]. x = 1 or x = 3 [c]. x = -3 or x = -7 [d]. x = 2 or x = 9",
            "[a]. (3x - 2)(x - 2) [b].  (3x + 2)(x - 2) [c].  (6x - 3)(2x - 2) [d].  (3x - 1)(x + 2)",
            "[a].y = 0.5x + 8.5 [b]. y = -0.5x + 4.5 [c]. y = 0.5x - 8.5 [d]. y = -0.5x - 8.5",
            "[a].x = -2 [b]. x = 2 [c]. x = 7 [d]. x = -1",
            "[a]. 10x + 10. [b].  6x + 13 [c].  3x + 7 [d].  2x - 2",
            "[a]. y = 7x - 1 [b].  y = 3x - 1 [c].  y = 3x + 3 [d].  y = 3x + 1",
            "[a]. x = -2 [b]. x = 3 [c]. x = 5 [d]. x = 11"
    };

        char characters[] = {
        'A',
        'C',
        'B',
        'A',
        'D',
        'B',
        'C',
        'A',
        'D',
        'B'
    };
    for_loop_print_question(math_question, math_possible_answer, characters);

}

void compare_answer(char compare, char character1){
      if (compare == character1) {
          score++;
          correct(score);
       } else {
           wrong(score);
       }

}

void math_introduction(){
    printf("\n\t------------------------Instructions-------------------------------\n\n");
    printf("\t\tThis game present a set of mathematical questions.\n");
    printf("\t\tThere are 4 possible answers(A-D).\n");
    printf("\t\tChoose the right answer by typing the letter and press enter.\n\n");
    printf("\t-------------------------------------------------------------------\n\n");
    printf( "\t\t           !! Wish you all the best !! \n\n");
    printf("\t     ......................................................\n" );
            
}

void for_loop_print_question(char mathQuestions[][140], char mathPossible[][140], char character[]) {
   for (int i = 0; i < 5; i++){
        char user_answer;
       printf("[%d]. %s",i+1, mathQuestions[i]);
       printf("%s\n", mathPossible[i]);
       scanf(" %c", &user_answer);
       user_answer = toupper(user_answer);
       char character0 = character[i];
       compare_answer(user_answer, character0);
   }
}

void math_quiz_option(){
   math_introduction();
 printf( "\n\nDo you still wish to continue playing ? If yes, then press 1. Else, press 0 :  " );
    int input1;
    scanf("%d", &input1);
   if(input1 == 1){
   math_question2();
   math_fact_lie_print(); 
   final_score();
   score = 0;
 } else {
      goodbye_message();
   }
}

//-------brain_whiz_quiz_end--------------


void million_instructions(){
    printf("-------------------INSTRUCTIONS--------------------\n");
    printf("Possible answers are A,B,C & D\n");
    printf("To use Fifty/Fifty Lifeline, Enter F\n");
    printf("To ask a Friend for help, Enter P\n");
    printf("To ask the Host for advice, Enter H\n");
    printf("Two checkpoints exist. You will fall back to them if you passed them before failing a question\n");
    printf("-------------------INSTRUCTIONS--------------------\n");
}

void million_exit(int million_a){
    printf("-------------------THE END OF MILLION GAME--------------------\n");
    printf("\nYou have come to the end of Who Wants To Be A Millionaire\n");
    printf("\nYour Total Reward is %d\n",million_a);
    printf("\nThank You For Playing Who Wants To Be A Millionaire\n");
    printf("-------------------THE END OF MILLION GAME--------------------\n");
}



void displayWelcomeMessage(void) {
     displayGameInstructions();
   }

void displayGoodLuckMessage(void) {
   printf("\t\t------------------------------------------\n\n");
   printf("\t\t------------------------------------------\n\n");
   printf("\t\t              GOOD LUCK!            \n\n");
   printf("\t\t------------------------------------------\n");
   printf("\t\t------------------------------------------\n\n");
}

void displayGameInstructions(void) {
    printf("\t\t------------------------------------------\n");
    printf("\t\t          Welcome to Quiz Game!\n\n");
    printf("\t\t------------------------------------------\n\n");
    printf("\t\t To start this game, here are the Instructions\n\n");
    printf("\t\t------------------------------------------\n");
    printf("\t\t------------------------------------------\n\n");
    printf("\t\t>>You will be presented with questions from\n"); 
    printf("\t\tRound 1 to Round 3(Easy rounds) and Round\n");
    printf("\t\t4 to Round 5(Hard rounds).<<\n");
    printf("\t\t>>For every question you have four options (A, B, C, D).<<\n");
    printf("\t\t>>For each question, you can either choose the\n");
    printf("\t\tanswer from the four options or use a lifeline.<<\n\n");
    printf("\t\t>>To Pass Through Round 1: You have to get 3 out of 5 correct.<<\n");
    printf("\t\t>>To Pass Through Round 2: You have to get 3 out of 5 correct.<<\n");
    printf("\t\t>>To Pass Through Round 3: You have to get 4 out of 5 correct.<<\n");
    printf("\t\t>>To Pass Through Round 4: You have to get 4 out of 5 correct.<<\n");
    printf("\t\t>>To Pass Through Round 5: You have to get 5 out of 5 correct.<<\n\n");
    printf("\t\t>>If you choose the wrong answer, you lose a point.<<\n\n");
    printf("\t\tYou may lose the game if not you don't have enough points to pass to the next round.\n\n");
    printf("\t\tIf you use a lifeline and still choose the wrong answer, you lose the game.\n");
}
void displayLifelineInstructions(void) { 
    printf("\t\t>>You have the following lifelines available:<<          \n");
    printf("\t\t>>'F' 50-50: Eliminates two incorrect answers.<<    \n");
    printf("\t\t>>'H' Hint: Reveals a hint for the answer.<<\n");
}

void displayInstructions(void) { 
    displayWelcomeMessage(); 
    displayLifelineInstructions();
    displayGoodLuckMessage();
}

void correct(int score2){
    printf("\nCorrect!\n");
    printf("You have %d points now\n\n", score);
}
void wrong(int score1){
    printf("\nWrong!\n");
    printf("You have %d points now\n\n", score);
}

void fifty_fifty(int question_num) {
    char qC[][100] = {
            "A.Mount Everest\nB.Uludag",
            "A.USA\nB.China",
            "C.Amazon River\nD.The Nile River",
            "A.San Fransisco\nB.San Diego",
            "C.Merida\nD.Mexico city",
            "C.Russia\nD.USA\n",
            "A.Alaska\nB.Washington",
            "C.Toronto\nD.Ottawa",
            "A.Egypt\nB.Mexico",
            "A.Surat Thani\nB.Bangkok",
            "B.Mexico\nC.USA",
            "C.Venice\nD.Naples",
            "B.Cluny\nC.The Louvre"
    };
    printf("%s\n",qC[question_num]);
}

void hintForHardQuestions(int question_num) {
    char hints[NUM_QUESTIONS][256] = {
            "The city is known for its iconic landmarks and romantic atmosphere.",
            "He was a general in the American Revolutionary War and is considered the Father of His Country.",
            "This team has won the most NBA championships in history, with a total of 16 championships.",
            "It is the lightest and most abundant chemical element in the universe.",
            "This South Korean film became the first non-English language film to win the Academy Award for Best Picture."
    };
    printf("Hint: %s\n", hints[question_num]);
}

void fifty_fifty1(int question_num) {
   char options[NUM_QUESTIONS][4][256] = {
           { "A) Berlin", "B) Paris", "C) London", "D) Rome" },
           { "A) George Washington", "B) John Adams", "C) Thomas Jefferson", "D) James Madison" },
           { "A) Los Angeles Lakers", "B) Chicago Bulls", "C) Golden State Warriors", "D) Boston Celtics" },
           { "A) He", "B) H", "C) O", "D) Ne" },
           { "A) Parasite", "B) Joker", "C) Once Upon a Time in Hollywood", "D) 1917" }
              };
   char correct_answer = answers[question_num]; 
   int num_incorrect = 0;  
   int incorrect_indices[2];  
   for (int i = 0; i < 4; i++) {
       if (options[question_num][i][0] != correct_answer) {
           incorrect_indices[num_incorrect] = i;
           num_incorrect++;
       }
       if (num_incorrect == 2) {
           break;
       }
   }
   for (int i = 0; i < 2; i++) {
       options[question_num][incorrect_indices[i]][0] = '\0';
   }
   // display remaining options
   for (int i = 0; i < 4; i++) {
       if (options[question_num][i][0] != '\0') {
           printf("%s\n", options[question_num][i]);
       }
   }
}

void printOutOption(char qS[][100], char qC[][100],char aS[], int initial, int end, int ranArr[]){
    char response;
        for (int i = initial; i < end; i++){
        int randNum = ranArr[i];
        printf("[%d] %s\n", i+1, qS[randNum]);
        printf("%s\n", qC[randNum]);
       printf("Enter your answer (A, B, C, or D) or use a lifeline (F for 50/50, H for hint): ");
       scanf(" %c", &response);
       response = toupper(response);
       if (response == 'F') {
                       fifty_fifty(randNum);
                       printf("Enter your answer (A, B, C, or D): ");
                       scanf(" %c", &response);
                       response = toupper(response);
                   }
        else if (response == 'H') {
            hint(randNum);
            printf("Enter your answer (A, B, C, or D): ");
            scanf(" %c", &response);
            response = toupper(response);

        }

         if(response == aS[randNum]){
           score++;
          correct(score);
         } else {
           wrong(score);
          }

         
            }
        
}

void looping(char qS[][100], char qC[][100], char aS[], int randArr[]){

int k = 0;
    while(k < 1){
        printf("\t\t--------------------Round 1-------------------\n\n");
        printf(">>In this round you need to answer 3 questions correctly to move to Round 2<<\n\n");
        
         int initial = 0, end = 2;
        printOutOption(qS,qC,aS,initial,end,randArr);

          if (score < 1) {
            printf("You lost! Better luck next time\n");
            break;
        } else {
            printf("\t\t--------------------Round 2-------------------\n\n");
            printf(">>In this round you need to answer 2 questions correctly to move to Round 3<<\n\n");
            
            initial = 2, end = 4;
            printOutOption(qS,qC,aS,initial,end,randArr);
        }

        if (score < 1) {
                printf("You lost! Better luck next time\n");
                break;
            } else {
                printf("\t\t--------------------Round 3-------------------\n\n");
                printf(">>In this round you need to answer 2 questions correctly to move to Round 4<<\n\n");
                
                 initial = 4, end = 7;
                 printOutOption(qS,qC,aS,initial,end,randArr);

            }

        k++;
}
 if (score < 2) {
  printf("\nYour final score: %d\n", score);
}

}

void ask_questions(void) {
    char questions[][100] = { 
            "What is the name of the tallest mountain in the world?\n",
            "Which country has the largest population in the world??\n",
            "What is the name of the longest river in Africa?\n",
            "What American city is the Golden Gate Bridge located in?\n",
            "What is the capital of Mexico?\n",
            "What is the name of the largest country in the world?\n",
            "What U.S. state is home to no documented poisonous snakes?\n",
            "What is the capital of Canada?\n",
            "What country are the Great Pyramids of Giza located in?\n",
            "What is the capital of Thailand?\n",
            "In which country was Frida Kahlo born?\n",
            "What present-day Italian city does Mt. Vesuvius overlook?\n",
            "The Mona Lisa by Leonardo da Vinci is on display in which Paris museum?\n"


    };
    char possible_options[][100] = {
            "A.Mount Everest\nB.Uludag\nC.K2\nD.Makalu",
            "A.USA\nB.China\nC.Russia\nD.India",
            "A.Missisipi River\nB.Yangtze River\nC.Amazon River\nD.The Nile River",
            "A.San Fransisco\nB.San Diego\nC.New York\nD.Los Angeles",
            "A.Oaxaca\nB.Puebla\nC.Merida\nD.Mexico city",
            "A.India\nB.China\nC.Russia\nD.USA",
            "A.Alaska\nB.Washington\nC.Ohio\nD.California",
            "A.Vancouver\nB.Montreal\nC.Toronto\nD.Ottawa",
            "A.Egypt\nB.Mexico\nC.Iceland\nD.Greenland",
            "A.Surat Thani\nB.Bangkok\nC.Phuket\nD.Pattaya City",
            "A.Austria\nB.Mexico\nC.USA\nD.India",
            "A.Milan\nB.Rome\nC.Venice\nD.Naples",
            "A.Carnavalet\nB.Cluny\nC.The Louvre\nD.Musee d'Orsay"

        

    };

    char answers[100] = {
            'A',
            'B',
            'D',
            'A',
            'D',
            'C',
            'A',
            'D',
            'A',
            'B',
            'B',
            'D',
            'C'

    };

     int* randArr = randomNumber();
     int arr[11];
        int p = 0;
        for(int i = 0; i < 100; i++){
            if(randArr[i] < 11){
                arr[p] = randArr[i];
                p++;
            }
        }
     looping(questions, possible_options, answers, arr);

    
}

void ask_hard_questions(void) {


    int k = 0;
    while (k < 1) {
           
           int *lessFive = randomNumber();
           int arr[5];
           int p = 0;
                for(int i = 0; i < 100; i++){
                    if(lessFive[i] < 5){
                        arr[p] = lessFive[i];
                        p++;
                    }
                }
                
            printf("\t\t--------------------Round 4-------------------\n\n");
            printf(">>In this round you need to answer 2 questions correctly to move to Round 5<<\n\n");


            char questions[NUM_QUESTIONS][256] = {
                    "What is the capital of France?",
                    "Who was the first president of the United States?",
                    "Which team won the most NBA championships?",
                    "What is the chemical symbol for hydrogen?",
                    "Which of the following movies won the Academy Award for Best Picture in 2020?"
            };
            char options[NUM_QUESTIONS][4][256] = {
                    { "A) Berlin", "B) Paris", "C) London", "D) Rome" },
                    { "A) George Washington", "B) John Adams", "C) Thomas Jefferson", "D) James Madison" },
                    { "A) Los Angeles Lakers", "B) Chicago Bulls", "C) Golden State Warriors", "D) Boston Celtics" },
                    { "A) He", "B) H", "C) O", "D) Ne"},
                    { "A) Parasite", "B) Joker", "C) Once Upon a Time in Hollywood", "D) 1917" }
                    };

            char user_answers[NUM_QUESTIONS]; 
            int lifelines[NUM_QUESTIONS] = { 1, 1,1,1,1};
            int randNum;
            for (int i = 0; i < 3; i++) {
                  randNum = arr[i];    
                printf("[%d] %s\n", i + 1, questions[randNum]);
                for (int j = 0; j < 4; j++) {
                    printf("%s\n", options[randNum][j]);
                }
                printf("Enter your answer (A, B, C, or D) or use a lifeline (F for 50/50, H for hint): ");
                char response;
                scanf(" %c", &response);
                response = toupper(response);
                if (response == 'F' && lifelines[i] == 1) {
                   fifty_fifty1(randNum);
                   printf("Enter your answer (A, B, C, or D): ");
                   scanf(" %c", &user_answers[randNum]);
                   user_answers[randNum] = toupper(user_answers[randNum]);
                   lifelines[i] = 0;
               }else if (response == 'H' && lifelines[i] == 1) {
                    hintForHardQuestions(randNum);
                    printf("Enter your answer (A, B, C, or D): ");
                    scanf(" %c", &user_answers[randNum]);
                    user_answers[randNum] = toupper(user_answers[randNum]);
                    lifelines[i] = 0;
                }else {
                   user_answers[randNum] = response;
               }
                if (user_answers[randNum] == answers[randNum]) {
                    score++;
                    correct(score);
                } else {
                    wrong(score);
                }
            }
              if ( score < 4) {
                printf("You lost! Better luck next time\n");
                break;
            } else {
                printf("\t\t--------------------Round 5-------------------\n\n");
                printf(">>This is the final round. Good Luck!<<\n\n");
                for (int i = 3; i < 5; i++) {

                randNum = arr[i];
                printf("[%d] %s\n", i + 1, questions[randNum]);
                for (int j = 0; j < 4; j++) {
                    printf("%s\n", options[randNum][j]);
                }
                printf("Enter your answer (A, B, C, or D) or use a lifeline (F for 50/50, H for hint): ");
                char response;
                scanf(" %c", &response);
                response = toupper(response);
                if (response == 'F' && lifelines[i] == 1) {
                   fifty_fifty1(randNum);
                   printf("Enter your answer (A, B, C, or D): ");
                   scanf(" %c", &user_answers[randNum]);
                   user_answers[randNum] = toupper(user_answers[randNum]);
                   lifelines[i] = 0;
               }else if (response == 'H' && lifelines[i] == 1) {
                   hintForHardQuestions(randNum);
                    printf("Enter your answer (A, B, C, or D): ");
                    scanf(" %c", &user_answers[randNum]);
                    user_answers[randNum] = toupper(user_answers[randNum]);
                    lifelines[i] = 0;
                }else {
                   user_answers[randNum] = response;
               }
                // check each answer
                if (user_answers[randNum] == answers[randNum]) {
                    score++;
                    correct(score);
                } else {
                    wrong(score);
                }
            }
            }  
        k++;
    }
    printf("\nYour final score: %d\n", score);
}


void hint(int question_num) {
    char qC[][100] = {
            "Hint:The Tallest mountain is 8,849m.",
            "Hint:It's population is 1.412 billion.",
            "Hint:The longest river measures 6,650km.",
            "Hint:The Golden States Warriors play there.\n",
            "Hint:It is one of the oldest and largest cities in the Americas.\n",
            "Hint:The area of the largest country is 17.1 million km2.\n",
            "Hint:It is the coldest state in the US.",
            "Hint:It is the 4th largest city in Canada.",
            "Hint:It is a dry Country.",
            "Hint:The capital has the longest city name in the world.",
            "Hint:The Native language is Spanish.",
            "Hint:The city that invented Swamp Buggy Racing.",
            "Hint:It is the most visited art museum in the world."

    };
    printf("%s\n",qC[question_num]);
}

void displayThankYouMessage(void) { 
    printf("*******************************\n");
    printf("Thank you for playing QuizGame!\n");
    printf("*******************************\n\n");
}

void play_quizgame(void){
     displayInstructions();

    printf(">>Press 's' and Enter to start the Game<<\n");
        char var, var1 = 's';
        getchar();
        while(var != var1) {
        var = getchar();
        }
   printf("\n");
ask_questions();
if (score > 2){
    ask_hard_questions();
}
displayThankYouMessage();
}

void v_factorlie(void){
    char statements[][100] = {
            "Tomatoes are fruits.", // fact
            "The Great Wall of China is visible from space.", // lie
            "Water freezes at 0 degrees Celsius.", // fact
            "Napoleon Bonaparte ruled Germany at a time in history.", // fact
            "Barack Obama was born in America.", // lie
            "Hamburg is a city in the state of Niedersachsen." // lie

    };
    char answers[] = {'F','L','F','F','L','L'}; // L for lie, F for fact
    int num_statements = sizeof(statements) / sizeof(statements[0]);
    int score = 0;

    printf("\nWelcome to the Fact or Lie Quiz!\n\n");
    for (int i = 0; i < num_statements; i++) {
        char user_answer;
        printf("Statement %d: %s\n\n", i + 1, statements[i]);
        printf("Is this statement a fact (F) or a lie (L)?\n");
        printf("Your answer: \n");
        scanf(" %c", &user_answer);
        user_answer = toupper(user_answer);
        if (user_answer == answers[i]) {
            score++;
            printf("Correct! You get a point.\n\n");
        } else {
            printf("Sorry, its incorrect. No points!\n\n");
        }
    }
    printf("Your final score is %d out of %d.\n", score, num_statements);

}

void v_play_factorlie() {
    printf("**********************\n");
    printf("Playing Fact or Lie!\n");
    printf("**********************\n");
    v_factorlie();
    printf("**********************************\n");
    printf("Thank you for playing Fact or Lie!\n");
    printf("**********************************\n");
}

void play_milliongame() {
    printf("\nPlaying who wants to be a millionaire...\n\n");

    int million_i = 0, million_k = 0, million_checkpoint = 0, million_reward = 0, million_count_replace = 0;
    int million_stay_in_game = 0, million_lifeline_friend = 1, million_lifeline_delete = 1, million_lifeline_host = 1;
    char million_std_answers[NUM_ROUNDS] = {'A', 'C', 'D', 'C', 'B', 'D', 'B', 'A', 'B', 'B', 'A', 'D', 'C', 'C', 'B'} , million_user_answers[NUM_ROUNDS];

    char questions[NUM_ROUNDS][256] = {
            "What is the capital of Germany?",
            "Which Disney character famously leaves a glass slipper behind at a royal ball?",
            "What name is given to the revolving belt machinery in an airport that delivers checked luggage from the plane to baggage reclaim?",
            "Which of these brands was chiefly associated with the manufacture of household locks?",
            "The hammer and sickle is one of the most recognisable symbols of which political ideology?",
            "Which toys have been marketed with the phrase “robots in disguise”?",
            "What does the word loquacious mean?",
            "Obstetrics is a branch of medicine particularly concerned with what?",
            "In Doctor Who, what was the signature look of the fourth Doctor, as portrayed by Tom Baker?",
            "Which of these religious observances lasts for the shortest period of time during the calendar year?",
            "At the closest point, which island group is only 50 miles south-east of the coast of Florida?",
            "Construction of which of these famous landmarks was completed first?",
            "Which of these cetaceans is classified as a “toothed whale”?",
            "Who is the only British politician to have held all four “Great Offices of State” at some point during their career?",
            "In 1718, which pirate died in battle off the coast of what is now North Carolina?"
    };
    char answers[NUM_ROUNDS][4][256] = {
            { "A) Berlin", "B) Paris", "C) London", "D) Rome" },
            { "A) Pocahontas", "B) Sleeping Beauty", "C) Cinderella", "D) Elsa" },
            { "A) Hangar", "B) Terminal", "C) Concourse", "D) Carousel" },
            { "A) Phillips", "B) Flymo", "C) Chubb", "D) Ronseal" },
            { "A) Republicanism", "B) Communism", "C) Conservatism", "D) Liberalism" },
            { "A) Bratz Dolls", "B) Sylvanian Families", "C) Hatchimals", "D) Transformers" },
            { "A) Angry", "B) Chatty", "C) Beautiful", "D) Shy" },
            { "A) Childbirth", "B) Broken bones", "C) Heart conditions", "D) Old age" },
            { "A) Bow-tie, braces and tweed jacket", "B) Wide-brimmed hat and extra long scarf", "C) Pinstripe suit and trainers", "D) Cape, velvet jacket and frilly shirt" },
            { "A) Ramadan", "B) Diwali", "C) Lent", "D) Hanukkah" },
            { "A) Bahamas", "B) US Virgin Islands", "C) Turks and Caicos Islands", "D) Bermuda" },
            { "A) Empire State Building", "B) Royal Albert Hall", "C) Eiffel Tower", "D) Big Ben Clock Tower" },
            { "A) Gray whale", "B) Minke whale", "C) Sperm whale", "D) Humpback whale" },
            { "A) David Lloyd George", "B) Harold Wilson", "C) James Callaghan", "D) John Major" },
            { "A) Calico Jack", "B) Blackbeard", "C) Bartholomew Roberts", "D) Captain Kidd" }
    };

    million_instructions();

    while(million_i < NUM_ROUNDS && million_stay_in_game == 0){
        printf("--------------------------------------------------------");
        printf("\nYou have %d:Fifty/Fifty\t%d:Phone a Friend\t%d:Hint\t\n",million_lifeline_delete,million_lifeline_friend,million_lifeline_host);

        printf("\n%d. %s\n\n",million_i+1,questions[million_i]);
        for(int j=0;j<4;j++){
            printf("%s\n",answers[million_i][j]);
        }

        point_one:

        printf("Enter a valid Response: ");
        scanf(" %c", &million_user_answers[million_i]);
        million_user_answers[million_i] = toupper(million_user_answers[million_i]);
        
        switch(million_user_answers[million_i]){
                case 'A':
                    if(million_user_answers[million_i] == million_std_answers[million_i]){
                        printf("\nCorrect!");
                        million_reward = million_reward + (10000 * (million_i+1));
                        printf("\n%d\n",million_reward);

                        if(million_i == 0){
                        million_checkpoint = 0;
                        }
                        else if(million_i == 4){
                        printf("--------CHECKPOINT ONE---------\n");
                        million_checkpoint = million_reward;
                        }
                        else if(million_i == 9){
                                printf("--------CHECKPOINT TWO---------\n");
                                million_checkpoint = million_reward;
                        }
                        else{}

                    }
                    else{
                        printf("\nIncorrect!\n");
                        million_stay_in_game = 1;
                    }
                    break;
                case 'B':
                    if(million_user_answers[million_i] == million_std_answers[million_i]){
                        million_reward = million_reward + (10000 * (million_i+1));
                        printf("\n%d\n",million_reward);
                        printf("\nCorrect!");

                        if(million_i == 0){
                        million_checkpoint = 0;
                        }
                        else if(million_i == 4){
                        printf("--------CHECKPOINT ONE---------\n");
                        million_checkpoint = million_reward;
                        }
                        else if(million_i == 9){
                                printf("--------CHECKPOINT TWO---------\n");
                                million_checkpoint = million_reward;
                        }
                        else{}

                    }
                    else{
                        printf("\nIncorrect!\n");
                        million_stay_in_game = 1;
                    }
                    break;
                case 'C':
                    if(million_user_answers[million_i] == million_std_answers[million_i]){
                        million_reward = million_reward + (10000 * (million_i+1));
                        printf("\n%d\n",million_reward);
                        printf("\nCorrect!");

                        if(million_i == 0){
                        million_checkpoint = 0;
                        }
                        else if(million_i == 4){
                        printf("--------CHECKPOINT ONE---------\n");
                        million_checkpoint = million_reward;
                        }
                        else if(million_i == 9){
                                printf("--------CHECKPOINT TWO---------\n");
                                million_checkpoint = million_reward;
                        }
                        else{}

                    }
                    else{
                        printf("\nIncorrect!\n");
                        million_stay_in_game = 1;
                    }
                    break;
                case 'D':
                    if(million_user_answers[million_i] == million_std_answers[million_i]){
                        million_reward = million_reward + (10000 * (million_i+1));
                        printf("\n%d\n",million_reward);
                        printf("\nCorrect!");

                        if(million_i == 0){
                        million_checkpoint = 0;
                        }
                        else if(million_i == 4){
                        printf("--------CHECKPOINT ONE---------\n");
                        million_checkpoint = million_reward;
                        }
                        else if(million_i == 9){
                                printf("--------CHECKPOINT TWO---------\n");
                                million_checkpoint = million_reward;
                        }
                        else{}
                    }
                    else{
                        printf("\nIncorrect!\n");
                        million_stay_in_game = 1;
                    }
                    break;
                case 'H':
                    if(million_lifeline_host != 1){
                        printf("\nHost lifeline already used\n");
                        goto point_one;
                    } else {
                        million_lifeline_host = 0;
                        printf("\n-----------HOST LIFELINE------------");
                        printf("\nYou can now ask the Host for help\n");
                        goto point_one;
                    }
                    break;
                case 'F':
                    if(million_lifeline_delete != 1){
                        printf("\nFifty/Fifty lifeline already used\n");
                        goto point_one;
                    }
                    else {
                            million_lifeline_delete = 0;
                            printf("\n-----------FIFTY/FIFTY LIFELINE------------");
                            printf("\nComputer will now MARK two wrong answers...\n");

                            while(million_k < 4 && million_count_replace < 2){
                                if(answers[million_i][million_k][0] != million_std_answers[million_i]){
                                answers[million_i][million_k][0] = 'X';
                                million_count_replace = million_count_replace + 1;
                                }
                                million_k++;
                            }
                            for(int million_n = 0; million_n < 4; million_n++){
                                printf("%s\n",answers[million_i][million_n]);
                            }
                            goto point_one;
                    }
                    break;
                case 'P':
                    if(million_lifeline_friend != 1){
                            printf("\nLifeline Friend already used\n");
                            goto point_one;
                        }
                        else{
                            million_lifeline_friend = 0;
                            printf("\n-----------FRIEND LIFELINE------------");
                            printf("\nYou can now ask a friend for help...\n");
                            for(int j=0;j<4;j++){
                                printf("%s\n",answers[million_i][j]);
                            }
                                goto point_one;
                        }
                    break;
                    case 'T':
                        million_stay_in_game = 1;
                    break;
                default:
                    goto point_one;
        }
        
        million_i++;
    }
    million_exit(million_checkpoint);
    // code for game 3 goes here
}

void v_guessTheNumber(void){
    int secret_number, guess;
    srand(time(NULL));
    secret_number = rand() % 100 + 1;
    printf("Guess the Number!\n\n");
    printf("I am thinking of a number between 1 and 100. Can you guess what it is?\n");
    while (1) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        if (guess > secret_number) {
            printf("Too high! Try again.\n");
        } else if (guess < secret_number) {
            printf("Too low! Try again.\n");
        } else {
            printf("Congratulations, you found the secret number!\n");
            break;
        }
    }
}

void v_play_guessTheNumber() {
    printf("*************************\n");
    printf("Playing Guess the Number!\n");
    printf("*************************\n\n");
    v_guessTheNumber();
    printf("****************************************\n");
    printf("Thank you for playing Guess the Number!\n");
    printf("****************************************\n");
}

void v_guessTheWord(char word[], char guessed[]) {
    int i;
    for (i = 0; i < strlen(word); i++) {
        if (guessed[i]) {
            printf("%c ", word[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

void v_play_guessTheWord() {
    char word[] = "Fulda";
    char guessed[MAX_WORD_LENGTH] = {0};
    int lives = MAX_LIVES;
    int word_length = strlen(word);
    char guess;
    guess = toupper(guess);

    printf("***********************\n");
    printf("Playing Guess the Word!\n");
    printf("***********************\n\n");

    printf("IMPORTANT: The first letter is a capital letter!\n\n");

    while (lives > 0) {
        int i;
        int correct = 0;

        printf("Lives: %d\n", lives);
        v_guessTheWord(word, guessed);
        printf("Guess a letter: ");
        scanf(" %c", &guess);


        for (i = 0; i < word_length; i++) {
            if (word[i] == guess) {
                guessed[i] = guess;
                correct = 1;
            }
        }

        if (!correct) {
            lives--;
        }

        if (strcmp(word, guessed) == 0) {
            printf("You win! The word was: %s\n\n", word);
            printf("*************************************\n");
            printf("Thank you for playing Guess the Word!\n");
            printf("*************************************\n");
            break;
        }
    }

    if (lives == 0) {
        printf("You lose! The word was: %s\n\n", word);
        printf("*************************************\n");
        printf("Thank you for playing Guess the Word!\n");
        printf("*************************************\n");
    }

}



void B_show_time(void) {
    time_t current_time;
    struct tm *time_info;
    char time_string[9];

    time(&current_time);
    time_info = localtime(&current_time);

    strftime(time_string, sizeof(time_string), "%H:%M", time_info);
    printf("The current time is: %s\n\n", time_string);
}

void B_displayWelcomeMessage(void) {
    printf("\t\t------------------------------------------\n\n");
    printf("\t\t------------------------------------------\n\n");
    printf("\t\t        Welcome to The EPIC GAME           \n\n");
    printf("\t\t------------------------------------------\n");
    printf("\t\t------------------------------------------\n\n");
}

void B_sayhello(char name[]){
    printf(".                       Hello %s         \n\n", name);
}

void B_username(void) {
    char name[100] = {0};
    printf("Please create a fun Username\n\n");
    scanf("%s", name);
    B_sayhello(name);
}

void b_entertostart() {
    char enter;
    printf("\t\t          Press 'any key' to begin   \n");
    scanf(" %c", &enter);
    enter = toupper(enter);
}

void B_userinfo(void){
    char info[100] = {0};
    printf("How old are you?\n");
    scanf("%s", info);
    printf("\t\t                 You are old enough!!!\n\n");
}

void B_displayGameInstructions() {
    printf("To start this game, here are the instructions:\n\n # Read each question carefully and select the best answer from the choices provided.\n # You will receive points and prizes for each correct answer, and the game will keep track of your progress.\n # At the end of the game, you will be shown your final score and will have the option to play again.\n # Have fun and good luck!\n\n\n");
}

int B_testround(void) {
    int score = 0;
    char answer[20];

    printf("Play a Test Round!\n\n");
    printf("The points you get in this round will be added to the other rounds.\n\n");
    printf("Question 1: What is the capital of Spain?\n\n");
    printf("Hint: It is located in the center of the country.\n\n");
    printf("Options: a.)Madrid b.)Barcelona c.)Valencia d.)Granada\n\n ");
    printf("Answer: ");
    scanf("%s", answer);

    if (strcmp(answer, "a") == 0) {
        printf("Correct!\n\n");
        score++;
    } else {
        printf("Incorrect. The answer is a.\n\n");
    }

    printf("Question 2: What is the smallest planet in our solar system?\n\n");
    printf("Hint: It is named after the messenger of the gods.\n\n");
    printf("Options: a.)Earth b.)Mars c.)Mercury d.)Sun\n\n");
    printf("Answer: ");
    scanf("%s", answer);

    if (strcmp(answer, "c") == 0) {
        printf("Correct!\n\n");
        score++;
    } else {
        printf("Incorrect. The answer is c.\n\n");
    }
    return score;
}

int B_round1(void) {
    int score = 0;
    char answer[20];

    printf("Round 1 - Math\n\n");
    printf("Question 1: What is the value of x in the equation 2x + 1 = 7?\n\n");
    printf("Hint: Subtract 1 from both sides and then divide both sides by 2.\n\n");
    printf("Options: 6, 1, 3, 4\n\n");
    printf("Answer: ");
    scanf("%s", answer);

    if (strcmp(answer, "3") == 0) {
        printf("Correct! You won a diamond.\n\n");
         int i, j, k;
        for (i = 0; i < 5; i++)
        {
            for (j = 5 - i; j > 1; j--)
            {
                printf(" ");
            }
            for (k = 0; k <= (2 * i); k++)
            {
                printf("*");
            }
            printf("\n");
        }
        for (i = 4; i >= 0; i--)
        {
            for (j = 5 - i; j > 1; j--)
            {
                printf(" ");
            }
            for (k = 0; k <= (2 * i); k++)
            {
                printf("*");
            }
            printf("\n");
        }
        score++;
    } else {
        printf("Incorrect. The answer is 3.\n\n");
    }

    printf("Question 2: What is the value of x in the equation 3x + 2 = 8?\n\n");
    printf("Hint: Subtract 2 from both sides and then divide both sides by 3.\n\n");
    printf("Options: 1, 2, 3, 4\n\n");
    printf("Answer: ");
    scanf("%s", answer);

    if (strcmp(answer, "2") == 0) {
        printf("Correct! You won a triangle.\n\n");
        int i, j;
        for (i = 0; i < 5; i++) {
            for (j = 0; j <= i; j++) {
                printf("*");
            }
            printf("\n");
        }
        score++;
    } else {
        printf("Incorrect. The answer is 2.\n\n");
    }
    return score;
}

int B_round2(void) {
    int score = 0;
    char answer[20];

    printf("Round 2 - True or False\n\n");
    printf("Question 1: The sun rises in the west.\n\n");
    printf("Hint:Think about the Earth's rotation on its axis towards the east.\n\n");
    printf("Options: Ture, False\n\n");
    printf("Answer: ");
    scanf("%s", answer);

    if (strcmp(answer, "False") == 0) {
        printf("Correct! You won a star.\n\n");
        int i, j, k;
        for (i = -4; i <= 4; i++) {
            for (j = 4; j >= abs(i); j--) {
                printf(" ");
            }
            for (k = 1; k <= abs(2 * i + 1); k++) {
                if (abs(i) == 4 || k == 1 || k == abs(2 * i + 1)) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
        score++;
    } else {
        printf("Incorrect. The answer is False.\n\n");
    }

    printf("Question 2: The capital city of France is known as the 'City of Love'.\n\n");
    printf("Hint: It is one of the most popular cities in the world.\n\n");
    printf("Options: True, False\n\n");
    printf("Answer: ");
    scanf("%s", answer);

    if (strcmp(answer, "True") == 0) {
        printf("Correct! You won a Sword.\n\n");
        printf("     /\\\n");
        printf("    /  \\\n");
        printf("   /    \\\n");
        printf("  /      \\\n");
        printf(" /________\\\n");
        printf("     |     \n");
        printf("     |     \n");
        printf("     |     \n");
        printf("     |     \n");
        printf("     |   \n");
        score++;
    } else {
        printf("Incorrect. The answer is True.\n\n");
    }
    return score;
}

int B_round3(void) {
    int score = 0;
    char answer[20];

    printf("Round 3\n\n");
    printf("Question 1: How many planets are in our solar system?\n\n");
    printf("Hint: Mercury, Venus, Earth, Mars, Jupiter, Saturn, Uranus, and Neptune.\n\n");
    printf("Options: 5, 6, 7, 8\n\n");
    printf("Answer: ");
    scanf("%s", answer);

    if (strcmp(answer, "8") == 0) {
        printf("Correct! You won a triangle.\n\n");
        int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
        score++;
    } else {
        printf("Incorrect. The answer is 8.\n\n");
    }

    printf("Question 2: How many bones are there in the human body?\n\n");
    printf("Hint: This number may vary in childhood due to some bones merging together as the body grows and develops.\n\n");
    printf("Options: 206, 205, 207, 204\n\n");
    printf("Answer: ");
    scanf("%s", answer);

    if (strcmp(answer, "206") == 0) {
        printf("Correct! You won a cat.\n\n");
        printf(" /\\_/\\\n( o.o )\n > ^ < \n");
        score++;
    } else {
        printf("Incorrect. The answer is 206.\n\n");
    }
    return score;
}

int B_round4(void) {
    int score = 0;
    char answer[20];
    printf("Round 4\n\n");
    printf("Question 1: What is the capital of France?\n\n");
    printf("Hint: It is known as the City of Light.\n\n");
    printf("Options: Paris, London, Madrid, Berlin\n\n");
    printf("Answer: ");
    scanf("%s", answer);
    
    if (strcmp(answer, "Paris") == 0) {
        printf("Correct! You won a Cow.\n\n");
        printf("        \\   ^__^\n         \\  (oo)\\_______\n            (__)\\       )\\/\\\n                ||----w |\n                ||     ||\n");
    
        score++;
    } else {
        printf("Incorrect. The answer is Paris.\n\n");
    }
    
    printf("Question 2: Who painted the Mona Lisa?\n\n");
    printf("Hint: He was a famous Italian artist.\n\n");
    printf("Options: a.)Leonardo da Vinci b.)Michelangelo c.)Raphael d.)Titian\n\n");
    printf("Answer: ");
    scanf("%s", answer);
    
    if (strcmp(answer, "a") == 0) {
        printf("Correct! You won a stick man.\n\n");
        printf("     o\n    \\|/\n    / \\\n");
        score++;
    } else {
        printf("Incorrect. The answer is a.\n\n");
    }
    return score;
}

int B_round5(void) {
    int score = 0;
    char answer[20];
    printf("Round 5\n\n");
    printf("Question 1: Who invented the World Wide Web?\n\n");
    printf("Hint: He is a British computer scientist.\n\n");
    printf("Options: a.)Bill Gates, b.)Steve Jobs, c.)Tim Berners-Lee, d.)Mark Zuckerberg\n\n");
    printf("Answer: ");
    scanf("%s", answer);
    
    if (strcmp(answer, "c") == 0) {
        printf("Correct! You won a diamond.\n\n");
        printf("    /\\\n   (  )\n  (    )\n   (  )\n    \\/\n");
        score++;
    } else {
        printf("Incorrect. The answer is c.\n\n");
    }
    
    printf("Question 2: Who was the first person to walk on the Moon?\n\n");
    printf("Hint: He was an American astronaut.\n\n");
    printf("Options: a.)Neil Armstrong b.)Buzz Aldrin c.)Michael Collins d.)Pete Conrad\n\n");
    printf("Answer: ");
    scanf("%s", answer);
    
    if (strcmp(answer, "a") == 0) {
        printf("Correct! You won a sitting stick man.\n\n");
        printf("  (o)\n /(  )\\\n(   )(   )\n");
        score++;
    } else {
        printf("Incorrect. The answer is a.\n\n");
    }
    return score;
}

int B_round6(void) {
int score = 0;
char answer[20];

printf("Round 6\n\n");
printf("Question 1: Who wrote the novel 'To Kill a Mockingbird'?\n\n");
printf("Hint: She is known as an American novelist.\n\n");
printf("Options: a.)Jane Austen, b.)Agatha Christie, c.)Harper Lee, d.)Mary Shelley\n\n");
printf("Answer: ");
scanf("%s", answer);

if (strcmp(answer, "c") == 0) {
    printf("Correct! You won a turtle shell.\n\n");
    printf("    ___\n  //   \\\\\n((      ))\n  \\    //\n   ----\n");
    score++;
} else {
    printf("Incorrect. The answer is c.\n\n");
}

printf("Question 2: Who painted the famous artwork 'The Starry Night'?\n\n");
printf("Hint: He was a post-Impressionist painter.\n\n");
printf("Options: a.)Vincent van Gogh b.)Pablo Picasso c.)Leonardo da Vinci d.)Rembrandt\n\n");
printf("Answer: ");
scanf("%s", answer);

if (strcmp(answer, "a") == 0) {
    printf("Correct! you won a dog.\n\n");
    printf(" /\\_/\\\n( o.o )\n > ^ < \n");
    score++;
} else {
    printf("Incorrect. The answer is a.\n\n");
}
return score;
}

int B_round7(void) {
int score = 0;
char answer[20];

printf("Round 7\n\n");
printf("Question 1: Who directed the movie 'The Shawshank Redemption'?\n\n");
printf("Hint: He is known for his work in Hollywood.\n\n");
printf("Options: a.)Martin Scorsese b.)Francis Ford Coppola c.)Steven Spielberg d.)Frank Darabont\n\n");
printf("Answer: ");
scanf("%s", answer);

if (strcmp(answer, "d") == 0) {
    printf("Correct! You won a house.\n\n");
     printf("    _____\n");
    printf("   /     \\\n");
    printf("  /_______\\\n");
    printf("  |[ ] [ ]|\n");
    printf("  |   =   |\n");
    score++;
} else {
    printf("Incorrect. The answer is d.\n\n");
}

printf("Question 2: Who invented the telephone?\n\n");
printf("Hint: He was a Scottish-born American inventor.\n\n");
printf("Options: a.)Alexander Graham Bell, b.)Thomas Edison, c.)Nikola Tesla, d.)Gutenberg\n\n");
printf("Answer: ");
scanf("%s", answer);

if (strcmp(answer, "a") == 0) {
    printf("Correct! You won a tree.\n\n");
    printf("      *\n");
    printf("     ***\n");
    printf("    *****\n");
    printf("   *******\n");
    printf("  *********\n");
    printf(" ***********\n");
    printf("    *****\n");
    printf("    *****\n");
    printf("    *****\n");
    score++;
} else {
    printf("Incorrect. The answer is a.\n\n");
}
return score;
}

int B_round8(void) {
int score = 0;
char answer[20];

printf("Round 8\n\n");
printf("Question 1: Who played the lead role in the movie 'The Godfather'?\n\n");
printf("Hint: He is a legendary Hollywood actor.\n\n");
printf("Options: a.)Marlon Brando, b.)Robert De Niro, c.)Al Pacino, d.)Jack Nicholson\n\n");
printf("Answer: ");
scanf("%s", answer);

if (strcmp(answer, "a") == 0) {
    printf("Correct! You won an Emerald.\n\n");
        printf("   /\\\n  /  \\   /\\\n /    \\ /  \\ \n/      \\    \\ \n\\      /    / \n \\    /  \\ / \n  \\  /\\\n   \\/\n");

    score++;
} else {
    printf("Incorrect. The answer is a.\n\n");
}

printf("Question 2: Who wrote the play 'Hamlet'?\n\n");
printf("Hint: He was an English playwright and poet.\n\n");
printf("Options: a.)William Shakespeare b.)Christopher Marlowe c.)Ben Jonson d.)John Milton\n\n");
printf("Answer: ");
scanf("%s", answer);

if (strcmp(answer, "a") == 0) {
    printf("Correct! You won a bird.\n\n");
    printf(" /\\_/\\\n( o.o )\n > ^ < \n");
    score++;
} else {
    printf("Incorrect. The answer is a.\n\n");
}
return score;
}

int B_round9(void) {
int score = 0;
char answer[20];
    
printf("Round 9\n\n");
printf("Question 1: The median is the value separating the higher half from the lower half of a data set.\n\n");
printf("Hint: It is commonly used to represent the center of a dataset.\n\n");
printf("Options: True, False\n\n");
printf("Answer: ");
scanf("%s", answer);

if (strcmp(answer, "True") == 0) {
    printf("Correct! You won a computer.\n\n");
    printf(" ________________\n");
    printf("|                |\n");
    printf("|                |\n");
    printf("|                |\n");
    printf("|                |\n");
    printf("|________________|\n");
    printf("   __________\n");
    printf("  | ________ |\n");
    printf("  | |      | |\n");
    printf("  | |______| |\n");
    printf("  |__________|\n");
    score++;
} else {
    printf("Incorrect. The answer is True.\n\n");
}

printf("Question 2: The mode of a data set is the value that occurs most frequently.\n\n");
printf("Hint: The mode is a statistical measure that represents the most frequently occurring value in a dataset.\n\n");
printf("Options: True, False\n\n");
printf("Answer: ");
scanf("%s", answer);

if (strcmp(answer, "True") == 0) {
    printf("Correct! You won a tooth.\n\n");
    printf("   ____________\n");
    printf("  /            \\\n");
    printf(" /              \\\n");
    printf("(______________()\n");
    printf(" \\    ___    /\n");
    printf("  \\  /   \\  /\n");
    printf("   \\/     \\/\n");
    score++;
} else {
    printf("Incorrect. The answer is True.\n\n");
}
return score;
}

int B_round10(void) {
int score = 0;
char answer[20];

printf("Round 10\n\n");
printf("Question 1: What is the chemical formula for water?\n\n");
printf("Hint: It is composed of two hydrogen atoms and one oxygen atom.\n\n");
printf("Options: CO2, O2, H2O, N2O\n\n");
printf("Answer: ");
scanf("%s", answer);

if (strcmp(answer, "H2O") == 0) {
    printf("Correct! You won a cool shape.\n");
        printf("   ____\n /      \\\n/________\\\n\\________/\n \\____/\n");
    score++;
} else {
    printf("Incorrect. The answer is H2O.\n\n");
}

printf("Question 2: Who developed the theory of relativity?\n\n");
printf("Hint: A German-born physicist.\n\n");
printf("Options: a.)Isaac Newton b.)Albert Einstein c.)Stephen Hawking d.)Neil deGrasse Tyson\n\n");
printf("Answer: ");
scanf("%s", answer);

if (strcmp(answer, "b") == 0) {
    printf("Correct! You won a rocket.\n\n");
    printf(" /\\\n//\\\\\nV  V\n");
    score++;
} else {
    printf("Incorrect. The answer is b.\n\n");
}
return score;
}

void B_saythankyou(void){
    printf("Dear player,\nI just wanted to take a moment to thank you for playing my game.\n It means a lot to me that you took the time to experience what I created.\n Your support and feedback are greatly appreciated.\n I hope you had a blast playing and I look forward to hearing more about your experience.\n Thank you again for your support and I hope to see you in future games!\n Best regards.\n\n\n");
}

void rate(void){
    int rate;
    printf("What would you rate my game out of 10?\n\n");
    scanf("%d", &rate);
    printf("Thank you for your rating!\n\n");
    printf("Your rating: %d/10\n\n", rate);
}

void B_write_review(void) {
    char response;
    char review[100];
    printf("Do you want to write a review (y/n)?\n\n ");
    scanf(" %c", &response);

    if (response == 'y') {
        printf("Please write a one word review: (eg. amazing, cool, etc.)\n\n");
        scanf("%s", review);
        printf("Thank you for your review\n\n");
    } else if (response == 'n') {
        printf("Thank you for your time.\n\n");
    } else {
        printf("Invalid response.\n\n");
    }
}

void b_epic_game() {
    B_displayWelcomeMessage();
    b_entertostart();
    B_username();
    B_userinfo();
    B_displayGameInstructions();
    B_show_time();
    int total_score = 0;
    total_score += B_testround();
    total_score += B_round1();
    total_score += B_round2();
    total_score += B_round3();
    total_score += B_round4();
    total_score += B_round5();
    total_score += B_round6();
    total_score += B_round7();
    total_score += B_round8();
    total_score += B_round9();
    total_score += B_round10();
    printf("You scored %d out of 22.\n", total_score);
    B_saythankyou();
    rate();
    B_write_review();
}


void b_WelcomeMessage() {
    printf("Welcome to the geography quiz game!\n");
    printf("Let's test your knowledge of geography!\n");
}

int b_askQuestion(int questionNumber, char* question, char* answer) {
    char userAnswer[100];
    printf("Question %d: %s\n", questionNumber, question);
    printf("Your answer: ");
    scanf("%s", userAnswer);
    return strcmp(userAnswer, answer) == 0;
}

void b_displayResults(int correctAnswers) {
    printf("You got %d out of 10 questions correct.\n", correctAnswers);
    if (correctAnswers >= 8) {
        printf("Excellent performance! You are a geography master!\n");
    } else if (correctAnswers >= 5) {
        printf("Good job! You know a fair bit about geography!\n");
    } else {
        printf("You need to brush up on your geography. Keep trying!\n");
    }
}


void b_play_geography(){
    int correctAnswers = 0;
    b_WelcomeMessage();
    correctAnswers += b_askQuestion(1, "What is the capital of France?", "Paris");
    correctAnswers += b_askQuestion(2, "What is the largest ocean in the world?", "Pacific");
    correctAnswers += b_askQuestion(3, "What is the currency of Japan?", "Yen");
    correctAnswers += b_askQuestion(4, "What is the tallest mountain in the world?", "Everest");
    correctAnswers += b_askQuestion(5, "What is the longest river in Africa?", "Nile");
    correctAnswers += b_askQuestion(6, "What is the capital of China?", "Beijing");
    correctAnswers += b_askQuestion(7, "What is the currency of the European Union?", "Euro");
    correctAnswers += b_askQuestion(8, "What is the capital of Australia?", "Canberra");
    correctAnswers += b_askQuestion(9, "What is the largest desert in the world?", "Sahara");
    correctAnswers += b_askQuestion(10, "What is the capital of India?", "New Delhi");
    b_displayResults(correctAnswers);
}



void b_guess_animal() {
    char animal[20];
    char user_input[20];
    printf("---Welcome to Guess The Animal---\n\n");
    printf("---Think of your favorite animal---\n\n");
    printf("Is it a wild animal? (yes/no)\n");
    scanf("%s", user_input);

    if (strcmp(user_input, "yes") == 0) {
        printf("Does it live in the jungle? (yes/no)\n");
        scanf("%s", user_input);

        if (strcmp(user_input, "yes") == 0) {
            strcpy(animal, "tiger");
        } else {
            strcpy(animal, "gazelle");
        }
    } else {
        printf("Is it a domesticated animal? (yes/no)\n");
        scanf("%s", user_input);

        if (strcmp(user_input, "yes") == 0) {
            strcpy(animal, "cat");
        } else {
            strcpy(animal, "goldfish");
        }
    }

    printf("Your favorite animal is a %s!\n", animal);
    printf("---Thank you for Playing Guess The Animal---\n\n");
}



void b_basketballQuiz() {
        int score = 0;
        char answer[20];

        printf("Welcome to the basketball quiz game!\n");
        printf("Answer each question with 'yes' or 'no'.\n");

        printf("\nQuestion 1: Is basketball a sport played with a ball and a hoop?\n");
        printf("Answer: ");
        scanf("%s", answer);
        if (strcmp(answer, "yes") == 0)
        {
            printf("Correct!\n");
            score++;
        }
        else
        {
            printf("Incorrect.\n");
        }

        printf("\nQuestion 2: Is the height of a basketball hoop 10 feet?\n");
        printf("Answer: ");
        scanf("%s", answer);
        if (strcmp(answer, "no") == 0)
        {
            printf("Correct!\n");
            score++;
        }
        else
        {
            printf("Incorrect.\n");
        }

        printf("\nQuestion 3: Is the term 'slam dunk' used in basketball?\n");
        printf("Answer: ");
        scanf("%s", answer);
        if (strcmp(answer, "yes") == 0)
        {
            printf("Correct!\n");
            score++;
        }
        else
        {
            printf("Incorrect.\n");
        }

        printf("\nQuestion 4: Can a player run with the ball in basketball?\n");
        printf("Answer: ");
        scanf("%s", answer);
        if (strcmp(answer, "no") == 0)
        {
            printf("Correct!\n");
            score++;
        }
        else
        {
            printf("Incorrect.\n");
        }

        printf("\nQuestion 5: Is the 3-point line closer to the basket in basketball than the free-throw line?\n");
        printf("Answer: ");
        scanf("%s", answer);
        if (strcmp(answer, "yes") == 0)
        {
            printf("Correct!\n");
            score++;
        }
        else
        {
            printf("Incorrect.\n");
        }

        printf("\nYou got %d out of 5 questions correct!\n", score);
        printf("Thanks for playing the basketball quiz game! Goodbye!\n");

}


void b_guessbirthyear()
{
    int year = 1961;
    int guess;
    int tries = 0;

    printf("Guess the year Barack Obama was born in: ");
    scanf("%d", &guess);

    while (guess != year) {
        if (guess < year) {
            printf("Too low. Guess again: ");
        } else if (guess > year) {
            printf("Too high. Guess again: ");
        }

        scanf("%d", &guess);
        tries++;
    }

    printf("Correct! It took you %d tries to guess the year Barack Obama was born in.\n", tries);

}


void b_germanyquiz()
{
    int score = 0;

    printf("Welcome to Germany Quiz.\n\n");
    printf("1. Germany is located in Europe.\n");
    printf("True or False?\n");
    char answer1[5];
    scanf("%s", answer1);
    if (strcmp(answer1, "True") == 0) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect. The answer is True.\n");
    }

    printf("2. Berlin is the capital city of Germany.\n");
    printf("True or False?\n");
    char answer2[5];
    scanf("%s", answer2);
    if (strcmp(answer2, "True") == 0) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect. The answer is True.\n");
    }

    printf("3. The currency used in Germany is the Euro.\n");
    printf("True or False?\n");
    char answer3[5];
    scanf("%s", answer3);
    if (strcmp(answer3, "True") == 0) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect. The answer is True.\n");
    }

    printf("4. The population of Germany is over 100 million.\n");
    printf("True or False?\n");
    char answer4[5];
    scanf("%s", answer4);
    if (strcmp(answer4, "False") == 0) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect. The answer is False.\n");
    }

    printf("5. The official language of Germany is French.\n");
    printf("True or False?\n");
    char answer5[5];
    scanf("%s", answer5);
    if (strcmp(answer5, "False") == 0) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect. The answer is False.\n");
    }

    printf("You scored %d out of 5.\n", score);
    printf("Thank You for Playing Germany Quiz.\n");

}


void b_BreakingBquiz() {
    int score = 0;
    char answer[4];

    printf("---Welcome to Breaking Bad Quiz---\n");
    printf("Answer each question with yes or no.\n");

    printf("\nQuestion 1: Was Breaking Bad set in Albuquerque, New Mexico?\n");
    scanf("%s", answer);
    if (strcmp(answer, "yes") == 0) {
        score++;
        printf("Correct!\n");
    } else {
        printf("Incorrect.\n");
    }

    printf("\nQuestion 2: Did Walter White have a degree in chemistry?\n");
    scanf("%s", answer);
    if (strcmp(answer, "yes") == 0) {
        score++;
        printf("Correct!\n");
    } else {
        printf("Incorrect.\n");
    }

    printf("\nQuestion 3: Did Jesse Pinkman start cooking meth with Walter White because he needed money to pay for his girlfriend's medical bills?\n");
    scanf("%s", answer);
    if (strcmp(answer, "no") == 0) {
        score++;
        printf("Correct!\n");
    } else {
        printf("Incorrect.\n");
    }

    printf("\nQuestion 4: Did Walter White have a son with cerebral palsy?\n");
    scanf("%s", answer);
    if (strcmp(answer, "yes") == 0) {
        score++;
        printf("Correct!\n");
    } else {
        printf("Incorrect.\n");
    }

    printf("\nQuestion 5: Did Walter White die at the end of Breaking Bad?\n");
    scanf("%s", answer);
    if (strcmp(answer, "yes") == 0) {
        score++;
        printf("Correct!\n");
    } else {
        printf("Incorrect.\n");
    }

    printf("\nYour score: %d/5\n", score);
    printf("\nThank you for playing Breaking Bad Quiz\n");
}


void b_crossword(){
    char word[10] = "C--S-W-RD";
    char answer[10] = "CROSSWORD";

    printf("Guess the word: %s\n", word);

    char letter;
    int i;
    for (i = 0; i < 9; i++) {
        int correct = 0;
        while (!correct) {
            printf("Enter letter %d: ", i + 1);
            scanf(" %c", &letter);
            if (letter != answer[i]) {
                printf("Incorrect letter, please try again!\n");
            } else {
                word[i] = letter;
                printf("Correct letter!\n");
                correct = 1;
            }
        }
        printf("Guess the word: %s\n", word);
    }

    printf("The word is: %s\n", word);
}


void b_gamble()
{
    int wallet = 100;  
    int bet;
    int guess;
    int number;

    srand(time(NULL));  

    while (wallet > 0) {
        printf("You have $%d. Enter your bet: ", wallet);
        scanf("%d", &bet);

        
        if (bet > wallet) {
            printf("You don't have enough money. Try a smaller bet.\n");
            continue;
        }
        if (bet <= 0) {
            printf("Invalid bet. Try again.\n");
            continue;
        }

        printf("Guess a number between 1 and 10: ");
        scanf("%d", &guess);

        number = rand() % 10 + 1;  

    
        if (guess == number) {
            printf("You win! The number was %d.\n", number);
            wallet += bet;
        } else {
            printf("You lose. The number was %d.\n", number);
            wallet -= bet;
        }
    }

    printf("You are out of money. Better luck next time!\n");
    
}


void b_historyevents() {
    int year, score = 0;

    printf("Welcome to the history quiz!\n");
    printf("Enter the year of the following historical events:\n");

    printf("\nEvent 1: The American Revolution\n");
    printf("Year: ");
    scanf("%d", &year);
    if (year == 1776) {
        printf("You got it right!\n");
        score++;
    } else {
        printf("Nope, the correct year is 1776.\n");
    }

    printf("\nEvent 2: The fall of the Berlin Wall\n");
    printf("Year: ");
    scanf("%d", &year);
    if (year == 1989) {
        printf("You got it right!\n");
        score++;
    } else {
        printf("Nope, the correct year is 1989.\n");
    }

    printf("\nEvent 3: The end of World War II\n");
    printf("Year: ");
    scanf("%d", &year);
    if (year == 1945) {
        printf("You got it right!\n");
        score++;
    } else {
        printf("Nope, the correct year is 1945.\n");
    }

    printf("\nYou scored %d/3.\n", score);
    printf("Thanks for playing!\n");
}

void b_personality() {
    char name[100];
    printf("What's your name? ");
    scanf("%s", name);

    printf("On a scale of 1 to 10, how introverted are you? ");
    scanf("%d", &introverted);

    printf("On a scale of 1 to 10, how energetic are you? ");
    scanf("%d", &energetic);

    printf("On a scale of 1 to 10, how optimistic are you? ");
    scanf("%d", &optimistic);

    printf("On a scale of 1 to 10, how empathetic are you? ");
    scanf("%d", &empathetic);

    printf("\nSummary for %s:\n\n", name);

    printf("Based on your answers, %s is a person who is\n ", name);
    if (introverted >= 7) {
        printf("introverted and tends to prefer more solitary activities.\n ");
    } else {
        printf("extroverted and tends to enjoy being in social situations.\n ");
    }

    if (energetic >= 7) {
        printf("They are full of energy and always on the go.\n ");
    } else {
        printf("They are relaxed and tend to take a more laid-back approach to life.\n ");
    }

    if (optimistic >= 7) {
        printf("They have an optimistic outlook on life and are generally hopeful and positive.\n ");
    } else {
        printf("They have a pessimistic outlook on life and tend to focus on the negative.\n ");
    }

    if (empathetic >= 7) {
        printf("%s is a very empathetic person who is able to understand and connect with others.\n ", name);
    } else {
        printf("%s is not as empathetic and may have trouble connecting with others emotionally.\n ", name);
    }

    printf("\n\nThis is just a general summary based on the answers provided.\nEveryone is unique and complex, and these answers only provide a limited \nview into %s's personality.", name);

}


void b_celebrity(){
    char name[20];
    printf("Think of a celebrity and I will try to guess who it is.\n");

    strcpy(celebrity, "Justin Bieber");
    printf("Is it %s? (y/n)\n", celebrity);
    scanf(" %c", &answer);
    if (tolower(answer) == 'y') {
        printf("I got it! It's %s\n", celebrity);

    }

    strcpy(celebrity, "Taylor Swift");
    printf("Is it %s? (y/n)\n", celebrity);
    scanf(" %c", &answer);
    if (tolower(answer) == 'y') {
        printf("I got it! It's %s\n", celebrity);

    }

    strcpy(celebrity, "Kanye West");
    printf("Is it %s? (y/n)\n", celebrity);
    scanf(" %c", &answer);
    if (tolower(answer) == 'y') {
        printf("I got it! It's %s\n", celebrity);

    }

    strcpy(celebrity, "Dwayne Johnson");
    printf("Is it %s? (y/n)\n", celebrity);
    scanf(" %c", &answer);
    if (tolower(answer) == 'y') {
        printf("I got it! It's %s\n", celebrity);

    }

    printf("I give up. Who were you thinking of?\n");
    scanf("%s", name);
    printf("Ah, yes! %s is a great celebrity.\n", name);

}


void b_hangman() {
    char word[MAX_LEN + 1];
    char display[MAX_LEN + 1];
    char used[26];
    int num_wrong_guesses;

    printf("Welcome to Hangman!\n");

    strcpy(word, "hangman");
    int i;
    for (i = 0; i < strlen(word); i++) {
        display[i] = '-';
    }
    display[i] = '\0';
    num_wrong_guesses = 0;
    memset(used, 0, sizeof used);

    char guess[MAX_LEN + 1];
    int good_guess, already_guessed;
    while (num_wrong_guesses < MAX_GUESSES && strchr(display, '-') != NULL) {
        printf("Current word: %s\n", display);
        printf("You have %d incorrect guesses left.\n", MAX_GUESSES - num_wrong_guesses);
        printf("Used letters: %s\n", used);
        printf("Enter your guess: ");
        scanf("%s", guess);
        if (strlen(guess) != 1 || !isalpha(*guess)) {
            printf("Invalid guess. Please enter a single letter.\n");
            continue;
        }
        already_guessed = 0;
        for (i = 0; i < 26; i++) {
            if (tolower(guess[0]) == used[i]) {
                printf("You already used the letter '%c'.\n", tolower(guess[0]));
                already_guessed = 1;
                break;
            }
        }
        if (already_guessed) {
            continue;
        }
        used[i] = tolower(guess[0]);
        good_guess = 0;
        for (i = 0; i < strlen(word); i++) {
            if (tolower(guess[0]) == tolower(word[i])) {
                display[i] = word[i];
                good_guess = 1;
            }
        }
        if (!good_guess) {
            printf("Incorrect! The letter '%c' is not in the word.\n", tolower(guess[0]));
            num_wrong_guesses++;
        }
    }
    if (num_wrong_guesses == MAX_GUESSES) {
        printf("You lose! The word was '%s'.\n", word);
    } else {
        printf("You win! The word was '%s'.\n", word);
    }

}


void b_football() {
    int score = 0;
    char answer[20];

    printf("Football History Quiz (before 2000)\n\n");

    printf("Q1) Who won the 1966 FIFA World Cup?\n");
    printf("A) England\nB) Germany\nC) Argentina\nD) Brazil\n\n");
    printf("Enter your answer: ");
    scanf("%s", answer);
    if (strcmp(answer, "A") == 0 || strcmp(answer, "a") == 0)
    {
        printf("Correct!\n");
        score++;
    }
    else
    {
        printf("Incorrect. The correct answer was England.\n");
    }

    printf("\nQ2) Which club won the first ever UEFA Champions League in 1955?\n");
    printf("A) Real Madrid\nB) Barcelona\nC) AC Milan\nD) Bayern Munich\n\n");
    printf("Enter your answer: ");
    scanf("%s", answer);
    if (strcmp(answer, "A") == 0 || strcmp(answer, "a") == 0)
    {
        printf("Correct!\n");
        score++;
    }
    else
    {
        printf("Incorrect. The correct answer was Real Madrid.\n");
    }

    printf("\nQ3) Who was the first player to win three Ballon d'Or awards?\n");
    printf("A) Lionel Messi\nB) Cristiano Ronaldo\nC) Johan Cruyff\nD) Michel Platini\n\n");
    printf("Enter your answer: ");
    scanf("%s", answer);
    if (strcmp(answer, "C") == 0 || strcmp(answer, "c") == 0)
    {
        printf("Correct!\n");
        score++;
    }
    else
    {
        printf("Incorrect. The correct answer was Johan Cruyff.\n");
    }

    printf("\nYour total score is %d out of 3\n", score);
}



void v_play_rockpapersciss(){
    int player_choice, computer_choice, player_score = 0, computer_score = 0;
    srand(time(NULL));

    printf("***************************\n");
    printf("Playing Rock,Paper,Scissors!\n");
    printf("***************************\n\n");

    printf("First to win 3 rounds wins!\n\n");

    while (1)
    {
        printf("Enter your choice:\n");
        printf("1. Rock\n2. Paper\n3. Scissors\n\n");
        printf("Your Choice:");
        scanf("%d", &player_choice);
        computer_choice = (rand() % 3) + 1;
        if (player_choice == ROCK)
        {
            if (computer_choice == ROCK)
            {
                printf("\nTie! Both picked Rock\n\n");
            }
            else if (computer_choice == PAPER)
            {
                printf("\nYou lose! I picked Paper\n\n");
                computer_score++;
                printf("You have %d/3 points and I have %d/3 points.\n\n",player_score, computer_score);
            }
            else
            {
                printf("\nYou win! I picked Scissors\n\n");
                player_score++;
                printf("You have %d/3 points and I have %d/3 points.\n\n",player_score, computer_score);
            }
        }
        else if (player_choice == PAPER)
        {
            if (computer_choice == ROCK)
            {
                printf("\nYou win! I picked Rock\n\n");
                player_score++;
                printf("You have %d/3 points and I have %d/3 points.\n\n",player_score, computer_score);
            }
            else if (computer_choice == PAPER)
            {
                printf("\nTie! Both picked Paper\n\n");
            }
            else
            {
                printf("\nYou lose! I picked Scissors\n\n");
                computer_score++;
                printf("You have %d/3 points and I have %d/3 points.\n\n",player_score, computer_score);
            }
        }
        else if (player_choice == SCISSORS)
        {
            if (computer_choice == ROCK)
            {
                printf("\nYou lose! I picked Rock\n\n");
                computer_score++;
                printf("You have %d/3 points and I have %d/3 points.\n\n",player_score, computer_score);
            }
            else if (computer_choice == PAPER)
            {
                printf("\nYou win! I picked Paper\n\n");
                player_score++;
                printf("You have %d/3 points and I have %d/3 points.\n\n",player_score, computer_score);
            }
            else
            {
                printf("\nTie! Both picked Scissors\n\n");
            }
        }
        else
        {
            printf("\nInvalid choice!\n\n");
        }
        if (player_score == 3 || computer_score == 3)
        {
            break;
        }
    }
    if (player_score == 3)
    {
        printf("You win the best of three!\n\n");
    }
    else
    {
        printf("I win the best of three!\n\n");
    }
    printf("******************************************\n");
    printf("Thank you for playing Rock,Paper,Scissors!\n");
    printf("******************************************\n\n");
}

void v_horoscope(int day, int month){

    if ((month == 3 && day >= 21) || (month == 4 && day <= 19)) {
        char horo;
        printf("\nYour horoscope is Aries.\n\n");
        printf("Do you want to know more about Aries personalities?\n");
        printf("Your Answer(Y/N): ");
        scanf(" %c", &horo);
        horo = toupper(horo);
        if (horo == 'Y'){
            printf("\nLike their fellow fire signs, Leo and Sagittarius, \nAries is a passionate, motivated, and confident leader who builds community with their cheerful disposition \nand relentless determination. \nUncomplicated and direct in their approach, they often get frustrated by exhaustive details and unnecessary nuances.\n\n");
        }else{
            printf("\nOkay no worries! But you missed the fun!\n\n");
        }
        printf("Do you want to know which Zodiac matches the best with Aries?\n");
        printf("Your Answer(Y/N): ");
        scanf(" %c", &horo);
        horo = toupper(horo);
        if (horo == 'Y'){
            printf("\nThere's never a dull moment between an Aries and Aquarius, which makes their relationship extremely exciting.\n\n");
        }else{
            printf("\nWe all match! I don't believe in it either!\n\n");
        }
    } else if ((month == 4 && day >= 20) || (month == 5 && day <= 20)) {
        char horo;
        printf("\nYour horoscope is Taurus.\n\n");
        printf("Do you want to know more about Taurus personalities?\n");
        printf("Your Answer(Y/N): ");
        scanf(" %c", &horo);
        horo = toupper(horo);
        if (horo == 'Y'){
            printf("\nTaureans aren't afraid to roll up their sleeves \nand work hard to earn big rewards. \nThey're ambitious, focused, and resilient and they feel most secure \nwhen steadily putting money into a savings account.\n\n");
        }else{
            printf("\nOkay no worries! But you missed the fun!\n\n");
        }
        printf("Do you want to know which Zodiac matches the best with Taurus?\n");
        printf("Your Answer(Y/N): ");
        scanf(" %c", &horo);
        horo = toupper(horo);
        if (horo == 'Y'){
            printf("\nTaurus and Cancer seriously get each other. \nThese two zodiac signs work well with one another because they hold a tight connection both physically and emotionally. \n\n");
        }else{
            printf("\nWe all match! I don't believe in it either!\n\n");
        }
    } else if ((month == 5 && day >= 21) || (month == 6 && day <= 20)) {
        char horo;
        printf("\nYour horoscope is Gemini.\n\n");
        printf("Do you want to know more about Gemini personalities?\n");
        printf("Your Answer(Y/N): ");
        scanf(" %c", &horo);
        horo = toupper(horo);
        if (horo == 'Y'){
            printf("\nPlayful and intellectually curious, Gemini is constantly juggling a variety of passions, \nhobbies, careers, and friend groups. \nThey are the social butterflies of the zodiac: \nThese quick-witted twins can talk to anyone about anything. \nFind them buzzing between happy hours, dinner parties, and dance floors.\n\n");
        }else{
            printf("\nOkay no worries! But you missed the fun!\n\n");
        }
        printf("Do you want to know which Zodiac matches the best with Gemini?\n");
        printf("Your Answer(Y/N): ");
        scanf(" %c", &horo);
        horo = toupper(horo);
        if (horo == 'Y'){
            printf("\nA Gemini and Aquarius have a crazy mental and emotional connection. \nThey get each other to the fullest, like they have known one another for years \neven if it's only been months (or weeks). \n\n");
        }else{
            printf("\nWe all match! I don't believe in it either!\n\n");
        }
        
    } else if ((month == 6 && day >= 21) || (month == 7 && day <= 22)) {
        char horo;
        printf("\nYour horoscope is Cancer.\n\n");
        printf("Do you want to know more about Cancer personalities?\n");
        printf("Your Answer(Y/N): ");
        scanf(" %c", &horo);
        horo = toupper(horo);
        if (horo == 'Y'){
            printf("\nCancer is the fourth sign of the zodiac and is represented by the Crab. \nThey're primarily known for being emotional, nurturing, and highly intuitive, \nas well as sensitive and at times insecure\n\n");
        }else{
            printf("\nOkay no worries! But you missed the fun!\n\n");
        }
        printf("Do you want to know which Zodiac matches the best with Cancer?\n");
        printf("Your Answer(Y/N): ");
        scanf(" %c", &horo);
        horo = toupper(horo);
        if (horo == 'Y'){
            printf("\nCancer and Pisces are two cool water signs and instinctively have one massive cosmic connection. \nThey work well together because each one knows just who the other is and they are proud of that.\n\n");
        }else{
            printf("\nWe all match! I don't believe in it either!\n\n");
        }
    } else if ((month == 7 && day >= 23) || (month == 8 && day <= 22)) {
        char horo;
        printf("\nYour horoscope is Leo.\n\n");
        printf("Do you want to know more about Leo personalities?\n");
        printf("Your Answer(Y/N): ");
        scanf(" %c", &horo);
        horo = toupper(horo);
        if (horo == 'Y'){
            printf("\nTypical sun in Leo traits include being confident, comfortable being the center of attention, \ndrama-adoring, ambitious, loyal, fiercely protective of their nearest and dearest, \ngenerous, luxury-loving, sunny, and big-hearted.\n\n");
        }else{
            printf("\nOkay no worries! But you missed the fun!\n\n");
        }
        printf("Do you want to know which Zodiac matches the best with Leo?\n");
        printf("Your Answer(Y/N): ");
        scanf(" %c", &horo);
        horo = toupper(horo);
        if (horo == 'Y'){
            printf("\nThe passion is high between Leo and Sagittarius, as both signs both enjoy life and love others who feel the same. \nThey are both passionate about what they want out of this world \nand extremely encouraging in helping the other achieve any goal or dream.\n\n");
        }else{
            printf("\nWe all match! I don't believe in it either!\n\n");
        }
    } else if ((month == 8 && day >= 23) || (month == 9 && day <= 22)) {
        char horo;
        printf("\nYour horoscope is Virgo.\n\n");
        printf("Do you want to know more about Virgo personalities?\n");
        printf("Your Answer(Y/N): ");
        scanf(" %c", &horo);
        horo = toupper(horo);
        if (horo == 'Y'){
            printf("\nVirgos are logical, practical, and systematic in their approach to life. \nThis earth sign is a perfectionist at heart and isn't afraid to improve skills through diligent and consistent practice.\n\n");
        }else{
            printf("\nOkay no worries! But you missed the fun!\n\n");
        }
        printf("Do you want to know which Zodiac matches the best with Virgo?\n");
        printf("Your Answer(Y/N): ");
        scanf(" %c", &horo);
        horo = toupper(horo);
        if (horo == 'Y'){
            printf("\nAs both are earth signs, Virgo and Taurus really hit it off. \nEasygoing and practical in their everyday lives, their relationship is cool, calm and collected.\n\n");
        }else{
            printf("\nWe all match! I don't believe in it either!\n\n");
        }
    } else if ((month == 9 && day >= 23) || (month == 10 && day <= 22)) {
        char horo;
        printf("\nYour horoscope is Libra.\n\n");
        printf("Do you want to know more about Libra personalities?\n");
        printf("Your Answer(Y/N): ");
        scanf(" %c", &horo);
        horo = toupper(horo);
        if (horo == 'Y'){
            printf("\nLibras are extremely agreeable and honest people \nwho believe strongly in the importance of social connections. \nLibras are among the most fascinating and intelligent individuals on the planet, \nand they have a lot to give.\n\n");
        }else{
            printf("\nOkay no worries! But you missed the fun!\n\n");
        }
        printf("Do you want to know which Zodiac matches the best with Libra?\n");
        printf("Your Answer(Y/N): ");
        scanf(" %c", &horo);
        horo = toupper(horo);
        if (horo == 'Y'){
            printf("\nA relationship between a Libra and Gemini is all about a strong intellectual connection. \nBoth are air signs and deep into mental stimulation.\n\n");
        }else{
            printf("\nWe all match! I don't believe in it either!\n\n");
        }
    } else if ((month == 10 && day >= 23) || (month == 11 && day <= 21)) {
        char horo;
        printf("\nYour horoscope is Scorpio.\n\n");
        printf("Do you want to know more about Scorpio personalities?\n");
        printf("Your Answer(Y/N): ");
        scanf(" %c", &horo);
        horo = toupper(horo);
        if (horo == 'Y'){
            printf("\nScorpios are known for their loyalty and devotion — and also their passion. \nIn fact, they are known to have such intense personalities that they are often confused with vibrant fire signs. \nAlas, they just have deep feelings and emotions.\n\n");
        }else{
            printf("\nOkay no worries! But you missed the fun!\n\n");
        }
        printf("Do you want to know which Zodiac matches the best with Scorpio?\n");
        printf("Your Answer(Y/N): ");
        scanf(" %c", &horo);
        horo = toupper(horo);
        if (horo == 'Y'){
            printf("\nSometimes having two passionate people in a relationship doesn't work. \nHowever, if one person is a Scorpio and the other is a Cancer, it can be perfect. \nThese two water signs are intense when it comes to emotions, but that only seems to make them even more compatible.\n\n");
        }else{
            printf("\nWe all match! I don't believe in it either!\n\n");
        }
    } else if ((month == 11 && day >= 22) || (month == 12 && day <= 21)) {
        char horo;
        printf("\nYour horoscope is Sagittarius.\n\n");
        printf("Do you want to know more about Sagittarius personalities?\n");
        printf("Your Answer(Y/N): ");
        scanf(" %c", &horo);
        horo = toupper(horo);
        if (horo == 'Y'){
            printf("\nRepresented by the archer (a half-man, half-horse centaur), \nSagittarius isn't afraid to use its bow and arrow to explore expansive terrain, \nseeking answers in places and spaces others wouldn't dare venture.\n\n");
        }else{
            printf("\nOkay no worries! But you missed the fun!\n\n");
        }
        printf("Do you want to know which Zodiac matches the best with Sagittarius?\n");
        printf("Your Answer(Y/N): ");
        scanf(" %c", &horo);
        horo = toupper(horo);
        if (horo == 'Y'){
            printf("\nSagittarius and Aries are both fire signs, \nso you can expect some serious hot passion between the two, making for a dynamite pair. \nThey have insane amounts of energy to bring into the relationship, \nwhich only grows stronger as it continues to blossom. \n\n");
        }else{
            printf("\nWe all match! I don't believe in it either!\n\n");
        }
    } else if ((month == 12 && day >= 22) || (month == 1 && day <= 19)) {
        char horo;
        printf("\nYour horoscope is Capricorn.\n\n");
        printf("Do you want to know more about Capricorn personalities?\n");
        printf("Your Answer(Y/N): ");
        scanf(" %c", &horo);
        horo = toupper(horo);
        if (horo == 'Y'){
            printf("\nCapricorns are overachievers, persistent, practical, and sensitive. \nThey're known for their hardworking habits, and they're overachievers who make success look effortless \n— even though they put a lot of time and care into their careers and relationships.\n\n");
        }else{
            printf("\nOkay no worries! But you missed the fun!\n\n");
        }
        printf("Do you want to know which Zodiac matches the best with Capricorn?\n");
        printf("Your Answer(Y/N): ");
        scanf(" %c", &horo);
        horo = toupper(horo);
        if (horo == 'Y'){
            printf("\nCapricorn and Taurus have something most only daydream about: endless adoration. \nThese two lovebirds will be together forever and actually enjoy one another's company to the end.\n\n");
        }else{
            printf("\nWe all match! I don't believe in it either!\n\n");
        }
    } else if ((month == 1 && day >= 20) || (month == 2 && day <= 18)) {
        char horo;
        printf("\nYour horoscope is Aquarius.\n\n");
        printf("Do you want to know more about Aquarius personalities?\n");
        printf("Your Answer(Y/N): ");
        scanf(" %c", &horo);
        horo = toupper(horo);
        if (horo == 'Y'){
            printf("\nAquarius is actually the final air sign, which means it deals with air-related concepts from a macro-perspective. \nOf all the zodiac signs, Aquarius is undoubtedly the most innovative, progressive, rebellious, and humanitarian.\n\n");
        }else{
            printf("\nOkay no worries! But you missed the fun!\n\n");
        }
        printf("Do you want to know which Zodiac matches the best with Aquarius?\n");
        printf("Your Answer(Y/N): ");
        scanf(" %c", &horo);
        horo = toupper(horo);
        if (horo == 'Y'){
            printf("\nAquarius and Gemini are both air signs that have a killer psychological connection. \nAnd it goes deep—really deep, like finishing each other's sentences. \nTheir relationship is almost mystical because it's one no one else can comprehend.\n\n");
        }else{
            printf("\nWe all match! I don't believe in it either!\n\n");
        }
    } else if ((month == 2 && day >= 19) || (month == 3 && day <= 20)) {
        char horo;
        printf("\nYour horoscope is Pisces.\n\n");
        printf("Do you want to know more about Pisces personalities?\n");
        printf("Your Answer(Y/N): ");
        scanf(" %c", &horo);
        horo = toupper(horo);
        if (horo == 'Y'){
            printf("\nPisces people are known for being emotionally sensitive, gracious, and emotionally aware. \nPisces characters are regarded for being among the most sympathetic of the zodiac signs, \nand they will go to great lengths to ensure the happiness of those around them. \nThey're also creative and imaginative.\n\n");
        }else{
            printf("\nOkay no worries! But you missed the fun!\n\n");
        }
        printf("Do you want to know which Zodiac matches the best with Pisces?\n");
        printf("Your Answer(Y/N): ");
        scanf(" %c", &horo);
        horo = toupper(horo);
        if (horo == 'Y'){
            printf("\nAnother pair that's very intuitive to one another is Pisces and Scorpio. \nThese two zodiac signs can get into each other's minds \nand know what they are thinking almost as well as if they were thinking it themselves. \nBut they aren't just into intellect; \nthey both have a hunger to understand the other's body and soul \nand learn what makes the other person tick.\n\n");
        }else{
            printf("\nWe all match! I don't believe in it either!\n\n");
        }
    } else {
        printf("Invalid birth date.\n");
    }
}

void v_play_horoscope(void) {
    int day, month;

    printf("*********************\n");
    printf("Check your Horoscope!\n");
    printf("*********************\n\n");

    printf("Enter your birth day: ");
    scanf("%d", &day);
    printf("Enter your birth month (in number): ");
    scanf("%d", &month);

    v_horoscope(day, month);

    printf("****************\n");
    printf("Have a nice day!\n");
    printf("****************\n\n");
}

void v_allaboutspace(void){
    char spacename[20];
    int space_choice;
    int space_score = 0;
    int space_answer;
    printf("\nEnter your Astronaut name: \n");
    scanf("%s", spacename);
    printf("\nHello, Commander %s! Pleased to have you onboard.\n\n", spacename);
    printf("Welcome to the space quiz game!\n");
    printf("In this game, you will be tested on your knowledge of space.\n");
    printf("You will be presented with five questions and graded accordingly.\n");
    printf("Let's see how much you know!\n\n");
    printf("Main Menu\n\n");
    printf("1. Start the Quiz!\n");
    printf("2. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &space_choice);

    if (space_choice == 1) {
    printf("Quiz Start!\n");
    printf("\nQuestion 1: What is the largest planet in our solar system?\n\n");
    printf("1. Earth\n");
    printf("2. Mars\n");
    printf("3. Jupiter\n");
    printf("4. Saturn\n");
    printf("\nEnter your answer: ");
    scanf("%d", &space_answer);
    if (space_answer == 3) {
      printf("\nCorrect!\n");
      space_score++;
      printf("\nFACT: Fifth in line from the Sun, Jupiter is, by far, the largest planet in the solar system – \nmore than twice as massive as all the other planets combined. \n");
    } else {
      printf("\nIncorrect\n");
      printf("\nThe Correct Answer was 3. Jupiter.\n");
      printf("\nFACT: Fifth in line from the Sun, Jupiter is, by far, the largest planet in the solar system – \nmore than twice as massive as all the other planets combined. \n");
    }
  }
    printf("\nQuestion 2: What is the smallest planet in our solar system?\n\n");
    printf("1. Mercury\n");
    printf("2. Mars\n");
    printf("3. Venus\n");
    printf("4. Pluto\n");
    printf("\nEnter your answer: ");
    scanf("%d", &space_answer);
    if (space_answer == 1) {
      printf("\nCorrect!\n");
      space_score++;
      printf("\nFACT: Mercury is the smallest planet in our solar system – only slightly larger than Earth's Moon.\n");
    } else {
      printf("\nIncorrect\n");
      printf("\nThe Correct Answer was 1. Mercury. Pluto is a dwarf planet.\n");
      printf("\nFACT: Mercury is the smallest planet in our solar system – only slightly larger than Earth's Moon.\n");
    }

    printf("\nQuestion 3: What is the name of the first man-made satellite to be launched into space?\n\n");
    printf("1. Sputnik 1\n");
    printf("2. Apollo 11\n");
    printf("3. Vostok 1\n");
    printf("4. Explorer 1\n");
    printf("\nEnter your answer: ");
    scanf("%d", &space_answer);
    if (space_answer == 1) {
      printf("\nCorrect!\n");
      space_score++;
      printf("\nFACT: Sputnik was only 23 inches in diameter but weighed about 184 pounds. \nAt 500 miles up, at the speed of 18,000 miles an hour, Sputnik circled the globe every 96 minutes, \nmaking 1,440 orbits around the Earth before beginning its rentry.\n");
    } else {
      printf("\nIncorrect\n");
      printf("\nThe Correct Answer was 1. Sputnik 1.\n");
      printf("\nFACT: Sputnik was only 23 inches in diameter but weighed about 184 pounds. \nAt 500 miles up, at the speed of 18,000 miles an hour, Sputnik circled the globe every 96 minutes, \nmaking 1,440 orbits around the Earth before beginning its rentry.\n");
    }

    printf("\nQuestion 4: What is the name of the first man to walk on the Moon?\n\n");
    printf("1. Neil Armstrong\n");
    printf("2. Buzz Aldrin\n");
    printf("3. Yuri Gagarin\n");
    printf("4. Valentina Tereshkova\n");
    printf("\nEnter your answer: ");
    scanf("%d", &space_answer);
    if (space_answer == 1) {
      printf("\nCorrect!\n");
      space_score++;
      printf("\nFACT: Neil Armstrong was the first human to walk on the moon during the NASA (National Aeronautics and Space Administration) Apollo 11 mission on 20th July 1969. \nHe completed the mission alongside co-pilots Edwin E. “Buzz” Aldrin and Michael Collins.\n");
    } else {
      printf("\nIncorrect\n");
      printf("\nThe Correct Answer was 1. Neil Armstrong.\n");
      printf("\nFACT: Neil Armstrong was the first human to walk on the moon during the NASA (National Aeronautics and Space Administration) Apollo 11 mission on 20th July 1969. \nHe completed the mission alongside co-pilots Edwin E. “Buzz” Aldrin and Michael Collins.\n");
    }

    printf("\nQuestion 5: What is the name of the first successful interplanetary probe?\n\n");
    printf("1. Pioneer 10\n");
    printf("2. Mariner 2\n");
    printf("3. Viking 1\n");
    printf("4. Luna 1\n");
    printf("Enter your answer: ");
    scanf("%d", &space_answer);
    if (space_answer == 1) {
      printf("\nCorrect!\n");
      space_score++;
      printf("\nFACT: For more than 25 years, Pioneer 10 was the most distant human-made object, \nbreaking records by crossing the asteroid belt, the orbit of Jupiter, and eventually even the orbit of Pluto.\n");
    } else {
      printf("\nIncorrect\n");
      printf("\nThe Correct Answer was 1. Pioneer 10.\n");
      printf("\nFACT: For more than 25 years, Pioneer 10 was the most distant human-made object, \nbreaking records by crossing the asteroid belt, the orbit of Jupiter, and eventually even the orbit of Pluto.\n");
    }
    
    printf("\nYour score is: %d\n\n", space_score);
    if (space_score == 5) {
      printf("\nCongratulations! You are ready to take off!\n\n");
    } else if (space_score >= 3) {
      printf("\nGood job! But you need some more training before you venture into space.\n\n");
    } else {
      printf("\nYou tried... but time to study more about Space!\n\n");
    }
}



void v_play_allaboutspace(void){
    int space_replay;
  printf("*********************************************\n");
  printf("Welcome to the Quiz which is all about Space!\n");
  printf("*********************************************\n\n");
  v_allaboutspace();
  printf("Do you want to play again? (1 - yes, 0 - no): ");
  scanf("%d", &space_replay);
  if(space_replay == 1) {
    v_allaboutspace();
    } else{
        
    }
  printf("*****************************************\n");
  printf("Hope you enjoyed. TO INFINITY AND BEYOND!\n");
  printf("*****************************************\n\n");
    
}


void feedbackForm(void){
    int rating;
    char feedback[1000];

    printf("\nQuick Feedback Form:\n\n");
    printf("On a scale of 1 to 5, how would you rate the quiz? (1 being poor and 5 being excellent): ");
    scanf("%d", &rating);
    getchar();
    printf("Please provide any additional feedback: ");
    fgets(feedback, sizeof(feedback), stdin);

    printf("\nThank you for your feedback!\n");
    printf("Your rating: %d/5\n", rating);
    printf("Your feedback: %s\n", feedback);
}

void displayCredits(void) {
    printf("*******************************\n");
    printf("Thank you for playing our Game!\n");
    printf("*******************************\n\n");
    printf("This game was developed as a project for Hochschule Fulda. \nCreated by Vedant Bodhe, Emmanuel Afanyede, Berke Sevenler and Gabriel Tchakunte.\n\n");
    printf("Special thanks to:\n");
    printf("- Herr Thomas Papendieck (Lecturer: Programmiermethoden)\n");
    printf("- Frau Monika Schak (Lecturer: Programming-1 in C)\n");
}

void progress_bar(int percentage)
{
    printf("\r[");
    for (int i = 0; i < 50; i++)
    {
        if (i < (percentage / 2))
        {
            printf(">");
        }
        else
        {
            printf(" ");
        }
    }
    printf("] %d%%", percentage);
    fflush(stdout);
}

void v_progress_bar(int argc, char *argv[]){
    for (int i = 0; i <= 100; i++)
    {
        progress_bar(i);
        usleep(100000);
    }
    printf("\n");

}

int main(int argc, char *argv[]) {
    int choice;
    printf("\t\t     Welcome to the Game Menu!\n");
    printf("\t\t----------------------------\n\n");
    printf("\t\t----------------------------\n\n");
    printf("\t\t           Welcome!            \n\n");
    printf("\t\t----------------------------\n");
    printf("\t\t----------------------------\n\n");
    printf("\t\tPress 'Enter' to join the Game   \n");
    char joinGame;
    scanf("%c", &joinGame);
    joinGame = toupper(joinGame);
    if (joinGame != ' ') {
        char vorName[100] ={0};
        char nachName[100] ={0};
        printf("\t\tPlease enter your First Name   \n");
        scanf("%s", vorName);
        printf("\t\tPlease enter your Surname   \n");
        scanf("%s", nachName);
        printf("\t\t------------------------------------------\n\n");
        printf("\t\t------------------------------------------\n\n");
        printf("\t\t               Hello %s %s!             \n\n", vorName, nachName);
        printf("\t\t------------------------------------------\n\n");
        printf("\t\t------------------------------------------\n\n");
        printf("\n\nPlease choose one of the number options from below\n\n");
    }

    int jump_to_menu = 0;

    while (choice != 26 || jump_to_menu) {
    printf("Welcome to the Game Menu!\n");
    printf("1. QuizGame\n");
    printf("2. Fact or Lie?\n");
    printf("3. Who wants to be a millionaire\n");
    printf("4. Guess the Number!\n");
    printf("5. Guess the Word!\n");
    printf("6. Smart Brain\n");
    printf("7. Epic Game\n");
    printf("8. Rock,Paper,Scissors!\n");
    printf("9. Math Quiz\n");
    printf("10. Check your Horoscope!\n");
    printf("11. Play Geography Quiz!\n");
    printf("12. Mini-Game: Guess the animal!\n");
    printf("13. Basketball Quiz!\n");
    printf("14. Guess Barack Obama's birth Year!\n");
    printf("15. Germany Quiz!\n");
    printf("16. Breaking Bad Quiz!\n");
    printf("17. Mini-Game: Crossword Puzzle!\n");
    printf("18. Gambling Game!\n");
    printf("19. Mini-Game: History Quiz!\n");
    printf("20. All About Space and the Universe!\n");
    printf("21. Brain whiz\n");
    printf("22. Mini-Game: Personality Quiz!\n");
    printf("23. Mini-Game: Guess the Celebrity!\n");
    printf("24. Mini-Game: Hangman!\n");
    printf("25. Mini-Game: Football Quiz!\n");
    printf("26. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    v_progress_bar(argc,argv);

    switch(choice) {
        case 1:
            play_quizgame();
            jump_to_menu = 1;
            break;
        case 2:
            v_play_factorlie();
            jump_to_menu = 1;
            break;
        case 3:
            play_milliongame();
            jump_to_menu = 1;
            break;
        case 4:
            v_play_guessTheNumber();
            jump_to_menu = 1;
            break;
        case 5:
            v_play_guessTheWord();
            jump_to_menu = 1;
            break;
        case 6:
            e_smart_brain();
            jump_to_menu = 1;
            break;
        case 7:
            b_epic_game();
            jump_to_menu = 1;
            break;
        case 8:
            v_play_rockpapersciss();
            jump_to_menu = 1;
            break;
        case 9:
            math_enter_game();
            jump_to_menu = 1;
            break;
        case 10:
            v_play_horoscope();
            jump_to_menu = 1;
            break;
        case 11:
                b_play_geography();
                jump_to_menu = 1;
                break;  
        case 12:
                b_guess_animal();
                jump_to_menu = 1;
                break;          
        case 13:
                b_basketballQuiz();
                jump_to_menu = 1;
                break;
        case 14:
                b_guessbirthyear();
                jump_to_menu = 1;
                break;
        case 15:
                b_germanyquiz();
                jump_to_menu = 1;
                break;
        case 16:
                b_BreakingBquiz();
                jump_to_menu = 1;
                break;
        case 17:
                b_crossword();
                jump_to_menu = 1;
                break;
        case 18:
                b_gamble();
                jump_to_menu = 1;
                break;
        case 19:
                b_historyevents();
                jump_to_menu = 1;
                break;
        case 20:
                v_play_allaboutspace();
                jump_to_menu = 1;
                break;
        case 21:
                math_quiz_option();
                jump_to_menu = 1;
                break;
        case 22:
                b_personality();
                jump_to_menu = 1;
                break;
         case 23:
                b_celebrity();
                jump_to_menu = 1;
                break;
        case 24:
                b_hangman();
                jump_to_menu = 1;
                break;
        case 25:
                b_football();
                jump_to_menu = 1;
                break;
        case 26:
                printf("\nThank you for trying our C code!\n");
                break;
        default:
            printf("Invalid choice!\n");
    }
    if (jump_to_menu) {
            jump_to_menu = 0;
            printf("\nType any key and press enter to jump back to the Main Menu.\n");
            char jump_key;
            scanf(" %c", &jump_key);
            jump_key = toupper(jump_key);
            v_progress_bar(argc,argv);
        }
    }
    feedbackForm();
    displayCredits();
    return 0;
}



