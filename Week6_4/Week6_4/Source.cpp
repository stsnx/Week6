#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
vector<char> a;
char t[800];
void callUnDuplicate(char *p,vector<char> x,int Size)
{
	x.push_back(*p);
	for (int i = 1; i < Size; i++)
	{
		if (x[x.size() - 1] != *(p + i))
		{
			x.push_back(*(p + i));
		}
	}
	for (int j = 0; j < x.size(); j++)
	{
		for (int i = 0; i <= j; i++)
		{
			cout << x[i];
		}
		cout << endl;
	}
}
int main()
{

	char* p1;
	p1 = t;
	cin >> t;
	int l = strlen(t);
	callUnDuplicate(p1,a, l);
	return 0;
}
