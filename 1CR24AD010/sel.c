#include<stdio.h>
int main(){
	int arr[] = {5,11,12,6,4,9,10,3,14};
	int n = 9;
	int temp;
	int min;
	int i,j,k;
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
	for(int k=0;k<n;k++){
		printf("%d ",arr[k]);
	}
}
