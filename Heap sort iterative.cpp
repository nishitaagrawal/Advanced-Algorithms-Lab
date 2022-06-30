# include <iostream> //Iterative Heap Sort
#include <bits/stdc++.h>
using namespace std;

void buildMaxHeap(int arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
			if (arr[i] > arr[(i - 1) / 2])
		{
			int j = i;
			while (arr[j] > arr[(j - 1) / 2])
			{
				swap(arr[j], arr[(j - 1) / 2]);
				j = (j - 1) / 2;
			}
		}
	}
	cout<<"Display max heap : ";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}

void heapSort(int arr[], int n)
{
	buildMaxHeap(arr, n);
	for (int i = n - 1; i > 0; i--)
	{
		swap(arr[0], arr[i]);
		int j = 0, index;	
		do
		{
			index = (2 * j + 1);
			if (arr[index] < arr[index + 1] && index < (i - 1))
				index++;
			if (arr[j] < arr[index] && index < i)
				swap(arr[j], arr[index]);
			j = index;
		} while (index < i);
	}
}
int main()
{
	int arr[10];
	int n;
	cout<<"Enter the size of the array : ";
	cin>>n;
	cout << "Enter the array elements : ";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	printf("Given array: ");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);		
	}
	printf("\n\n");
	heapSort(arr, n);
	printf(" \n Sorted array: ");
	for (int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	return 0;
}

