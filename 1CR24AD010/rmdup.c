//Remove duplicate elements from an array
#include<stdio.h>
void main(){
	int arr[]={4, 2, 7, 2, 4, 9, 1};
	int n = 9;
	int temp;
	int min;
	int i=0;
	for(int j=0;j<n-1;j++){
		min=j;
		for(int k=j+1;k<=n-1;k++){
			if(arr[min]>arr[k]){
				min=k;
			}
		}
		if(j!=min){
			temp=arr[min];
			arr[min]=arr[j];
			arr[j]=temp;
		}
	}
	for(int j=1;j<n;j++){
		if(arr[i]!=arr[j]){
			i++;
			arr[i] = arr[j];
		}
	}
	int new_n = i+1;
	for(int k=0;k<new_n;k++){
		printf("%d ",arr[k]);
	}
}
