#include <stdio.h>


int calculateSum(int *arr, int n) {
    if (n == 0) { 
        return 0;
    }
    return *arr + calculateSum(arr + 1, n - 1); 
}

int main() {
    int scores[10]; 
    int n = 10;     
    int sum;
    char choice;

    do {
        printf("Enter the scores of 10 subjects (0-100):\n");
        for (int i = 0; i < n; i++) {
            while (1) { 
                printf("Subject %d: ", i + 1);
                scanf("%d", &scores[i]);
                if (scores[i] >= 0 && scores[i] <= 100) {
                    break; 
                }
                printf("Invalid input! Please enter marks between 0 and 100.\n");
            }
        }

        
        sum = calculateSum(scores, 10);

      
        printf("\n--- Summary ---\n");
        printf("Scores of all 10 subjects: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", scores[i]);
        }
        printf("\nSum of the first 10 scores: %d\n", sum);

       
        double average = sum / 10.0;
        printf("Average of the first 10 scores: %.2f\n", average);

       
        if (average >= 50.0) {
            printf("Status: Passed!\n");
        } else {
            printf("Status: Failed. Better luck next time.\n");
        }

        
        printf("\nDo you want to enter marks for another student? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the program. Goodbye!\n");
    return 0;
}