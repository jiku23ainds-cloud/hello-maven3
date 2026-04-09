#include<stdio.h>
void combine_lists(int arr1[], int n1, int arr2[], int n2, int *result){
	int i=0,j=0,k=0;
	while(i<n1 && j<n2){
		result[k++]=arr1[i++];
		result[k++]=arr2[j++];
	}
	
	while(i<n1){
		result[k++]=arr1[i++];
	}
	
	while(j<n2){
		result[k++]=arr2[j++];
	}
}

void main(){

	int n1,n2;  
	
	printf("Enter the size of Array 1 : ");
	scanf("%d",&n1);
	
	int arr1[n1];
	
	printf("Enter the elements of Array 1 : ");
	for(int i=0;i<n1;i++){
		scanf("%d",&arr1[i]);
	}
	
	printf("Enter the size of Array 2 : ");
	scanf("%d",&n2);
	
	int arr2[n2];
	
	printf("Enter the elements of Array 1 : ");
	for(int j=0;j<n2;j++){
		scanf("%d",&arr2[j]);
	}
	
	int n;
	n=n1+n2;
	int result[n];
	
	combine_lists(arr1,n1,arr2,n2,result);
	printf("Result Array After Combining Two Arrays Alternatingly : ");
	for(int k=0;k<n1;k++){
		printf("%d",result[k]);
	}
}
	
