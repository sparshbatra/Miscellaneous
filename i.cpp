#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
vector<int> adj[100000+10];
int visi[100000+10]={0};
int parent[100000+10]={0};
void dfs(int src){
	visi[src] = 1;
	for(int i=0; i<adj[src].size(); ++i){
		int neighbor = adj[src][i];
		if(visi[neighbor] == 2)
			continue;
		if(visi[neighbor] == 1){
			vector<int> ans;

			int node= src;
			while(1){
				ans.push_back(node);
				node = parent[node];
				if(node == neighbor){
					break;
				}
			}
			ans.push_back(neighbor);

			reverse(ans.begin(), ans.end());
			ans.push_back(neighbor);
			cout<<ans.size()<<endl;
			for(auto x : ans){
				cout<<x<<" ";
			}
			exit(0);
		}
		else{
			parent[neighbor] = src;
			dfs(neighbor);
		}
	}

	visi[src] = 2;
}
int main(){
	int m;
	cin>>n>>m;
	while(m--){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);

	}
	for(int i=1; i<=n; ++i){
		if(visi[i]==0)
		dfs(i);

	}
	cout<<"IMPOSSIBLE";

		
}