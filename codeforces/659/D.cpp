#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
const ll MAones = 1e5+10;
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll n;
ll x[20000];
ll y[20000];


int main(){
	cin >> n;
	for (int i=0;i<n+1;i++){
		cin >> x[i];
		cin >> y[i];
	}
	int cnt=0;
	for (int i=0;i<n-1;i++){
		if (y[i+1] < y[i] and (x[i+2] > x[i+1])){
			cnt++;
		}
		else if (x[i+1] > x[i] and (y[i+2] > y[i+1])){
			cnt++;
		}
		else if (y[i+1] > y[i] and (x[i+2] < x[i+1])){
			cnt++;
		}
		else if (x[i+1] < x[i] and (y[i+2] < y[i+1])){
			cnt++;
		}
	}

	cout << cnt;
	return(0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
