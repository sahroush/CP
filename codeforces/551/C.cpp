#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 1e5+10;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

ll n , m;
ll a[maxn] , b[maxn];

bool chk(ll p){
    ll b = 0, x = 0;
	for(ll i = n; i > 0; i--){
		if(a[i] <= b){
			b -= a[i];
		}
		else{
			ll d = a[i] - b;
			if(p - i <= 0) return 0;
			if(d % (p - i)) b = p - i - d % (p - i);
			else b = 0;
			x += (d + p - i - 1) / (p - i);
		}
	}
	return (x <= m);
}

int main(){
    migmig
    cin >> n >> m;

    for (ll i =1  ; i<= n ; i ++){
        cin >> a[i];
    }
    ll l = 0 , r = 1e16;



    while (r - l > 1){
        ll mid  = (l + r)/2;
        //cout << mid << '\t' << chk(mid) << endl;
        if (chk(mid)){
            r = mid;
        }
        else{
            l = mid;
        }
    }
    cout << r;
    return(0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
