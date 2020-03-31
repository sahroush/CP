#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e5;
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

int a[maxn];
int ans[maxn];
int q;
int n;
int num[maxn];


int main(){
    migmig
    cin >> q;
    while(q -- ){
        cin >> n;
        set < int > st;
        st.clear();
        for(int i = 0 ; i < n ; i ++){
            cin >> a[i];
            if(a[i]%2==0){
                ans[i] = 2;
                st.insert(2);
            }
            else if(a[i]%3==0){
                ans[i] = 3;
                st.insert(3);
            }
            else if(a[i]%5==0){
                ans[i] = 5;
                st.insert(5);
            }
            else if(a[i]%7==0){
                ans[i] = 7;
                st.insert(7);
            }
            else if(a[i]%11==0){
                ans[i] = 11;
                st.insert(11);
            }
            else if(a[i]%13==0){
                ans[i] = 13;
                st.insert(13);
            }
            else if(a[i]%17==0){
                ans[i] = 17;
                st.insert(17);
            }
            else if(a[i]%19==0){
                ans[i] = 19;
                st.insert(19);
            }
            else if(a[i]%23==0){
                ans[i] = 23;
                st.insert(23);
            }
            else if(a[i]%29==0){
                ans[i] = 29;
                st.insert(29);
            }
            else if(a[i]%31==0){
                ans[i] = 31;
                st.insert(31);
            }
        }
        int cnt = 1;
        for(int i : st){
            num[i] = cnt++;
        }
        cout << st.size() << endl;
        for(int i = 0 ; i < n ; i ++){
            cout << num[ans[i]] << ' ';
        }
        cout << endl;
    }





    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
