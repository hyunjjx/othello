#include "gameboard.h"


/* 검은돌 놓는 player입장에서 표현.
	내용이 check_put_white_stone.c와 비슷하므로
	주석은 대부분 생략하였음
*/
int north_im_black(int x, int y)
{
	int i = 0;

	// 1단계
	if ((x - 1) < 0)
		return 0;

	else
	{
		// 2단계
		if (gameboard[x - 1][y] != 'O')
			return 0;
		else 
		{
			// 3단계
			if ((x - 2) < 0)
				return 0;	
			else
			{
				// 4단계
				while (gameboard[x - 2 - i][y] == 'O')
				{
					i++;
					if ((x - 2 - i) < 0)
						return 0;
				}

				// 5단계
				if (gameboard[x - 2 - i][y] == ' ') 
					return 0; 
				else
					return 1; 
			}
		}
	}
}

int south_im_black(int x, int y)
{
	int i = 0; 

	// 1단계
	if ((x + 1) > (N - 1)) 
		return 0; 

	else
	{
		// 2단계
		if (gameboard[x + 1][y] != 'O')
			return 0;
		else 
		{
			// 3단계
			if ((x + 2) > (N - 1))	
				return 0;		
			{
				// 4단계
				while (gameboard[x + 2 + i][y] == 'O')
				{
					i++;	
							
					if ((x + 2 + i) > (N - 1))
						return 0;
				}

				// 5단계
				if (gameboard[x + 2 + i][y] == ' ') 
					return 0;
				else
					return 1; 
			}
		}
	}
}

int east_im_black(int x, int y)
{
	int i = 0; 

	// 1단계
	if ((y - 1) < 0) 
		return 0; 

	else 
	{
		// 2단계
		if (gameboard[x][y - 1] != 'O')
			return 0;
		else 
		{
			// 3단계
			if ((y - 2) < 0)	
				return 0;	
			else
			{
				// 4단계
				while (gameboard[x][y - 2 - i] == 'O')
				{
					i++;	
					if ((y - 2 - i) < 0)
						return 0;
				}

				// 5단계
				if (gameboard[x][y - 2 - i] == ' ') 
					return 0;
				else
					return 1; 
			}
		}
	}
}

int west_im_black(int x, int y)
{
	int i = 0; 

	// 1단계
	if ((y + 1) > (N - 1)) 
		return 0; 

	else 
	{
		// 2단계
		if (gameboard[x][y + 1] != 'O')
			return 0;
		else 
		{
			// 3단계
			if ((y + 2) > (N - 1))	
				return 0;	
			else
			{
				// 4단계
				while (gameboard[x][y + 2 + i] == 'O')
				{
					i++;	
					if ((y + 2 + i) > (N - 1))
						return 0;
				}

				// 5단계
				if (gameboard[x][y + 2 + i] == ' ') 
					return 0; 
				else
					return 1; 
			}
		}
	}
}

int north_west_im_black(int x, int y)
{
	int i = 0; 

	// 1단계
	if (((x - 1) < 0) || ((y + 1) > (N - 1)))
		return 0; 

	else 
	{
		// 2단계
		if (gameboard[x - 1][y + 1] != 'O')
			return 0;
		else 
		{
			// 3단계
			if (((x - 2) < 0) || (y + 2) > (N - 1))	
											
				return 0;
			else
			{
				// 4단계
				while (gameboard[x - 2 - i][y + 2 + i] == 'O')
				{
					i++; 	
					if (((x - 2 - i) < 0) || (y + 2 + i) > (N - 1))
						return 0;
				}

				// 5단계
				if (gameboard[x - 2 - i][y + 2 + i] == ' ') 
					return 0;
				else
					return 1; 
			}
		}
	}
}

int south_west_im_black(int x, int y)
{
	int i = 0;

	// 1단계
	if (((x + 1) > (N - 1)) || ((y + 1) > (N - 1)))
		return 0;

	else 
	{
		// 2단계
		if (gameboard[x + 1][y + 1] != 'O') 
			return 0;
		else
		{
			// 3단계
			if (((x + 2) > (N - 1)) || (y + 2) > (N - 1))	
				return 0;
			else
			{
				// 4단계
				while (gameboard[x + 2 + i][y + 2 + i] == 'O')
				{
					i++; 	
					if (((x + 2 + i) > (N - 1)) || (y + 2 + i) > (N - 1))
						return 0;
				}

				// 5단계
				if (gameboard[x + 2 + i][y + 2 + i] == ' ') 
					return 0; 
				else
					return 1;
			}
		}
	}
}

int south_east_im_black(int x, int y)
{
	int i = 0; 

	// 1단계
	if (((x + 1) > (N - 1)) || ((y - 1) < 0))
		return 0; 

	else 
	{
		// 2단계
		if (gameboard[x + 1][y - 1] != 'O') 
			return 0;
		else 
		{
			// 3단계
			if (((x + 2) > (N - 1)) || (y - 2) < 0)
				return 0;
			else
			{
				// 4단계
				while (gameboard[x + 2 + i][y - 2 - i] == 'O')
				{
					i++; 	
					if (((x + 2 + i) > (N - 1)) || ((y - 2 - i) < 0))
						return 0;
				}

				// 5단계
				if (gameboard[x + 2 + i][y - 2 - i] == ' ') 
					return 0; 
				else
					return 1; 
			}
		}
	}
}

int north_east_im_black(int x, int y)
{
	int i = 0; 

	// 1단계
	if (((x - 1) < 0) || ((y - 1) < 0))
		return 0; 

	else 
	{
		// 2단계
		if (gameboard[x - 1][y - 1] != 'O') 
			return 0;
		else 
		{
			// 3단계
			if (((x - 2) < 0) || ((y - 2) < 0))	
				return 0;
			else
			{
				// 4단계
				while (gameboard[x - 2 - i][y - 2 - i] == 'O')
				{
					i++; 	
					if (((x - 2 - i) < 0) || ((y - 2 - i) < 0))
						return 0;
				}

				// 5단계
				if (gameboard[x - 2 - i][y - 2 - i] == ' ') 
					return 0; 
				else
					return 1;
			}
		}
	}
}

int check_put_black_stone(int a, int b)
{
	int north, south, west, east;
	int north_west, north_east;
	int south_west, south_east;
	int result;

	north = north_im_black(a, b);
	south = south_im_black(a, b);
	west = west_im_black(a, b);
	east = east_im_black(a, b);
	north_west = north_west_im_black(a, b);
	south_west = south_west_im_black(a, b);
	south_east = south_east_im_black(a, b);
	north_east = north_east_im_black(a, b);

	//입력한 칸이 빈칸이 아니라면 놓을 수 없음
	if (gameboard[a][b] != ' ')
		return 0;

	//한 방향이라도 놓을 수 있다면 result가 1을 반환하여 돌 놓기 가능
	result = (north || south || west || east ||
		north_west || south_west || south_east || north_east);

	return result;
}

int all_check_put_black_stone(void)
{
	int row, col;
	int result_check = 0;

	for (row = 0; row < N; row++)
	{
		for (col = 0; col < N; col++)
			result_check += check_put_black_stone(row, col);
	}

	if (result_check > 0)
		return 1;
	else
		return 0;
}
