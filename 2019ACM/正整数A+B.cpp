#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    char num1[10000], num2[10000];
	char jl1, jl2;
	jl1 = jl2 = 0;
	scanf("%s ", num1);
	gets(num2);
	int t1, t2;
	t1 = t2 = 0;
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	if(len1 > 4) jl1 = '?';
	if(len2 > 4) jl2 = '?';
	for(int i = 0; num1[i] != '\0' && jl1 != '?'; i++) {
		if(num1[i] < '0' || num2[i] > '9') {
			jl1 = '?';
		}
	}
	for(int i = 0; num2[i] != '\0' && jl2 != '?'; i++) {
		if(num2[i] < '0' || num2[i] > '9') {
			jl2 = '?';
		}
	}
	if(jl1 != '?') {
		sscanf(num1, "%d", &t1);
		if(t1 > 1000 || t1 < 1) jl1 = '?';
	}
	if(jl2 != '?') {
		sscanf(num2, "%d", &t2);
		if(t2 > 1000 || t2 < 1) jl2 = '?';
	}
	if(jl1 != '?') printf("%d", t1);
	else printf("?");
	printf(" + ");
	if(jl2 != '?') printf("%d", t2);
	else printf("?");
	printf(" = ");
	if(jl1 == '?' || jl2 == '?') printf("?\n");
	else printf("%d\n", t1+t2);
	return 0;
}
