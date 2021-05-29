#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
vector<pair<ll,ll>> adj[100000+10];
vector<pair<ll,ll>> revAdj[100000+10];
ll distFromStart[100000+10];
ll distFromEnd[100000+10];
ll visi[100000+10]={0};
void djikstra(vector<pair<ll,ll>> *adjList, ll src, ll* shortestDist){
	set<pair<ll, ll>> s; // dist, node
	s.insert({0, src});
	shortestDist[src] = 0;

	while(!s.empty()){
		ll dist, node;
		tie(dist, node) = *s.begin();
		s.erase(s.begin());
		
		if(visi[node] == 1)
				continue;
		visi[node] = 1;

		shortestDist[node] = dist;


		for(ll i=0; i<adjList[node].size(); ++i){
			ll neighbor = adjList[node][i].first;
			ll w = adjList[node][i].second;
			
			// s.erase({shortestDist[neighbor], neighbor});


			s.insert({dist + w, neighbor});
		}
	}
	// for(ll i=1; i<=n ;++i){
	// 	cout<<shortestDist[i]<<" ";
	// }
	// cout<<endl;

}

void flightDiscount(){
	
	ll ans = LONG_MAX;
	for(ll i=1; i<=n; ++i){
		ll node = i;
		for(ll j=0; j<adj[i].size(); ++j){
			ll neighbor = adj[i][j].first;
			ll edgeWeight = adj[i][j].second;

			ans = min(ans, distFromStart[node] + edgeWeight/2 + distFromEnd[neighbor]);


		}
	}
	cout<<ans;
}

int main(){
	ll m;	
	cin>>n>>m;
	while(m--){
		ll a,b,c;
		cin>>a>>b>>c;
		adj[a].push_back({b,c});
		revAdj[b].push_back({a,c});

	}
	for(ll i =0; i<=n; ++i){
		distFromStart[i] = 1e16;
		distFromEnd[i] = 1e16;

	}
	djikstra(adj, 1, distFromStart);
	memset(visi, 0, sizeof(visi));
	djikstra(revAdj, n, distFromEnd);
	flightDiscount();
}