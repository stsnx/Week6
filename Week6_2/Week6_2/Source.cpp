#include <iostream>
using namespace std;
int temp[18][2];
int minor[3][3];
int test[3][3] = { {1,1,1},{1,1,1},{1,1,1} };
void callCofactor(int t[3][3]);
void findminor(int* t[])
{

	int xPosition = 0, yPosition = 0;
	int xminor = 0, yminor = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				if (k != i)
				{
					for (int l = 0; l < 3; l++)
					{
						if (l != j)
						{
							temp[yPosition][xPosition] = *(t[k] + l);
							xPosition++;
						}
					}
					yPosition++;
					xPosition = 0;
				}
			}
			minor[yminor][xminor] = (temp[yPosition - 2][0] * temp[yPosition - 1][1]) - (temp[yPosition - 2][1] * temp[yPosition - 1][0]);
			xminor++;
		}
		yminor++;
		xminor = 0;
	}
}
void callCofactor(int t[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			minor[i][j] *= pow(-1, (i + 1) + (j + 1));
	}
}
int main()
{
	int x[3][3];
	int* p[3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> x[i][j];
	}
	for (int i = 0; i < 3; i++)
		p[i] = x[i];
	int* tt[3];
	for (int i = 0; i < 3; i++)
		tt[i] = test[i];
	findminor(p);
	callCofactor(minor);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) cout << minor[i][j] << ' ';
		cout << endl;
	}
	return 0;
}
