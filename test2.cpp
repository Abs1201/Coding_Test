// C++ program for Merge Sort
#include <bits/stdc++.h>
#include <ctime>
using namespace std;

// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[], int const left, int const mid,
		int const right)
{
	int const subArrayOne = mid - left + 1;
	int const subArrayTwo = right - mid;

	// Create temp arrays
	auto *leftArray = new int[subArrayOne],
		*rightArray = new int[subArrayTwo];

	// Copy data to temp arrays leftArray[] and rightArray[]
	for (auto i = 0; i < subArrayOne; i++)
		leftArray[i] = array[left + i];
	for (auto j = 0; j < subArrayTwo; j++)
		rightArray[j] = array[mid + 1 + j];

	auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
	int indexOfMergedArray = left;

	// Merge the temp arrays back into array[left..right]
	while (indexOfSubArrayOne < subArrayOne
		&& indexOfSubArrayTwo < subArrayTwo) {
		if (leftArray[indexOfSubArrayOne]
			<= rightArray[indexOfSubArrayTwo]) {
			array[indexOfMergedArray]
				= leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			array[indexOfMergedArray]
				= rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}

	// Copy the remaining elements of
	// left[], if there are any
	while (indexOfSubArrayOne < subArrayOne) {
		array[indexOfMergedArray]
			= leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}

	// Copy the remaining elements of
	// right[], if there are any
	while (indexOfSubArrayTwo < subArrayTwo) {
		array[indexOfMergedArray]
			= rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
	delete[] leftArray;
	delete[] rightArray;
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(int array[], int const begin, int const end)
{
	if (begin >= end)
		return;

	int mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
}


// second way.
// const int MAX_SIZE=260000;
// int sorted[MAX_SIZE];

// void merge(int list[], int left, int mid, int right){
//   int i, j, k, l;
//   i = left;
//   j = mid+1;
//   k = left;

//   /* 분할 정렬된 list의 합병 */
//   while(i<=mid && j<=right){
//     if(list[i]<=list[j])
//       sorted[k++] = list[i++];
//     else
//       sorted[k++] = list[j++];
//   }

//   // 남아 있는 값들을 일괄 복사
//   if(i>mid){
//     for(l=j; l<=right; l++)
//       sorted[k++] = list[l];
//   }
//   // 남아 있는 값들을 일괄 복사
//   else{
//     for(l=i; l<=mid; l++)
//       sorted[k++] = list[l];
//   }

//   // 배열 sorted[](임시 배열)의 리스트를 배열 list[]로 재복사
//   for(l=left; l<=right; l++){
//     list[l] = sorted[l];
//   }
// }

// 합병 정렬
// void mergeSort(int list[], int left, int right){
//   int mid;

//   if(left<right){
//     mid = (left+right)/2; // 중간 위치를 계산하여 리스트를 균등 분할 -분할(Divide)
//     mergeSort(list, left, mid); // 앞쪽 부분 리스트 정렬 -정복(Conquer)
//     mergeSort(list, mid+1, right); // 뒤쪽 부분 리스트 정렬 -정복(Conquer)
//     merge(list, left, mid, right); // 정렬된 2개의 부분 배열을 합병하는 과정 -결합(Combine)
//   }
// }



// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
	cout << endl;
}

// Driver code
int main()
{
    clock_t start, finish;
    double duration;
	int arrSize;
 
	// int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr[200000];

	freopen("input.txt", "r", stdin);
	cin >> arrSize;
    for(int i=0; i<arrSize; i++){
        cin >> arr[i];
    }


    start = clock();
	mergeSort(arr, 0, arrSize - 1);
    finish=clock();

    duration = (double)(finish - start);
    cout << duration << " ms" << endl;

	// cout << "\nSorted array is \n";
	// printArray(arr, arrSize);
	return 0;
}

// This code is contributed by Mayank Tyagi
// This code was revised by Joshua Estes
