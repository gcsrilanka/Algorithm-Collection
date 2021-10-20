#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#define Max 10
using namespace std;

class Graph{
	list<int> adjlist[Max];
	
	public:
	void addEdge(int u,int v){
		adjlist[u].push_back(v);
		//if undirected
		//adjlist[v].push_back(u);
	}
	void printGraph(){
		list<int>::iterator it;
		
		for(int i=0;i<Max;i++){
			cout<<i<<"->";
			for(it=adjlist[i].begin();it!=adjlist[i].end();++it){
				cout<<*it<<"-";
			}
			cout<<"/\n";
		}
		cout<<"\n\n";
	}
	
	void isreachable(int u,int v){
		bool visited[Max]={false};
		list<int>::iterator it;
		int check=0;
		queue<int> q;
		visited[u]=true;
		q.push(u);
		while(!q.empty()){
			int d=q.front();
			q.pop();
			if(d==v){
				check=1;
			}
			for(it=adjlist[d].begin();it!=adjlist[d].end();++it){
				if(visited[*it]==false){
					visited[*it]=true;
					q.push(*it);
				}	
			}
				
		}
		if(check){
			cout<<"The edge "<<v<<" is reachable from "<<u<<endl;
		}else{
			cout<<"The edge "<<v<<" is not reachable from "<<u<<endl;
		}
		cout<<"\n";
		return;
		
	}
	
	
};

int main(){
	Graph graph;
	graph.addEdge(1,3);
	graph.addEdge(3,1);
	graph.addEdge(6,10);
	graph.addEdge(2,6);
	graph.addEdge(6,4);
	graph.addEdge(4,5);
	graph.addEdge(8,6);
	
	graph.isreachable(1,3);
	graph.printGraph();
	
	
	
	
	return 0;
}
