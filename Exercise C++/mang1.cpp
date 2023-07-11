#include<iostream>;
#include<random>;
using namespace std;
#define MAX 1000
void nhapmang(int a[], int &n);
void xuatmang(int a[], int &n);
void sapxepnhodenlon(int a[], int n);
void hoanvi(int a, int b, int temp);
void timkiemphantudautien(int a[],int ktu,int n, int &idx);
void themphantu(int a[],int &n ,int idx, int pt);
void xoaphantu(int a[],int &n ,int pt);
int main()
{
	int myarray[MAX];
	int nsize;
	nhapmang(myarray, nsize);
	xuatmang(myarray, nsize);
	cout<<"mang khi da sap xep: "<<'\n';
	sapxepnhodenlon(myarray, nsize);
	xuatmang(myarray, nsize);
	int so(0),l(0);
	cout<<"nhap so can tim: ";
	cin>>so;
	timkiemphantudautien(myarray,so,nsize,l);
	int idx, ptu;
	cout<<"nhap vi tri so can them: "; cin>>idx;
	cout<<"nhap so can them: "; cin>>ptu;
	themphantu(myarray,nsize,idx,ptu);
	xuatmang(myarray, nsize);
	xoaphantu(myarray, nsize, ptu);
	xuatmang(myarray,nsize);
	//xoaphantu(myarray, nsize, pt);
return 0;	
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
	bool test(true);
	for (int i=0; i<=n-1; i++)
	 {
	 	min=a[i];
	 	for (int j=i+1; j<=n-1; j++)
	 	{
	 	 	if (a[j]<min)
	 	 	 {
	 	 	 	min=a[j];
	 	 	 	idx=j;
	 	 	 	test=true;
			 }
		}
		if (test==true)
		 {
		 hoanvi(a[i],a[idx]);
		 test=false;
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
	 {
	 idx=i;
	 cout<<"ki tu can tim nam o vi tri so: "<<idx<<endl;
     }
     else cout<<"ki tu khong o trong mang \n";
}
void themphantu(int a[], int &n, int idx, int ptu)
{
	for (int i(n); i>=idx+1; i--)
	{
		a[i]=a[i-1];
	}
	a[idx]=ptu;
	n++;
}
void xoaphantu(int a[], int &n, int ptu)
{
	int idx;
	timkiemphantudautien(a,ptu,n,idx);
	for (int i=idx;i<=n-2 ; i++)
	{
		a[i]=a[i+1];
	}
	a[n-1]=0;
	n--;
}
