#include<iostream>
#include<list>
#include<vector>
#include<iterator>
#define Max 10
using namespace std;
list<int> g[Max];
void addEdge(int u,int v){
	g[u].push_back(v);
	g[v].push_back(u);
	
}

void print(){
	list<int>::iterator ptr;
	for(int i=1;i<Max;i++){
		cout<<i<<"->";
		for(ptr=g[i].begin();ptr!=g[i].end();ptr++){
			cout<<*ptr<<" ";
		}
		cout<<endl;
	}
}
int main(){
	addEdge(1,2);
	addEdge(2,6);
	addEdge(3,5);
	addEdge(5,6);
	print();
	return 0;
}
