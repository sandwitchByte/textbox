#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <string.h>
#define STRING_LIMIT 256

struct config{

  char corner;
  char horizontal_line;
  char vertical_line;

  int help;
};
  
void show_help(struct config conf){
  printf("Usage: textbox [MESSAGE] [OPTION ..]\n\n");
  printf("textbox is a small tool that puts text into an ASCII box\n\n");
  printf("Options:\n");
  printf("\t-c    set a custom character for the corner (default is '+')\n");
  printf("\t-h    set a custom character for the horizontal lines (default is '-')\n");
  printf("\t-v    set a custom character for the vertical lines (default is '|')\n");
  printf("\t-h    show help\n");
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
  
  draw_horizontal_bound(corner, line, width);
  draw_space(line2, width);

  //insert the string
  printf("%c%c", line2, ' ');
  printf("%s", text);
  printf(" %c%c", line2, '\n'); 

  draw_space(line2, width);
  draw_horizontal_bound(corner, line, width);
  
}

int main(int argc, char **argv){

  char str[STRING_LIMIT];
  strcpy(str, argv[1]);
  int s_width = strlen(str);

  printf("\n\n");
  draw_box(3, s_width, '+', '-', '|', str);

  return 0;
}
