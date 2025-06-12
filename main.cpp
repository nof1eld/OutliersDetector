#include <stdio.h>
#include <stdlib.h>

void sortArray(float arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

float calculateQ1(float array[], int size) {
    if ((size/2)%2 == 0)
    {
        return (array[(size/4)-1] + array[(size/4)])/2.00;
    } else {
        return array[((size/2 +1)/2)-1];
    }
}

float calculateQ3(float array[], int size) {
    if ((size/2)%2 == 0)
    {
        return (array[(3*size/4)-1] + array[(3*size/4)])/2.00;
    } else {
        return array[((3*size/2 +1)/2)-1];
    }
}

int main() {
    int totalVotes, outliersCount, thereAreOutliers = 0;
    float q1, q3, iqr, minValue, maxValue;
    do
    {
        printf("Enter the total number of votes: ");
        scanf("%d", &totalVotes);
        if (totalVotes < 4) {
            printf("Invalid number of votes. Please enter a value of 4 or more.\n");
        }
    } while (totalVotes < 4);
    
   
    float votes[totalVotes];
    
    for(int i = 0; i < totalVotes; i++)
    {
        do
        {
            printf("Enter vote %d: ", i + 1);
            scanf("%f", &votes[i]);
            if (votes[i] < 0) {
                printf("Invalid vote. Please enter a value above 0.\n");
            }
        } while (votes[i] < 0);
    }
    sortArray(votes, totalVotes);

    printf("-----votes-----\n");
    for(int i = 0; i < totalVotes; i++)
    {
        printf("Vote %d: %f\n", i + 1, votes[i]);
    }
    q1 = calculateQ1(votes, totalVotes);
    q3 = calculateQ3(votes, totalVotes);
    iqr = q3 - q1;
    minValue = q1 - 1.5 * iqr;
    maxValue = q3 + 1.5 * iqr;

    printf("-----outliers-----\n");
    for (int i = 0; i < totalVotes; i++)
    {
        if (votes[i] < minValue || votes[i] > maxValue) {
            thereAreOutliers = 1;
            printf("Vote %d: %f is an outlier\n", i + 1, votes[i]);
        }
    }
    if (thereAreOutliers == 0) {
        printf("None\n");
    }

    return 0;
}