#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <string.h>
#define STRING_LIMIT 256

int get_term_width(){
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  return w.ws_col;
}

int get_term_height(){
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  return w.ws_row;
}

void draw_horizontal_bound(char corner, char line, int width){
  printf("%c", corner);
  for(int i=0; i< width+2; i++) printf("%c", line);
  printf("%c", corner);
  printf("\n");
}

void draw_space(char line2, int width){
  printf("%c", line2);
  for(int i=0; i< width+2; i++) printf(" ");
  printf("%c", line2);
  printf("\n");
}


void draw_box(int height, int width, char corner, char line, char line2, char text[STRING_LIMIT]){

  //TO DO
  // theres a bug with displaying the string

  
  draw_horizontal_bound(corner, line, width);
  draw_space(line2, width);

  //insert the string
  printf("%c%c", line2, ' ');
  printf("%s", text);
  printf("%c%c", line2, '\n');  //bug here

  // k ik where the bug is
  //when inputting the string im also inputting a newline to finish the command
  //maybe it becomes part of the string who knows ..
  
  // it should be solved if i start taking input from command args (i hope)

  draw_space(line2, width);
  draw_horizontal_bound(corner, line, width);
  
}

int main(int argc, char **argv){
  int term_height = get_term_height();
  int term_width = get_term_width();

  char str[STRING_LIMIT];
  fgets(str, STRING_LIMIT, stdin);
  int s_width = strlen(str);

  printf("\n\n");
  draw_box(3, s_width, '#', '#', '#', str);
  
  return 0;
}
