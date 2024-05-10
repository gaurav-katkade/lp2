#include <iostream>
using namespace std;

void JobScheduling(int jobs[][3], int n)
{
    // sorting according to profits
    // and simultaneously finding max deadline
    int maxD = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        // for max deadline
        if (maxD < jobs[i][0])
        {
            maxD = jobs[i][0];
        }

        // for sorting
        for (int j = i+1; j <n; j++) {
        if (jobs[i][1] < jobs[j][1]) {
            int tempD = jobs[j][0];
            int tempP = jobs[j][1];
            jobs[j][0] = jobs[i][0];
            jobs[j][1] = jobs[i][1];
            jobs[i][0] = tempD;
            jobs[i][1] = tempP;
        }
     }
    }

   for (int i = 0; i < n; i++)
    {
       
        cout<<jobs[i][0]<<jobs[i][1]<<"\n";
        
    }
    // creating array upto max deadline
    int ans[maxD];
    // intitalize it with -1;
    for (int j = 0; j < maxD; j++)
    {
        ans[j] = -1;
    }

    // sequencing jobs according to profit and within deadline
    for (int k = 0; k < n; k++)
    {
        for (int m = maxD; m >= 0; m--)
        {
            // if job deadline is withing limit and no other max profit job has taken place then only allocate the job
            if (m < jobs[k][0] && ans[m] == -1)
            {
                ans[m] = jobs[k][1]; // we are storing profit
            }
        }
    }

    // print the answer, we are printing profits of that job as output
    for (int h = 0; h < maxD; h++)
    {
        cout << ans[h] << " ";
    }
}

int main()
{
    int n;
    cout << "Enter number of Jobs : ";
    cin >> n;

    int jobs[n][3];
    for (int i = 0; i < n; i++)
    {
        cout << "\nFor job " << (i + 1) << ": ";
        cout << "Enter deadline :";
        cin >> jobs[i][0];
        cout << "Enter profit : ";
        cin >> jobs[i][1];
    }

    JobScheduling(jobs, n);
}