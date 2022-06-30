#include<iostream>
using namespace std;
void merge(int Arr[],int l,int m,int r) 
{
	int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    int L[n1],R[n2];
    for (i=0;i<n1;i++)
    {
    	L[i]=Arr[l+i];
	} 
    for (j=0;j<n2;j++)
    {
    	R[j]=Arr[m+1+j];
	}  
    i=0,j=0,k=l;
    while(i<n1 && j<n2) 
	{
        if (L[i] <= R[j]) 
		{
			Arr[k]=L[i];
			i++;
        } 
		else 
		{
			Arr[k]=R[j];
            j++;
        }
        k++;
    }
    while (i<n1) 
	{
		Arr[k]=L[i];
		i++;
		k++;
    }
    while (j<n2) 
	{
		Arr[k]=R[j];
		j++;
		k++;
    }
}
void merge_sort(int Arr[], int N)
{
    for(int sub_size=1;sub_size<N;sub_size*=2)
    {
        for(int L=0; L<N; L+=(2*sub_size))
        {
            int Mid=min(L+sub_size-1,N-1);
            int R=min(L+2*sub_size-1,N-1);
            // function to merge  two sub-arrays of
            // size sub_size starting from L and Mid
            merge(Arr, L,Mid,R);
        }
    }
}
int main()
{
    int i;
    int N = 8;
    int Arr[N] = {3, 2, 1, 9, 5, 4, 10, 11};
    cout<<"Unsorted Array: ";
    for(i=0;i<N;i++)
    {
    	cout<<Arr[i]<<" ";
	}
    cout<<endl;
    merge_sort(Arr, N);
    cout<<"Sorted Array: ";
    for(i=0;i<N;i++)
    {
    	cout<<Arr[i]<<" ";
	}
    return 0;
}

