#include <stdio.h>
#include <stdbool.h>
#include "utils.h"

#include <stdlib.h>
#include <time.h>

char *ask_question_string(char *question, char *buf, int buf_siz);


int main(void){
  // Buffer for name input
  int buf_siz_name       = 20;
  char buf_name[buf_siz_name];
 
  int guess           = 0;  // Current Guess
  int guess_count     = 0;  // Amount of Guesses
  int guess_count_max = 15; // Maximum Amount of Guesses

  // Get Random Number
  seed_random();                
  int num = random_number(100); 

  // Print Rules
  ask_question_string("Skriv ditt namn: ", buf_name, buf_siz_name);
  printf("Du %s, jag tänker på ett tal.\n", buf_name);
  puts("Kan du gissa vilket?");

  
  do{
    // Get Guess
    guess = ask_question_int_safe("", 5);
    guess_count++;
    
    if (guess == -1) {
      printf("Gissningen är inte ett nummer!\n");           
    }else{
      if (guess > num){
	puts("För stort!\n");
      }else if (guess < num){
	puts("För litet!\n");
      }

      // Print Guesses Left
      printf("Gissning %d av %d", guess_count, guess_count_max);

      // Exit if Too Much guesses
      if (guess_count >= guess_count_max){
	printf("Slut på gissningar, jag tänkte på %d\n", num);
	return 0;
      }
      
    }
  }while (guess != num);

  // Succeded, Print Winning Message
  printf("Bingo! Det tog %s %d många gissningar\n", buf_name, guess_count);
  printf("att komma fram till %d.\n", num);

  return 0;

}
