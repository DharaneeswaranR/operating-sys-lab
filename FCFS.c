#include <stdio.h>

int main()
{
    int n, twt, ttat;
    printf("Enter number of process: ");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n];
    float awt, atat;

    printf("Enter burst time of process:\n");
    for (int i = 0; i < n; i++)
    {
        printf("P[%d]: ", i + 1);
        scanf("%d", &bt[i]);
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
        printf("%d\t        %d\t        %d\t        %d\t\n", i+1, bt[i], wt[i], tat[i]);
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
P[3]: 1
P[4]: 4
P[5]: 3

Process id      Burst time      Waiting time    Turn around time
1               2               0               2
2               3               2               5
3               1               5               6
4               4               6               10
5               3               10              13

Total waiting time: 23
Total turn around time: 36
Average waiting time: 4.600000
Average turn around time: 7.200000

*/

