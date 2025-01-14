/* 11_dice_game.c */
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main () {

  //seed
  srand(getpid());
  //1.create a variable named balance and assign the value of 1000
  unsigned int balance = 1000;
  unsigned int bet,guess;
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
  sleep(2);
  unsigned int dice = rand() % 7;
  if(guess == dice){
      balance += bet * 3;
      printf("your balance: %u\n",balance);
    }
  else {
      balance -= bet;
      printf("your balance: %u\n",balance);
    }
  }
}
