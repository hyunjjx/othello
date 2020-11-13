#include "gameboard.h"

//가로줄 ----출력함수
void print_horiz_line(void)
{
	// 배치 결과 출력시 필요한 가로줄 ----을 편리하게 쓰기 위함
	int i;

	printf("\n ");
	for (i = 0; i < 2 * N + 1; i++)
		printf("-");
	printf("\n");
}

//현재 돌 개수 상태 출력
void print_status(void)
{
	int row, col; //가로줄, 세로줄 셀 때 사용
	int white = 0; //흰색 돌 셀 때
	int black = 0; //검은색 돌 셀 때

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
			if (gameboard[row][col] == 'X')
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
	int i; //반복문

	/* 돌 배치 상태 출력 예시
	 0 1 2 3	//첫번째 줄
	 --------
	 0| | | |	// 세번째 줄,	0행
	 1| | | |					1행
	 2| | | |					2행
	 3| | | |					3행
	 --------
	*/

	// 첫번째 줄 출력
	printf(" ");
	for (i = 0; i < N; i++)
		printf(" %d", i);
	print_horiz_line();

	// 세 번째 줄부터 출력
	for (row = 0; row < N; row++)
	{
		printf("%d|", row); // 지금이 몇 번째 행인지
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

//뒤집은 결과 출력 함수
void print_flip_result(int n, int s, int w, int e,
	int nw, int ne, int sw, int se)
{
	int sum;

	//어느 방향에서 몇개의 돌 뒤집었는지 출력
	printf("\n\n");
	printf(" :: flip result :: \n");
	printf("N: %d	S: %d	W: %d	E: %d\n", n, s, w, e);
	printf("NW: %d	NE: %d	SW: %d	SE: %d\n", nw, ne, sw, se);

	//플레이어가 총 몇개 뒤집었는지 결과 출력
	sum = n + s + w + e + nw + ne + sw + se;
	printf("White has flipped %d othellos! \n\n\n", sum);
}
