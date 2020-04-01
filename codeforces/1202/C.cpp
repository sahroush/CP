#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e5;
const ll mod =998244353;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b, ll md = mod) {
    ll res = 1;while(b){if(b&1){res=(a*res)%mod;}a=(a*a)%mod;b>>=1;}return(res);
}

int q;
string s;

int main(){
    migmig
    cin >> q;
    while(q -- ){
        cin >> s;
        int n = s.size();
        int x = 0 , y = 0;
        int mxx = 0 , mnx = 0,mxy = 0 , mny =0;
        int mxl = 0 , mxr = 0 , mxd = 0 , mxu = 0;
        for(int i = 0 ; i < n ; i ++){
            if(s[i] == 'W'){
                y++;
            }
            else if(s[i] == 'S'){
                y--;
            }
            else if(s[i] == 'D'){
                x++;
            }
            else{
                x--;
            }
            mxx = max(mxx , x);
            mnx = min(mnx , x);
            mxy = max(mxy , y);
            mny = min(mny , y);
            mxu = max(mxu , y - mny);
            mxd = max(mxd , mxy - y);
            mxl = max(mxl , mxx - x);
            mxr = max(mxr , x - mnx);
        }
        cout << min((ll)(max(mxl , mxr)+1) * (1+(ll)(max((int)((mxu + mxd)!=0), max(mxu , mxd) - (int)(mxu!=mxd)))) , (1+(ll)max(mxu , mxd)) * (1+(ll)(max((int)((mxl + mxr)!=0), max(mxl , mxr) - (int)(mxl!=mxr))))) << endl;
    }

    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
