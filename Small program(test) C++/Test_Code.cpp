#include<iostream>;
#include<cstdio>;
#include<math.h>
using namespace std;
int main()
{
	string s="123456";
	int number=0;
	int temp=s.size();
	int z=pow(10,s.size());
	for (int i=0; i<s.size(); i++)
	{
		number=number+(s[i]-48)*(pow(10,s.size()-i-1));
	}
	cout<<number;
return 0;
}
