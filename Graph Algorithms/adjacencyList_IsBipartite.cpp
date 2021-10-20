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
	
	void isbipartite(){
		bool visited[Max]={false};
		int partition[Max]={0};
		int distance[Max]={0};
		queue<int> q;
		list<int>::iterator it;
		int check=1;
		
		visited[1]=true;
		partition[1]=1;
		distance[1]=0;
		q.push(1);
		while(!q.empty()){
			int u=q.front();
			for(it=adjlist[u].begin();it!=adjlist[u].end();++it){
				if(partition[u]==partition[*it]){
					check=0;
				}else{
					if(visited[*it]==false){
						visited[*it]=true;
						distance[*it]=distance[u]+1;
						partition[*it]=3-partition[u];
						q.push(*it);	
					}
				}
			}
			q.pop();
		}
		if(check){
			cout<<"This is a bipartite graph"<<endl;
		}else{
			cout<<"This is not a bipartite graph"<<endl;
		}
		cout<<endl;
		return;
	}
	
};

int main(){
	Graph bi_true;
	bi_true.printGraph();
    bi_true.addEdge(1,2);
    bi_true.addEdge(1,3);
    bi_true.addEdge(2,4);
    bi_true.addEdge(3,5);
    bi_true.addEdge(4,6);
    bi_true.addEdge(5,6);
	bi_true.isbipartite(); 
	return 0;
}
