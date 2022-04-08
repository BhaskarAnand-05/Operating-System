#include "Headerfile.h"
using namespace std;

//FCFS Disk Scheduling Algorithm
void FCFS()
{

    int i, j, k, n, m, sum = 0, x, y, h;
    cout << "Enter the size of disk\n";
    cin >> m;
    cout << "Enter number of requests\n";
    cin >> n;
    cout << "Enter the requests\n";

    // creating an array of size n
    vector<int> a(n);
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (i = 0; i < n; i++)
    {
        if (a[i] > m)
        {
            cout << "Error, Unknown position " << a[i] << "\n";
            return ;
        }
    }
    cout << "Enter the head position\n";
    cin >> h;

    // head will be at h at the starting
    int temp = h;
    cout << temp;
    for (i = 0; i < n; i++)
    {
        cout << " -> " << a[i] << ' ';
        // calculating the difference for the head movement
        sum += abs(a[i] - temp);
        // head is now at the next I/O request
        temp = a[i];
    }
    cout << '\n';
    cout << "Total head movements = " << sum << '\n';
    
}

// Program Execution begins from the main function
int main()
{

    system("cls");
    int choice;
    cout << "Program By Bhaskar Anand 2K20/CO/121" << endl
         << endl;
    cout << "FCFS  Disk Scheduling Algorithm  " << endl;
    

    system("cls");
    FCFS();

    return 0;
}