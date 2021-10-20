#include<iostream>
using namespace std;
#define Max 10
int graph[Max][Max];
void addEdge(int u,int v){
	graph[u][v]=1;
	graph[v][u]=1;
}

void prints(){
	cout<<"   ";
	for(int j=1;j<Max;j++){
			cout<<j<<" ";
		}
		cout<<endl;
	for(int i=1;i<Max;i++){
		cout<<i<<"  ";
		for(int j=1;j<Max;j++){
			cout<<graph[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main(){

	
	addEdge(1,2);
    addEdge(3,2);
    addEdge(3,4);
    addEdge(4,2);
    addEdge(4,5);
    addEdge(5,2);
    addEdge(5,1);
    prints();
	return 0;
}
