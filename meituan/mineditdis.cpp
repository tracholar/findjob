#include<stdio.h>
#include<stdlib.h>
#include<string.h>



int edit_dist(char *src, char *dst, int n, int m){
	if(n==0 && m==0) return 0;
	if(n==0) return m;
	if(m==0) return n;

	int d1,d2,d3;
	if(src[n-1]==dst[m-1]) d1=edit_dist(src,dst,n-1,m-1);
	else d1=edit_dist(src,dst,n-1,m-1)+1;

	d2 = edit_dist(src,dst,n-1,m)+1;
	d3 = edit_dist(src,dst,n,m-1)+1;
	
	if(d2<d1) d1=d2;
	if(d3<d1) d1=d3;
	return d1;

}
int edit_distance(char *src, char *dst) {
	int n=strlen(src), m = strlen(dst);
	return edit_dist(src, dst,n, m);
}

int main(){
	char *p="abce", *q="ac";
	printf("%d\n", edit_distance(p,q));
	getchar();
}