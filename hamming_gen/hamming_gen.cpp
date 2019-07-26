#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int n,p=0;
	cout<<"enter size of data"<<endl;
	cin>>n;
	int c[n],rp[n]={0};
	while(n+p+1>pow(2,p))
    p++;
	cout<<"no of total bits"<<n+p;
	cout << " Enter the Data Bits One by One :" << endl;
			for (int i = n; i>0; i--)
			    cin >> c[i];
int q=n,r=p,a[30];
for(int i=n;i>0;i--)
	cout<<c[i];
cout<<endl;
p--;
	for(int i=n+p+1;i>0;i--)
	{
		if(i==pow(2,p))
		{
			a[i]=0;
			p--;
		}

		else
		{

			a[i]=c[q];
			q--;

		}
	}
	for(int i=n+r;i>0;i--)
	{
//		cout<<"i"<<i<<endl;
		cout<<a[i];
	}
cout<<endl;
int d1=0;
d1 = 0;
  int min, max = 0, parity, s, j;
for (int i = 1; i <= n + r; i = pow (2, d1))
    {
      ++d1;
      parity = 0;
      j = i;
      s = i;
      min = 1;
      max = i;
      for (j; j <= n + r;)
      	  {
    	  	  for (s = j; max >= min && s <= n + r; ++min, ++s)
    	  	  {
    	  		  if (a[s] == 1)
    	  			  parity++;
    	  	  }
    	  	  j = s + i;
    	  	  min = 1;
      	  }
      if (parity % 2 == 0) // Even Parity
      {
      	
    	  a[i] = 0;
      }
      else
      {
      	
    	  a[i] = 1;
      }
    }
for(int i=n+r;i>0;i--)
	{
		cout<<a[i];
	}
int m;
int data[20];
cout<<"on the receiver side"<<endl;
cout<<"enter the no of bits of data recieved"<<endl;
cin>>m;
if(m==n+r)
{
	cout<<"enter data received"<<endl;
	for(int i=m;i>0;i--)
	{
		cin>>data[i];
	}
	d1=0;
	int z=1;
	for (int i = 1; i <= n + r; i = pow (2, d1))
    {
      ++d1;
      parity = 0;
      j = i;
      s = i;
      min = 1;
      max = i;
      for (j; j <= n + r;)
      	  {
    	  	  for (s = j; max >= min && s <= n + r; ++min, ++s)
    	  	  {
    	  		  if (data[s] == 1)
    	  			  parity++;
    	  	  }
    	  	  j = s + i;
    	  	  min = 1;
      	  }
      if (parity % 2 == 0) // Even Parity
      {
      	
    	  rp[z] = 0;
    	  z++;
      }
      else
      {
    	  rp[z] = 1;
    	  z++;
      }
    }
    int flag=0,sum=0;
for(int i=r;i>0;i--)
{

	cout<<i<<" "<<rp[i]<<endl;
	if(rp[i]==0)
		flag=0;
	else
	{
		flag=1;
		sum=sum+pow(2,i-1);
	}
}
if(flag==1)
{
	cout<<"error in received code at bit "<<sum<<endl;
	
}
}
else
	cout<<"wrong size of data received"<<endl;
	return 0;

}
