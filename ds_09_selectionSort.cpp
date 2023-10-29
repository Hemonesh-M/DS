#include<iostream>
using namespace std;
int main(){
    int arr[100];  
    int n; 
    int element;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
     if(n>100){
        cout<<"OVERFLOW-you cannot add more elements to array"<<endl;
    }
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout<<"Elements before sorting"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    // SELECTION SORTING
for (int i = 0; i < n - 1; i++)
{
    int min = arr[i];
    int minidx = i; 
    for (int j = i; j < n; j++) 
    {
        if (min > arr[j])
        {
            min = arr[j];
            minidx = j;
        }
    }
    int temp = arr[minidx];
    arr[minidx] = arr[i];
    arr[i] = temp;
}

    cout<<"Elements after sorting"<<endl;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    cout<<endl;
    return 0;
}