#include<stdio.h>
void main(){
	int arr[]={1,2,3,4,5,6,7,8,66};
	int key,low,high,mid;
	int loc=-1;
	printf("Enter the element to search : ");
	scanf("%d",&key);
	low=0;
	high=8;
	while(low<=high){
		mid=(low+high)/2;
		if(arr[mid]==key){
			loc=mid;
			break;
		}
		else if(arr[mid]>key){
			high=mid-1;
		}
		else if(arr[mid]<key){
			low=mid+1;
		}
		}
	if(loc==-1)
		printf("Key not found");
	else
		printf("Key is found at position %d\n",loc);
}
