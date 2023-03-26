#include <iostream>
using namespace std;


//print Marks&Nules matrix to console
void print(char arr[][3], int h, int w)
{
	cout << endl;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

//check win combinations
bool checkWin(char arr[][3])
{
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != '-')
	{
		return true;
	}
	if (arr[2][0] == arr[1][1] && arr[1][1] == arr[0][2] && arr[2][0] != '-')
	{
		return true;
	}


	if (arr[0][0] == arr[0][1] && arr[1][1] == arr[0][2] && arr[0][0] != '-')
	{
		return true;
	}
	if (arr[1][0] == arr[1][1] && arr[1][1] == arr[1][2] && arr[1][0] != '-')
	{
		return true;
	}
	if (arr[2][0] == arr[2][1] && arr[2][1] == arr[2][2] && arr[2][0] != '-')
	{
		return true;
	}


	if (arr[0][0] == arr[1][0] && arr[1][0] == arr[2][0] && arr[0][0] != '-')
	{
		return true;
	}
	if (arr[0][1] == arr[1][1] && arr[1][1] == arr[2][1] && arr[0][1] != '-')
	{
		return true;
	}
	if (arr[0][2] == arr[1][2] && arr[1][2] == arr[2][2] && arr[0][2] != '-')
	{
		return true;
	}
	return false;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	const int h = 3;
	const int w = 3;
	const int SIZE1 = 9;

	char arr[h][w]
	{
		{'-','-','-'},
		{'-','-','-'},
		{'-','-','-'},
	};

	bool win = false;
	bool isFirstPlayer = true;
	bool lock;
	char playerChar;
	int a;
	int b;
	for (int t = 0; t < h * w; t++)
	{
		if (win)
			break;

		lock = true;
		if (isFirstPlayer)
			playerChar = 'x';
		else
			playerChar = 'o';

		while (lock == true)
		{
			print(arr, h, w);
			cout << "Игрок " << playerChar << ", введите координаты: " << endl;
			cin >> a >> b;
			a -= 1;
			b -= 1;
			lock = false;
			if (a >= 3 || b >= 3)
			{
				lock = true;
				cout << "Неверные координаты " << endl;
				continue;
			}
			if (arr[a][b] == '-') {
				isFirstPlayer = !isFirstPlayer;
				arr[a][b] = playerChar;
				if (checkWin(arr))
				{
					win = true;
					cout << "Игрок " << playerChar << " победил" << endl;
				}

			}
			else {
				lock = true;
				cout << "Неверные координаты " << endl;
			}

		}
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
