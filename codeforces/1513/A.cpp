#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;cin>>T;
	while(T--){
		int n,k;cin>>n>>k;
		if(2*k>=n) puts("-1");
		else{
			int l=1,r=n;
			while(l<=n-k){
				cout<<l<<" ";
				if(r>n-k) cout<<r<<" ";
				l++,r--;
			}
			puts("");
		}
	}
	return 0;
}
