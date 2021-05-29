#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll mod = 1000000000+7;
vector<ll> previousSamllerCalculate(std::vector<ll> a){
	vector<ll> ans(n);
	stack<ll> s;
	for(ll i=0; i<n; ++i){
		while(!s.empty() && a[s.top()]>=a[i]){
			s.pop();
		}
		if(s.empty()){
			ans[i] = -1;
		}
		else{
			ans[i] = s.top();
		}
		s.push(i);

	}
	
	return ans;
}
vector<ll> nextSmallerCalculate(std::vector<ll> a){
	std::vector<ll> ans;
	reverse(a.begin(), a.end());
	ans = previousSamllerCalculate(a);
	reverse(ans.begin(), ans.end());
	
	for(ll i=0; i<n; ++i){
		ans[i] = n-1-ans[i];
	}
	
	return ans;

}
int main(){
	
	cin>>n;
	std::vector<ll> a;
	for(ll i=0; i<n; ++i){
		ll x;cin>>x;
		a.push_back(x);
	}	
	std::vector<ll> previousSamller, nextSmaller;
	previousSamller = previousSamllerCalculate(a);
	nextSmaller = nextSmallerCalculate(a);

	ll ans = 0;
	ll prefixSum[n];
	prefixSum[0] = a[0];
	for(ll i=1; i<n; ++i){
		prefixSum[i] = prefixSum[i-1] + a[i];
	}
	for(ll i=0; i<n; ++i){
		ll x = nextSmaller[i]-1;
		ll y = previousSamller[i]+1;
		
		ans= max(ans, (a[i]*(prefixSum[x]-(y==0?0:prefixSum[y-1]))));
	}
	cout<<ans%mod;

}