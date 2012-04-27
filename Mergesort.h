#include <stdio.h>
#include <limits.h>

static int result[20]={0};

void copy_array(int source[],int dest[],int floor,int ceiling){
	int i = 0;
	while(floor <= ceiling){
		dest[i++] = source[floor++];
	}
	//set a sentinel
	dest[i] = INT_MAX;
}

void merge(int a[],int floor,int middle,int ceiling){
	int b[20] = {0};
	int c[20] = {0};
	copy_array(a,b,floor,middle);
	copy_array(a,c,middle+1,ceiling);

	int i=0,j=0,k=0;
	while(b[j] < INT_MAX && c[k] < INT_MAX){
		result[i++] = b[j] < c[k]? b[j++]:c[k++];
	}
	if(b[j] == INT_MAX){
		while(c[k] != INT_MAX){
			result[i++] = c[k++];
		}
	}
	else if(c[k] == INT_MAX){
		while(b[j] != INT_MAX){
			result[i++] = b[j++];
		}
	}
	/*write the sorted result into source array to ensure
	  each part of the source is a sorted part before we 
	  merge the part
	*/
	i = 0;
	while(i < (j+k)){
		a[floor+i] = result[i];
		i++;
	}
}

void mergesort(int a[],int floor,int ceiling){
	if(floor < ceiling){
		int q;
		q = (floor+ceiling)/2;
		mergesort(a,floor,q);
		mergesort(a,q+1,ceiling);
		merge(a,floor,q,ceiling);
	}
}