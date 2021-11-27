/*7b - Find Minimum Cost Spanning Tree for a given undirected graph using Kruskal’s and
Prim’s Algorithm.*/

#include <iostream>
#include <vector>

using namespace std;

#define V 6

int MinVertex(vector<int> &value, vector<bool> &setMST)
{
    int min = INT32_MAX;
    int vertex;
    for (int i = 0; i < V; i++)
    {
        if (setMST[i] == false && value[i] < min)
        {
            vertex = i;
            min = value[i];
        }
    }
    return vertex;
}

void findMST(int graph[V][V])
{
    
    int parent[V];                 
    // Stores MST
    vector<int> value(V, INT32_MAX); //used for storing edges
    vector<bool> setMST(V, false); //to store nodes that are there in MST

    parent[0] = -1; //start node has no parent
    value[0] = 0;   //start node has value=0

    //MST Algorithm
    for (int i = 0; i < V - 1; i++)
    {
        //select best vertex by applying greedy method
        int u = MinVertex(value, setMST);
        setMST[u] = true;

        //Relax adjacent vertices(not yet included in MST)
        for (int j = 0; j < V; j++)
        {
            /* 1. Edge is present from u to j
          2. Vertex j is not included in MST
          3. Edge weight is smaller than current edge weight
          */

            if (graph[u][j] != 0 && setMST[j] == false && graph[u][j] < value[j])
            {
                value[j] = graph[u][j];
                parent[j] = u;
            }
        }
    }
    //Print MST
   
    cout << "Edges of Prims Minimun Spanning tree are :" << endl;
    for (int i = 1; i < V; i++)
    {
        cout << "u->V :" << parent[i] << "->" << i << " wt = " << graph[parent[i]][i] << "\n";
    }
}

int updateMat(int graph[5][5]){
    int v1,v2,wt;
    while(1){
        cout<<"\nEnter V1 V2 WT: ";
        cin>>v1>>v2>>wt;
        graph[v1][v2] = graph[v2][v1] = wt;
        cout<<"\nDo you want to continue(y/n): ";
        char c;
        cin>>c;
        if(c!='y'){
            return 0;
        }
    }
    

}

int main()
{
    int graph[V][V] = {{0, 4, 6, 0, 0, 0},
                       {4, 0, 6, 3, 4, 0},
                       {6, 6, 0, 1, 8, 0},
                       {0, 3, 1, 0, 2, 3},
                       {0, 4, 8, 2, 0, 7},
                       {0, 0, 0, 3, 7, 0}};
    // int arr[10];
    // cout<<"Enter the vertices: ";
    // for(int i=0;i<5;i++){
    //     cin>>arr[i];
    // }
    // int graph[5][5];
    // for(int i=0;i<5;i++){
    //     for(int j=0;j<5;j++){
    //         graph[i][j]=0;
    //     }
    // }
    // cout<<"\nInitial Adjacency Matrix representation: ";
    // for(int i=0;i<5;i++){
    //     cout<<endl;
    //     for(int j=0;j<5;j++){
    //         cout<<graph[i][j]<<" ";
    //     }
    // }

    // updateMat(graph);
    

    findMST(graph);
    
    return 0;
}