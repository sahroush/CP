#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const ll maxn = 1e4+100;
const ll ZERO = 0;
const ld SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define endl '\n'
#define push_back pb
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

int n , q ,a[maxn];

bool chk(int x){
    int cnt = 0;
    for (int i =0 ; i < n ; i++){
        if (a[i] >= x){
            cnt++;
        }
        else{
            break;
        }
    }
    return(cnt >= x );
}


int main (){
    migmig
    cin >> q;
    while (q -- ){
        char s[maxn] , t[maxn];
        bool f = 0;
        cin >> n >> s >> t;
        int cnt[30];
        fill (cnt , cnt + 27 , 0);
        for (int i = 0 ; i < n ; i ++){
            cnt [s[i] - 'a']++;
            cnt [t[i] - 'a']++;
        }
        for (int i =0 ; i < 26 ; i ++){
            if (cnt[i]%2 == 1){
                cout << "NO" << endl;
                f = 1;
                break;
            }
        }
        int wtf = 0;
        string a = "", b = "";
        for (int i = 0; i < n ; i ++){
            if (s[i]!=t[i]){
                a+=s[i];
                b+=t[i];
                wtf++;
            }
        }
        if (wtf == 0){
            cout << "YES" << endl;
            f = 1;
        }
        if (wtf > 4 and !f){
            f = 1;
            cout << "NO" << endl;
        }
        string ap = a , bp = b;
        if(!f){
        for (int i = 0 ; i < wtf ; i ++){
            for (int j = 0 ; j < wtf ; j ++){
                swap(a[i] , b[j]);
                if (a == b){
                    if (!f){
                        f = 1;
                        cout << "YES " << endl;
                    }
                }
                a = ap;
                b = bp;
            }
        }
        }
        if (!f){
            cout << "NO" << endl;
        }



    }



    return(0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.