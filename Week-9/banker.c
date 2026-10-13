#include <stdio.h>
int main()
{
    int p, r;
    int max[10][10], alloc[10][10], need[10][10];
    int avail[10], work[10], finish[10], safe[10];
    int i, j, count = 0, possible;
    printf("Enter number of processes: ");
    scanf("%d", &p);
    printf("Enter number of resources: ");
    scanf("%d", &r);
    printf("\nEnter Maximum Matrix:\n");
    for (i = 0; i < p; i++)
    {
        printf("P%d: ", i + 1);
        for (j = 0; j < r; j++)
            scanf("%d", &max[i][j]);
    }
    printf("\nEnter Allocation Matrix:\n");
    for (i = 0; i < p; i++)
    {
        printf("P%d: ", i + 1);
        for (j = 0; j < r; j++)
            scanf("%d", &alloc[i][j]);
    }
    /* Calculate Need Matrix */
    for (i = 0; i < p; i++)
        for (j = 0; j < r; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    printf("\nEnter Available Resources: ");
    for (j = 0; j < r; j++)
    {
        scanf("%d", &avail[j]);
        work[j] = avail[j];
    }
    for (i = 0; i < p; i++)
        finish[i] = 0;
    /* Banker's Algorithm */
    while (count < p)
    {
        possible = 0;
        for (i = 0; i < p; i++)
        {
            if (finish[i] == 0)
            {
                int canRun = 1;
                for (j = 0; j < r; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        canRun = 0;
                        break;
                    }
                }
                if (canRun)
                {
                    printf("\nP%d can execute.", i + 1);
                    for (j = 0; j < r; j++)
                        work[j] += alloc[i][j];
                    safe[count++] = i + 1;
                    finish[i] = 1;
                    possible = 1;
                }
            }
        }
        if (!possible)
            break;
    }
    if (count == p)
    {
        printf("\n\nSystem is in a SAFE state.");
        printf("\nSafe Sequence: ");
        for (i = 0; i < p; i++)
        {
            printf("P%d", safe[i]);
            if (i < p - 1)
                printf(" -> ");
        }
    }
    else
    {
        printf("\n\nSystem is in an UNSAFE state.");
    }

    printf("\n");
    return 0;
}
