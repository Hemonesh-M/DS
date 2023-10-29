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
    // INSERTION SORTING
    for (int i = 1; i <= n - 1; i++)
    {
        int j = i;
        while (j >= 1 && arr[j] < arr[j - 1])
        {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
    cout<<"Elements after sorting"<<endl;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    cout<<endl;
    return 0;
}