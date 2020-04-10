/* Bellman_Ford Algorathim for weighted directed graph (even negative weights)

1) This step initializes distances from source to all vertices as infinite and distance to source itself as 0. 
	Create an array dist[] of size |V| with all values as infinite except dist[src] where src is source vertex.

2) This step calculates shortest distances. Do following |V|-1 times where |V| is the number of vertices in given graph.
…..a) Do following for each edge u-v
………………If dist[v] > dist[u] + weight of edge uv, then update dist[v]
………………….dist[v] = dist[u] + weight of edge uv

3) This step reports if there is a negative weight cycle in graph.
	 Do following for each edge u-v
		……If dist[v] > dist[u] + weight of edge uv, 
			then “Graph contains negative weight cycle”
The idea of step 3 is, step 2 guarantees shortest distances if graph doesn’t contain negative weight cycle. 
If we iterate through all edges one more time and get a shorter path for any vertex, then there is a negative weight cycle
*/
#include<iostream>
using namespace std;
int n,d[100]={0};
int Bellman_Ford_Algo(int G[][100],int v)
{
	for(int i=1;i<=n;i++)
	{
		if(i!=v)
			d[i]=2147483647;	//initialize the distance non source vetrex as infinity
		else
			d[i]=0;				//initialize the distance of source vertex as zero
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(G[i][j]!=0)
			{
				if(d[j]>d[i]+G[i][j])
					d[j]=d[i]+G[i][j];
			}
		}
	}
	//Checking if graph contains a negative cycle
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(G[i][j]!=0)
			{
				if(d[j]>d[i]+G[i][j])
				{
					flag=1;
					break;
				}
			}
		}
	}
	return flag;
}
int main()
{
	int v,G[100][100]={0};
	cout<<"Enter the number of vertices in the weighted directed graph: ";
	cin>>n;
	cout<<"Let the vertices be 1,2,...,"<<n<<"\nEnter the adjacency matrix of the weighted directed graph (negative edges allowed):"<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>G[i][j];
		}
	}
	cout<<"Enter the source vertex: ";
	cin>>v;
	if(Bellman_Ford_Algo(G,v))
		cout<<"The graph contains negative cycle!!"<<endl;
	else
	{
		for(int i=1;i<=n;i++)
		{
			cout<<"Distance of vertex "<<v<<" from "<<i<<" is "<<d[i]<<endl;
		}
	}
	return 0;
}
