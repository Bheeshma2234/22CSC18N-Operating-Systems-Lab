#include <stdio.h>

int main()
{
    int n, i;
    int p[20], at[20], bt[20];
    int ct[20], tat[20], wt[20];
    int completed[20] = {0};
    int current_time = 0;
    int completed_count = 0;
    int shortest;
    float avg_tat = 0, avg_wt = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    // Input
    for (i = 0; i < n; i++)
    {
        printf("\nProcess %d\n", i + 1);
        printf("Process ID: ");
        scanf("%d", &p[i]);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
    }
    // SJF Scheduling
    while (completed_count < n)
    {
        shortest = -1;
        // Find shortest process that has arrived
        for (i = 0; i < n; i++)
        {
            if (completed[i] == 0 && at[i] <= current_time)
            {
                if (shortest == -1 || bt[i] < bt[shortest])
                {
                    shortest = i;
                }
            }
        }
        // If no process has arrived
        if (shortest == -1)
        {
            current_time++;
            continue;
        }
        // Execute process
        current_time = current_time + bt[shortest];
        ct[shortest] = current_time;
        tat[shortest] = ct[shortest] - at[shortest];
        wt[shortest] = tat[shortest] - bt[shortest];
        completed[shortest] = 1;
        completed_count++;
    }
    // Calculate averages
    for (i = 0; i < n; i++)
    {
        avg_tat += tat[i];
        avg_wt += wt[i];
    }
    avg_tat = avg_tat / n;
    avg_wt = avg_wt / n;
    // Display result
    printf("\n\nSJF Non-Preemptive Scheduling\n");
    printf("---------------------------------------------\n");
    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    printf("---------------------------------------------\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("---------------------------------------------\n");
    printf("Average Turnaround Time = %.2f\n", avg_tat);
    printf("Average Waiting Time = %.2f\n", avg_wt);
    return 0;
}
