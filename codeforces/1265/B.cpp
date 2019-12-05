#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

const ll maxn =10e5+10;
const ld SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define random_init mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T>bool checkmin(T &a,T b){return a > b ? a = b, 1 : 0;}
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

int q;
set <int> st;
int n , a[maxn];

int main(){
    migmig
    cin >> q;
    while(q-- ){
        cin >> n;
        int pos = 1;
        for (int i = 0 ; i < n;  i ++){
            cin >> a[i];
            if(a[i] == 1){
                pos = i;
            }
        }
        int l = max(pos - 1 , 0) , r = min(pos+1 , n - 1);
        //st.clear();
        //st.insert(1);
        bool ans[maxn];
        a[pos] = 5e5;
        ans[1] = 1;
        int mx = 1;
        for (int i = 0 ; i < n - 1 ; i ++){
            if(a[l] < a[r]){
                //st.insert(a[l]);
                mx = max(mx , a[l]);
                a[l] = 5e5;
                l --;

            }
            else{
                //st.insert(a[r]);
                mx = max(mx , a[r]);
                a[r] = 5e5;
                r++;

            }
            r = min(n - 1 , r);
            l = max(l , 0);
            if(mx == i + 2){
                ans[i + 2] = 1;
            }
            else{
                ans[i+2] = 0;
            }
        }
        for (int i = 0 ; i < n ; i ++){
            cout << ans[i+1];
        }
        cout << endl;
    }



    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
