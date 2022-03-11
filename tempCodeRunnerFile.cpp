
        // according to its size ad assign to it
        for (int i = 0; i < n; i++)
        {
            // Find the best fit block for current process
            int wstIdx = -1;
            for (int j = 0; j < m; j++)
            {
                if (blockSize[j] >= processSize[i])
                {
                    if (wstIdx == -1)
                        wstIdx = j;
                    else if (blockSize[wstIdx] < blockSize[j])
                        wstIdx = j;
                }
            }

            // If we could find a block for current process
            if (wstIdx != -1)
            {
                // allocate block j to p[i] process
                allocation[i] = wstIdx;

                // Reduce available memory in this block.
                blockSize[wstIdx] -= processSize[i];
            }
        }

        cout << "\nProcess No.\tProcess Size\tBlock no.\n";
        for (int i = 0; i < n; i++)
        {
            cout << " " << i + 1 << "\t\t" << processSize[i] << "\t\t";
            if (allocation[i] != -1)
                cout << allocation[i] + 1;
            else
                cout << "Not Allocated";
            cout << endl;
        }
    }

// Program Execution begins from the main function
int main()
{
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);

    system("cls");
    int choice;
    cout << "Program By Bhaskar Anand 2K20/CO/121" << endl
         << endl;
    cout << "Enter your choice\n 1. First-Fit Algorithm \n 2. Best-Fit Algorithm \n 3. Worst-Fit Algorithm" << endl;
    cin >> choice;
    
    system("cls");
    if (choice == 1)
    {
        FirstFit(blockSize, m, processSize, n);
    }
    else if (choice == 2)
    {
        BestFit(blockSize, m, processSize, n);
    }

    else if (choice == 3)
    {
        WorstFit(blockSize, m, processSize, n);
    }

    return 0;
}



