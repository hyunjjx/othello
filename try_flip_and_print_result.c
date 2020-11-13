#include "gameboard.h"

//����� �÷��̾ ������ �õ�
void try_flip_white_player(int row, int col)
{
	int north = 0, south = 0, west = 0, east = 0;
	int north_west = 0, north_east = 0;
	int south_west = 0, south_east = 0;
	int k; //�ݺ������� �ʿ�

	/*	���� ��Ī�� �̿��� ������ 
		�� �������� ���� ���� �� �� �ִ��� ����,
		�� ��ŭ ���� �����´�.
	*/

	//���� �� ������ �õ�
	if (north_im_white(row, col) == 1)
	{
		while (gameboard[row - 1 - north][col] == 'X')
		{
			north++;
		}

		//�� ������
		for (k = 0; k < north; k++)
			gameboard[row - 1 - k][col] = 'O';
	}

	//���� �� ������ �õ�
	if (south_im_white(row, col) == 1)
	{
		while (gameboard[row + 1 + south][col] == 'X')
		{
			south++;
		}
		for (k = 0; k < south; k++)
			gameboard[row + 1 + k][col] = 'O';
	}

	//����(������) �� ������ �õ�
	if (west_im_white(row, col) == 1)
	{
		while (gameboard[row][col + 1 + west] == 'X')
		{
			west++;
		}
		for (k = 0; k < west; k++)
			gameboard[row][col + 1 + k] = 'O';
	}

	//����(����) �� ������ �õ�
	if (east_im_white(row, col) == 1)
	{
		while (gameboard[row][col - 1 - east] == 'X')
		{
			east++;
		}
		for (k = 0; k < east; k++)
			gameboard[row][col - 1 - k] = 'O';
	}

	//�ϼ���(������ ����) �� ������ �õ�
	if (north_west_im_white(row, col) == 1)
	{
		while (gameboard[row - 1 - north_west][col + 1 + north_west] == 'X')
		{
			north_west++;
		}
		for (k = 0; k < north_west; k++)
			gameboard[row - 1 - k][col + 1 + k] = 'O';
	}

	//�ϵ���(������ ����) �� ������ �õ�
	if (north_east_im_white(row, col) == 1)
	{
		while (gameboard[row - 1 - north_east][col - 1 - north_east] == 'X')
		{
			north_east++;
		}
		for (k = 0; k < north_east; k++)
			gameboard[row - 1 - k][col - 1 - k] = 'O';
	}

	//������(������ �Ʒ�) �� ������ �õ�
	if (south_west_im_white(row, col) == 1)
	{
		while (gameboard[row + 1 + south_west][col + 1 + south_west] == 'X')
		{
			south_west++;
		}
		for (k = 0; k < south_west; k++)
			gameboard[row + 1 + k][col + 1 + k] = 'O';
	}

	//������(���� �Ʒ�) �� ������ �õ�
	if (south_east_im_white(row, col) == 1)
	{
		while (gameboard[row + 1 + south_east][col - 1 - south_east] == 'X')
		{
			south_east++;
		}
		for (k = 0; k < south_east; k++)
			gameboard[row + 1 + k][col - 1 - k] = 'O';
	}

	//���� �� ���� ������ ��� ���
	print_flip_result(north, south, west, east,
		north_west, north_east, south_west, south_east);
}

//�������� �÷��̾ ������ �õ�
void try_flip_black_player(int row, int col)
{
	int north = 0, south = 0, west = 0, east = 0;
	int north_west = 0, north_east = 0;
	int south_west = 0, south_east = 0;
	int k; //�ݺ������� �ʿ�

	/*	���� ��Ī�� �̿��� ������
		�� �������� ���� ���� �� �� �ִ��� ����,
		�� ��ŭ ���� �����´�.
	*/
	//���� �� ������ �õ�
	if (north_im_black(row, col) == 1)
	{
		//�� � �ִ��� ����
		while (gameboard[row - 1 - north][col] == 'O')
		{
			north++;
		}

		//�� ������
		for (k = 0; k < north; k++)
			gameboard[row - 1 - k][col] = 'X';
	}

	//���� �� ������ �õ�
	if (south_im_black(row, col) == 1)
	{
		while (gameboard[row + 1 + south][col] == 'O')
		{
			south++;
		}
		for (k = 0; k < south; k++)
			gameboard[row + 1 + k][col] = 'X';
	}

	//����(������) �� ������ �õ�
	if (west_im_black(row, col) == 1)
	{
		while (gameboard[row][col + 1 + west] == 'O')
		{
			west++;
		}
		for (k = 0; k < west; k++)
			gameboard[row][col + 1 + k] = 'X';
	}

	//����(����) �� ������ �õ�
	if (east_im_black(row, col) == 1)
	{
		while (gameboard[row][col - 1 - east] == 'O')
		{
			east++;
		}
		for (k = 0; k < east; k++)
			gameboard[row][col - 1 - k] = 'X';
	}

	//�ϼ���(������ ����) �� ������ �õ�
	if (north_west_im_black(row, col) == 1)
	{
		while (gameboard[row - 1 - north_west][col + 1 + north_west] == 'O')
		{
			north_west++;
		}
		for (k = 0; k < north_west; k++)
			gameboard[row - 1 - k][col + 1 + k] = 'X';
	}

	//�ϵ���(������ ����) �� ������ �õ�
	if (north_east_im_black(row, col) == 1)
	{
		while (gameboard[row - 1 - north_east][col - 1 - north_east] == 'O')
		{
			north_east++;
		}
		for (k = 0; k < north_east; k++)
			gameboard[row - 1 - k][col - 1 - k] = 'X';
	}

	//������(������ �Ʒ�) �� ������ �õ�
	if (south_west_im_black(row, col) == 1)
	{
		while (gameboard[row + 1 + south_west][col + 1 + south_west] == 'O')
		{
			south_west++;
		}
		for (k = 0; k < south_west; k++)
			gameboard[row + 1 + k][col + 1 + k] = 'X';
	}

	//������(���� �Ʒ�) �� ������ �õ�
	if (south_east_im_black(row, col) == 1)
	{
		while (gameboard[row + 1 + south_east][col - 1 - south_east] == 'O')
		{
			south_east++;
		}
		for (k = 0; k < south_east; k++)
			gameboard[row + 1 + k][col - 1 - k] = 'X';
	}

	//���� �� ���� ������ ��� ���
	print_flip_result(north, south, west, east,
		north_west, north_east, south_west, south_east);
}
