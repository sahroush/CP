#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll maxn = 1e5+10;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);




int main(){
    migmig;
    ll n;
	cin>>n;
	ll a[n];
	ld k;
	ll plus=0;
	for (int i = 0 ;i < n; i ++){
		cin>>a[i];
		k=ld(a[i])/2.0;
		a[i]=ll(a[i]/2);
		if(a[i]-0.5==k && a[i]<=0)
		{
			plus++;
			if(plus%2)
			a[i]--;			
		}
		else if(a[i]+0.5==k && a[i]>=0)
		{
			plus++;
			if(plus%2==0)
			a[i]++;			
		}

		cout<<a[i]<<"\n";
	}
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.