#include <stdio.h>
#define N 6
int gameboard[N][N];

//print.c ���� �Լ� ����
void print_horiz_line(void);
void print_status(void);
void print_othello(void);

//other.c ���� �Լ� ����
void init_othello(void);
int check_put_stone(void);

//check_put_white_stone.c
int north_im_white(int x, int y);
int south_im_white(int x, int y);
int east_im_white(int x, int y);
int west_im_white(int x, int y);
int north_east_im_white(int x, int y);
int north_west_im_white(int x, int y);
int south_east_im_white(int x, int y);
int south_west_im_white(int x, int y);
int check_put_white_stone(int a, int b);

//check_put_black_stone.c
int north_im_black(int x, int y);
int south_im_black(int x, int y);
int east_im_black(int x, int y);
int west_im_black(int x, int y);
int north_east_im_black(int x, int y);
int north_west_im_black(int x, int y);
int south_east_im_black(int x, int y);
int south_west_im_black(int x, int y);
int check_put_black_stone(int a, int b);