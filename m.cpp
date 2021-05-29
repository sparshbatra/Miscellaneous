#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	int n;cin>>n;
	int a[n];
	for(int i=0; i<n; ++i){
		cin>>a[i];
	}	
	sort(a, a+n);
	int ans=0;
	for(int i=0; i<n; ++i){
		int element = a[i];
		for(int j=element; j<=a[n-1]; j+=element){
			int l = j;
			int r = j+element-1;

			int leftIndex = lower_bound(a, a+n, l) - a; 
			// if(a[leftIndex]/i == )
			int rightIndex = upper_bound(a, a+n, r) - a;
			rightIndex--;


			ans += (rightIndex-leftIndex+1)*(j/element);
		}
	}
	cout<<ans;
}