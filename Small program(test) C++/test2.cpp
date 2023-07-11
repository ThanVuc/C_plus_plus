#include<iostream>
#include<cstring>
using namespace std;

int sotanggiamnhonhat(string s, char c[])
{
	if (s[1]>=s[0])
	 {
	 	for (int i=1; i<s.size(); i++)
	 	{
	 		if (s[i+1]<s[i])
	 		for (int j=i+1; j<=s.size(); j++)
	 		{
	 			s[j]=s[i];
	 			break;
			}
		}
	 } else
	 {
	 	for (int i=1; i<s.size(); i++)
	 	{
	 		if (s[i+1]>s[i])
	 		{ 
	 		 for (int j=i+1; j<=s.size(); j++)
	 		 { 
	 			s[j]='0';
			 }
			 s[i]=s[i]+1;
			 break;
		    }
		}
	 }
	 for (int i=0; i<=s.size(); i++)
	  	if (i!= s.size()) 
		  c[i]=s[i];
		else c[i]='\0';
	long long result(0);
	int a(0);
	long long test(1);
	int temp=strlen(c);
	for (int i=0; i<temp; i++)
	{
		test=1;
	    a=static_cast<int>(c[i]);
		for (int j=1;j<=temp-i-1; j++)
		{
			test=test*10;
		}
		result=result+test*(a-48);
    }
	return result;
}
int main()
{
	string n;
	char c[11];
    cin>>n;
	cout<<sotanggiamnhonhat(n,c)<<endl;
return 0;	 
}