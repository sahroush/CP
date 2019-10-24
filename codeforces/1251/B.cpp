#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll maxn = 1e4+10;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

int q , n ;
int zero[60] , one[60];
string bin[60];

bool chk(int a , int b){
    if ((a+b)%2){
        return(1);
    }
    else{
        if (a%2 or b%2){
            return(0);
        }
    }
    return(1);
}

bool  val(int a , int b , int c , int d){
    if (a < 0 or b < 0 or c < 0 or d < 0){
        return(0);
    }
    //cout << a << '\t' << c << '\t' << b  << '\t' << d << endl;
    if (chk(a , c) and chk(b , d)){
        //cout << 2;
        return(1);
    }
    return(0);

}



bool ans(int i){

    if (bin[i].size()%2){
        return(1);
    }
    else{
        //cout << one[i] <<'\t' << zero[i] << endl;
        if (one[i]%2 and zero[i]%2){
            return(0);
        }
    }

    return(1);
}


bool cmp(int i , int j){
    if(bin[i].size() > bin[j].size() ){
        swap(bin[i] , bin[j]);
        swap(one[i] , one[j]);
        swap(zero[i] , zero[j]);
        return(1);
    }
    return(0);
}

int main(){
    migmig;
    //dokme(chk(4 , 0));
    cin >> q;
    while (q--){
        cin >> n;

        int srtlist[n+10];
        for (int i = 0 ; i < n ; i  ++){
            cin >> bin[i];
            srtlist[i] = i;
        }
        int cnt1 = 0 , cnt0 = 0;
        fill(zero , zero+n+5 , 0);
        fill(one , one+n+5 , 0);
        for (int i = 0; i < n ; i ++){
            for (int j = 0 ; j < bin[i].size() ; j ++){
                if (bin[i][j] == '1'){
                    one[i]++;
                    cnt1++;
                }
                else{
                    zero[i]++;
                    cnt0++;
                }
            }
        }
        sort(srtlist , srtlist + n , cmp);
        int cnt = 0;
        for (int i = 0 ; i <  n ; i ++){
            for (int j = 0 ; j < n ; j ++){
                if (i!=j){
                    if (val(one[i]+1 , one[j]-1 , zero[i]-1 , zero[j]+1) ){
                        one[i]++;
                        one[j]--;
                        zero[j]++;
                        zero[i]--;

                    }
                    else if(val(one[i]-1 , one[j]+1 , zero[i]+1 , zero[j]-1) ){
                        zero[i]++;
                        zero[j]--;
                        one[j]++;
                        one[i]--;

                    }
                }

            }
        }
        for (int i = 0 ; i < n ; i ++){
            if (ans(i)){
                cnt++;
            }
        }
        cout << cnt << endl;

    }

    return(0);
}




//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
