#include <stdio.h>
using namespace std;

void printArray(int arr[], int n){
	for (int i = 0; i < n; i++){
		printf("%d", arr[i]);
	} printf("\n");


void rotateArr(int arr[], int d, int n){
	int tempArr[d];
	for (int i = 0; i < n; i++){
		while (i < d){
			tempArr[i] = arr[i];
			//arr[i] = 0;
			i++;
		}

		int p = 0;
		while (p < n-d){
			arr[p] = arr[i];
			p++;
			i++;
		}	
	}

	int n2 = sizeof(tempArr)/sizeof(tempArr[0]);
	for (int i = n; i > n-d-1; i--){
		arr[i] = tempArr[n2];
		n2--;
	}
	
}

int main(){
	int arr[] = {1,2,3,4,5,6,7};
	int n = sizeof(arr)/sizeof(arr[0]);

	// before rotate
	printf("==== Before Rotate ====\n");
	printArray(arr, n);

	// after rotate
	printf("==== After Rotate ====\n");
	rotateArr(arr, 3, n);
	printArray(arr, n);
	return 0;
}