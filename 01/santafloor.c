#include <stdio.h>

void main(){
  FILE *fp;
  fp = fopen( "moves.txt", "r" );
  int floor = 0;
  int pt = 1;
  int basement = 0;

  char c;
  while( (c = fgetc(fp)) != EOF ){
    if( c == '(' ) {
      floor++;
    } else if( c == ')' ){
      floor--;
    }

    if( (floor < 0) && (basement == 0) ){
      basement = pt;
    }
    pt++;
  }
 fclose(fp);
 printf("floors: %d basementpos: %d \n",floor, basement);
}
