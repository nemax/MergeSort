#include <stdio.h>
#include <limits.h>

void copy_array(int source[],int dest[],int floor,int ceiling){
	int i = 0;
	while(floor <= ceiling){
		dest[i++] = source[floor++];
	}
	//set a sentinel
	dest[i] = INT_MAX;
}

void merge(int a[],int floor,int middle,int ceiling){
	int temp_1[20] = {0};
	int temp_2[20] = {0};
	copy_array(a,temp_1,floor,middle);
	copy_array(a,temp_2,middle+1,ceiling);

	int j=0,k=0;
	while(temp_1[j] < INT_MAX && temp_2[k] < INT_MAX){
		a[floor++] = temp_1[j] < temp_2[k]? temp_1[j++]:temp_2[k++];
	}
	if(temp_1[j] == INT_MAX){
		while(temp_2[k] != INT_MAX){
			a[floor++] = temp_2[k++];
		}
	}
	else if(temp_2[k] == INT_MAX){
		while(temp_1[j] != INT_MAX){
			a[floor++] = temp_1[j++];
		}
	}
}

void mergesort(int a[],int floor,int ceiling){
	if(floor < ceiling){
		int q;
		q = (floor+ceiling)/2;
		/*merge the first half of the array,once there is only
		  one element in the array,we can see it as a sorted 
		  array
		*/
		mergesort(a,floor,q);
		mergesort(a,q+1,ceiling);
		/*combine two sorted array*/
		merge(a,floor,q,ceiling);
	}
}