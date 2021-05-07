#include <bits/stdc++.h>
using namespace std;
int n;
int dp[2*100000+10][25];
vector<int> adj[2*100000+10];
int indegree[2*100000+10];
int outdegree[2*100000+10];
int timer=0;


void fillUp(int n, int *e){
	dp[n][0] = e[n];
	for(int i=1; i<=20; ++i){
		if(dp[n][i-1] == -1)
			continue;
		dp[n][i] = dp[dp[n][i-1]][i-1];
	}
	
}

void dfs(int src, int* e){
	fillUp(src, e);
	indegree[src] = ++timer;

	for(auto ngr: adj[src]){
		if(ngr == e[src])
			continue;
		dfs(ngr, e);
	}
	outdegree[src] = ++timer;
}

int query(int x, int k){
	if(k==0)
		return x;
	int t=1;
	for(int bit=20; bit>=0; --bit){
		if((t<<bit) & k ){
			if(dp[x][bit]==-1) return -1;
			return query(dp[x][bit], k-(t<<bit));
		}
	}
	return -1;
}
bool isAncestor(int a, int b){
	if(indegree[a]<=indegree[b] && outdegree[a]>=outdegree[b]){
		return true;
	}
	return false;
}
int LCA(int a, int b){
	if(isAncestor(a,b))
		return a;
	if(isAncestor(b,a))
		return b;

	for(int i=20; i>=0; --i){
		if(dp[a][i] == -1)
			continue;
		if(isAncestor(dp[a][i],b)){
			continue;
		}
		else{
			a = dp[a][i];
		}

	}
	return dp[a][0];
}

int main(){
	int q;
	cin>>n>>q;
	int e[n+1];
	e[1] = -1;
	for(int i=2; i<=n; ++i){
		cin>>e[i];
		adj[i].push_back(e[i]);
		adj[e[i]].push_back(i);

	}
	memset(dp, -1, sizeof(dp));

	dfs(1, e);

	// while(q--){
	// 	int x,k;
	// 	cin>>x>>k;
	// 	cout<< query(x, k) <<endl;
	// }	
	while(q--){
		int a,b;cin>>a>>b;
		cout<<LCA(a, b)<<endl;
	}

}