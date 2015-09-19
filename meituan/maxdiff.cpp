#include<stdio.h>
#include<stdlib.h>
#include<string.h>




int findMaxDifference(int *arr, int len) {
	int *diff = (int *)malloc(sizeof(int)*len);
	int i,maxdiff,cdiff;
	diff[0]=0;
	for(i=1;i<len;i++){
		diff[i] = arr[i]-arr[i-1];
	}
	maxdiff = 0;
	cdiff = 0;
	for(i=1;i<len;i++){
		if(diff[i]>=0){
			cdiff+=diff[i];
			maxdiff = (maxdiff<cdiff)? cdiff:maxdiff;
		}else{
			cdiff=0;
		}
	}
	return maxdiff;
}


int main(){
	int a[10]={7,5,10};
	printf("%d\n", findMaxDifference(a,3));
	getchar();
}

