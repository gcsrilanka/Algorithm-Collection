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
	
	void outDegree(){
		list<int>::iterator it;
		int outdegree[Max]={0};
		for(int i=0;i<Max;++i){
			for(it=adjlist[i].begin();it!=adjlist[i].end();++it){
				outdegree[i]++;
			}
		}
		cout<<"Out degree"<<endl;
		for(int i=1;i<Max;i++){
			cout<<i<<":"<<outdegree[i]<<endl;
		}
		cout<<"\n\n";
	}
	void inDegree(){
		list<int>::iterator it;
		int indegree[Max]={0};
		for(int i=0;i<Max;++i){
			for(it=adjlist[i].begin();it!=adjlist[i].end();++it){
				indegree[*it]++;
			}
		}
		cout<<"In degree"<<endl;
		for(int i=1;i<Max;i++){
			cout<<i<<":"<<indegree[i]<<endl;
		}
		cout<<"\n\n";
	}

};

int main(){
	Graph g;
	g.addEdge(1,2);
	g.addEdge(3,1);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.addEdge(5,6);
	g.addEdge(6,7);
	g.addEdge(7,8);
	g.addEdge(7,9);
	
	g.printGraph();
	g.outDegree();
	g.inDegree();

	return 0;
}
