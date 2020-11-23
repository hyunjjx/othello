#include "gameboard.h"


/*  �� ���� �÷��̾� ���忡��
	gameboard[x][y]�� ���� ������ ���� 
	���� ���� �� ������ ������ Ȯ���ϴ� ����.
	�ٸ� ���⵵ ����ϰ� �۵���. 
	���ǻ� gameboard[x][y]�� [x][y]�� ��Ī

	1�ܰ�.	[x][y]��  north �����ڸ��� ��ġ�ϸ�
			(��, (x-1)<0�� ��)
			north���⿡ �̿��� ������ �� �����Ƿ�
			0 ��ȯ.

			(x-1)>=0�̸� 2�ܰ��.


	2�ܰ�.	[x][y]�� ���ʿ� �ִ� ���� �������� �ƴ� ��
			(��, �����̰ų� ����� ��)
			north���⿡ �̿����� �����ϴ���
			���� ������ �� �����Ƿ�
			0 ��ȯ.

			[x][y]�� ���ʿ� �ִ� ��,
			(��, [x-1][y]) �� �������� ��
			3�ܰ��.


	3�ܰ�.	[x-1][y]�� north �����ڸ��� ��ġ�� ��
			(��, (x-2)<0�� ��)
			north ���⿡ �̿��� ������ �� �����Ƿ�
			0 ��ȯ

			(x-2)>=0�̸� 4�ܰ��


	4�ܰ�.	north�������� ��ĭ �� ���� ���������� Ȯ��
			�������̶�� ��ĭ �� ��������.
			�������� �ƴ� ĭ�� ���ö� 5�ܰ��

	5�ܰ�.	�������� ��� ���� ���� ĭ��
			��ĭ�̶��, �̿����� �������� �����Ƿ�
			0��ȯ

			��� ���̶��, north ���⿡ �̿����� �����ϰ�
			�� ���̿� ������ ���� �����ϱ� ������
			[x][y]�� ����� ��ġ ����
*/
int north_im_white(int x, int y)
{
	int i = 0; //while�� �ȿ��� north�� �� �� ���

	// 1�ܰ�
	if ((x - 1) < 0) // gameboard[x][y]�� �����ڸ��� ���� ��
		return 0; //[x][y]�� �� ��ġ �Ұ�

	else // gameboard[x][y]�� north�����ڸ��� ���� ���� ��
	{
		// 2�ܰ�
		if (gameboard[x - 1][y] != 'X') // north ���� �������� �ƴҶ�
			return 0;
		else // north ���� �������� ��
		{
			// 3�ܰ�
			if ((x - 2) < 0)	//north�� ������ ���� ������, �� ���� �����ڸ��� ��ġ�Ͽ�
				return 0;	//�̿��� ���� ���� �� ���� ���
			else
			{
				// 4�ܰ�
				while (gameboard[x - 2 - i][y] == 'X')
				{
					i++;	//��ĭ�� north�� ���µ�
							//�������̸� ��� north�� ��

					//north�� ���� ���߿� ĭ�� ������ 0��ȯ
					if ((x - 2 - i) < 0)
						return 0;
				}

				// 5�ܰ�
				if (gameboard[x - 2 - i][y] == ' ') //north���� ��� ����, ���� ĭ�� ��ĭ�̸� 0��ȯ
					return 0; //��, �÷��̾�� [x][y]�� �� ��ġ �Ұ�
				else
					return 1; // ��ġ ����
			}
		}
	}
}

int south_im_white(int x, int y)
{
	int i = 0;  //while�� �ȿ��� south�� �� �� ���

	// 1�ܰ�
	if ((x + 1) > (N-1)) // gameboard[x][y]�� �����ڸ��� ���� ��
		return 0; //[x][y]�� �� ��ġ �Ұ�

	else
	{
		// 2�ܰ�
		if (gameboard[x + 1][y] != 'X') // south���� �������� �ƴҶ�
			return 0;
		else // south ���� �������� ��
		{
			// 3�ܰ�
			if ((x + 2) > (N-1))	//south�� ������ ���� ������, �� ���� �����ڸ��� ��ġ�Ͽ�
				return 0;		//�̿��� ���� ���� �� ���� ���
			else
			{
				// 4�ܰ�
				while (gameboard[x + 2 + i][y] == 'X')
				{
					i++;	//��ĭ�� south�� ���µ�
							//�������̸� ��� south�� ��

					//south���� ���� ���߿� ĭ�� ������ 0��ȯ
					if ((x + 2 + i) > (N-1))
						return 0;
				}

				// 5�ܰ�
				if (gameboard[x + 2 + i][y] == ' ') //south���� ��� ����, ���� ĭ�� ��ĭ�̸� 0��ȯ
					return 0;	//��, �÷��̾�� [x][y]�� �� ��ġ �Ұ�
				else
					return 1; // ��ġ ����
			}
		}
	}
}

int east_im_white(int x, int y)
{
	int i = 0; //while�� ������ ���

	// 1�ܰ�
	if ((y - 1) < 0) // gameboard[x][y]�� �����ڸ��� ���� ��
		return 0; //[x][y]�� �� ��ġ �Ұ�

	else // gameboard[x][y]�� east �����ڸ��� ���� ���� ��
	{
		// 2�ܰ�
		if (gameboard[x][y - 1] != 'X') // east ���� �������� �ƴҶ�
			return 0;
		else // east ���� �������� ��
		{
			// 3�ܰ�
			if ((y - 2) < 0)	//east�� ������ ���� ������, �� ���� �����ڸ��� ��ġ�Ͽ�
				return 0;	//�̿��� ���� ���� �� ���� ���
			else
			{
				// 4�ܰ�
				while (gameboard[x][y - 2 - i] == 'X')
				{
					i++;	//��ĭ�� east���� ���µ�
							//�������̸� ��� east���� ��

					//�������� ���� ���߿� ĭ�� ������ 0��ȯ
					if ((y - 2 - i) < 0)
						return 0;
				}

				// 5�ܰ�
				if (gameboard[x][y - 2 - i] == ' ') //east���� ��� ����, ���� ĭ�� ��ĭ�̸� 0��ȯ
					return 0; //��, �÷��̾�� [x][y]�� �� ��ġ �Ұ�
				else
					return 1; // ��ġ ����
			}
		}
	}
}

int west_im_white(int x, int y)
{
	int i = 0; //while�� �ȿ��� ���

	// 1�ܰ�
	if ((y + 1) > (N-1)) // gameboard[x][y]�� west �����ڸ��� ���� ���� ��
		return 0; //[x][y]�� �� ��ġ �Ұ�

	else // gameboard[x][y]�� west �����ڸ��� ���� ���� ��
	{
		// 2�ܰ�
		if (gameboard[x][y + 1] != 'X')
			return 0;
		else // west ���� �������� ��
		{
			// 3�ܰ�
			if ((y + 2) > (N-1))	//west�� ������ ���� ������, �� ���� �����ڸ��� ��ġ�Ͽ�
				return 0;	//�̿��� ���� ���� �� ���� ���
			else
			{
				// 4�ܰ�
				while (gameboard[x][y + 2 + i] == 'X')
				{
					i++;	//��ĭ�� west���� ���µ�
							//�������̸� ��� west���� ��

					//west���� ���� ���߿� ĭ�� ������ 0��ȯ
					if ((y + 2 + i) > (N-1))
						return 0;
				}

				// 5�ܰ�
				if (gameboard[x][y + 2 + i] == ' ') //west���� ��� ����, ���� ĭ�� ��ĭ�̸� 0��ȯ
					return 0; //��, �÷��̾�� [x][y]�� �� ��ġ �Ұ�
				else
					return 1; // ��ġ ����
			}
		}
	}
}

int north_west_im_white(int x, int y)
{
	int i = 0; //while�� �ȿ��� north_west�� �� �� ���


	// 1�ܰ�
	if (((x - 1) < 0) || ((y + 1) > (N - 1)) )
		return 0; //[x][y]�� �� ��ġ �Ұ�

	else // gameboard[x][y]�� �����ڸ��� ���� ���� ��
	{
		// 2�ܰ�
		if (gameboard[x - 1][y + 1] != 'X') // north_west ���� �������� �ƴҶ�
			return 0;
		else // north_west ���� �������� ��
		{
			// 3�ܰ�
			if (((x - 2) < 0) || (y + 2) > (N - 1))	//north_west�� ������ ���� ������,
												//�� ���� �����ڸ��� ��ġ�Ͽ�
				return 0;//�̿��� ���� ���� �� ���� ���
			else
			{
				// 4�ܰ�
				while (gameboard[x - 2 - i][y + 2 + i] == 'X')
				{
					i++; 	//��ĭ�� north_west�� ���µ�
							//�������̸� ��� north_west�� ��

					//north_west���� ���� ���߿� ĭ�� ������ 0��ȯ
					if (((x - 2 - i) < 0) || (y + 2 + i) > (N - 1))
						return 0;
				}

				// 5�ܰ�
				if (gameboard[x - 2 - i][y + 2 + i] == ' ') //north_west���� ��� ����, 
															//���� ĭ�� ��ĭ�̸� 0��ȯ
					return 0; //��, �÷��̾�� [x][y]�� �� ��ġ �Ұ�
				else
					return 1; // ��ġ ����
			}
		}
	}
}

int south_west_im_white(int x, int y)
{
	int i = 0; //while�� �ȿ��� ���

	// 1�ܰ�
	if (((x + 1) > (N - 1)) || ((y + 1) > (N - 1)))
		return 0; //[x][y]�� �� ��ġ �Ұ�

	else // gameboard[x][y]�� south_west �����ڸ��� ���� ���� ��
	{
		// 2�ܰ�
		if (gameboard[x + 1][y + 1] != 'X') // south_west ���� �������� �ƴҶ�
			return 0;
		else // south_west ���� �������� ��
		{
			// 3�ܰ�
			if (((x + 2) > (N - 1)) || (y + 2) > (N - 1))	//south_west�� ������ ���� ������, 
															//�� ���� �����ڸ��� ��ġ�Ͽ�
				return 0;//�̿��� ���� ���� �� ���� ���
			else
			{
				// 4�ܰ�
				while (gameboard[x + 2 + i][y + 2 + i] == 'X')
				{
					i++; 	//��ĭ�� south_west�� ���µ�
							//�������̸� ��� south_west�� ��

					//south_west�� ���� ���߿� ĭ�� ������ 0��ȯ
					if (((x + 2 + i) > (N - 1)) || (y + 2 + i) > (N - 1))
						return 0;
				}

				// 5�ܰ�
				if (gameboard[x + 2 + i][y + 2 + i] == ' ') //south_west�� ��� ����, 
															//���� ĭ�� ��ĭ�̸� 0��ȯ
					return 0; //��, �÷��̾�� [x][y]�� �� ��ġ �Ұ�
				else
					return 1; // ��ġ ����
			}
		}
	}
}

int south_east_im_white(int x, int y)
{
	int i = 0; //while�� �ȿ��� ���

	// 1�ܰ�
	if (((x + 1) > (N - 1)) || ((y - 1) < 0))
		return 0; //[x][y]�� �� ��ġ �Ұ�

	else // gameboard[x][y]�� south_east �����ڸ��� ���� ���� ��
	{
		// 2�ܰ�
		if (gameboard[x + 1][y - 1] != 'X') // south_east���� �������� �ƴҶ�
			return 0;
		else // south_east���� �������� ��
		{
			// 3�ܰ�
			if (((x + 2) > (N - 1)) || (y - 2) < 0)	//south_east�� ������ ���� ������, 
													//�� ���� �����ڸ��� ��ġ�Ͽ�
				return 0;//�̿��� ���� ���� �� ���� ���
			else
			{
				// 4�ܰ�
				while (gameboard[x + 2 + i][y - 2 - i] == 'X')
				{
					i++; 	//��ĭ�� south_east�� ���µ�
							//�������̸� ��� south_east�� ��

					//south_east�� ���� ���߿� ĭ�� ������ 0��ȯ
					if (((x + 2 + i) > (N - 1)) || ((y - 2 - i) < 0))
						return 0;
				}

				// 5�ܰ�
				if (gameboard[x + 2 + i][y - 2 - i] == ' ') //south_east�� ��� ����, 
															//���� ĭ�� ��ĭ�̸� 0��ȯ
					return 0; //��, �÷��̾�� [x][y]�� �� ��ġ �Ұ�
				else
					return 1; // ��ġ ����
			}
		}
	}
}

int north_east_im_white(int x, int y)
{
	int i = 0; //while�� �ȿ��� ���

	// 1�ܰ�
	if (((x - 1) < 0) || ((y - 1) < 0))
		return 0; //[x][y]�� �� ��ġ �Ұ�

	else // gameboard[x][y]�� �����ڸ��� ���� ���� ��
	{
		// 2�ܰ�
		if (gameboard[x - 1][y - 1] != 'X') // north_east���� �������� �ƴҶ�
			return 0;
		else // north_east���� �������� ��
		{
			// 3�ܰ�
			if (((x - 2) < 0) || ((y - 2) < 0))	//north_east�� ������ ���� ������, 
												//�� ���� �����ڸ��� ��ġ�Ͽ�
				return 0;	//�̿��� ���� ���� �� ���� ���
			else
			{
				// 4�ܰ�
				while (gameboard[x - 2 - i][y - 2 - i] == 'X')
				{
					i++; 	//��ĭ�� north_east�� ���µ�
							//�������̸� ��� north_east�� ��

					//north_east�� ���� ���߿� ĭ�� ������ 0��ȯ
					if (((x - 2 - i) < 0) || ((y - 2 - i) < 0))
						return 0;
				}

				// 5�ܰ�
				if (gameboard[x - 2 - i][y - 2 - i] == ' ') //north_east�� ��� ����, 
															//���� ĭ�� ��ĭ�̸� 0��ȯ
					return 0; //��, �÷��̾�� [x][y]�� �� ��ġ �Ұ�
				else
					return 1; // ��ġ ����
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

	//�Է��� ĭ�� ��ĭ�� �ƴ϶�� ���� �� ����
	if (gameboard[a][b] != ' ')
		return 0;

	//�� �����̶� ���� �� �ִٸ� result�� 1�� ��ȯ�Ͽ� �� ���� ����
	result = (north || south || west || east ||
		north_west || south_west || south_east || north_east);

	return result;
}

//����� �÷��̾ ���� ���� �� �ִ� ĭ�� �� �ϳ��� �ִ��� Ȯ��  
int all_check_put_white_stone(void)
{
	int row, col;
	int result_check=0;

	//���� ���� �� �ִٸ� result_check�� 1�� ����  
	for (row = 0; row < N; row++)
	{
		for (col = 0; col < N; col++)
			result_check += check_put_white_stone(row, col);
	}
 
	if (result_check > 0)
		return 1; // ��� �� �÷��̾ �� ��ġ ����  
	else
		return 0; // ��ġ �Ұ�  
}
