#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  clear_screen(s);
  color c;

  struct matrix *m2;
  m2 = new_matrix(4, 2);

  printf("\nTesting add_edge. Adding (1, 2, 3), (4, 5, 6) m2 =\n");
  add_edge(m2, 1, 2, 3, 4, 5, 6);
  print_matrix(m2);
  printf("\n");

  struct matrix *m1;
  m1 = new_matrix(4, 4);

  printf("Testing ident. m1 =\n");
  ident(m1);
  print_matrix(m1);
  printf("\n");

  printf("Testing Matrix mult. m1 * m2 =\n");
  matrix_mult(m1, m2);
  print_matrix(m2);
  printf("\n");

  printf("Testing Matrix mult. m1 =\n");
  free_matrix(m1);
  m1 = new_matrix(4, 4);
  add_edge(m1, 1, 2, 3, 4, 5, 6);
  add_edge(m1, 7, 8, 9, 10, 11, 12);
  print_matrix(m1);
  printf("\n");

  printf("Testing Matrix mult. m1 * m2 =\n");
  matrix_mult(m1, m2);
  print_matrix(m2);
  printf("\n");

  free_matrix(m1);
  free_matrix(m2);

  printf("Drawing picture...\n\n");

  struct matrix *m3;
  m3 = new_matrix(4,4);
  int i, j, k;

  c.red = 255;

  // Left Leg
  add_edge(m3,100,50,0,200,50,0);
  add_edge(m3,200,50,0,200,125,0);
  add_edge(m3,200,125,0,205,135,0);
  add_edge(m3,205,135,0,215,140,0);
  add_edge(m3,215,140,0,225,145,0);
  add_edge(m3,225,145,0,275,145,0);

  // Right Leg
  add_edge(m3,400,50,0,300,50,0);
  add_edge(m3,300,50,0,300,125,0);
  add_edge(m3,300,125,0,295,135,0);
  add_edge(m3,295,135,0,285,140,0);
  add_edge(m3,285,140,0,275,145,0);

  // Left Side
  add_edge(m3,100,50,0,100,300,0);
  add_edge(m3,100,300,0,105,320,0);
  add_edge(m3,105,320,0,115,335,0);
  add_edge(m3,115,335,0,125,345,0);
  add_edge(m3,125,345,0,140,355,0);
  add_edge(m3,140,355,0,155,360,0);
  add_edge(m3,155,360,0,175,365,0);
  add_edge(m3,175,365,0,205,370,0);
  add_edge(m3,205,370,0,295,370,0);

  // Right Side
  add_edge(m3,400,50,0,400,300,0);
  add_edge(m3,400,300,0,395,320,0);
  add_edge(m3,395,320,0,385,335,0);
  add_edge(m3,385,335,0,375,345,0);
  add_edge(m3,375,345,0,360,355,0);
  add_edge(m3,360,355,0,345,360,0);
  add_edge(m3,345,360,0,325,365,0);
  add_edge(m3,325,365,0,295,370,0);

  draw_lines(m3,s,c);

  struct matrix *m4;
  m4 = new_matrix(4,4);
  c.red = 70;
  c.green = 200;
  c.blue = 255;

  // Goggles Left Up
  add_edge(m4,150,300,0,153,310,0);
  add_edge(m4,153,310,0,160,315,0);
  add_edge(m4,160,315,0,170,320,0);
  add_edge(m4,170,320,0,185,325,0);
  add_edge(m4,185,325,0,205,328,0);
  add_edge(m4,205,328,0,225,330,0);
  add_edge(m4,225,330,0,275,330,0);

  // Goggles Right Up
  add_edge(m4,350,300,0,347,310,0);
  add_edge(m4,347,310,0,340,315,0);
  add_edge(m4,340,315,0,330,320,0);
  add_edge(m4,330,320,0,315,325,0);
  add_edge(m4,315,325,0,295,328,0);
  add_edge(m4,295,328,0,275,330,0);

  // Goggles Left Down
  add_edge(m4,150,300,0,153,290,0);
  add_edge(m4,153,290,0,160,285,0);
  add_edge(m4,160,285,0,170,280,0);
  add_edge(m4,170,280,0,185,275,0);
  add_edge(m4,185,275,0,205,272,0);
  add_edge(m4,205,272,0,225,270,0);
  add_edge(m4,225,270,0,275,270,0);

  // Goggles Right Down
  add_edge(m4,350,300,0,347,290,0);
  add_edge(m4,347,290,0,340,285,0);
  add_edge(m4,340,285,0,330,280,0);
  add_edge(m4,330,280,0,315,275,0);
  add_edge(m4,315,275,0,295,272,0);
  add_edge(m4,295,272,0,275,270,0);

  draw_lines(m4,s,c);

  // save_ppm_ascii(s, "work02.ppm");
  display(s);
  save_extension(s, "amogus.png");

}
