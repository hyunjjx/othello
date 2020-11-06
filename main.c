#include <stdio.h>
#include "gameboard.h"

int main(void)
{
	int scan_row, scan_col;
	int player = 0; // 턴이 진행될 때 마다 1씩 증가. 2로 나눠 나머지가 0일땐 white player.
	init_othello(); // 게임 초기화
	//while ()
	//{
		print_othello(); // 배치상태 출력
		//if (!check_put_stone()) //놓을 수 있는 칸이 없다면 반복문 빠져나감
			//continue;

		/*if ((player / 2) == 0) //white player 차례
		{
			// 배치할 입력좌표 받기
			printf("\n\nput a new white othello : ");
			scanf_s("%d %d", &scan_row, &scan_col);
			if (check_put_white_stone(scan_row, scan_col)) //입력좌표가 적절하다면
				if


		}	*/	

	//}
	return 0;
}
