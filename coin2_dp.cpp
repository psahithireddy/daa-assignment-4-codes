#include<iostream> 
using namespace std; 
int l[100];
int minCoins(int deno[], int m, int V) 
{ 
	// V is the number that requires change
	// m is the number of denominations
	// deno[] has the different denominations in any order
	// l[] has the limit of each denomination in deno[]
    // M[i] will be storing the minimum number of coins required for i value.  So M[V] will have the no. of coins required for V
	//coin[][] will store the coins used for making i wherei=0,1,...,V 
    int M[V+1];
	int coin[50][50],k; 
    M[0] = 0; 				 // Initialize M[0] to zero
    for (int i=1; i<=V; i++) // Initialize all values as Infinite 
        M[i] = 2147483647; 
    for (int i=1; i<=V; i++) // for each i where i=0,1,...,V
    {  
        for (int j=0; j<m; j++)
		{ 
        	if (deno[j] <= i) //for every denomination less than i
        	{ 
          		int c=0;
          		if(M[i-deno[j]]!=2147483647)
	          		for(k=0;k<M[i-deno[j]];k++)// if M[] not infinte then count the number of deno[j] used in (i-deno[j])
				  	{
				  		if(coin[i-deno[j]][k]==deno[j])
				  			c++;
					}
				if(c<l[j])// if the count of deno[j] is less than the limit l[j] then include it in M[i]
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
		}
    } 
    if(M[V]!=2147483647)// if change is possible then print the coins used else return 0
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
	cout<<"Enter the number of each denominations in order of the denominations: ";
    for(int i=0;i<n;i++)
    {
    	cin>>l[i];
	}
    cout<<"Enter the number for change: ";
    cin>>num; 
    cout <<"\nChange for " << num << ": "; 
    int x=minCoins(deno, n, num);
    if(x==0)
    cout<<"\nChange doesn't exist!";
    else
    cout<<endl<<"Number of coins required: "<<x<<endl;
    return 0; 
} 

