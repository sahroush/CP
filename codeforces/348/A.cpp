#include <bits/stdc++.h>
#include<iostream>
#include<cmath>

using namespace std;
typedef long long ll;
const ll MAX1 = 1e5+10;


#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);




int main(){
	ll n;
	ll inp;
	cin >> n;
	ll l[n];
	bool f=0;
	for (int i=0;i<n;i++){
		cin >> inp;
		l[i]=inp;
		if (i>0){
			if (l[i]!=l[i-1]){
				f=1;
			}
		}
	}
	ll cnt=0;
	sort(l,l+n);
	for (int i=0 ;i < n;i++){
		cnt+=l[i];
		//cout << l[i] << endl;
	}

	ll a=cnt/(n-1);
	if (a*(n-1)!=cnt){
		a++;
	}
	//cout << a;
	cout << max(l[n-1],a) ;
	
	return(0);
}

/*
7
9 7 7 8 8 7 8
*/
