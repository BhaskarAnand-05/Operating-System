#include "Headerfile.h"
// Headerfile.h Contains all the necessary headerfiles for this code

// C++ Implementation of Non-Preemptive Priority Scheduling Algorithm

void NONPREEMPTIVE()
{
    int n = 5;       // Number of Processes
    int CPU = 0;     // CPU Current time
    int allTime = 0; // Time needed to finish all processes

    int arrivaltime[n] = {0, 5, 12, 2, 9};
    int bursttime[n] = {11, 28, 2, 10, 16};
    int priority[n] = {2, 0, 3, 1, 4};

    for (int i = 0; i < n; i++)
    {
        cout << "Enter arrival time of process " << i + 1 << ": ";
        cin >> arrivaltime[i];
        cout << "Enter burst time of process " << i + 1 << ": ";
        cin >> bursttime[i];
        cout << "Enter priority of the process " << i + 1 << ": ";
        cin >> priority[i];
    }

    int ATt[n];
    int NoP = n; // number of Processes
    int PPt[n];
    int waitingTime[n];
    int turnaroundTime[n];
    int i = 0;

    for (i = 0; i < n; i++)
    {
        PPt[i] = priority[i];
        ATt[i] = arrivaltime[i];
    }

    int LAT = 0; // LastArrivalTime
    for (i = 0; i < n; i++)
        if (arrivaltime[i] > LAT)
            LAT = arrivaltime[i];

    int MAX_P = 0; // Max Priority
    for (i = 0; i < n; i++)
        if (PPt[i] > MAX_P)
            MAX_P = PPt[i];

    int ATi = 0;     // Pointing to Arrival Time indix
    int P1 = PPt[0]; // Pointing to 1st priority Value
    int P2 = PPt[0]; // Pointing to 2nd priority Value

    // finding the First Arrival Time and Highest priority Process
    int j = -1;
    while (NoP > 0 && CPU <= 1000)
    {
        for (i = 0; i < n; i++)
        {
            if ((ATt[i] <= CPU) && (ATt[i] != (LAT + 10)))
            {
                if (PPt[i] != (MAX_P + 1))
                {
                    P2 = PPt[i];
                    j = 1;

                    if (P2 < P1)
                    {
                        j = 1;
                        ATi = i;
                        P1 = PPt[i];
                        P2 = PPt[i];
                    }
                }
            }
        }

        if (j == -1)
        {
            CPU = CPU + 1;
            continue;
        }
        else
        {
            waitingTime[ATi] = CPU - ATt[ATi];
            CPU = CPU + bursttime[ATi];
            turnaroundTime[ATi] = CPU - ATt[ATi];
            ATt[ATi] = LAT + 10;
            j = -1;
            PPt[ATi] = MAX_P + 1;
            ATi = 0;        // Pointing to Arrival Time index
            P1 = MAX_P + 1; // Pointing to 1st priority Value
            P2 = MAX_P + 1; // Pointing to 2nd priority Value
            NoP = NoP - 1;
        }
    }

    cout << "\nProcess_Number\tBurst_Time\tPriority\tArrival_Time\tWaiting_Time\tTurnaround_Time\n\n";
    for (i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << "\t\t" << bursttime[i] << "\t\t" << priority[i] << "\t\t" << arrivaltime[i] << "\t\t" << waitingTime[i] << "\t\t" << turnaroundTime[i] << endl;
    }

    float AvgWT = 0;  // Average waiting time
    float AVGTaT = 0; // Average Turn around time
    for (i = 0; i < n; i++)
    {
        AvgWT = waitingTime[i] + AvgWT;
        AVGTaT = turnaroundTime[i] + AVGTaT;
    }

    cout << "Average waiting time = " << AvgWT / n << endl;
    cout << "Average turnaround time = " << AVGTaT / n << endl;
}

// C++ Implementation of Preemptive Priority Scheduling Algorithm
struct process
{
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    int start_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
};

void PREEMPTIVE()
{

    int n;
    struct process p[100];
    float avg_turnaround_time;
    float avg_waiting_time;
    float avg_response_time;
    float cpu_utilisation;
    int total_turnaround_time = 0;
    int total_waiting_time = 0;
    int total_response_time = 0;
    int total_idle_time = 0;
    float throughput;
    int burst_remaining[100];
    int is_completed[100];
    memset(is_completed, 0, sizeof(is_completed));

    cout << setprecision(2) << fixed;

    cout << "Enter the number of processes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter arrival time of process " << i + 1 << ": ";
        cin >> p[i].arrival_time;
        cout << "Enter burst time of process " << i + 1 << ": ";
        cin >> p[i].burst_time;
        cout << "Enter priority of the process " << i + 1 << ": ";
        cin >> p[i].priority;
        p[i].pid = i + 1;
        burst_remaining[i] = p[i].burst_time;
        cout << endl;
    }

    int current_time = 0;
    int completed = 0;
    int prev = 0;

    while (completed != n)
    {
        int idx = -1;
        int mx = -1;
        for (int i = 0; i < n; i++)
        {
            if (p[i].arrival_time <= current_time && is_completed[i] == 0)
            {
                if (p[i].priority > mx)
                {
                    mx = p[i].priority;
                    idx = i;
                }
                if (p[i].priority == mx)
                {
                    if (p[i].arrival_time < p[idx].arrival_time)
                    {
                        mx = p[i].priority;
                        idx = i;
                    }
                }
            }
        }

        if (idx != -1)
        {
            if (burst_remaining[idx] == p[idx].burst_time)
            {
                p[idx].start_time = current_time;
                total_idle_time += p[idx].start_time - prev;
            }
            burst_remaining[idx] -= 1;
            current_time++;
            prev = current_time;

            if (burst_remaining[idx] == 0)
            {
                p[idx].completion_time = current_time;
                p[idx].turnaround_time = p[idx].completion_time - p[idx].arrival_time;
                p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;
                p[idx].response_time = p[idx].start_time - p[idx].arrival_time;

                total_turnaround_time += p[idx].turnaround_time;
                total_waiting_time += p[idx].waiting_time;
                total_response_time += p[idx].response_time;

                is_completed[idx] = 1;
                completed++;
            }
        }
        else
        {
            current_time++;
        }
    }

    int min_arrival_time = 10000000;
    int max_completion_time = -1;
    for (int i = 0; i < n; i++)
    {
        min_arrival_time = min(min_arrival_time, p[i].arrival_time);
        max_completion_time = max(max_completion_time, p[i].completion_time);
    }

    avg_turnaround_time = (float)total_turnaround_time / n;
    avg_waiting_time = (float)total_waiting_time / n;
    avg_response_time = (float)total_response_time / n;
    cpu_utilisation = ((max_completion_time - total_idle_time) / (float)max_completion_time) * 100;
    throughput = float(n) / (max_completion_time - min_arrival_time);

    cout << endl
         << endl;

    cout << "#P\t"
         << "AT\t"
         << "BT\t"
         << "PRI\t"
         << "ST\t"
         << "CT\t"
         << "TAT\t"
         << "WT\t"
         << "RT\t"
         << "\n"
         << endl;

    for (int i = 0; i < n; i++)
    {
        cout << p[i].pid << "\t" << p[i].arrival_time << "\t" << p[i].burst_time << "\t" << p[i].priority << "\t" << p[i].start_time << "\t" << p[i].completion_time << "\t" << p[i].turnaround_time << "\t" << p[i].waiting_time << "\t" << p[i].response_time << "\t"
             << "\n"
             << endl;
    }
    cout << "Average Turnaround Time = " << avg_turnaround_time << endl;
    cout << "Average Waiting Time = " << avg_waiting_time << endl;
    cout << "Average Response Time = " << avg_response_time << endl;
    cout << "CPU Utilization = " << cpu_utilisation << "%" << endl;
    cout << "Throughput = " << throughput << " process/unit time" << endl;
}

/*

AT - Arrival Time of the process
BT - Burst time of the process
ST - Start time of the process
CT - Completion time of the process
TAT - Turnaround time of the process
WT - Waiting time of the process
RT - Response time of the process

Formulas used:

TAT = CT - AT
WT = TAT - BT
RT = ST - AT

*/

// Program Execution begins from the main function
int main()
{

    system("cls");
    int choice;
    cout << "Program By Bhaskar Anand 2K20/CO/121" << endl
         << endl;
    cout << "Enter your choice\n 1. Preemptive Priority Schedling\n 2. Non- Preemptive Priority Scheduling" << endl;
    cin >> choice;

    system("cls");
    if (choice == 1)
    {
        PREEMPTIVE();
    }
    else if (choice == 2)
    {
        NONPREEMPTIVE();
    }

    return 0;
}