#include <bits/stdc++.h>
using namespace std;

char str[100];
int main() {
	int n;
	scanf("%d", &n);
	scanf("%s", str);
	int minn = 0x3f3f3f3f;
	for(int i = 0; i < n-3; i++) {
		int temp = 0;
		int t1 = 0, t2 = 0;
		t1 = 'Z'-str[i]+1;
		t2 = str[i]-'A';
		temp += min(t1, t2);
		if(str[i+1] > 'C') {
			t1 = 'Z'-str[i+1]+'C'-'A'+1;
			t2 = str[i+1]-'C';
		} else {
			t1 = 0x3f3f3f3f;
			t2 = 'C'-str[i+1];
		}
		temp += min(t1, t2);
		if(str[i+2] > 'T') {
			t1 = 'Z'-str[i+2]+'T'-'A'+1;
			t2 = str[i+2]-'T';
		} else {
			t1 = str[i+2]-'A'+'Z'-'T'+1;
			t2 = 'T'-str[i+2];
		}
		temp += min(t1, t2);
		if(str[i+3] > 'G') {
			t1 = 'Z'-str[i+3]+'G'-'A'+1;
			t2 = str[i+3]-'G';
		} else {
			t1 = str[i+3]-'A'+'Z'-'G'+1;
			t2 = 'G'-str[i+3];
		}
		temp += min(t1, t2);
		minn = min(temp, minn);
	}
	printf("%d\n", minn);
	return 0;
}
