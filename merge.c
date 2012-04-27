#include "Mergesort.h"

int main(){
	int a[10]={25,1,67,66,45,78,23,58,90,34};
	mergesort(a,0,9);
	int i = 0;
	while(i < 10){
		printf("a[%d]=%d\n",i,a[i++]);
	}
	return 0;
}