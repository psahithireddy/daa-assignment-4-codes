#include<iostream>
using namespace std;
# define INF 999999
int A[50][50];
int floydwarshall(int G[][50],int V)
{
	for(int i=1;i<=V;i++)
	for(int j=1;j<=V;j++)
	A[i][j]=G[i][j];
	
	for(int k=1;k<=V;k++)
		for(int i=1;i<=V;i++)
			for(int j=1;j<=V;j++)
				if(A[i][k] + A[k][j] < A[i][j]) 
                      A[i][j] = A[i][k] + A[k][j]; 
                            
  cout<<"answer for all pairs shortest path:";
	for(int i=1;i<=V;i++)
	{	
		for(int j=1;j<=V;j++)
		{
			cout<< i<<"->"<<j<<":   ";
			if(A[i][j]==9999)
			cout<<"INF";
			else
			cout<<A[i][j];
			cout<<"\n";
		}
	}return 0;                          
}

int main()
{
	int V;
	cout<<"enter no.of vertices";
	cin>>V;
	int G[V][50];
	cout<<"enter edge weights , if there is no edge press 9999:";
	for(int i=1;i<=V;i++)
	{	
		for(int j=1;j<=V;j++)
		{
			cout<< i<<"->"<<j<<":   ";
			cin>>G[i][j];
			cout<<"\n";
		}
	}
	floydwarshall(G,V);
	return 0;
	}		
