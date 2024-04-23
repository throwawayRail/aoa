#include<stdio.h>
int main(){
    int n, numbers[100], key;

    printf("Enter the dimensions of the array: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("Enter element %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    for (int i = 1; i < n; i++) {
        key = numbers[i];
        int j = i - 1;

        while (j >= 0 && numbers[j] > key) {
            numbers[j + 1] = numbers[j];
            j = j - 1;
        }
        numbers[j + 1] = key;
    }

    for (int i = 0; i < n; i++)
        printf("%d ", numbers[i]);
    printf("\n");
    return 0;
}
