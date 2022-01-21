#include "Headerfile.h"
// Headerfile.h contains all the required Header File

// Program Execution begins from the main function
int main()
{
    system("cls");
    int process[100];
    int n;
    int burst_time[100], waiting_time[100], completion_time[100];

    cout << endl
         << "Enter the No. of Processes to be executed through CPU" << endl
         << endl;
    cin >> n;

    // Taking Inputs according to the arrival time of the processes
    cout << "Enter the Burst Time for the Processes" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Process [" << i + 1 << "] :-\t";
        cin >> burst_time[i];
        cout << endl;
    }
    // Calculating the Turn_Around Time of the processes
    completion_time [-1] = 0;

    for (int i = 0; i < n; i++)
    {
        completion_time[i] = completion_time[i - 1] + burst_time[i];
    }
    // Calculating the Waiting Time of the processes
    waiting_time[0] = 0;
    for (int i = 1; i < n; i++)
    {
        waiting_time[i] = completion_time[i - 1];
    }

    // Displaying the (Ouput) Average Waiting Time of the Processes
    system("cls");
    cout << "\t\t\t\t First- Come, First-Served (FCFS) Scheduling" << endl
         << endl;

    cout << "Process"
         << "\t\t\t\t\t"
         << "Burst Time"
         << "\t\t\t\t\t"
         << "Turnaround Time"
         << "\t\t\t\t\t"
         << "Waiting Time" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "Process [" << i + 1 << "]\t\t\t\t" << burst_time[i] << "\t\t\t\t\t\t  " << completion_time[i] << "\t\t\t\t\t\t" << waiting_time[i] << endl;
    }
    // Calculating Average Waiting Time For the Problem
    float Average_Waiting_Time = 0;

    cout << "\n\nAverage Waiting Time = \t"
         << "Sum of Waiting time for all Processes / Total No. of Process" << endl<<endl<<endl;

    cout << "Average Waiting Time = \t [" ;
    for (int i = 0; i < n - 1; i++)
    {
        cout << waiting_time[i] << " + ";
    }
    cout<< waiting_time[n-1] << "] /"<<n;

    for (int i = 0; i < n; i++)
    {
        Average_Waiting_Time += waiting_time[i];
    }

    cout << endl
         << "Average Waiting Time = \t" << Average_Waiting_Time/n;

    return 0;
}

// End of the Program