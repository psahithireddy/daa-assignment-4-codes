#include <iostream> 
using namespace std;
int n,num,deno[10],l[10]; 
void findMin(int V) 
{ 
    int ans[20][20]={{0}},k=0,h=0,index,min=1000000,flag=0;// min is just given a intial large value 
    //ans[i][j] s a two dimensional array that stores diff combinations possible in each row 
    //index will store the corresponding i value of ans having min number of denominations
	//so I will print only the notes in index as answer
    while(n>0)
	{
		k=0;
		V=num;
	    for (int i = n - 1; i >= 0; i--) 
		{
			int c=0;
	        while (V >= deno[i]&&c<l[i]) //checking if the number is less than the denominations (in descending order)
			{ 
	            V -= deno[i]; 
	            ans[h][k]=deno[i];//storing the denomination used 
	            c++;//counting the number of times the denomination is used
	            k++;
	        } 
	    } 
	    if(V==0)//when a combination is possible
	    {	flag=1;	
		    if(k<min&&k!=0)//if the count is less than previous combinations and also not zero(no combinations)
		    {
		    	min=k;
		    	index=h;//storing the min position 
			}
		}
		h++;//so that next combination is stored in the next row of "ans"
	    n--;//this will remove the largest denomination from considering in the next loop
	}
	if(flag==0)
		cout<<"change doesnt exist";
	else	
    	for (int i = 0; i < min; i++) //printing the denominations with min count with help of "index"
        cout << ans[index][i] << "  "; 
} 
int main() 
{ 
    cout<<"Enter the number of denominations: ";
    cin>>n;
    cout<<"Enter the denominations in ascending order: "<<endl;
    for(int i=0;i<n;i++)
    {
    	cin>>deno[i];
	}
	cout<<"Enter the number of each denominations in order of the denominations: "<<endl;
    for(int i=0;i<n;i++)
    {
    	cin>>l[i];
	}
    cout<<"Enter the number for change: ";
    cin>>num;
    cout << "Following is minimal number of change for " << num << ": "; 
    findMin(num); 
    cout<<endl;
    return 0; 
} 

