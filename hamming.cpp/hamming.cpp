#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int a[11],b[11],r1,r2,r3,r4,r;
	for(int i=0;i<11;i++)
		a[i]=0;
	cout<<"enter 7 bit data(from left to right)"<<endl;
	cin>>a[10];
	cin>>a[9];
	cin>>a[8];
	cin>>a[6];
	cin>>a[5];
	cin>>a[4];
	cin>>a[2];
	a[0]=a[0]^a[2]^a[4]^a[6]^a[8]^a[10];
	a[1]=a[1]^a[2]^a[5]^a[6]^a[9]^a[10];
	a[3]=a[3]^a[4]^a[5]^a[6];
	a[7]=a[7]^a[8]^a[9]^a[10];
	cout<<"enter the received data"<<endl;
	for(int i=10;i>=0;i--)
			cin>>b[i];
	r1=b[0]^b[2]^b[4]^b[6]^b[8]^b[10];
	r2=b[1]^b[2]^b[5]^b[6]^b[9]^b[10];
	r3=b[3]^b[4]^b[5]^b[6];
	r4=b[7]^b[8]^b[9]^b[10];
	r=r1+r2+r3+r4;
	if(r==0)
		cout<<"no error in code"<<endl;
	else
	{
		cout<<"error"<<endl;
		r1=r1*pow(2,0);
		r2=r2*pow(2,1);
		r3=r3*pow(2,2);
		r4=r4*pow(2,3);
		r=r1+r2+r3+r4;
		cout<<"error found in bit "<<r<<endl;
		b[r-1]=b[r-1]^1;
		cout<<"corrected code is"<<endl;
		for(int i=10;i>=0;i--)
				cout<<b[i];

	}

}
