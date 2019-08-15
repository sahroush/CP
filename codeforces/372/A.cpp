#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX = 5e5+10;
const ll ZERO = 0; 
const ll SADAT = 7.84e-17;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 

 
ll n;
ll l[MAX]; 
int main(){
	cin >> n;
	for (int i = 0; i < n ;i ++)	cin >> l[i];
	sort(l,l+n);
	int k=n-1,m= 0;
	for (int i = k - 1; i >= 0; i--){
		if (l[k] >= l[i] * 2) m++, k--;
	}
	if (n % 2){
		if (m > n / 2) cout << (n / 2 + 1) << endl;
		else cout << (n - m) << endl;
	}
	else{
		if (m > n / 2) cout << (n / 2) << endl;
		else cout << (n - m) << endl;
	}
	return(0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
