#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
int visi[100000+10]={0};
vector<int> adj[100000+10];
void dfs(int src){
	visi[src] = 1;
	for(int i=0; i<adj[src].size(); ++i){
		int neighbor = adj[src][i];
		if(visi[neighbor] == 0){
			dfs(neighbor);
		}
	}
}
void fn(){
	vector<int> v;
	for(int i=1; i<=n; ++i){
		if(visi[i] == 0){
			dfs(i);
			v.push_back(i);
		}
	}
	int ans = v.size()-1;
	cout<<ans<<endl;
	if(ans==0)
		return;
	
	for(int i=1; i<v.size(); ++i){
		cout<<v[i-1]<<" "<<v[i]<<endl;
	}
}
int main(){
	cin>>n>>m;
	while(m--){
		int u,v;cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);

	}
	fn();
}