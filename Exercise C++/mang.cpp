#include<iostream>;
#include<random>;
using namespace std;
#define MAX 1000
void nhapmang(int a[], int &n);
void xuatmang(int a[], int &n);
void sapxep(int a[]);
void hoanvi(int a, int b, int temp);
void timkiemphantudautien(int a[],int ktu);
void themphantu(int a[], int pt, int idx);
void xoaphantu(int a[], int pt);
int main()
{
	int myarray[MAX];
	int nsize;
	nhapmang(myarray, nsize);
	xoaphantu(myarray, nsize);
}
void nhapmang(int a[], int &n)
{
	cout<<"Nhap so phan tu cua mang: ";
	cin>>n;
	random_device rd;
	mt19937 rdf(rd());
	uniform_int_distribution<int>rg(1,1000);
	for (int i=0; i<=n-1; i++)
	{
		a[i]=rg(rdf);
	}
}
void xuatmang(int a[], int &n)
{
	for (int i=0; i<=n-1; i++)
	{
	  cout<<"A["<<i<<"]= "<<a[i]<<'\n';
    }
}
void hoanvi(int &a, int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
	
}
void sapxepnhodenlon(int a[], int n)
{
	int min(0);
	int idx(0);
	for (int i=0; i<=n-1; i++)
	 {
	 	min=a[i];
	 	for (int j=i+1; j<=n-1; j++)
	 	{
	 	 	if (min<a[j])
	 	 	 {
	 	 	 	min=a[j];
	 	 	 	idx=j;
			 }
			 hoanvi(a[i],a[idx]);
		}
	 }
}
void timkiemphantudautien(int a[], int ktu, int n, int &idx)
{
	int i=0;
	while (a[i]!=ktu)
	{
		i++;
		if (i>=n)
		{
		 idx=-1;
		 break;
	    }
	}
	if (i<n) 
	 idx=i;
	cout<<"ki tu can tim nam o vi tri so: "<<idx<<endl;
}
void themphantu(int a[], int &n, int idx, int ptu)
{
	for (int i(n); i>=idx+1; i--)
	{
		a[i]=a[i-1];
	}
	a[idx]=ptu;
}
void xoaphantu(int a[], int &n, int ptu)
{
	int idx;
	timkiemphantudautien(a,ptu,n,idx);
	for (int i=idx;i<=n-2 ; i++)
	{
		a[i]=a[i-1];
	}
	a[n-1]=0;
}
