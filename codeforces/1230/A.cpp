#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 1e3+1;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e10;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

int n;

int main(){
    ll a[4];
    for (int i = 0 ; i < 4 ; i ++){
        cin >> a[i];
    }
    sort(a , a+4);

    if (a[0] + a[3] == a[1] + a[2]){
        dokme("YES")
    }
    if (a[0]+a[1] +a[2]  == a[3]){
        dokme("Yes")
    }
    dokme("NO")

    return(0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, l is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
