#include <iostream>

using namespace std;

char matrix[3][3] = { '1', '2', '3', '4','5', '6', '7', '8', '9' };
char player = 'X';
int n;

void show()
{
	system("cls");
	cout << " Tic Tac Toe v1.3.0" << endl;
	cout << "--------------------" << endl << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void input()
{
	int in;
	cout << "Player ' "<< player << " ' Press Number of the Fild : ";
	cin >> in;

	if (in == 1)
	{
		if (matrix[0][0] == '1')
		{
			matrix[0][0] = player;
		}
		else
		{
			cout << "Already used this !" << endl;
			input();
		}	
	}
	if (in == 2)
	{
		if (matrix[0][1] == '2')
		{
			matrix[0][1] = player;
		}
		else
		{
			cout << "Already used this !" << endl;
			input();
		}	
	}
	if (in == 3)
	{
		if (matrix[0][2] == '3')
		{
			matrix[0][2] = player;
		}
		else
		{
			cout << "Already used this !" << endl;
			input();
		}	
	}
	if (in == 4)
	{
		if (matrix[1][0] == '4')
		{
			matrix[1][0] = player;
		}
		else
		{
			cout << "Already used this !" << endl;
			input();
		}	
	}
	if (in == 5)
	{
		if (matrix[1][1] == '5')
		{
			matrix[1][1] = player;
		}
		else
		{
			cout << "Already used this !" << endl;
			input();
		}	
	}
	if (in == 6)
	{
		if (matrix[1][2] == '6')
		{
			matrix[1][2] = player;
		}
		else
		{
			cout << "Already used this !" << endl;
			input();
		}	
	}
	if (in == 7)
	{
		if (matrix[2][0] == '7')
		{
			matrix[2][0] = player;
		}
		else
		{
			cout << "Already used this !" << endl;
			input();
		}	
	}
	if (in == 8)
	{
		if (matrix[2][1] == '8')
		{
			matrix[2][1] = player;
		}
		else
		{
			cout << "Already used this !" << endl;
			input();
		}	
	}
	if (in == 9)
	{
		if (matrix[2][2] == '9')
		{
			matrix[2][2] = player;
		}
		else
		{
			cout << "Already used this !" << endl;
			input();
		}	
	}
}

void setplayer()
{
	if (player == 'X')
		player = 'O';
	else
		player = 'X';
}

char win()
{
	//X
	if (matrix[0][0] == 'X' && matrix[0][1] == 'X' && matrix[0][2] == 'X')
		return 'X';
	if (matrix[1][0] == 'X' && matrix[1][1] == 'X' && matrix[1][2] == 'X')
		return 'X';
	if (matrix[2][0] == 'X' && matrix[2][1] == 'X' && matrix[2][2] == 'X')
		return 'X';

	if (matrix[0][0] == 'X' && matrix[1][0] == 'X' && matrix[2][0] == 'X')
		return 'X';
	if (matrix[0][1] == 'X' && matrix[1][1] == 'X' && matrix[2][1] == 'X')
		return 'X';
	if (matrix[0][2] == 'X' && matrix[1][2] == 'X' && matrix[2][2] == 'X')
		return 'X';

	if (matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X')
		return 'X';
	if (matrix[0][2] == 'X' && matrix[1][1] == 'X' && matrix[2][0] == 'X')
		return 'X';

	//O
	if (matrix[0][0] == 'O' && matrix[0][1] == 'O' && matrix[0][2] == 'O')
		return 'O';
	if (matrix[1][0] == 'O' && matrix[1][1] == 'O' && matrix[1][2] == 'O')
		return 'O';
	if (matrix[2][0] == 'O' && matrix[2][1] == 'O' && matrix[2][2] == 'O')
		return 'O';

	if (matrix[0][0] == 'O' && matrix[1][0] == 'O' && matrix[2][0] == 'O')
		return 'O';
	if (matrix[0][1] == 'O' && matrix[1][1] == 'O' && matrix[2][1] == 'O')
		return 'O';
	if (matrix[0][2] == 'O' && matrix[1][2] == 'O' && matrix[2][2] == 'O')
		return 'O';

	if (matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O')
		return 'O';
	if (matrix[0][2] == 'O' && matrix[1][1] == 'O' && matrix[2][0] == 'O')
		return 'O';
	
	return '/';
}

int main()
{
	show();
	n = 0;
	while (1)
	{
		n++;
		input();
		show();
		if (win() == 'X')
		{
			cout << "Player ' X ' win !!!" << endl;
			break; 

		}
		else if (win() == 'O')
		{
			cout << "Player ' O ' win !!!" << endl;
			break;
		}
		else if (n == 9 && win()== '/')
		{
			cout << "Macth Draw !" << endl;
			break;
		}

		setplayer();

	}
	cout << endl;
	system("pause");
	return 0;
}