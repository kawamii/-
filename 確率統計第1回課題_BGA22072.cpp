#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include<math.h>
#include <vector>

using namespace std;

double koryu(double x){
    return 141*sin(x);
}

int main() {
    vector<double> ans(10000);
    for(int i=0;i<10000;i++){
        double x = (double(rand())/double(32767))*2*M_PI;
        ans[i] = koryu(x);
    }

    for(int i=0;i<10000;i++){
        cout<<ans[i]<<", ";
    }
    return 0;
}