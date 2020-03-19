#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn =3e6+1000;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dominance true
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b, ll md = mod) {
    ll res = 1;while(b){if(b&1){res=(a*res)%mod;}a=(a*a)%mod;b>>=1;}return(res);
}

int q;
string s;

bool ispol(string s){
    int l = 0 , r = s.size() - 1;
    for (int i = 0 ; i < s.size()/2; i ++){
        if(s[l] != s[r]){
            return(0);
        }
        l++,r--;
    }
    return(1);
}

vector < int > kmp(string s){
    int i = -1 ;
    vector < int > f(s.size() + 1);
    f[0] = -1;
    for (int j = 0 ; j < s.size() ; j ++){
        while(s[j]!=s[i] and i!=-1){
            i = f[i];
        }
        f[j + 1] = ++i;
    }
    return(f);
}

bool chk(int x){
    if(x > s.size()){
        return(0);
    }
    for (int i = 0 ; i <= x ; i ++){
        string pre = "" , suf = "";
        for (int j = 0 ; j < i ; j ++){
            pre+=s[j];
        }
        for (int j = 0 ; j < x - i ; j ++ ){
            suf+=s[s.size() - (x-i - 1) + j - 1];
        }
        if(ispol(pre + suf)){
            return(1);
        }
    }
    return(0);
}

int ans(string x){
    string rx = x;
    reverse(rx.begin() , rx.end());
    return(kmp(x + "^" + rx).back());
}

int main(){
    migmig
    cin >> q;

    while(q--){
        cin >> s;
        int mx = 0;
        int lst = 0;
        int goo  = 0;
        for (int i = 0 ; i <= s.size()/2 ; i ++){
            bool f = 1;
            for (int j = 0 ; j < i ; j ++){
                if(s[j]!=s[s.size()-1-j]){
                    f = 0;
                }
            }
            if(!f){
                break;
            }
            string boz = "";

            for (int j = i ; j < s.size()-i; j ++ ){
                boz+=s[j];
            }
            if( 2*i  + ans(boz) > mx){
                lst = i;
                goo = ans(boz);
            }
            mx = max(mx , 2*i  + ans(boz));
            reverse(boz.begin() , boz.end());
            if( 2*i  + ans(boz) > mx){
                lst = i;
                goo = -ans(boz);
            }
            mx = max(mx , 2*i  + ans(boz));
        }
        for(int i = 0 ; i < lst ; i ++){
            cout << s[i];
        }
        if(goo > 0){

            for (int i = 0 ; i < goo ; i++){
                cout << s[i+lst];
            }
        }
        else{
            string boz = "";
            for (int j = lst ; j < s.size()-lst; j ++ ){
                boz+=s[j];
            }
            reverse(boz.begin() , boz.end());
            for (int i = 0 ; i < -goo ; i ++){
                cout << boz[i];
            }
        }

        for(int i = lst-1 ; i >= 0 ; i--){
            cout << s[i];
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
