#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

const ll maxn =2e6;
const ld SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define mkp make_pair
#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define random_init mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define ms(x , y) memset(x , y , sizeof x);
#define prnt(x)  for(int i = 0 ; i < x.size() ; i ++) cout << x[i] << ' ';
template<class T>bool checkmin(T &a,T b){return a > b ? a = b, 1 : 0;}
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

int q , r , c;
string s[maxn];

int main(){
    migmig
    cin >> q;
    while (q --){
        cin >> r >> c;
        bool f = 0;
        bool fft = 0;
        for (int i = 0;  i < r ; i ++){
            cin >> s[i];
            for (int j = 0 ; j < c ; j ++){
                if(s[i] [j] == 'A'){
                    f = 1;
                }
                else{
                    fft = 1;
                }
            }
        }
        if(!fft){
            cout << 0 << endl;
            continue;
        }
        if(!f){
            cout << "MORTAL" << endl;continue;
        }
        bool ff = 0;
        for (int i = 0 ; i < c ; i ++){
            if(s[0][i] == 'P'){
                ff = 1;
                break;
            }
        }
        if(!ff){
            cout << "1" << endl ; continue;
        }
        ff = 0;
        for (int i = 0 ; i < c ; i ++){
            if(s[r - 1][i] == 'P'){
                ff = 1;
                break;
            }
        }
        if(!ff){
            cout << "1" << endl ; continue;
        }

        ff = 0;
        for (int i = 0 ; i < r ; i ++){
            if(s[i][0] == 'P'){
                ff = 1;
                break;
            }
        }
        if(!ff){
            cout << "1" << endl ; continue;
        }
        ff = 0;
        for (int i = 0 ; i < r ; i ++){
            if(s[i][c  - 1] == 'P'){
                ff = 1;
                break;
            }
        }
        if(!ff){
            cout << "1" << endl ; continue;
        }


        int ans = 4;
        for (int i = 0 ; i < r ; i ++){
            bool p = 1;

            for (int j = 0;  j < c ; j ++){
                if(s[i][j] == 'P'){
                    p = 0;
                    break;
                }
            }
            if(p == 1){
                ans = 2;
                break;
            }
        }
        if(ans == 2){
            cout << ans << endl;
            continue;
        }
        for (int i = 0 ; i < c ; i ++){
            bool p = 1;

            for (int j = 0;  j < r ; j ++){
                if(s[j][i] == 'P'){
                    p = 0;
                    break;
                }
            }
            if(p == 1){
                ans = 2;
                break;
            }
        }
        if(ans == 2){
            cout << ans << endl;
            continue;
        }
        if(s[0][0] == 'A' or s[r - 1][0] == 'A' or s[0][c - 1] == 'A' or s[r- 1][c - 1] == 'A'){
            cout << 2 << endl;
            continue;
        }

        ans = 4;

        ff = 1;
        for (int i = 0 ; i < c ; i ++){
            if(s[0][i] == 'A'){
                ff = 0;
                break;
            }
        }
        if(!ff){
            cout << "3" << endl ; continue;
        }
        ff = 1;
        for (int i = 0 ; i < c ; i ++){
            if(s[r - 1][i] == 'A'){
                ff = 0;
                break;
            }
        }
        if(!ff){
            cout << "3" << endl ; continue;
        }

        ff = 1;
        for (int i = 0 ; i < r ; i ++){
            if(s[i][0] == 'A'){
                ff = 0;
                break;
            }
        }
        if(!ff){
            cout << "3" << endl ; continue;
        }
        ff =1;
        for (int i = 0 ; i < r ; i ++){
            if(s[i][c  - 1] == 'A'){
                ff =0;
                break;
            }
        }
        if(!ff){
            cout << "3" << endl ; continue;
        }

        cout << 4 << endl;

    }




    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.