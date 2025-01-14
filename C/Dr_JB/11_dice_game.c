/* 11_dice_game.c */
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

unsigned int myRandom(unsigned int max){
  return rand() % max + 1;
}
int main () {

  //seed
  srand(getpid());
  //1.create a variable named balance and assign the value of 1000
  unsigned int balance = 1000;
  unsigned int bet,guess,dice;
  while(balance){
  //2.ask user to bet
  printf("please place your bet: ");
  fflush(stdout);
  scanf("%u",&bet);
  printf("please enter your guess,0 to exit: ");
  fflush(stdout);
  scanf("%u",&guess);
  if(guess == 0)
    return 0;
  printf("Throwing the dice ...\n");
  sleep(2);
  dice = myRandom(6);
  if(guess == dice){
      balance += bet * 3;
      printf("You won - congratulation! balance: %u\n",balance);
    }
  else {
      balance -= bet;
      printf("Sorry, you lost! balance: %u\n",balance);
    }
  }
  printf("GAME OVER!\n");
  return 0;
}
