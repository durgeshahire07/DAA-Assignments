/*7b - Find Minimum Cost Spanning Tree for a given undirected graph using Kruskal’s and
Prim’s Algorithm.*/

#include<bits/stdc++.h>
using namespace std;

#define V 6 

int MinVertex(vector<int>& value,vector<bool>& setMST)
{
    int min=INT_MAX;
    int vertex;
    for(int i=0;i<V;i++)
    {
        if(setMST[i]==false && value[i]<min)
        {
            vertex=i;
            min=value[i];
        }
    }
    return vertex;
}

void findMST(int graph[V][V])
{
   int parent[V] ;// Stores MST
   vector<int> value(V,INT_MAX);//used for storing edges
   vector<bool> setMST(V,false);//to store nodes that are there in MST
   
   parent[0]=-1;//start node has no parent
   value[0]=0;//start node has value=0
   
   //MST Algorithm
   for(int i=0;i<V-1;i++)
   {
      //select best vertex by applying greedy method
      int u=MinVertex(value,setMST);
      setMST[u]=true;
      
      //Relax adjacent vertices(not yet included in MST)
      for(int j=0;j<V;j++)
      {
          /* 1. Edge is present from u to j
          2. Vertex j is not included in MST
          3. Edge weight is smaller than current edge weight
          */
          
          if(graph[u][j]!=0 && setMST[j]==false && graph[u][j]<value[j])
          {
              value[j]=graph[u][j];
              parent[j]=u;
          }
      }
   }   
   //Print MST
   cout<<"Edges of Prims Minimun Spanning tree are :"<<endl;
   for(int i=1;i<V;i++)
   {
       cout<<"u->V :"<<parent[i]<<"->"<<i<<" wt = "<<graph[parent[i]][i]<<"\n";
   }
}


int main()
{
    int graph[V][V]={{0,4,6,0,0,0},{4,0,6,3,4,0},{6,6,0,1,8,0},
    {0,3,1,0,2,3},{0,4,8,2,0,7},{0,0,0,3,7,0}};
    
    findMST(graph);
    return 0;
    
}