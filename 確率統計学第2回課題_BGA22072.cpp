#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=((int)(n)-1);i>=0;i--)
#define rreps(i,n) for(int i=((int)(n));i>0;i--)
#define rep2(i,s,n) for(int i=(s);i<(int)(n);i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
template<class T> bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}
template<class T> bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
const ll INF = 1LL << 60;
 
int main(){
    vector<vector<double>> hyou(6,vector<double>(6, 0.0));

    rep(i,6){//X_1
        rep(j,6){//X_2
        int X, Y;
            if(i>=j){
                X=i;
                Y=j;
            } else {
                X=j;
                Y=i;
            }
            hyou[Y][X] += 1.0;
        }
    }

    rep(i,6){
        rep(j,6){
            hyou[i][j] /= 36.0;
        }
    }

    vector<double> x_syuhen(6);
    vector<double> y_syuhen(6);

    //周辺確率
    rep(i,6){
        double sum=0.0;
        rep(j,6){
            sum += hyou[j][i];
        }
        x_syuhen[i] = sum;
        cout<<"P_x("<<i+1<<") = "<<x_syuhen[i]<<endl;
    }

    rep(i,6){
        double sum=0.0;
        rep(j,6){
            sum += hyou[i][j];
        }
        y_syuhen[i] = sum;
        cout<<"P_y("<<i+1<<") = "<<y_syuhen[i]<<endl;
    }

    //期待値
    double e_x = 0.0;
    double e_y = 0.0;

    rep(i,6){
        e_x += x_syuhen[i]*(i+1);
        e_y += y_syuhen[i]*(i+1);
    }
    cout<<"Xの期待値: "<<e_x<<endl;
    cout<<"Yの期待値: "<<e_y<<endl;

    //分散
    double v_x = 0.0;
    double v_y = 0.0; 

    rep(i,6){
        v_x += ((i+1)-e_x)*((i+1)-e_x)*x_syuhen[i];
        v_y += ((i+1)-e_y)*((i+1)-e_y)*y_syuhen[i];
    }

    cout<<"Xの分散: "<<v_x<<endl;
    cout<<"Yの分散: "<<v_y<<endl;

    //期待値xy
    double e_xy = 0.0;
    rep(i,6){
        rep(j,6){
            e_xy += (i+1)*(j+1)*hyou[i][j];
        }
    }

    cout<<"XYの期待値: "<<e_xy<<endl;

    //共分散
    double cov_xy = e_xy - e_x*e_y;
    cout<<"共分散: "<<cov_xy<<endl;

    //相関係数
    double soukankeisu = cov_xy/(sqrt(v_x)*sqrt(v_y));
    cout<<"相関係数: "<<soukankeisu<<endl;
    
    return 0;
}