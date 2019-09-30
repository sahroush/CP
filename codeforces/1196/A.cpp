#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
//const ll MAX1 = 1e5+10;
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int main(){
	ll q,l[3];
	cin >>q;
	for(int i=0;i<q;i++){
		for(int j=0;j<3;j++){
			cin >> l[j];
		}
		sort(l,l+3);
		cout << (l[0]+l[1]+l[2])/2 << endl;
	}
	return(0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.