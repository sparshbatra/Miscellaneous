//shortest dist I
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
vector<pair<ll, ll>> adj[2*100000+10];
ll dist[100000+10];
ll visi[100000+10]={0};

void djikstra(){
	dist[1] = 0;
	set<pair<ll, ll>> s;
	s.insert({0, 1});

	while(!s.empty()){
		ll dis, node;
		tie(dis, node) = *s.begin();
		visi[node] = 1;
		s.erase(s.begin());

		for(ll i=0; i<adj[node].size(); ++i){
			ll weight = adj[node][i].second;
			ll neighbor = adj[node][i].first;

			if(visi[neighbor] == 1){
				continue;
			}
			s.erase({dist[neighbor], neighbor});
			dist[neighbor] = min(weight + dist[node], dist[neighbor]);

			s.insert({dist[neighbor], neighbor});

		}
	}
}

int main(){
	ll m;
	cin>>n>>m;
	while(m--){
		ll a,b,c;cin>>a>>b>>c;
		adj[a].push_back({b,c});
	}
	for(ll i=1; i<=n; ++i){
		dist[i] = 1e15;
	}

	djikstra();
	for(ll i=1; i<=n; ++i){
		cout<<dist[i]<<" ";
	}
}