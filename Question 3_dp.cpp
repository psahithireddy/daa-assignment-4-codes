#include<iostream>
#include<cstdlib>
using namespace std;
class node
{
public:
int u;
node* nptr;
};
class list
{
public:
node* list;
int length;
void push(int u);
void display();
};


void list::push(int u)
{
node *temp=(node*)malloc(sizeof(node));
if(temp==NULL)
{cout<<"memory is full\n";}
else
{
temp->u=u;

temp->nptr=NULL;
if(length==0)
{
list=temp;
length++;
}
else
{
temp->nptr=list;
list=temp;
length++;
}
}
}



void list::display()
{
node* temp=list;
while(temp!=NULL)
{
cout<<temp->u<<" ";
temp=temp->nptr;
}
cout<<"\n";
}

class graph
{
public:
int adjmatrix[50][50];
int v;
list* lsl[50];
int visit[50];
int fis[50];
int lis[50];
int els[50];
};
int print(graph *g,int s)
{
node* temp=g->lsl[s]->list;
while(temp!=NULL)
{
if(temp->u==s)
cout<<" "<<s<<" ";
else
print(g,temp->u);

temp=temp->nptr;

}

}
int maxis(graph* g,int source)
{
g->visit[source]=1;
list* inc=(list*)malloc(sizeof(list));
inc->list=NULL;inc->length=0;
list* exc=(list*)malloc(sizeof(list));
exc->list=NULL;exc->length=0;
if(g->v==0)
return 0;
if(g->fis[source])
return g->fis[source];
int count=0;

for(int i=0;i<g->v;i++)
{
if((g->visit[i]!=1)&&(g->adjmatrix[source][i]!=0))
{
count++;
}
}
if(count==0)
{
g->lsl[source]->push(source);
return (g->fis[source]=1);}
g->lis[source]=1;
inc->push(source);
for(int i=0;i<g->v;i++)
{
if((g->visit[i]!=1)&&(g->adjmatrix[source][i]!=0))
{

g->els[source]+=maxis(g,i);
exc->push(i);
cout<<"source : "<<source<<"\n";
for (int i=0;i<g->v;i++)
{
cout<<g->lis[i]<<"  "<<g->els[i]<<"  "<<g->fis[i]<<"\n"; 
}

for(int j=0;j<g->v;j++)
{
if(g->adjmatrix[i][j]!=0)
{
if(j!=source)
{

g->lis[source]+=g->fis[j];

inc->push(j);
}
}
}
}
}

if(g->lis[source]>g->els[source])
{g->fis[source]=g->lis[source];g->lsl[source]=inc;}
else
{g->fis[source]=g->els[source];g->lsl[source]=exc;}


return g->fis[source];
}






int main()
{

graph* g=(graph*)malloc(sizeof(graph));

for(int i=0;i<50;i++)
{
g->lis[i]=0;g->els[i]=0;g->visit[i]=0;
g->lsl[i]=(list*)malloc(sizeof(list));
g->lsl[i]->list=NULL;g->lsl[i]->length=0;
}
for(int i=0;i<50;i++)
for(int j=0;j<50;j++)
{
g->adjmatrix[i][j]=0;
}

cout<<"enter no of vertices \n";
cin>>g->v;
for(int i=0;i<g->v;i++)
for(int j=0;j<g->v;j++)
{
cin>>g->adjmatrix[i][j];;
}

int num=maxis(g,0);

cout<<"largest independent set possible is : "<<num<<"\n";
/*
cout<<"\n";
for (int i=0;i<g->v;i++)
{
cout<<g->lis[i]<<"  "<<g->els[i]<<"  "<<g->fis[i]<<"\n"; 
}
cout<<"\n";
cout<<"source : "<<source<<"\n";
for (int i=0;i<g->v;i++)
{
cout<<g->lis[i]<<"  "<<g->els[i]<<"  "<<g->fis[i]<<"\n"; 
}
for(int i=0;i<g->v;i++)
{
g->lsl[i]->display();
}
for(int i=0;i<g->v;i++)
{
cout<<"vertex : "<<i<<"\n";
g->lsl[i]->display();
}

*/

cout<<"elements\n";
print(g,0);
}
