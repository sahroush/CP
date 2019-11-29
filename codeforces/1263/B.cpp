#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int ,int > pii;

const ll maxn =3e5+10;
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

ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

int t;

int main(){
    migmig
    cin >> t;
    while (t -- ){
        int n ;
        cin >> n;
        char s[100][14];
        for (int i = 0 ; i < n; i ++){
            cin >> s[i];
        }
        int cnt = 0;
        set <char> s1 , s2 , s3 , s4;
        s1.clear();
        for (int i =0 ; i < n ; i ++){
            s1.insert(s[i][0]);
        }
        set<string> st;
        char chr[10] ={'0' , '1' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9'};
        for (int i = 0 ; i < n ; i ++){
            if(st.count(s[i]) == 1){
                cnt++;
                for (int j = 0 ; j < 10 ; j ++){
                    if(s1.count(chr[j]) == 0){
                        s[i][0] = chr[j];
                        s1.insert(chr[j]);
                        break;
                    }
                }
            }
            st.insert(s[i]);
        }
        cout << cnt << endl;
        for (int i = 0; i < n ; i ++ ){
            cout << s[i] << endl;;
        }
    }


    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
