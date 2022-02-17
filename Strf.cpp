#include "Headerfile.h"
#include <chrono>
#include <thread>

using namespace std;
using namespace this_thread;     // sleep_for, sleep_until
using namespace chrono_literals; // ns, us, ms, s, h, etc.
using chrono::system_clock;

void pressEnterToContinue()
{
    // This prompts the user to press "ENTER" to continue
    while (1)
    {
        string str = "%%%%%%%%%%%%%   PRESS ANY KEY TO CONTINUE    %%%%%%%%%%%%%%";
        cout << str;
        sleep_until(system_clock::now() + 0.25s); // wait a quarter-second
        cout << string(str.length(), '\b');       // delete printed line
        // repeat
        str += ".";
        cout << str;
        sleep_until(system_clock::now() + 0.25s); // wait a quarter-second
        cout << string(str.length(), '\b');       // delete printed line
        // repeat
        str += ".";
        cout << str;
        sleep_until(system_clock::now() + 0.25s); // wait a quarter-second
        cout << string(str.length(), '\b');       // delete printed line
        // repeat
        str += ".";
        cout << str;
        sleep_until(system_clock::now() + 0.25s); // wait a quarter-second
        cout << string(str.length(), '\b');       // delete printed line
        if (cin.get())
            break;
    }
    cin.ignore();
}

void strf()
{
    int a[10], b[10], x[10];
    int waiting[10], turnaround[10], completion[10];
    int i, j, smallest, count = 0, time, n;
    double avg = 0, tt = 0, end;
    
    cout << endl
         << "\t\tSortest Time Remaining First (SRTF) Scheduling" << endl;
    cout << "\n Enter the number of Processes:-\t";
    cin >> n;
    system("cls");
    cout << endl
         << "\t\tSortest Time Remaining First (SRTF) Scheduling" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << endl
             << "Enter the Details for Process " << i + 1 << endl
             << endl;
        cout << "Arrival Time:";
        cin >> a[i];
        cout << endl
             << "Burst Time:";
        cin >> b[i];
        cout << "-------------------------------------------------------------------------------------------";
    }

    system("cls");

    cout << endl
         << "\t\tSortest Time Remaining First (SRTF) Scheduling" << endl;
    for (i = 0; i < n; i++)
        x[i] = b[i];

    b[9] = 9999;
    for (time = 0; count != n; time++)
    {
        smallest = 9;
        for (i = 0; i < n; i++)
        {
            if (a[i] <= time && b[i] < b[smallest] && b[i] > 0)
                smallest = i;
        }
        b[smallest]--;

        if (b[smallest] == 0)
        {
            count++;
            end = time + 1;
            completion[smallest] = end;
            waiting[smallest] = end - a[smallest] - x[smallest];
            turnaround[smallest] = end - a[smallest];
        }
    }
    cout << "Process"
         << "\t"
         << "Burst-time"
         << "\t"
         << "Arrival-time"
         << "\t"
         << "Waiting-time"
         << "\t"
         << "Turnaround-time"
         << "\t\t"
         << "Completion-time" << endl;
    for (i = 0; i < n; i++)
    {
        cout << "p" << i + 1 << "\t\t" << x[i] << "\t\t" << a[i] << "\t\t" << waiting[i] << "\t\t" << turnaround[i] << "\t\t" << completion[i] << endl;
        avg = avg + waiting[i];
        tt = tt + turnaround[i];
    }
    cout << "\n\nAverage waiting time =" << avg / n;
    cout << "  Average Turnaround time =" << tt / n << endl;
}

int main()
{
    system("cls");
    cout << "\t\tThis program belongs to BHASKAR ANAND 2K20/CO/121" << endl;
    cout << endl
         << "\t\tSortest Time Remaining First (SRTF) Scheduling" << endl;
    cout << "\t\t1. Preemptive" << endl
         << endl;
    pressEnterToContinue();

    system("cls");

    strf();

    return 0;
}
