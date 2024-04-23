#include<stdio.h>
int sack_capacity, profit[10], weight[10], object[10], no_of_items;
float ratio[10], sack_used, sack_unused, temp, fraction_used, total_profit = 0, fraction_per_item[10];
void sort_ratio();
void greedy_logic();
void print_summary();

int main(){
    printf("Enter the capacity of knapsack: ");
    scanf("%d", &sack_capacity);
    printf("Enter the no of items in knapsack: ");
    scanf("%d", &no_of_items);

    for(int i = 0; i < no_of_items; i++){
        printf("Enter details for item %d", i + 1);
        printf("\n\tWeight: ");
        scanf("%d", &weight[i]);
        printf("\tProfit: ");
        scanf("%d", &profit[i]);
        ratio[i] = (float)profit[i] / (float)weight[i];
        object[i] = i + 1;
    }

    sort_ratio();
    greedy_logic();
    print_summary();
}

void sort_ratio(){
    for(int i = 0; i < no_of_items; i++){
        for(int j = 0; j < no_of_items - i - 1; j++){
            if(ratio[j + 1] > ratio[j]){
                temp = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = temp;

                temp = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = temp;

                temp = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = temp;

                temp = object[j];
                object[j] = object[j + 1];
                object[j + 1] = temp;
            }
        }
    }
}

void print_summary(){
    printf("Table after sorting according to profit-weight ratio: \n");
    printf("Object\tProfit\tWeight\tRatio\tFraction_used\n");
    for(int i = 0; i < no_of_items; i++)
        printf("%d\t%d\t%d\t%f\t%f\n", object[i], profit[i], weight[i], ratio[i], fraction_per_item[i]);
    printf("\nTotal Weight: %f\n", sack_used);
    printf("\nTotal Profit: %f\n", total_profit);
}

void greedy_logic(){
    sack_unused = sack_capacity;
    sack_used = 0;
    int i = 0;
    while((sack_unused != 0) && (i < no_of_items)){
        while(i < no_of_items){
            if(sack_unused > 1 * weight[i]){
               sack_used += weight[i];
               sack_unused -= weight[i];
               total_profit += profit[i];
               fraction_per_item[i] = 1;
            }

            else{
                fraction_used = sack_unused / (float)weight[i];
                sack_used += fraction_used * weight[i];
                sack_unused -= fraction_used * weight[i];
                total_profit += fraction_used * profit[i];
                fraction_per_item[i] = fraction_used;
            }
            i++;
        }
    }
}

