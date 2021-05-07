// djikstra - modified question
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n;
vector<pair<ll, ll>> adj[100000+10];
ll visited[100000+10]={0};
ll minDistance[100000+10];
ll noOfMinDistancePath[100000+10];
ll minNoOfFlights[100000+10];
ll maxNoOfFlights[100000+10];
ll mod = 1000000007;
void djikstra(){
	set<pair<ll, ll>> s; // pair of distance and node
	s.insert({0,1});
	minDistance[1] = 0;
	noOfMinDistancePath[1] = 1;
	minNoOfFlights[1] = 0;
	maxNoOfFlights[1] = 0;

	while(!s.empty()){
		ll dist, node;
		tie(dist,node) = *(s.begin());
		visited[node] = 1;
		s.erase(s.begin());
		for(auto x : adj[node]){
			ll neighborNode = x.first;
			ll weight = x.second;
			
			if(visited[neighborNode]==1){
				if(minDistance[neighborNode] == minDistance[node] + weight){
					noOfMinDistancePath[neighborNode] += noOfMinDistancePath[node];
					noOfMinDistancePath[neighborNode] %= mod;

					minNoOfFlights[neighborNode] = min(1 + minNoOfFlights[node], minNoOfFlights[neighborNode]);
					maxNoOfFlights[neighborNode] = max(1 + maxNoOfFlights[node], maxNoOfFlights[neighborNode]);
				}
				continue;
			}
			s.erase({minDistance[neighborNode], neighborNode});

			if(minDistance[neighborNode] > minDistance[node] + weight){
				minDistance[neighborNode] = minDistance[node] + weight;
				noOfMinDistancePath[neighborNode] = noOfMinDistancePath[node];
				minNoOfFlights[neighborNode] = 1 + minNoOfFlights[node];
				maxNoOfFlights[neighborNode] = 1 + maxNoOfFlights[node];
			}
			else if(minDistance[neighborNode] == minDistance[node] + weight){
				noOfMinDistancePath[neighborNode] += noOfMinDistancePath[node];
					noOfMinDistancePath[neighborNode] %= mod;

				minNoOfFlights[neighborNode] = min(1 + minNoOfFlights[node], minNoOfFlights[neighborNode]);
				maxNoOfFlights[neighborNode] = max(1 + maxNoOfFlights[node], maxNoOfFlights[neighborNode]);
			}
			
			s.insert({minDistance[neighborNode], neighborNode});

		}
	}
}

signed main(){
	ll m;
	cin>>n>>m;
	while(m--){
		ll a,b,c;
		cin>>a>>b>>c;
		adj[a].push_back({b,c});
	}

	for(ll i=1; i<=n; ++i){
		minDistance[i] = 1e15;
		noOfMinDistancePath[i]=0;
		minNoOfFlights[i]=1e15;
		maxNoOfFlights[i]=-1;
	}

	djikstra();

	cout<<minDistance[n]<<" ";
	cout<<noOfMinDistancePath[n]<<" ";
	cout<<minNoOfFlights[n]<<" ";
	cout<<maxNoOfFlights[n];



}