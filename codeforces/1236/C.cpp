#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 510;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

ll a[maxn][maxn];
int main(){
    migmig
    ll n;
    ll x = 1;
    cin >> n;
    int tmp = 0;
    for (int i = 0 ; i < n/2 ; i ++){
        for (int j = 0 ; j < n ; j++){

            a[j][i] = x++;

        }
    }
    for (int i = n/2 ; i < n ; i ++){
        for (int j = n-1 ; j > -1 ; j--){
            a[j][i] = x++;
        }
    }
    for (int i =0 ; i < n ; i ++){
        for (int j = 0 ; j < n ; j  ++){
            cout << a[i][j] << ' ' ;
        }
        cout << endl;
    }



    return(0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
