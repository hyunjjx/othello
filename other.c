#include "gameboard.h"

//게임 초기화
void init_othello(void)
{
	int row, col; //반복문에서 필요

	/*첫번째 가로줄에서, 0번째 칸부터 마지막 칸까지 공백문자 대입한 후
	두번째 가로줄로 넘어가서, 다시 0번째 칸부터 마지막 칸까지 공백문자 대입
	이런식으로 마지막 가로줄까지 대입*/

	//일단 모든 칸에 공백문자 저장
	for (row = 0; row < N; row++)
	{
		for (col = 0; col < N; col++)
			gameboard[row][col] = ' ';
	}

	//중앙 칸에 O돌, X돌 두개씩 저장
	gameboard[N / 2 - 1][N / 2 - 1] = 'O';
	gameboard[N / 2][N / 2] = 'O';
	gameboard[N / 2][N / 2 - 1] = 'X';
	gameboard[N / 2 - 1][N / 2] = 'X';
}

//돌 배치가 가능한 칸이 있는지 확인
int check_put_stone(void)
{
	int blank = 0; // 빈 칸의 개수 세기
	int check_white = 0;
	int check_black = 0;
	int flip = 0;
	int row, col;

	// 조건 1. 빈 칸이 있는지 확인
	// 배열 내에 빈칸의 개수를 세기
	for (row = 0; row < N; row++)
	{
		for (col = 0; col < N; col++)
		{
			if (gameboard[row][col] == ' ')
				blank++;
		}
	}
	if (blank == 0)
		return 0; //배치 가능한 칸이 없음

	//조건2. 돌을 뒤집을 수 있는 칸이 있는지 확인
	for (row = 0; row < N; row++)
	{
		for (col = 0; col < N; col++)
		{
			check_white += check_put_white_stone(row, col);
			check_black += check_put_black_stone(row, col);
		}
	}
	if ((check_white + check_black) > 0)
		return 1;
	else
		return 0;
}

//게임 종료 조건
int isGameEnd(void) //게임 종료할 조건. 반환값이 0이면 게임 계속 진행
{
	/* 게임 종료 조건.
	칸이 모두 차거나
	모든 알이 한가직 색으로 통일되거나,
	양쪽 player 모두 뒤집기 가능한 칸이 없을때
	*/

	
	int row, col;
	int blank = 0;
	int white = 0, black = 0;
	int check_white = 0, check_black = 0;

	//칸이 모두 찬 경우
	for (row = 0; row < N; row++)
	{
		for (col = 0; col < N; col++)
		{
			if (gameboard[row][col] == ' ')
				blank++;
		}
	}
	if (blank == 0)
		return 1; //게임 종료

	// 모든 알이 한가지 색으로 통일될 때 (빈칸 있어도 됨)
	//판의 흰색과 검은색 돌 개수 모두 센 뒤, 둘 중 하나라도 0이 있다면 
	//게임 종료
	for (row = 0; row < N; row++)
	{
		for (col = 0; col < N; col++)
		{
			if (gameboard[row][col] == 'O')
				white++;
			if (gameboard[row][col] == 'X')
				black++;
		}
	}

	if (white == 0)
		return 1;
	if (black == 0)
		return 1;

	//두 플레이어가 놓을 수 있는 돌이 있다면
	for (row = 0; row < N; row++)
	{
		for (col = 0; col < N; col++)
		{
			check_white += check_put_white_stone(row, col);
			check_black += check_put_black_stone(row, col);
		}
	}
	if ((check_white + check_black) > 0)
		return 0; //게임 계속 진행
	else
		return 1; //게임 종료
}

//게임 결과 출력
//알의 배치 및 최종 승자
void print_game_result(void)
{
	int row, col;
	int white = 0, black = 0;
	int blank = 0;
	
	printf("\n\n::gameresult::\n");
	print_othello();
	//흰색 돌과 검은색 돌 개수 세기
	for (row = 0; row < N; row++)
	{
		for (col = 0; col < N; col++)
		{
			if (gameboard[row][col] == 'O')
				white++;
			if (gameboard[row][col] == 'X')
				black++;
		}
	}

	if (white > black)
		printf("\nwhite player win! \n");
	else if (black > white)
		printf("\n black player win! \n");
	else
		printf("\nwhite player and black player tied! \n");



}
