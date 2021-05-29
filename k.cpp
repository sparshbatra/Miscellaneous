#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
std::vector<int> adj[100000+10];
int visi[100000+10]={0};
void dfs(int src){
	visi[src] = 1;
	for(auto neighbor: adj[src]){
		if(visi[neighbor] == 2){
			continue;
		}
		if(visi[neighbor] == 1){
			cout<<"IMPOSSIBLE";
			exit(0);
		}
		dfs(neighbor);
	}
	visi[src] = 2;

}
void hasCycle(){
	for(int i=1; i<=n; ++i){
		if(visi[i] == 0){
			dfs(i);
		}
	}
}
std::vector<int> topoArray;
void dfs2(int src){
	visi[src] = 1;
	for(auto neighbor: adj[src]){
		if(visi[neighbor] == 2){
			continue;
		}
		if(visi[neighbor] == 1){
			continue;
		}
		
		dfs2(neighbor);
	}
	topoArray.push_back(src);
	visi[src] = 2;	
}
void topoSort(){
	for(int i=1; i<=n; ++i){
		if(visi[i] == 0){
			dfs2(i);
		}
	}
	// cout<<"topoArray is "<<endl;
	// for(auto x: topoArray){
	// 	cout<<x<<" ";
	// }
	// cout<<endl;
	reverse(topoArray.begin(), topoArray.end());
}
int parent[100000+10];
void maximumNodes(){
	
	int maxDist[n+1];
	for(int i=0; i<=n; ++i){
		maxDist[i] = -1;
	}
	maxDist[1] = 0;
	parent[1] = -1;


	for(int i=0; i<n; ++i){ // traverse topoArray
		int node = topoArray[i];

		for(auto neighbor : adj[node]){

			if(maxDist[neighbor] < maxDist[node] + 1 && maxDist[node]!=-1){
				maxDist[neighbor] = maxDist[node] + 1;
				parent[neighbor] = node;
			}
		}

	}
	if(maxDist[n] == -1){
		cout<<"IMPOSSIBLE";exit(0);
	}
	vector<int> ans;
	int node = n;
	while(node != 1){

		ans.push_back(node);
		node = parent[node];

	}
	ans.push_back(1);
	reverse(ans.begin(), ans.end());
	cout<<ans.size()<<endl;
	for(auto x: ans){
		cout<<x<<" ";
	}
}

int main(){
	int m;
	cin>>n>>m;
	while(m--){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		parent[b] = a;
	}
	hasCycle();
	memset(visi, 0, sizeof(visi));
	topoSort();//only for DAG
	maximumNodes();

}
