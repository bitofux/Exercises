#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>


static char* trl(unsigned int timeout){

  //create a buff
  static char buf[513];
  
  fd_set rfds;
  FD_ZERO(&rfds);
  FD_SET(STDIN_FILENO,&rfds);
  struct timeval tv;
  tv.tv_sec = timeout;
  tv.tv_usec = 0;
  
  int ret = select(1, &rfds, 0, 0, &tv);
  if(ret && FD_ISSET(STDIN_FILENO,&rfds)){
    unsigned int read_ret = read(STDIN_FILENO,buf,sizeof(buf) - 1);
    if(read_ret < 1)
      return NULL;
    buf[--read_ret] = '\0';
    return buf;
  }else 
    return NULL;

}
int main () {

  char* name;
  printf("What is your name? Think fast!\n");
  name = trl(3);
  if(name != NULL)
    printf("Hello %s\n",name);
  else 
    printf("Too slow!\n");

  return 0;
}
