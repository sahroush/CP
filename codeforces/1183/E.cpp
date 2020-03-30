#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b, ll md = mod) {
    ll res = 1;while(b){if(b&1){res=(a*res)%mod;}a=(a*a)%mod;b>>=1;}return(res);
}

int ans=0;
int n , k;
string s;
queue < string > q;
set < string > st;

int main(){
    cin >> n >> k;
    cin >> s;
    q.push(s);
    st.insert(s);
    k--;
    while(!q.empty() and k){
        auto v = q.front();
        q.pop();
        for (int i = 0 ; i < v.size() ; i ++){
            string nw = "";
            for (int j = 0 ; j < v.size() ; j ++){
                if(j!=i){
                    nw+=v[j];
                }
            }
            if(!st.count(nw)){
                st.insert(nw);
                ans += n - nw.size();
                k--;
                q.push(nw);
            }
            if(k == 0){
                break;
            }
        }
        if(k == 0){
            break;
        }
    }
    if(k){
        dokme(-1);
    }
    cout << ans;
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
