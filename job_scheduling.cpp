#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a job
struct Job {
    int start, finish, profit;
};
 
// Comparator function to sort jobs by finish time
bool compareJobs(Job a, Job b) {
    return a.finish < b.finish;
}

// Greedy function to schedule jobs
vector<int> scheduleJobs(vector<Job>& jobs) {
    // Sort jobs by finish time
    sort(jobs.begin(), jobs.end(), compareJobs);

    vector<int> schedule;
    int n = jobs.size();
    int lastFinish = 0;

    // Iterate through the sorted jobs
    for (int i = 0; i < n; i++) {
        // If the current job doesn't overlap with the last scheduled job 
        if (jobs[i].start >= lastFinish) {
            schedule.push_back(i);
            lastFinish = jobs[i].finish;
        }
    }

    return schedule;
}

int main() {
    vector<Job> jobs = {
        {1, 2, 50},
        {3, 5, 20},
        {6, 19, 100},
        {2, 100, 200}
    };

    vector<int> schedule = scheduleJobs(jobs);

    cout << "Jobs scheduled: ";
    for (int i : schedule) {
        cout << "(" << jobs[i].start << ", " << jobs[i].finish << ", " << jobs[i].profit << ") ";
    }
    cout << endl;

    return 0;
}