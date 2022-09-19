#include <stdio.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int main()
{
    int n, twt, ttat;
    printf("Enter number of process: ");
    scanf("%d", &n);

    int p[n], bt[n], wt[n], tat[n];
    float awt, atat;

    printf("Enter burst time of process:\n");
    for (int i = 0; i < n; i++)
    {
        printf("P[%d]: ", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1;
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (bt[j] > bt[j+1]) 
            {
                swap(&bt[j], &bt[j+1]);
                swap(&p[j], &p[j+1]);
            }
        }
        
    }
    
    wt[0] = 0;
    tat[0] = bt[0];
    twt = wt[0];
    ttat = tat[0];
    for (int i = 1; i < n; i++)
    {
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = wt[i] + bt[i];
        twt += wt[i];
        ttat += tat[i];
    }
    
    awt = (float)twt / n;
    atat = (float)ttat / n;

    printf("\nProcess id\tBurst time\tWaiting time\tTurn around time\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t        %d\t        %d\t        %d\t\n", p[i], bt[i], wt[i], tat[i]);
    }
    
    printf("\nTotal waiting time: %d\n", twt);
    printf("Total turn around time: %d\n", ttat);
    printf("Average waiting time: %f\n", awt);
    printf("Average turn around time: %f\n", atat);
    
    return 0;
}

/* Output:

Enter number of process: 5
Enter burst time of process:
P[1]: 2
P[2]: 3
P[3]: 9
P[4]: 1
P[5]: 4

Process id      Burst time      Waiting time    Turn around time
4               1               0               1
1               2               1               3
2               3               3               6
5               4               6               10
3               9               10              19

Total waiting time: 20
Total turn around time: 39
Average waiting time: 4.000000
Average turn around time: 7.800000

*/