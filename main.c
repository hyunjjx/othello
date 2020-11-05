#include <stdio.h>
#define N 6

int gameboard[N][N];

void print_othello(void);
void print_horiz_line(void);
void init_othello(void);
void print_status(void);

// 흰색 돌은 O, 검은색 돌은 X

int main(void)
{

	init_othello(); // 게임 초기화

	print_othello(); // 배치상태 출력
	

	return 0;
}

void print_othello(void) // 배치 상태 출력
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

void print_horiz_line(void) //가로줄 ------- 출력 함수
{
	// 배치결과 출력시 필요한 가로줄 ----을 편리하게 쓰기 위한 함수
	int i;
	printf("\n ");
	for (i = 0; i < 2 * N + 1; i++)
		printf("-");
	printf("\n");
}

void init_othello(void) // 게임 초기화
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

void print_status(void) // 현재 돌 개수 상태 출력
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

void check_result(void) // 게임 최종 결과 출력
{
	printf(" ");
}

