#include<iostream>//implementation of knapsack problem//
using namespace std;
int max(int a, int b)
{
	if(a>b)
		return a;
	else
		return b;
}			
	  
int main()
{
	int n;
	cout<<"enter no. of objects\n";
	cin>>n;
	int w[n+5],p[n+5],flag[n+5];
	cout<<"enter weights and corresponding profits\n";
	for(int i=1;i<=n;i++)
	{
		cout<<"weight of obj"<< i<<":";
		cin>>w[i];
		cout<<"profit of obj"<< i<<":";
		cin>>p[i];
		cout<<"\n";
	}
	int W,w1;
	cout<<"enter max capacity of knapsack\n";
	cin>>W;
	int M[n+1][W+1];
	for(int i=0;i<=W;i++)
		M[0][i]=0;
	for(int i=1;i<=n;i++)
		for( w1=0;w1<=W;w1++)
		{
			if(w1<w[i])
				M[i][w1]=M[i-1][w1];
			else
				M[i][w1]=max(M[i-1][w1],p[i]+M[i-1][w1-w[i]]);			
		}
	cout<<"max profit is"<<M[n][W]<<"\n";
	return 0;
}		
