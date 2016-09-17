#include <iostream>
using namespace std;

int pos_x, pos_y;
enum direction {
	Right, Down, Left, Up
};

direction next_direction(direction dire)
{
	switch (dire) {
	case Right: return Down;
	case Down: return Left;
	case Left: return Up;
	case Up: return Right;
	}
}

void move(direction dire)
{
	switch (dire) {
	case Right: pos_y++; return;
	case Down: pos_x++; return;
	case Left: pos_y--; return;
	case Up: pos_x--; return;
	}
}

int buf[1024][1024];

int main()
{
	int n;
	int counter = 1;
	direction dir = Right;
	cin >> n;
	pos_x = (n - 1) / 2; pos_y = pos_x;
	buf[pos_x][pos_y] = counter++;
	for (int i = 1; counter <= n * n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			move(dir);
			buf[pos_x][pos_y] = counter++;
		}
		dir = next_direction(dir);
		for (int j = 0; j < i; ++j)
		{
			move(dir);
			buf[pos_x][pos_y] = counter++;
		}
		dir = next_direction(dir);
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n - 1; ++j)
		{
			cout << buf[i][j] << " ";
		}
		cout << buf[i][n - 1] << endl;
	}
	//system("pause");
	return 0;
}