#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	ll n;cin>>n;
	n *= 9;
	n += 1;
	double x = log10(n);
	int y = (int)x;
	double d = x-y;
	cout<<x<<" "<<y<<" "<<d<<endl;
	if(x - ((int)x) == 0){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}

}
int main(){
	int t;cin>>t;
	while(t--){
		solve();
	}
}