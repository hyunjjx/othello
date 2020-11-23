#include "gameboard.h"


/*  흰돌 놓는 플레이어 입장에서
	gameboard[x][y]의 북쪽 방향을 보며 
	돌을 놓을 수 있을지 없을지 확인하는 과정.
	다른 방향도 비슷하게 작동함. 
	편의상 gameboard[x][y]를 [x][y]라 지칭

	1단계.	[x][y]가  north 가장자리에 위치하면
			(즉, (x-1)<0일 때)
			north방향에 이웃알 존재할 수 없으므로
			0 반환.

			(x-1)>=0이면 2단계로.


	2단계.	[x][y]의 북쪽에 있는 돌이 검은색이 아닐 때
			(즉, 공백이거나 흰색일 때)
			north방향에 이웃알이 존재하더라도
			돌을 뒤집을 수 없으므로
			0 반환.

			[x][y]의 북쪽에 있는 돌,
			(즉, [x-1][y]) 이 검은색일 때
			3단계로.


	3단계.	[x-1][y]가 north 가장자리에 위치할 때
			(즉, (x-2)<0일 때)
			north 방향에 이웃알 존재할 수 없으므로
			0 반환

			(x-2)>=0이면 4단계로


	4단계.	north방향으로 한칸 더 가도 검은색인지 확인
			검은색이라면 한칸 더 북쪽으로.
			검은색이 아닌 칸이 나올때 5단계로

	5단계.	북쪽으로 계속 가서 만난 칸이
			빈칸이라면, 이웃알이 존재하지 않으므로
			0반환

			흰색 돌이라면, north 방향에 이웃알이 존재하고
			그 사이에 검은색 돌이 존재하기 때문에
			[x][y]에 흰색돌 배치 가능
*/
int north_im_white(int x, int y)
{
	int i = 0; //while문 안에서 north로 갈 때 사용

	// 1단계
	if ((x - 1) < 0) // gameboard[x][y]가 가장자리에 있을 때
		return 0; //[x][y]에 돌 배치 불가

	else // gameboard[x][y]가 north가장자리에 있지 않을 때
	{
		// 2단계
		if (gameboard[x - 1][y] != 'X') // north 돌이 검은색이 아닐때
			return 0;
		else // north 돌이 검은색일 때
		{
			// 3단계
			if ((x - 2) < 0)	//north에 검은색 돌이 있으나, 그 돌이 가장자리에 위치하여
				return 0;	//이웃한 돌이 있을 수 없는 경우
			else
			{
				// 4단계
				while (gameboard[x - 2 - i][y] == 'X')
				{
					i++;	//한칸씩 north로 갔는데
							//검은색이면 계속 north로 감

					//north로 가는 와중에 칸이 끝나면 0반환
					if ((x - 2 - i) < 0)
						return 0;
				}

				// 5단계
				if (gameboard[x - 2 - i][y] == ' ') //north으로 계속 가서, 만난 칸이 빈칸이면 0반환
					return 0; //즉, 플레이어는 [x][y]에 돌 배치 불가
				else
					return 1; // 배치 가능
			}
		}
	}
}

int south_im_white(int x, int y)
{
	int i = 0;  //while문 안에서 south로 갈 때 사용

	// 1단계
	if ((x + 1) > (N-1)) // gameboard[x][y]가 가장자리에 있을 때
		return 0; //[x][y]에 돌 배치 불가

	else
	{
		// 2단계
		if (gameboard[x + 1][y] != 'X') // south돌이 검은색이 아닐때
			return 0;
		else // south 돌이 검은색일 때
		{
			// 3단계
			if ((x + 2) > (N-1))	//south에 검은색 돌이 있으나, 그 돌이 가장자리에 위치하여
				return 0;		//이웃한 돌이 있을 수 없는 경우
			else
			{
				// 4단계
				while (gameboard[x + 2 + i][y] == 'X')
				{
					i++;	//한칸씩 south로 갔는데
							//검은색이면 계속 south로 감

					//south으로 가는 와중에 칸이 끝나면 0반환
					if ((x + 2 + i) > (N-1))
						return 0;
				}

				// 5단계
				if (gameboard[x + 2 + i][y] == ' ') //south으로 계속 가서, 만난 칸이 빈칸이면 0반환
					return 0;	//즉, 플레이어는 [x][y]에 돌 배치 불가
				else
					return 1; // 배치 가능
			}
		}
	}
}

int east_im_white(int x, int y)
{
	int i = 0; //while문 내에서 사용

	// 1단계
	if ((y - 1) < 0) // gameboard[x][y]가 가장자리에 있을 때
		return 0; //[x][y]에 돌 배치 불가

	else // gameboard[x][y]가 east 가장자리에 있지 않을 때
	{
		// 2단계
		if (gameboard[x][y - 1] != 'X') // east 돌이 검은색이 아닐때
			return 0;
		else // east 돌이 검은색일 때
		{
			// 3단계
			if ((y - 2) < 0)	//east에 검은색 돌이 있으나, 그 돌이 가장자리에 위치하여
				return 0;	//이웃한 돌이 있을 수 없는 경우
			else
			{
				// 4단계
				while (gameboard[x][y - 2 - i] == 'X')
				{
					i++;	//한칸씩 east으로 갔는데
							//검은색이면 계속 east으로 감

					//북쪽으로 가는 와중에 칸이 끝나면 0반환
					if ((y - 2 - i) < 0)
						return 0;
				}

				// 5단계
				if (gameboard[x][y - 2 - i] == ' ') //east으로 계속 가서, 만난 칸이 빈칸이면 0반환
					return 0; //즉, 플레이어는 [x][y]에 돌 배치 불가
				else
					return 1; // 배치 가능
			}
		}
	}
}

int west_im_white(int x, int y)
{
	int i = 0; //while문 안에서 사용

	// 1단계
	if ((y + 1) > (N-1)) // gameboard[x][y]가 west 가장자리에 있지 않을 때
		return 0; //[x][y]에 돌 배치 불가

	else // gameboard[x][y]가 west 가장자리에 있지 않을 때
	{
		// 2단계
		if (gameboard[x][y + 1] != 'X')
			return 0;
		else // west 돌이 검은색일 때
		{
			// 3단계
			if ((y + 2) > (N-1))	//west에 검은색 돌이 있으나, 그 돌이 가장자리에 위치하여
				return 0;	//이웃한 돌이 있을 수 없는 경우
			else
			{
				// 4단계
				while (gameboard[x][y + 2 + i] == 'X')
				{
					i++;	//한칸씩 west으로 갔는데
							//검은색이면 계속 west으로 감

					//west으로 가는 와중에 칸이 끝나면 0반환
					if ((y + 2 + i) > (N-1))
						return 0;
				}

				// 5단계
				if (gameboard[x][y + 2 + i] == ' ') //west으로 계속 가서, 만난 칸이 빈칸이면 0반환
					return 0; //즉, 플레이어는 [x][y]에 돌 배치 불가
				else
					return 1; // 배치 가능
			}
		}
	}
}

int north_west_im_white(int x, int y)
{
	int i = 0; //while문 안에서 north_west로 갈 때 사용


	// 1단계
	if (((x - 1) < 0) || ((y + 1) > (N - 1)) )
		return 0; //[x][y]에 돌 배치 불가

	else // gameboard[x][y]가 가장자리에 있지 않을 때
	{
		// 2단계
		if (gameboard[x - 1][y + 1] != 'X') // north_west 돌이 검은색이 아닐때
			return 0;
		else // north_west 돌이 검은색일 때
		{
			// 3단계
			if (((x - 2) < 0) || (y + 2) > (N - 1))	//north_west에 검은색 돌이 있으나,
												//그 돌이 가장자리에 위치하여
				return 0;//이웃한 돌이 있을 수 없는 경우
			else
			{
				// 4단계
				while (gameboard[x - 2 - i][y + 2 + i] == 'X')
				{
					i++; 	//한칸씩 north_west로 갔는데
							//검은색이면 계속 north_west로 감

					//north_west으로 가는 와중에 칸이 끝나면 0반환
					if (((x - 2 - i) < 0) || (y + 2 + i) > (N - 1))
						return 0;
				}

				// 5단계
				if (gameboard[x - 2 - i][y + 2 + i] == ' ') //north_west으로 계속 가서, 
															//만난 칸이 빈칸이면 0반환
					return 0; //즉, 플레이어는 [x][y]에 돌 배치 불가
				else
					return 1; // 배치 가능
			}
		}
	}
}

int south_west_im_white(int x, int y)
{
	int i = 0; //while문 안에서 사용

	// 1단계
	if (((x + 1) > (N - 1)) || ((y + 1) > (N - 1)))
		return 0; //[x][y]에 돌 배치 불가

	else // gameboard[x][y]가 south_west 가장자리에 있지 않을 때
	{
		// 2단계
		if (gameboard[x + 1][y + 1] != 'X') // south_west 돌이 검은색이 아닐때
			return 0;
		else // south_west 돌이 검은색일 때
		{
			// 3단계
			if (((x + 2) > (N - 1)) || (y + 2) > (N - 1))	//south_west에 검은색 돌이 있으나, 
															//그 돌이 가장자리에 위치하여
				return 0;//이웃한 돌이 있을 수 없는 경우
			else
			{
				// 4단계
				while (gameboard[x + 2 + i][y + 2 + i] == 'X')
				{
					i++; 	//한칸씩 south_west로 갔는데
							//검은색이면 계속 south_west로 감

					//south_west로 가는 와중에 칸이 끝나면 0반환
					if (((x + 2 + i) > (N - 1)) || (y + 2 + i) > (N - 1))
						return 0;
				}

				// 5단계
				if (gameboard[x + 2 + i][y + 2 + i] == ' ') //south_west로 계속 가서, 
															//만난 칸이 빈칸이면 0반환
					return 0; //즉, 플레이어는 [x][y]에 돌 배치 불가
				else
					return 1; // 배치 가능
			}
		}
	}
}

int south_east_im_white(int x, int y)
{
	int i = 0; //while문 안에서 사용

	// 1단계
	if (((x + 1) > (N - 1)) || ((y - 1) < 0))
		return 0; //[x][y]에 돌 배치 불가

	else // gameboard[x][y]가 south_east 가장자리에 있지 않을 때
	{
		// 2단계
		if (gameboard[x + 1][y - 1] != 'X') // south_east돌이 검은색이 아닐때
			return 0;
		else // south_east돌이 검은색일 때
		{
			// 3단계
			if (((x + 2) > (N - 1)) || (y - 2) < 0)	//south_east에 검은색 돌이 있으나, 
													//그 돌이 가장자리에 위치하여
				return 0;//이웃한 돌이 있을 수 없는 경우
			else
			{
				// 4단계
				while (gameboard[x + 2 + i][y - 2 - i] == 'X')
				{
					i++; 	//한칸씩 south_east로 갔는데
							//검은색이면 계속 south_east로 감

					//south_east로 가는 와중에 칸이 끝나면 0반환
					if (((x + 2 + i) > (N - 1)) || ((y - 2 - i) < 0))
						return 0;
				}

				// 5단계
				if (gameboard[x + 2 + i][y - 2 - i] == ' ') //south_east로 계속 가서, 
															//만난 칸이 빈칸이면 0반환
					return 0; //즉, 플레이어는 [x][y]에 돌 배치 불가
				else
					return 1; // 배치 가능
			}
		}
	}
}

int north_east_im_white(int x, int y)
{
	int i = 0; //while문 안에서 사용

	// 1단계
	if (((x - 1) < 0) || ((y - 1) < 0))
		return 0; //[x][y]에 돌 배치 불가

	else // gameboard[x][y]가 가장자리에 있지 않을 때
	{
		// 2단계
		if (gameboard[x - 1][y - 1] != 'X') // north_east돌이 검은색이 아닐때
			return 0;
		else // north_east돌이 검은색일 때
		{
			// 3단계
			if (((x - 2) < 0) || ((y - 2) < 0))	//north_east에 검은색 돌이 있으나, 
												//그 돌이 가장자리에 위치하여
				return 0;	//이웃한 돌이 있을 수 없는 경우
			else
			{
				// 4단계
				while (gameboard[x - 2 - i][y - 2 - i] == 'X')
				{
					i++; 	//한칸씩 north_east로 갔는데
							//검은색이면 계속 north_east로 감

					//north_east로 가는 와중에 칸이 끝나면 0반환
					if (((x - 2 - i) < 0) || ((y - 2 - i) < 0))
						return 0;
				}

				// 5단계
				if (gameboard[x - 2 - i][y - 2 - i] == ' ') //north_east로 계속 가서, 
															//만난 칸이 빈칸이면 0반환
					return 0; //즉, 플레이어는 [x][y]에 돌 배치 불가
				else
					return 1; // 배치 가능
			}
		}
	}
}

int check_put_white_stone(int a, int b)
{
	int north, south, west, east;
	int north_west, north_east;
	int south_west, south_east;
	int result;

	north = north_im_white(a, b);
	south = south_im_white(a, b);
	west = west_im_white(a, b);
	east = east_im_white(a, b);
	north_west = north_west_im_white(a, b);
	south_west = south_west_im_white(a, b);
	south_east = south_east_im_white(a, b);
	north_east = north_east_im_white(a, b);

	//입력한 칸이 빈칸이 아니라면 놓을 수 없음
	if (gameboard[a][b] != ' ')
		return 0;

	//한 방향이라도 놓을 수 있다면 result가 1을 반환하여 돌 놓기 가능
	result = (north || south || west || east ||
		north_west || south_west || south_east || north_east);

	return result;
}

//흰색돌 플레이어가 돌을 놓을 수 있는 칸이 단 하나라도 있는지 확인  
int all_check_put_white_stone(void)
{
	int row, col;
	int result_check=0;

	//돌을 놓을 수 있다면 result_check가 1씩 증가  
	for (row = 0; row < N; row++)
	{
		for (col = 0; col < N; col++)
			result_check += check_put_white_stone(row, col);
	}
 
	if (result_check > 0)
		return 1; // 흰색 돌 플레이어가 돌 배치 가능  
	else
		return 0; // 배치 불가  
}
