#include "Headerfile.h"

int main()
{
    int n;
    int num[n];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    int a = num[0];
    int b = num[n];

    sort(a, b);
    for (int i = 0; i < n; i++)
    {
        cout << num[i] << endl;
    }

    return 0;
}

