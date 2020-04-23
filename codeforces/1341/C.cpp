#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int q;
int n;
int p[maxn];
int cnt[maxn];
int pos[maxn];
set < int > st;


int main(){
    migmig
    cin >> q;
    while(q -- ){
        cin >> n;
        st.clear();
        for(int i = 1 ; i <= n ; i ++){
            cnt[i] = 0;
            st.insert(i);
        }
        bool oke = 1;
        for(int i = 1 ; i <= n;  i ++){
            cin >> p[i];
            if(cnt[p[i]]){
                oke = 0;
            }
            else{
                cnt[p[i]] = 1;
            }
            pos[p[i]] = i;
        }
        int past = pos[1];
        for(int i = 2 ; i <= n ; i ++){
            st.erase(past);
            if(*st.rbegin() < past){
                past = pos[i];
            }
            else{
                if(pos[i]!=past+1){
                    oke = 0;
                    break;
                }
                past = pos[i];
            }
        }

        
        cout << ((oke)?"Yes" : "No") << endl;
    }

    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
