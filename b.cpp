#include<bits/stdc++.h>
using namespace std;
stack<int> s;
vector<int> adj[100000+10];
int visi[100000+10]={0};
void dfs(int src, int n){
    visi[src] = 1;
    for(auto x : adj[src]){
		if(visi[x]==1)continue;
		dfs(x,n);
	}
	s.push(src);

}
int main(){
    int n;cin>>n;
    int m;cin>>m;
    for(int i=0; i<m; ++i){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        
    }
	for(int i=1; i<=n; ++i){
		if(visi[i]==0)
			dfs(i, n);
	}
	if(int(s.size())!=n){
		cout<<"IMPOSSIBLE";return 0;
	}
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
    
}
