#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll maxn = 2100;
const ll ZERO = 0;
const ld SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

int q , n;

bool cmp(char a , char b){
    return(a < b);
}

int main (){
    migmig
    cin >> q;
    while (q--){
        string s;
        cin >> s;
        n = s.size();
        bool f = 1;
        sort(s.begin() , s.end() , cmp);
        //cout << s;
        if (  (int)s[0]!=(int)s[1]+1  and (int)s[0]!=(char)s[1]-1 and n > 1){
            f = 0;
            //cout << 2;
        }
        if (  (int)s[n-1]!=(int)s[n-2]+1  and (int)s[n-1]!=(char)s[n-2]-1 and n > 1){
            f = 0;
        }

        for (int i =1 ; i < n-1 ; i ++ ){
            if ((int)s[i]!=(int)s[i-1]+1 and (int)s[i]!=(int)s[i+1]+1 or (int)s[i]!=(int)s[i-1]-1 and (int)s[i]!=(char)s[i+1]-1){
                f = 0;
                break;
            }
        }
        int cnt[30];
        fill(cnt , cnt+28 , 0);
        for (int i =0 ; i  < n ; i ++){
            cnt[(int)s[i]-'a']++;
            if (cnt[(int)s[i]-'a'] > 1){
                f = 0;
                //cout << (int)s[i]-'a' << endl;
                break;
            }
        }
        if(f){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
        cout << endl;
    }


    return(0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
