#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 5e4+10;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

int n , q;

int main(){
    migmig
    cin >> q;
    for (int i = 0 ; i < q; i ++){
        cin >> n;
        int ans = 0;
        if (n%2 == 1){
            ans++;
            n++;
        }
        if (n / 2 == 1){
            ans += 2;
        }
        cout << ans << endl;
    }


    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.