#include <stdio.h>
#define MAX_INT 999999
#define MIN_INT -999999
void main(){
  FILE *fp;
  char *fn = "moves.txt";

  //Count the size of the required array
  int xmin=MAX_INT, xmax=MIN_INT, ymin=MAX_INT, ymax=MIN_INT;
  int x = 0, y = 0;
  fp = fopen( fn, "r" );
  char c;
  while( (c = fgetc(fp)) != EOF ){
    switch( c ){
      case '>':
        x++;
        break;
      case '<':
        x--;
        break;
      case '^':
        y++;
        break;
      case 'v':
        y--;
        break;
      default:
        break;
    }
    if( x > xmax ){
      xmax = x;
    } else if ( x < xmin ){
      xmin = x;
    }
    if( y > ymax ){
      ymax = y;
    } else if ( y < ymin ){
      ymin = y;
    }
  }
  fclose(fp);

  //Now that we know how big of a grid santa is working on, we can do some
  //stuff with arrays.  yaaaaaaaaaaaay
  int x_offset = xmin;
  int y_offset = ymin;
  int x_size = xmax - x_offset + 1;
  int y_size = ymax - y_offset + 1;
  printf("x: %d %d y: %d %d\n", xmin, xmax, ymin, ymax);
  printf("x: %d y: %d\n", x_size, y_size);
  fp = fopen( fn, "r" );
  int houses[ x_size ][ y_size ];
  int i, j;
  for( i = 0; i < x_size; i++ ){
    for( j = 0; j < y_size; j++ ){
      houses[i][j] = 0;
    }
  }

  int total = 1;
  x = 0 - x_offset;
  y = 0 - y_offset;
  houses[x][y] = 1;
  while((c = fgetc(fp)) != EOF){
    switch( c ){
      case '>':
        x++;
        break;
      case '<':
        x--;
        break;
      case '^':
        y++;
        break;
      case 'v':
        y--;
        break;
      default:
        break;
    }
    if( houses[x][y] == 0 ){
      total++;
    }
    houses[x][y]++;
  }
  fclose(fp);
  printf("Houses: %d\n", total);
}
