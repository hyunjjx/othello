#include <stdio.h>
#include "gameboard.h"

//���� �ʱ�ȭ
void init_othello(void)
{
	int row, col; //�ݺ������� �ʿ�

	/*ù��° �����ٿ���, 0��° ĭ���� ������ ĭ���� ���鹮�� ������ ��
	�ι�° �����ٷ� �Ѿ��, �ٽ� 0��° ĭ���� ������ ĭ���� ���鹮�� ����
	�̷������� ������ �����ٱ��� ����*/

	//�ϴ� ��� ĭ�� ���鹮�� ����
	for (row = 0; row < N; row++)
	{
		for (col = 0; col < N; col++)
			gameboard[row][col] = ' ';
	}

	//�߾� ĭ�� O��, X�� �ΰ��� ����
	gameboard[N / 2 - 1][N / 2 - 1] = 'O';
	gameboard[N / 2][N / 2] = 'O';
	gameboard[N / 2][N / 2 - 1] = 'X';
	gameboard[N / 2 - 1][N / 2] = 'X';
}

//�� ��ġ�� ������ ĭ�� �ִ��� Ȯ��
int check_put_stone(void)
{
	int blank = 0; // �� ĭ�� ���� ����
	int check_white = 0;
	int check_black = 0;
	int flip = 0;
	int row, col;

	// ���� 1. �� ĭ�� �ִ��� Ȯ��
	// �迭 ���� ��ĭ�� ������ ����
	for (row = 0; row < N; row++)
	{
		for (col = 0; col < N; col++)
		{
			if (gameboard[row][col] == ' ')
				blank++;
		}
	}
	if (blank == 0)
		return 0; //��ġ ������ ĭ�� ����

	//����2. ���� ������ �� �ִ� ĭ�� �ִ��� Ȯ��
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