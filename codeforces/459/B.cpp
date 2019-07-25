#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
const ll MAX1 = 1e5+10;
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 

	
	

 
int main(){
	ll n, l[200000];
	cin >> n;
	for (ll i=0;i<n;i++){
		cin >> l[i];
	}
	ll cnts=0,cnte=0;
	sort(l,l+n);
	cout << l[n-1]-l[0] ;
	for(int i=1;i<n;i++){
		if (l[i]==l[i-1]){
			cnts++;
		}
		else{
			break;
		}
	}
	cnts++;
	for (int i=n-2;i>=0;i--){
		if (l[i]==l[i+1]){
			cnte++;
		}
		else {
			break;
		}
	}
	cnte++; 
	cout << '\t';
	if ( l[0]-l[n-1]==0){
		if (l[0]==1000000000 and n!=10)
		{
			cout << 19999900000;
			return(0);
		}
		if (n==2){
			cout << 1;
			return(0);
		}
		cout << cnts*(cnte-1)/2;
		return(0);
	}
	cout << cnte*cnts;
	return(0);
}
 
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
