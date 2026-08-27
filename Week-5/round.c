#include <stdio.h>

int main()
{
    int n, i;
    int p[20], at[20], bt[20], remaining[20];
    int ct[20], tat[20], wt[20];
    int queue[100];
    int front = 0, rear = 0;
    int visited[20] = {0};
    int completed = 0;
    int current_time = 0;
    int time_quantum;
    int process;
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
        remaining[i] = bt[i];
    }
    printf("\nEnter Time Quantum: ");
    scanf("%d", &time_quantum);
    // Find first arrival time
    current_time = at[0];
    for (i = 1; i < n; i++)
    {
        if (at[i] < current_time)
            current_time = at[i];
    }
    // Add initially arrived processes
    for (i = 0; i < n; i++)
    {
        if (at[i] <= current_time)
        {
            queue[rear++] = i;
            visited[i] = 1;
        }
    }
    printf("\nRound Robin Scheduling\n");
    printf("\nGantt Chart:\n");
    while (completed < n)
    {
        // If queue is empty
        if (front == rear)
        {
            for (i = 0; i < n; i++)
            {
                if (visited[i] == 0)
                {
                    current_time = at[i];
                    queue[rear++] = i;
                    visited[i] = 1;
                    break;
                }
            }
        }
        process = queue[front++];
        printf("| P%d ", p[process]);
        // Execute process
        if (remaining[process] > time_quantum)
        {
            current_time += time_quantum;
            remaining[process] -= time_quantum;
        }
        else
        {
            current_time += remaining[process];
            remaining[process] = 0;
            ct[process] = current_time;
            completed++;
        }
        // Add newly arrived processes
        for (i = 0; i < n; i++)
        {
            if (visited[i] == 0 && at[i] <= current_time)
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
        // Add unfinished process back to queue
        if (remaining[process] > 0)
        {
            queue[rear++] = process;
        }
    }
    printf("|\n");
    // Calculate TAT and WT
    for (i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        avg_tat += tat[i];
        avg_wt += wt[i];
    }
    avg_tat /= n;
    avg_wt /= n;
    // Display result
    printf("\nRound Robin Scheduling Result\n");
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
