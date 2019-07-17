#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
using namespace std;

typedef long long ll;
const ll MAX1 = 1e5+10;






int main(){
	//std::ios_base::sync_with_stdio (false);
  	//cin.tie(0);
	ll n,m,a;
	cin >> n>>m>>a;
	n+=a-1;
	m+=a-1;
	n=n/a;
	m=m/a;
	cout<< n*m;
	return(0);

}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
