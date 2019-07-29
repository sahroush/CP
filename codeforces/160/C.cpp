#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
const ll MAX1 = 1e5+10;
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
ll n,k;
ll l[100000],m[100000] ,r=-1,s=0;
int main(){
	cin  >> n >> k;
	for (int i=0;i<n;i++){
		cin >> l[i];
		m[i]=l[i];
	}
	sort(m,m+n);
	ll p=(k-1)/n;
	cout << m[p] << '\t';
	for (int i=0; i<n; i++) {
		if (m[i]==m[(k-1)/n]) {
			if (r==-1){
				r=i;
			} 
			s++;
		}
	}
	ll q=(k-n*r)/(s+0.0)-1+0.99;
	cout<<m[q];
	return(0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
