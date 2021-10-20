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
	
	
	private:
	bool isCyclicUtil(int v, bool visited[], bool recStack[]){ 
	    if(visited[v] == false) 
	    { 
	        
	        visited[v] = true; 
	        recStack[v] = true; 
	  
	       
	        list<int>::iterator it; 
	        for(it = adjlist[v].begin(); it != adjlist[v].end(); ++it) 
	        { 
	            if ( !visited[*it] && isCyclicUtil(*it, visited, recStack) ) 
	                return true; 
	            else if (recStack[*it]) 
	                return true; 
	        } 
	  
	    } 
	    recStack[v] = false;  
	    return false; 
	} 
	
	public:
	bool isCyclic(){ 
	    bool visited[Max];
	    bool recStack[Max];
	    for(int i = 0; i < Max; i++){ 
	        visited[i] = false; 
	        recStack[i] = false; 
	    } 
	  
	    for(int i = 0; i < Max; i++) 
	        if (isCyclicUtil(i, visited, recStack)) 
	            return true; 
	  
	    return false; 
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
	
	
	if(g.isCyclic()){
		cout<<"Graph is cyclic"<<endl;
	}else{
		cout<<"Graph is not cyclic"<<endl;
	}
	
	
	return 0;
}
