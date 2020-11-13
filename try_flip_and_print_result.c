#include "gameboard.h"

//흰색돌 플레이어가 뒤집기 시도
void try_flip_white_player(int row, int col)
{
	int north = 0, south = 0, west = 0, east = 0;
	int north_west = 0, north_east = 0;
	int south_west = 0, south_east = 0;
	int k; //반복문에서 필요

	/*	방향 명칭을 이용한 변수는 
		그 방향으로 상대방 돌이 몇 개 있는지 세고,
		그 만큼 돌을 뒤집는다.
	*/

	//북쪽 돌 뒤집기 시도
	if (north_im_white(row, col) == 1)
	{
		while (gameboard[row - 1 - north][col] == 'X')
		{
			north++;
		}

		//돌 뒤집기
		for (k = 0; k < north; k++)
			gameboard[row - 1 - k][col] = 'O';
	}

	//남쪽 돌 뒤집기 시도
	if (south_im_white(row, col) == 1)
	{
		while (gameboard[row + 1 + south][col] == 'X')
		{
			south++;
		}
		for (k = 0; k < south; k++)
			gameboard[row + 1 + k][col] = 'O';
	}

	//서쪽(오른쪽) 돌 뒤집기 시도
	if (west_im_white(row, col) == 1)
	{
		while (gameboard[row][col + 1 + west] == 'X')
		{
			west++;
		}
		for (k = 0; k < west; k++)
			gameboard[row][col + 1 + k] = 'O';
	}

	//동쪽(왼쪽) 돌 뒤집기 시도
	if (east_im_white(row, col) == 1)
	{
		while (gameboard[row][col - 1 - east] == 'X')
		{
			east++;
		}
		for (k = 0; k < east; k++)
			gameboard[row][col - 1 - k] = 'O';
	}

	//북서쪽(오른쪽 위에) 돌 뒤집기 시도
	if (north_west_im_white(row, col) == 1)
	{
		while (gameboard[row - 1 - north_west][col + 1 + north_west] == 'X')
		{
			north_west++;
		}
		for (k = 0; k < north_west; k++)
			gameboard[row - 1 - k][col + 1 + k] = 'O';
	}

	//북동쪽(오른쪽 위에) 돌 뒤집기 시도
	if (north_east_im_white(row, col) == 1)
	{
		while (gameboard[row - 1 - north_east][col - 1 - north_east] == 'X')
		{
			north_east++;
		}
		for (k = 0; k < north_east; k++)
			gameboard[row - 1 - k][col - 1 - k] = 'O';
	}

	//남서쪽(오른쪽 아래) 돌 뒤집기 시도
	if (south_west_im_white(row, col) == 1)
	{
		while (gameboard[row + 1 + south_west][col + 1 + south_west] == 'X')
		{
			south_west++;
		}
		for (k = 0; k < south_west; k++)
			gameboard[row + 1 + k][col + 1 + k] = 'O';
	}

	//남동쪽(왼쪽 아래) 돌 뒤집기 시도
	if (south_east_im_white(row, col) == 1)
	{
		while (gameboard[row + 1 + south_east][col - 1 - south_east] == 'X')
		{
			south_east++;
		}
		for (k = 0; k < south_east; k++)
			gameboard[row + 1 + k][col - 1 - k] = 'O';
	}

	//방향 에 따른 뒤집기 결과 출력
	print_flip_result(north, south, west, east,
		north_west, north_east, south_west, south_east);
}

//검은색돌 플레이어가 뒤집기 시도
void try_flip_black_player(int row, int col)
{
	int north = 0, south = 0, west = 0, east = 0;
	int north_west = 0, north_east = 0;
	int south_west = 0, south_east = 0;
	int k; //반복문에서 필요

	/*	방향 명칭을 이용한 변수는
		그 방향으로 상대방 돌이 몇 개 있는지 세고,
		그 만큼 돌을 뒤집는다.
	*/
	//북쪽 돌 뒤집기 시도
	if (north_im_black(row, col) == 1)
	{
		//돌 몇개 있는지 세기
		while (gameboard[row - 1 - north][col] == 'O')
		{
			north++;
		}

		//돌 뒤집기
		for (k = 0; k < north; k++)
			gameboard[row - 1 - k][col] = 'X';
	}

	//남쪽 돌 뒤집기 시도
	if (south_im_black(row, col) == 1)
	{
		while (gameboard[row + 1 + south][col] == 'O')
		{
			south++;
		}
		for (k = 0; k < south; k++)
			gameboard[row + 1 + k][col] = 'X';
	}

	//서쪽(오른쪽) 돌 뒤집기 시도
	if (west_im_black(row, col) == 1)
	{
		while (gameboard[row][col + 1 + west] == 'O')
		{
			west++;
		}
		for (k = 0; k < west; k++)
			gameboard[row][col + 1 + k] = 'X';
	}

	//동쪽(왼쪽) 돌 뒤집기 시도
	if (east_im_black(row, col) == 1)
	{
		while (gameboard[row][col - 1 - east] == 'O')
		{
			east++;
		}
		for (k = 0; k < east; k++)
			gameboard[row][col - 1 - k] = 'X';
	}

	//북서쪽(오른쪽 위에) 돌 뒤집기 시도
	if (north_west_im_black(row, col) == 1)
	{
		while (gameboard[row - 1 - north_west][col + 1 + north_west] == 'O')
		{
			north_west++;
		}
		for (k = 0; k < north_west; k++)
			gameboard[row - 1 - k][col + 1 + k] = 'X';
	}

	//북동쪽(오른쪽 위에) 돌 뒤집기 시도
	if (north_east_im_black(row, col) == 1)
	{
		while (gameboard[row - 1 - north_east][col - 1 - north_east] == 'O')
		{
			north_east++;
		}
		for (k = 0; k < north_east; k++)
			gameboard[row - 1 - k][col - 1 - k] = 'X';
	}

	//남서쪽(오른쪽 아래) 돌 뒤집기 시도
	if (south_west_im_black(row, col) == 1)
	{
		while (gameboard[row + 1 + south_west][col + 1 + south_west] == 'O')
		{
			south_west++;
		}
		for (k = 0; k < south_west; k++)
			gameboard[row + 1 + k][col + 1 + k] = 'X';
	}

	//남동쪽(왼쪽 아래) 돌 뒤집기 시도
	if (south_east_im_black(row, col) == 1)
	{
		while (gameboard[row + 1 + south_east][col - 1 - south_east] == 'O')
		{
			south_east++;
		}
		for (k = 0; k < south_east; k++)
			gameboard[row + 1 + k][col - 1 - k] = 'X';
	}

	//방향 에 따른 뒤집기 결과 출력
	print_flip_result(north, south, west, east,
		north_west, north_east, south_west, south_east);
}
