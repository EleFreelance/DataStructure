#include<iostream>
#include<list>
#include<vector>

using namespace std;

int main()
{
	list<int> l;
	vector<int> v;
	v.push_back(10);
	v[0]=20;
	for (int i = 0; i < 1; i++)
	{
		cout<<v[i]<<endl;
	}
	getchar();
	return 0;
}