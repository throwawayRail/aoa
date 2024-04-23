#include<stdio.h>
int arr[100];
int binarySearch(int, int);
int bubbleSort(int);

int main(){
    int n, search;
    printf("Enter the dimensions of the array: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    bubbleSort(n);
    printf("Sorted array: ");
    for(int i = 0; i < n; i++) 
        printf("%d ", arr[i]);

    printf("Element to search: ");
    scanf("%d", &search);

    int result = binarySearch(n, search);
    if(result == -1)  
        printf("Element is not present in array\n");
    else
        printf("Element is present at  index %d\n", result + 1);
    return 0;
}

int bubbleSort(int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr [j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int n, int search){
    int low, high;
    low = 0;
    high = n - 1;
    while (low <= high) {
        int mid = (high + low) / 2;

        if (arr[mid] == search)
            return mid;

        else if (arr[mid] < search)
            low = mid + 1;

        else
            high = mid - 1;
    }
    return -1;
}
