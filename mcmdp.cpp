#include<iostream>
using namespace std;
int p[50];
int mco(int p[50],int n)
{	
	int S[n+1][n+1];
	int M[n+1][n+1];
	int j,q;
	for(int i=1;i<=n;i++)
		M[i][i]=0;
	for(int l=2;l<=n;l++)
	{	
		for(int i=1;i<=n-l+1;i++)
		{
			j=i+l-1;
			M[i][j]=2147483647;
			for(int k=i;k<=j-1;k++)
			{
				q=M[i][k]+M[k+1][j]+(p[i-1]*p[k]*p[j]);
				if(q<M[i][j])
				{
					M[i][j]=q;
					S[i][j]=k;
				}
			}
		}
	}	
		cout<<"min no.of multiplications are :"<<M[1][n]<<"\n";
		
}					
		 
int main()
{
	int n;
	cout<<"enter no. of matrices";
	cin>>n;
	int p[n+1];
	for(int i=0;i<n;i++)
	{
		cout<<"\n"<<"< p"<<i<<",p"<<i+1<<"> ";
		cin>>p[i]>>p[i+1];
	}		
	mco(p,n);
	return 0;
}	
