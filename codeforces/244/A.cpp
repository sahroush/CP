#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll maxn = 1e6+100;
const ll ZERO = 0;
const ld SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

bool f[maxn];
vector <int> vec [maxn];

int main (){
    migmig
    int n , k ;
    int a[40];
    cin >> n;
    cin >> k;
    for (int i = 0 ; i < k ; i ++){
        cin >> a[i];
        vec[i].push_back(a[i]);
        f[a[i]]  = 1;
    }
    int cnt = 0;

    for (int i =1 ; i <= n*k ; i ++){
        while (vec[cnt].size()== n){
            cnt++;
        }
        if (!f[i]){
            f[i]= 1;
            vec[cnt].push_back(i);
        }
    }
    for (int i = 0; i < k ; i ++){
        for (int j = 0 ; j < n ;  j ++){
            cout << vec[i][j] << ' ';
        }
        cout << endl;
    }


    return(0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
