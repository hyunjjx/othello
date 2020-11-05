#include <stdio.h>
#define N 6

int gameboard[N][N];

void print_othello(void);
void print_horiz_line(void);
void init_othello(void);
void print_status(void);

// ��� ���� O, ������ ���� X

int main(void)
{

	init_othello(); // ���� �ʱ�ȭ

	print_othello(); // ��ġ���� ���
	

	return 0;
}

void print_othello(void) // ��ġ ���� ���
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

void print_horiz_line(void) //������ ------- ��� �Լ�
{
	// ��ġ��� ��½� �ʿ��� ������ ----�� ���ϰ� ���� ���� �Լ�
	int i;
	printf("\n ");
	for (i = 0; i < 2 * N + 1; i++)
		printf("-");
	printf("\n");
}

void init_othello(void) // ���� �ʱ�ȭ
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

void print_status(void) // ���� �� ���� ���� ���
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

void check_result(void) // ���� ���� ��� ���
{
	printf(" ");
}

