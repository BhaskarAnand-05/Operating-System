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
    // Calculating the Completion Time of the processes
    completion_time[0] = 0;

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

    // Displaying the Ouput of the Processes
    system("cls");
    cout << "\t\t\t\t First- Come, First-Served (FCFS) Scheduling" << endl
         << endl;

    cout << "Process"
         << "\t\t\t\t\t"
         << "Burst Time"
         << "\t\t\t\t\t"
         << "Completion Time"
         << "\t\t\t\t\t"
         << "Waiting Time" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "Process [" << i + 1 << "]\t\t\t\t" << burst_time[i] << "\t\t\t\t\t\t  " << completion_time[i] << "\t\t\t\t\t\t" << waiting_time[i] << endl;
    }

    return 0;
}

// End of the Program