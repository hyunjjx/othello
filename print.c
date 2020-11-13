#include "gameboard.h"

//������ ----����Լ�
void print_horiz_line(void)
{
	// ��ġ ��� ��½� �ʿ��� ������ ----�� ���ϰ� ���� ����
	int i;

	printf("\n ");
	for (i = 0; i < 2 * N + 1; i++)
		printf("-");
	printf("\n");
}

//���� �� ���� ���� ���
void print_status(void)
{
	int row, col; //������, ������ �� �� ���
	int white = 0; //��� �� �� ��
	int black = 0; //������ �� �� ��

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
			if (gameboard[row][col] == 'X')
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
	int i; //�ݺ���

	/* �� ��ġ ���� ��� ����
	 0 1 2 3	//ù��° ��
	 --------
	 0| | | |	// ����° ��,	0��
	 1| | | |					1��
	 2| | | |					2��
	 3| | | |					3��
	 --------
	*/

	// ù��° �� ���
	printf(" ");
	for (i = 0; i < N; i++)
		printf(" %d", i);
	print_horiz_line();

	// �� ��° �ٺ��� ���
	for (row = 0; row < N; row++)
	{
		printf("%d|", row); // ������ �� ��° ������
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

//������ ��� ��� �Լ�
void print_flip_result(int n, int s, int w, int e,
	int nw, int ne, int sw, int se)
{
	int sum;

	//��� ���⿡�� ��� �� ���������� ���
	printf("\n\n");
	printf(" :: flip result :: \n");
	printf("N: %d	S: %d	W: %d	E: %d\n", n, s, w, e);
	printf("NW: %d	NE: %d	SW: %d	SE: %d\n", nw, ne, sw, se);

	//�÷��̾ �� � ���������� ��� ���
	sum = n + s + w + e + nw + ne + sw + se;
	printf("White has flipped %d othellos! \n\n\n", sum);
}
