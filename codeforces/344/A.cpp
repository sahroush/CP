#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
//const ll MAX1 = 1e5+10;
 
ll trl( ll q){
	ll r=0;
    while (q >= 5) {
        r += q / 5;
        q /= 5;
    }
	return(r) ;
}
 
int main(){
	int n,cnt=1;
	string s,p;
	cin >> n;
	for (int i=0;i<n;i++){
		cin >> s;
		if (i>0 and p!=s){
			cnt++;
		}
		p=s;
	}
	cout << cnt;
	return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
