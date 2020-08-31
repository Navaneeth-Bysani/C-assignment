#include<stdio.h>
#include<conio.h>
#include<string.h>

void merge(int a[], int low, int mid, int high) {
	int i = low, j = mid+1, k=0;
	int b[high-low+1];
	while(i <= mid && j <= high) {
		if(a[i] <= a[j]) {
			b[k] = a[i];
			i++;
			k++;
		} else {
			b[k] = a[j];
			j++;
			k++;
		}
	}
	while(j != high+1) {
		b[k++] = a[j++];
	}
	
	while(i != high + 1) {
		b[k++] = a[i++];
	}
	
	for(i=low, j = 0; i <= high ; i++, j++) {
		a[i] = b[j];
	}
}

int mergesort(int a[],int low, int high) {
	int mid;
	
	if(low<high) {
	mid = (low+high)/2;
	mergesort(a,low,mid);
	mergesort(a,mid+1, high);
	
	merge(a,low,mid,high);
	}
	
}


int main() {
	int a[5] = {1,200,180,175,-300};
	int low = 0, high = 4;
	int i;
	mergesort(a,low,high);
	for(i=0;i<5;i++) {
		printf("%d	",a[i]);
	}
}
