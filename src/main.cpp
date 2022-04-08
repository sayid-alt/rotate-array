#include <stdio.h>
using namespace std;

void printArray(int arr[], int size){
	for (int i = 0; i < size; i++){
		printf("%d", arr[i]);
	} printf("\n");
}

//Function to rotate an array by d elements in counter-clockwise direction. 
void rotateArr(int arr[], int step, int size){
	if (step <= size){
		int tempArr[step]; // declare for temporary d'th first element
		
		for (int i = 0; i < size; i++){
			while (i < step){
				tempArr[i] = arr[i]; // store d'th first element to tempArr
				//arr[i] = 0;
				i++; // increment i when arr[i] is stored in tempArr
			}
			
			// shift rest of the elements of arr[] towards left
			int p = 0; // declare index for the d'th first element
			while (p < size-step){
				arr[p] = arr[i];
				p++;
				i++;
			}	
		}

		// replace the element in temporary array to the main array
		int n2 = sizeof(tempArr)/sizeof(tempArr[0]);
		for (int j = size; j >= size-step; j--){
			arr[j] = tempArr[n2];
			n2--;
		}
	} 
	
	else{
		printf("Can't rotate the array, Steps must be lower than or equal to the size\n");
	}
}

int main(){
	int arr[] = {5,2,1,0,9,4,3};
	int n = sizeof(arr)/sizeof(arr[0]);

	// before rotate
	printf("==== Before Rotate ====\n");
	printArray(arr, n);

	// after rotate
	printf("==== After Rotate ====\n");
	rotateArr(arr, 5, n); // number of steps must be lower than or equal to size of array
	printArray(arr, n);
	return 0;
}