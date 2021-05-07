#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n;
int k;
vector<pair<int,int>> adj[2*100000 + 10];
int dis[100000+10][15];
int cnt[100000+10]={0};
int falak=0;
void djikstra(){
	multiset<pair<int, int>> s;
	s.insert({0, 1});
	
	while(!s.empty()){
		if(falak>(n+1)*(k+1))
			break;
		pair<int, int> p = *s.begin();
		s.erase(s.begin());
		if(cnt[p.second]>k)
			continue;
		cnt[p.second] += 1;
		dis[p.second][cnt[p.second]] = p.first;
 		falak++;

		for(int i=0; i<adj[p.second].size(); ++i){
			int node = adj[p.second][i].first;
			int w = adj[p.second][i].second;
			s.insert({p.first+w, node});

		}
	}
}
 
signed main(){
	int m;cin>>n>>m>>k;
	while(m--){
		int a,b,c;
		cin>>a>>b>>c;
		adj[a].push_back({b,c});
	}
	// for(int i=1; i<=n; ++i){
	// 	dis[i] = 1e15;
	// }
	djikstra();
 
	for(int i=1; i<=k; ++i){
		cout<<dis[n][i]<<" ";
	}
 
}