#include "gameboard.h"

int main(void)
{
	int scan_row, scan_col;
	int player = 0; // ���� ����� �� ���� 1�� ����. 2�� ���� �������� 0�϶� white player.
	init_othello(); // ���� �ʱ�ȭ
	while (isGameEnd()==0)
	{
		print_othello(); // ��ġ���� ���
		if (!check_put_stone()) //���� �� �ִ� ĭ�� ���ٸ� �ݺ��� ��������
			continue;

		if ((player % 2)==0)
		{
		//��� �� �÷��̾� ����
			if (all_check_put_white_stone() == 0)
			{
				printf("\nwhite player's turn is passed!\n");
				player++;
				continue;
			}

				// ��ġ�� �Է���ǥ �ޱ�
				printf("\n\nput a new white othello : ");
				scanf_s("%d %d", &scan_row, &scan_col);

				// �Է���ǥ�� �������ϴٸ�
				while (check_put_white_stone(scan_row, scan_col) == 0)
				{
					printf("invalid input!\n");
					printf("put a new white othello :");
					scanf_s("%d %d", &scan_row, &scan_col);
				} 

				// �Է� ��ǥ�� �����ϴٸ�
				gameboard[scan_row][scan_col] = 'O';
				try_flip_white_player(scan_row, scan_col);
				player++;

		}
		else //������ �� �÷��̾� ����
		{
			if (all_check_put_black_stone() == 0)
			{
				printf("\nblack player's turn is passed!\n");
				player++;
				continue;
			}

					// ��ġ�� �Է���ǥ �ޱ�
			printf("\n\nput a new black othello : ");
			scanf_s("%d %d", &scan_row, &scan_col);

			// �Է���ǥ�� �������ϴٸ�
			while (check_put_black_stone(scan_row, scan_col) == 0)
			{
				printf("invalid input! \n");
				printf("put a new black othello :");
				scanf_s("%d %d", &scan_row, &scan_col);
			}

			// �Է� ��ǥ�� �����ϴٸ�
			gameboard[scan_row][scan_col] = 'X';
			try_flip_black_player(scan_row, scan_col);

			player++;

		}

		
	}
	print_game_result();
	return 0;
}
