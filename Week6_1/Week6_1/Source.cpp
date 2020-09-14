#include <iostream>
using namespace std;
int temp[18][2];
void findminor(int *t[])
{
	
	int xPosition=0, yPosition=0;
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
							temp[yPosition][xPosition] = *(t[k]+l);
							xPosition++;
						}
					}
					yPosition++;
					xPosition = 0;
				}
			}
			cout <<(temp[yPosition-2][0] * temp[yPosition-1][1])-(temp[yPosition-2][1] *temp[yPosition-1][0])<<' ';
		}
		cout << endl;
	}
}
int main()
{
	int x[3][3];
	int *p[3];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) 
			cin >> x[i][j];
	}
	for (int i = 0; i < 3; i++)
	p[i] = x[i];
	findminor(p);
	return 0;
}