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

    int p[n], bt[n], pt[n], wt[n], tat[n];
    float awt, atat;

    printf("Enter burst time of process:\n");
    for (int i = 0; i < n; i++)
    {
        printf("P[%d]: ", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1;
    }

    printf("Enter priority number of process:\n");
    for (int i = 0; i < n; i++)
    {
        printf("P[%d]: ", i + 1);
        scanf("%d", &pt[i]);
    }
    

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (pt[j] > pt[j+1]) 
            {
                swap(&pt[j], &pt[j+1]);
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

    printf("\nProcess id\tPriority\tBurst time\tWaiting time\tTurn around time\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t        %d\t        %d\t        %d\t        %d\t\n", p[i], pt[i], bt[i], wt[i], tat[i]);
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
P[1]: 3
P[2]: 6
P[3]: 7
P[4]: 2
P[5]: 5
Enter priority number of process:
P[1]: 4
P[2]: 3
P[3]: 1
P[4]: 2
P[5]: 6

Process id      Priority        Burst time      Waiting time    Turn around time
3               1               7               0               7
4               2               2               7               9
2               3               6               9               15
1               4               3               15              18
5               6               5               18              23

Total waiting time: 49
Total turn around time: 72
Average waiting time: 9.800000
Average turn around time: 14.400000

*/
