#include<iostream> //recurssive
using namespace std;
int display(int b[],int m)
{
	int i;
	cout<<"\nThe array after pass is : ";
	for(i=0;i<m;i++)
	{
		cout<<b[i]<<"\t";
	}
}
void recursiveInsertionSort(int arr[], int n){
    if (n <= 1){
    	display(arr,n);
    	return;
	}
	recursiveInsertionSort( arr, n-1 );
    int nth = arr[n-1];
    int j = n-2;
    while (j >= 0 && arr[j] > nth){
       arr[j+1] = arr[j];
       j--;
    }
    arr[j+1] = nth;
    display(arr,n);
}
int main(){
    int array[10],n,i;
	cout<<"Enter the value of n : ";
	cin>>n;
	cout<<"Enter the elements : ";
	for(i=0;i<n;i++)
	{
		cin>>array[i];
	}
    cout<<"Unsorted Array : ";
    for (int i=0; i < n; i++)
    {
    	cout<<array[i]<<" ";
	}
    recursiveInsertionSort(array, n);
    cout<<"\nSorted Array:\t";
    for (int i=0; i < n; i++)
    {
    	cout<<" "<<array[i];
	}
    return 0;
}

