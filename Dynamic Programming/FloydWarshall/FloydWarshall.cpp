// Floyd Warshall algorithm
 // Use to find all pairs of shortest path
#include<bits/stdc++.h>
using namespace std;

#define V 4     // Number of vertices in graph problem

#define INF INT_MAX  // INF infinite maximum distance value for not connected vertices <limits.h> header file used

void output(int dist[][V]) // output matrix show here
{

 cout<<"ALL SHORTEST PATH FOR EVERY VERTICES\n";


  for(int i=0;i<V;i++){
    for(int j=0;j<V;j++){
        if(dist[i][j]==INF)
             cout<<"INF"<<"  ";
        else
            cout<<dist[i][j]<<"  ";
  }
  cout<<endl;
 }
}
void flyodWarshall(int g[][V])   // g graph to find all pairs shortest path
{
   int dist[V][V]; // 2D array to contain final all pairs path


  for(int i=0;i<V;i++){
    for(int j=0;j<V;j++){
        dist[i][j]=g[i][j];   // here we are just putting the original graph values to dist[][] matrix
    }
  }

 for(int k=0;k<V;k++){  // select source  vertices

  for(int i=0;i<V;i++){ // select destination vertices

    for(int j=0;j<V;j++){ //  if k shortest path it will work

          if((dist[i][j]>dist[i][k]+dist[k][j]) && (dist[i][k]!=INF) &&(dist[k][j]!=INF))
              dist[i][j]=dist[i][k]+dist[k][j];

    }
  }
 }
 output(dist);  // print shortest matrix
}

int main(){

int Gra[V][V]={{0,3,INF,7},{8,0,2,INF},{5,INF,0,1},{2,INF,INF,0}};  // index value 0 show self loop edges and INF infinite largest distance


flyodWarshall(Gra); // use to find paths

return 0;
}
