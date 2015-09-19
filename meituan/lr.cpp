#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float J(int n, int d, float *X, int *y, float lam, float *wb){
	float loss=0.0f,py;
	int i,j,offset;
	for(i=0;i<d;i++){
		loss += 0.5*lam*wb[i];
	}

	for(i=0;i<n;i++){
		offset = i*d;
		py=wb[d];
		for(j=0;j<d;j++){
			py += wb[j]*X[offset+j];
		}
		py = exp(- py*y[i]);
		loss += 1.0/n*log(1+py);
	}
	return loss;

}
void dJ(int n, int d, float *X, int *y, float lam, float *wb, float *dwb){
	float loss=0.0f,py;
	int i,j,offset;
	for(i=0;i<d;i++){
		dwb[i] = lam*wb[i];
	}
	dwb[d]=0.0f;

	for(i=0;i<n;i++){
		offset = i*d;
		py=wb[d];
		for(j=0;j<d;j++){
			py += wb[j]*X[offset+j];
		}
		py = exp(- py*y[i]);

		for(j=0;j<d;j++){
			dwb[j] += 1.0/n*(-y[i])*py/(1+py)*X[offset+j];
		}
		dwb[d] += 1.0/n*(-y[i])*py/(1+py);
	}
}

float* train_logistic_regression(int n, int d, float *X, int *y, float lam, float *wb) {
	int i,j;
	float * dwb = (float*) malloc(sizeof(float)*(d+1));
	for(i=0;i<d+1;i++) wb[i]=0.0f;
	for(i=0;i<10000;i++){ //iter
		dJ(n,d,X,y,lam,wb,dwb);
		for(j=0;j<d+1;j++){
			wb[j] -= dwb[j]*0.01;
		}
		//printf("%f, %f\n",J(n,d,X,y,lam,wb), dwb[0]+dwb[1]+dwb[2]);
	}
	free(dwb);
	for(i=0;i<d+1;i++){
		wb[i] = (int)(1000.0f*wb[i]);
		wb[i] = wb[i]/1000.0f;
	}
	return wb;
}

int main(){
	float X[2]={-0.5,1.5},lam=0.1,wb[2]={0,0};
	int y[2]={-1,1}, n=2,d=1;
	float * wb0 = train_logistic_regression(n,d,X,y,lam,wb);
	printf("[%.3f %.3f]\n",wb0[0],wb0[1]);
	getchar();
}