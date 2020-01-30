#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =8e5+5;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

int n;
int a[maxn] , cnt[maxn];
set <int> st;

bool solve(int x){
    auto it = st.lower_bound(x);
    if(it == st.end()){
        return(1);
    }
    ++it;
    if(it!=st.end()){
        return(0);
    }
    --it;
    cnt[*it]++;
    return(0);
}

int main(){
    migmig
    cin >> n;
    for (int i = 1 ; i <= n ; i ++){
        cin >> a[i];
        if(solve(a[i])){
            cnt[a[i]] --;
        }
        st.insert(a[i]);
    }
    //cnt[n + 1] = -10000;
    int mx =-1  , tof = 1;

    for (int i = 1 ; i <= n ; i ++){
        //cout << cnt[i] << endl;
        if(cnt[i] > mx){
            mx = cnt[i ];
            tof = i ;
        }
    }
    cout << tof;


    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
