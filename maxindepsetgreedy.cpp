#include<iostream>
using namespace std;
int A[50][50];
int B[50];
 void maxindepset(int A[][50],int n)
{
	for(int i=0;i<50;i++)
	B[i]=9999;
	int s[n]={0},degree[n]={99},min,index,count=0,vertex;
	for(int i=1;i<n+1;i++)
	B[i]=i;
	while(B[1]!=9999)
	{
		min=n+1;
   		for(int i=1;i<n+1;i++) 
      		{
	 		for(int h=1;h<n+1;h++)	
			{if(i==B[h])
       			{
			for(int j=1;j<n+1;j++)
            		{
			degree[i]= degree[i]+A[i][j];}
        			if(degree[i]<min)
            			{
					min=degree[i];
           		 		vertex=i;
				}
			}}
   
		}//cout<<"\nvertex is and degree of vertex and 0"<< vertex<< degree[vertex]<< degree[0] ;
    		 for(int k=1;k<n+1;k++)
       		 if(A[vertex][k]==1)
            	{ 
			for(int i=1;i<n+1;i++)  
			A[k][i]=A[i][k]=0;
        		A[vertex][k]=A[k][vertex]=0;
			for(int h=1;h<n+1;h++)
			{
				if(k==B[h])
				{     // cout<<"\n"<<k <<"for "<<vertex;
					index=h;
					for(int w=index;w<n+1;w++)   // removing k from array B
					B[w]=B[w+1];
				}
				
			}	
		}
			for(int h=1;h<n+1;h++)	
			{	if(vertex==B[h])
				{
					index=h;
					for(int w=index;w<n+1;w++)   // removing vertex from array B
					B[w]=B[w+1];
					//cout<<"\n"<<vertex<<" is deleted and index is"<<index;	
				}	
			}
		//cout<<"\nB[0] IS and B[1] is"<<B[0]<<B[1];
		s[count]=vertex;
		count++;	
	}
	cout<<"answer is: ";
	for(int i=0;i<count;i++)
	cout<<s[i]<<" ";
}
int main()
{
	int v;
	cout<<"enter no. of vertices";
	cin>>v;
	for(int i=1;i<v+1;i++)
	for(int j=1;j<v+1;j++)
	{
		cout<<i<<"->"<<j;
		cin>>A[i][j];
		cout<<"\n";
	}
		
	maxindepset(A,v);
	return 0;
}
