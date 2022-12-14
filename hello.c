//function for binary search


#include<stdio.h>

// x is number to be searched
// arr is array from where number is to be searched
// n is size of the arr

// we have declared the function with two tests in while loop
int binarySearch2(int x,int arr[],int n);

// we have declared the function with one test in while loop
int binarySearch1(int x,int arr[],int n);


int main(){
	
	// sample array
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	
	// search on sample array with binary search of 2 tests
	printf("%d",binarySearch2(5,arr,10));

	// search on sample array with binary search of 1 test
	printf("%d",binarySearch1(5,arr,10));

	return 0;
}

// code for function
int binarySearch2(int x,int arr[],int n){
	
	// init start,mid & end
	int start,mid,end;
	
	// init start and end
	start = 0;
	end = n-1;

	// search till start is less than or equal to end
	while(start <= end){

		// find mid index of current array window
		mid = (start + end)/2;

		// if number to be found is less than mid element of current array
		if(arr[mid] > x){
			end = mid-1;
		}

		// if number to be found is greater than mid element of current array
		else if(arr[mid] <x){
			start = mid+1;
		}
		
		// if you find the number to be found
		else{
			return mid;
		}

	}

	// if you dont find it return it
	return -1;

}


// code for function
int binarySearch1(int x,int arr[],int n){
	
	// init start,mid & end
	int start,mid,end;
	
	// init start and end
	start = 0;
	end = n-1;
	
	// find mid index of current array window
	mid = (start + end)/2;


	// search till start is less than or equal to end and arr[mid] is not equal to x
	while(start < end && arr[mid] != x){

		// if number to be found is less than mid element of current array
		if(arr[mid] > x){
			end = mid-1;
		}else{
			start = mid+1;
		}
		
		// find mid index of current array window
		mid = (start + end)/2;


	}

	if(arr[mid] == x){
		return mid;
	}else{
		return -1;
	}

}


