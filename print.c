#include <stdio.h>
#include "gameboard.h"

//가로줄 ----출력함수
void print_horiz_line(void)
{
	int i;
	// 배치 결과 출력시 필요한 가로줄 ----을 편리하게 쓰기 위함
	printf("\n ");
	for (i = 0; i < 2 * N + 1; i++)
		printf("-");
	printf("\n");
}

//현재 돌 개수 상태 출력
void print_status(void)
{
	int row, col; //가로줄, 세로줄 셀 때 사용
	int white = 0; //흰색 돌 셀 때 사용
	int black = 0; //검은색 돌 셀 때 사용

	//흰색 돌 세기
	for (row = 0; row < N; row++)
	{
		for (col = 0; col < N; col++)
		{
			if (gameboard[row][col] == 'O')
				white++;
		}
	}

	//검은색 돌 세기
	for (row = 0; row < N; row++)
	{
		for (col = 0; col < N; col++)
		{
			if (gameboard[row][col] == 'O')
				black++;
		}
	}

	//돌 개수 상태 출력
	printf(" STATUS - WHITE : %d, BLACK : %d", white, black);
}

//현재 돌 배치 상태 출력
void print_othello(void)
{
	int col, row; //row는 가로줄, col은 세로줄
	int i; // 반복문 돌릴 때 쓰일 변수

	//돌 배치 칸 출력
	printf(" ");
	for (i = 0; i < N; i++) // 상태 출력의 맨 윗줄 출력
		printf(" %d", i);
	print_horiz_line();

	for (row = 0; row < N; row++)
	{
		printf("%d|", row); // 맨 왼쪽에는 몇번째 가로줄인지 출력
		for (col = 0; col < N; col++)
		{
			printf("%c|", gameboard[row][col]); // 배열 내에 있는 문자를 출력
		}
		print_horiz_line();
	}
	printf("\n");


	//돌 개수 상태 출력
	print_status();
}
