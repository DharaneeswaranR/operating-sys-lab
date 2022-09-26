#include <stdio.h>

int main()
{
    int mn, pn;
    printf("No. of blocks: ");
    scanf("%d", &mn);
    printf("No. of process: ");
    scanf("%d", &pn);

    int m[mn], p[pn], aloc[pn];

    for (int i = 0; i < mn; i++)
    {
        printf("\nSize of memory block %d: ", i);
        scanf("%d", &m[i]);
    }

    for (int i = 0; i < pn; i++)
    {
        printf("\nSize of process %d: ", i);
        scanf("%d", &p[i]);
        aloc[i] = 0;
    }

    for (int i = 0; i < pn; i++)
    {
        for (int j = 0; j < mn; j++)
        {
            if (p[i] <= m[j] && aloc[i] == 0) 
            {
                printf("\nProcess %d is allocated to block %d", i, j);
                aloc[i] = 1;
                m[j] = m[j] - p[i]; 
            }
        }
        
    }
    
    printf("\nRemaining space left:\n");
    for (int i = 0; i < mn; i++)
    {
        printf("\nBlock %d: %d", i, m[i]);
    }
    
     
    for (int i = 0; i < pn; i++)
    {
        if (aloc[i] == 0)
        {
            printf("\nProcess %d is unallocated", i);
        }
    }
}

/*

No. of blocks: 3

No. of process: 2

Size of memory block 0: 242

Size of memory block 1: 300

Size of memory block 2: 200

Size of process 0: 100

Size of process 1: 300

Process 0 is allocated to block 0
Process 1 is allocated to block 1
Remaining space left:

Block 0: 142
Block 1: 0
Block 2: 200

*/