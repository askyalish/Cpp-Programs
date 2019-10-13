#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

bool gameOver;
const int width = 24;
const int height = 24;
int x, y, fruitX, fruitY, score;

int tailX[100], tailY[100];		//this array is for grow snake after eat food
int nTail;						//this is for grow snake after eat food

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void Setup()
{
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}
void Draw()
{
	system("cls");
	for (int i = 0; i < width + 2; i++)
		cout << "#";
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < height; j++)
		{
			if (j == 0)
				cout << "#";
				
			if (i == y && j == x)
				cout << "@";
			else if (i == fruitY && j == fruitX)
				cout << "F";
			else
			{
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "o";
						print = true;
					}
				}
				if(!print)
					cout << " ";
			}

			if (j == width - 1)
				cout << "#";
		}
		cout << endl;
	}

	for (int i = 0; i < width + 2; i++)
		cout << "#";
	cout << endl;
	cout << "Score : " << score;
}
void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'q':
			gameOver = true;
			break;
		}
	}
}
void Logic()
{
	int prevX = tailX[0];				//remember preveas tail
	int prevY = tailY[0];				//
	int prev2X, prev2Y;
	tailX[0] = x;						//the X first element follow the heat
	tailY[0] = y;						//the y first element follow the heat
	for (int i = 1; i < nTail; i++)		//
	{
		prev2X = tailX[i];				//
		prev2Y = tailY[i];				//

		tailX[i] = prevX;				//
		tailY[i] = prevY;				//

		prevX = prev2X;					//
		prevY = prev2Y;					//
	}

	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
	
	/* //This is Wall hit GameOver 
		if (x > width || x < 0 || y > height || y < 0)
			gameOver = true;
	*/
	if (x >= width) x = 0; else if (x < 0) x = width - 1;		//wall passing over
	if (y >= height) y = 0; else if (y < 0) y = height - 1;		//wall passing over

	for (int i = 0; i < nTail; i++)
	{
		if (tailX[i] == x && tailY[i] == y)
			gameOver = true;
	}

	if (x == fruitX && y == fruitY)
	{
		score += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
		nTail++;					//this array is for grow snake after eat food
	}
}
int main()
{
		Setup();
		while (!gameOver)
		{
			Draw();
			Input();
			Logic();
			Sleep(10);
		}
	
		cout << endl;
	system("pause");
	return 0;
}