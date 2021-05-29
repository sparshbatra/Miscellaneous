#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
vector<int> adj[100000+10];
int visi[100000+10]={0};
int team[100000+10];
void bfs(int src){
	queue<int> q; // node and parent
	q.push(src);
	visi[src] = 1;
	team[src] = 0;

	while(!q.empty()){
		int node = q.front();
		q.pop();
		
		for(int i=0; i<adj[node].size(); ++i){
			int nbr = adj[node][i];
			
			if(team[nbr] == team[node]){
				cout<<"IMPOSSIBLE";
				exit(0);
				return;
			}
			if(visi[nbr] == 1)
				continue;

			q.push(nbr);
			team[nbr] = 1-team[node];
			visi[nbr] = 1;
		}

	}


}
int main(){
	int m;
	cin>>n>>m;
	while(m--){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);

	}
	for(int i=1; i<=n; ++i){
		team[i] = -1;
	}
	for(int i=1; i<=n; ++i){
		if(visi[i] == 0){
			bfs(i);
		}
	}
	for(int i=1; i<=n; ++i){
		cout<<team[i]+1<<" ";
	}
	
}