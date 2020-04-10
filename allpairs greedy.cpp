
#include <iostream> 
using namespace std;
# define  INT_MAX 9999
int V;
int minDistance(int dist[], bool sptSet[]) 
{
	int min = INT_MAX, min_index; 

	for (int v = 0; v < V; v++) 
		if (sptSet[v] == false && dist[v] <= min) 
			min = dist[v], min_index = v; 

	return min_index; 
} 

int printSolution(int dist[]) 
{ 
	
	for (int i = 0; i < V; i++) 
		printf("%d \t\t %d\n", i, dist[i]); 
} 

void dijkstra(int graph[][50],int src) 
{ 
	int dist[V];  

	bool sptSet[V]; 
	for (int i = 0; i < V; i++) 
		dist[i] = INT_MAX, sptSet[i] = false; 

	
	dist[src] = 0; 
	for (int count = 0; count < V - 1; count++) { 
		int u = minDistance(dist, sptSet); 

		
		sptSet[u] = true; 
 
		for (int v = 0; v < V; v++)
			if (!sptSet[v] && graph[u][v]!=9999 && dist[u] != INT_MAX 
				&& dist[u] + graph[u][v] < dist[v]) 
				dist[v] = dist[u] + graph[u][v]; 
	} 


	printSolution(dist); 
} 

int main() 
{ 	
	cout<<" enter no. of vertices:";
	cin>>V;
	int graph[V][50];
	cout<<"enter edges, if there is no edge press 9999\n";
	for (int i = 0; i < V; i++) 
	for (int j = 0; j < V; j++)
	{
		cout<< i<<"->"<<j<<": ";
		cin>>graph[i][j];
		cout<<"\n";
	 }
	for (int i = 0; i < V; i++) 
	{
		cout<<"distance from source vertex  "<<i<<" to:\n"; 
		dijkstra(graph,i); 
	}
	return 0; 
} 

