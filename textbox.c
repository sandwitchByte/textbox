#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

int getTermWidth(){
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  return w.ws_col;
}

int getTermHeight(){
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  return w.ws_row;
}

int main(int argc, char **argv){
  int height = getTermHeight();
  int width = getTermWidth();

  return 0;
}
