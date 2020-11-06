#include <stdio.h>
#include "gameboard.h"

//������ ----����Լ�
void print_horiz_line(void)
{
	int i;
	// ��ġ ��� ��½� �ʿ��� ������ ----�� ���ϰ� ���� ����
	printf("\n ");
	for (i = 0; i < 2 * N + 1; i++)
		printf("-");
	printf("\n");
}

//���� �� ���� ���� ���
void print_status(void)
{
	int row, col; //������, ������ �� �� ���
	int white = 0; //��� �� �� �� ���
	int black = 0; //������ �� �� �� ���

	//��� �� ����
	for (row = 0; row < N; row++)
	{
		for (col = 0; col < N; col++)
		{
			if (gameboard[row][col] == 'O')
				white++;
		}
	}

	//������ �� ����
	for (row = 0; row < N; row++)
	{
		for (col = 0; col < N; col++)
		{
			if (gameboard[row][col] == 'O')
				black++;
		}
	}

	//�� ���� ���� ���
	printf(" STATUS - WHITE : %d, BLACK : %d", white, black);
}

//���� �� ��ġ ���� ���
void print_othello(void)
{
	int col, row; //row�� ������, col�� ������
	int i; // �ݺ��� ���� �� ���� ����

	//�� ��ġ ĭ ���
	printf(" ");
	for (i = 0; i < N; i++) // ���� ����� �� ���� ���
		printf(" %d", i);
	print_horiz_line();

	for (row = 0; row < N; row++)
	{
		printf("%d|", row); // �� ���ʿ��� ���° ���������� ���
		for (col = 0; col < N; col++)
		{
			printf("%c|", gameboard[row][col]); // �迭 ���� �ִ� ���ڸ� ���
		}
		print_horiz_line();
	}
	printf("\n");


	//�� ���� ���� ���
	print_status();
}
