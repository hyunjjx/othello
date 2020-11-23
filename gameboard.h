#include <stdio.h>
#define N 6
int gameboard[N][N];

//print.c
void print_horiz_line(void);
void print_status(void);
void print_othello(void);
void print_flip_result(int n, int s, int w, int e,
	int nw, int ne, int sw, int se, int player);
void print_game_result(void);

//other.c
void init_othello(void);
int check_put_stone(void);
int isGameEnd(void);
void print_game_result(void);

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
int all_check_put_white_stone(void);

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
int all_check_put_black_stone(void);

//try_flip_and_print_result.c
void try_flip_white_player(int row, int col);
void try_flip_black_player(int row, int col);
