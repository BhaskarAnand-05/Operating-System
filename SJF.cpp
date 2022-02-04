#include "Headerfile.h"
// Headerfile.h contains all the required Header File


// This is the code for non preemptive scheduling
void NONPREMPTIVE()
{
    int burst_time[20], process[20], waiting_time[20], tat[20], i, j, n, total = 0, pos, temp;
    float avg_waiting_time, avg_tat;
    printf("Enter number of process:\t");
    scanf("%d", &n);
    printf("\nEnter Burst Time:\n");
    for (i = 0; i < n; i++)
    {
        printf("Process%d:\t", i + 1);
        scanf("%d", &burst_time[i]);
        process[i] = i + 1;
    }
    // sorting of burst times
    for (i = 0; i < n; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (burst_time[j] < burst_time[pos])
                pos = j;
        }
        temp = burst_time[i];
        burst_time[i] = burst_time[pos];
        burst_time[pos] = temp;
        temp = process[i];
        process[i] = process[pos];
        process[pos] = temp;
    }
    // Calculating the Turn_Around Time and Waiting Time of the processes

    waiting_time[0] = 0;
    for (i = 1; i < n; i++)
    {
        waiting_time[i] = 0;
        for (j = 0; j < i; j++)
            waiting_time[i] += burst_time[j];
        total += waiting_time[i];
    }
    avg_waiting_time = (float)total / n;
    total = 0;
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for (i = 0; i < n; i++)
    {
        tat[i] = burst_time[i] + waiting_time[i];
        total += tat[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d", process[i], burst_time[i], waiting_time[i], tat[i]);
    }
    avg_tat = (float)total / n;
    printf("\n\nAverage Waiting Time=%f", avg_waiting_time);
    printf("\nAverage Turnaround Time=%f\n", avg_tat);
}

// This is the code for preemptive scheduling

void PREEMPTIVE()
{
    int arrival_time[10],
        burst_time[10],
        temp[10];
    int i, smallest, count = 0, time, limit;
    double wait_time = 0, turnaround_time = 0, end;
    float average_waiting_time, average_turnaround_time;
    printf("\nEnter the Total Number of Processes:\t");
    scanf("%d", &limit);
    printf("\nEnter Details of %d Processes", limit);
    for (i = 0; i < limit; i++)
    {
        cout<<endl<<"Process "<<i+1;
        printf("\nEnter Arrival Time:\t");
        scanf("%d", &arrival_time[i]);
        printf("Enter Burst Time:\t");
        scanf("%d", &burst_time[i]);
        temp[i] = burst_time[i];
    }
    // Calculating the Turn_Around Time and Waiting Time of the processes
    burst_time[9] = 9999;
    for (time = 0; count != limit; time++)
    {
        smallest = 9;
        for (i = 0; i < limit; i++)
        {
            if (arrival_time[i] <= time && burst_time[i] < burst_time[smallest] && burst_time[i] > 0)
            {
                smallest = i;
            }
        }
        burst_time[smallest]--;
        if (burst_time[smallest] == 0)
        {
            count++;
            end = time + 1;
            wait_time = wait_time + end - arrival_time[smallest] - temp[smallest];
            turnaround_time = turnaround_time + end - arrival_time[smallest];
        }
    }
    average_waiting_time = wait_time / limit;
    average_turnaround_time = turnaround_time / limit;
    printf("\n\nAverage Waiting Time:\t%lf\n", average_waiting_time);
    printf("Average Turnaround Time:\t%lf\n", average_turnaround_time);
}

// Program Execution begins from the main function
int main()
{

    system("cls");
    int choice;
    cout << "Program By Bhaskar Anand 2K20/CO/121" << endl
         << endl;
    cout << "Enter your choice\n 1. Preemptive SJF Schedling\n 2. Non- Preemptive SJF Scheduling" << endl;
    cin >> choice;

    system("cls");
    if (choice == 1)
    {
        PREEMPTIVE();
    }
    else if(choice==2)
    {
        NONPREMPTIVE();
    }
    

    

    return 0;
}