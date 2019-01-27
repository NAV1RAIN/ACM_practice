#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

set<string> ss;
int main(int argc, const char *argv[])
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
	ss.clear();
    int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);
		string temp;
		for(int j = 0; j < k; j++) {
			cin >> temp;
			if(k != 1) ss.insert(temp);  
		}
	}
	bool flag = true;
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++) {
		string temp;
		cin >> temp;
		if(!ss.count(temp) && flag) {
			flag = false;
			cout << temp;
			ss.insert(temp);
		} else if(!ss.count(temp) && !flag) {
			cout << " " << temp;
			ss.insert(temp);
		}
	}
	if(flag) cout << "No one is handsome" << endl;
    return 0;
}
