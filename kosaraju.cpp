// it is algorithm to check strongly  connected graph which mean
//that from any node we can acess any other node if not then it is not strongly connected
 #include <bits/stdc++.h>
using namespace std;

void addedge(vector<int>graph[],int u,int v){
	graph[u].push_back(v);	
}

vector<int>ORDER;

void dfs(int source,vector<bool>&visited,vector<int>graph[]){
	visited[source]=true;
	for (auto x:graph[source])
	{
		/* code */
		if(!visited[x]){
			dfs(x,visited,graph);
		}
	}
	ORDER.push_back(source);
}
void reverse_dfs(int src,vector<bool>&visited2,vector<int>reverse_graph[]){
	visited2[src]=true;
	for(auto x:reverse_graph[src]){
		if(!visited2[x]){
			reverse_dfs(x,visited2,reverse_graph);
		}
	}
}
int kosaraju(int size,vector<int>graph[]){
	ORDER.clear();
	vector<int>reverse_graph[size];
	for (int y = 0; y<size; y++)
	{
		for(auto x:graph[y]){
			reverse_graph[x].push_back(y);
		}
	}
	vector<bool>visited(size,false);
	for (int i = 0; i <size; i++)
	{
		if (!visited[i])
		{
			dfs(i,visited,graph);
		}
	}
	//main part of kosaraju
	vector<bool>visit(size,false);
	int counter=0;
	for(int i=size-1;i>=0;i--){
		if(!visit[ORDER[i]]){
			
			reverse_dfs(ORDER[i],visit,reverse_graph);
			cout<<"("<<ORDER[i]<<""<<")";
			counter++;

		}
	}
	return counter;

}
int main(){
	int size=5;
	vector<int>graph[size];
	addedge(graph,0,2);
	addedge(graph,2,1);
	addedge(graph,1,0);
	addedge(graph,0,3);
	addedge(graph,3,4);
	cout<<"--STRONGLY CONNECTED COMPONENT ARE :"<<kosaraju(size,graph);


	return 0;
}