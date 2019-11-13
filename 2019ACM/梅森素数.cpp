#include <bits/stdc++.h>
using namespace std;
bool isflag[100005];
vector<int> arr;
int main() {
    int n;
    for(int i = 2; i < 100000; i++) {
        bool flag = true;
        for(int j = 2; j <= sqrt(i) && flag; j++) {
            if(i%j == 0) flag = false;
        }
        if(flag) {
            arr.push_back(i);
            isflag[i] = true;
        }
    }
    
    return 0;
}

//m+1为2的阶乘
//2 3 5 7 11
//3 7 31