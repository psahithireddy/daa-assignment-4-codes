#include<iostream> 
using namespace std; 
int minCoins(int deno[], int m, int V) 
{ 
    // M[i] will be storing the minimum number of coins required for i value.  So M[V] will have result 
    int M[V+1];
	int coin[50][50],k; 
    M[0] = 0; 
    for (int i=1; i<=V; i++) // Initialize all values as Infinite 
        M[i] = 2147483647; 
    for (int i=1; i<=V; i++) 
    {  
        for (int j=0; j<m; j++) 
          if (deno[j] <= i) 
          { 
            	int res = M[i-deno[j]]; 
            	if (res != 2147483647 && res + 1 < M[i])
				{
			  		M[i] = res + 1; 
			  		for(k=0;k<M[i]-1;k++)
			  		{
			  			coin[i][k]=coin[i-deno[j]][k];
					}
					coin[i][k]=deno[j];
				}  
          } 
    } 
    if(M[V]!=2147483647)
    {
    	for(int k=0;k<M[V];k++)
		{
			cout<<coin[V][k]<<" ";
		}
		return M[V];
	}
	else
    	return 0; 
} 
int main() 
{ 
	int num,n,deno[100];
    cout<<"Enter the number of denominations: ";
    cin>>n;
    cout<<"Enter the denominations : ";
    for(int i=0;i<n;i++)
    {
    	cin>>deno[i];
	}
    cout<<"Enter the number for change: ";
    cin>>num; 
    cout << "Change for " << num << ": "; 
    int x=minCoins(deno, n, num);
    if(x==0)
    cout<<"Change doesn't exist!";
    cout<<endl;
    return 0; 
} 

