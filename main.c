#include "gameboard.h"

int main(void)
{
	int scan_row, scan_col;
	int player = 0; // 턴이 진행될 때 마다 1씩 증가. 2로 나눠 나머지가 0일땐 white player.
	init_othello(); // 게임 초기화
	while (isGameEnd()==0)
	{
		print_othello(); // 배치상태 출력
		if (!check_put_stone()) //놓을 수 있는 칸이 없다면 반복문 빠져나감
			continue;

		if ((player % 2)==0)
		{
		//흰색 돌 플레이어 차례
			if (all_check_put_white_stone() == 0)
			{
				printf("\nwhite player's turn is passed!\n");
				player++;
				continue;
			}

				// 배치할 입력좌표 받기
				printf("\n\nput a new white othello : ");
				scanf_s("%d %d", &scan_row, &scan_col);

				// 입력좌표가 부적절하다면
				while (check_put_white_stone(scan_row, scan_col) == 0)
				{
					printf("invalid input!\n");
					printf("put a new white othello :");
					scanf_s("%d %d", &scan_row, &scan_col);
				} 

				// 입력 좌표가 적절하다면
				gameboard[scan_row][scan_col] = 'O';
				try_flip_white_player(scan_row, scan_col);
				player++;

		}
		else //검은색 돌 플레이어 차례
		{
			if (all_check_put_black_stone() == 0)
			{
				printf("\nblack player's turn is passed!\n");
				player++;
				continue;
			}

					// 배치할 입력좌표 받기
			printf("\n\nput a new black othello : ");
			scanf_s("%d %d", &scan_row, &scan_col);

			// 입력좌표가 부적절하다면
			while (check_put_black_stone(scan_row, scan_col) == 0)
			{
				printf("invalid input! \n");
				printf("put a new black othello :");
				scanf_s("%d %d", &scan_row, &scan_col);
			}

			// 입력 좌표가 적절하다면
			gameboard[scan_row][scan_col] = 'X';
			try_flip_black_player(scan_row, scan_col);

			player++;

		}

		
	}
	print_game_result();
	return 0;
}
