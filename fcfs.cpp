/* Simple C++ program for implementation 
of FCFS scheduling */

#include<bits/stdc++.h>
using namespace std;
struct Process 
{ 
// course code
   int ccode;
//class duration
   int duration; 
//prefered arrival time
   int arrival_time; 
};
bool sortArrivalTime(Process a, Process b)
{
	return (a.arrival_time < b.arrival_time);

}
 
// function to find the waiting time for all processes
void findWaitingTime(Process proc[], int n, int wt[])
{
    // waiting time for first process will be 0
    wt[0] = 0;
 
    // calculating waiting time
    for (int i = 1; i < n ; i++)
    {
        wt[i] =  proc[i-1].duration + wt[i-1];
    }
}
 
// function to calculate turn around time
void findTurnAroundTime(Process proc[], int n, int wt[], int tat[])
{
    // calculating turnaround time by adding
    // bt[i] + wt[i]
    for (int i = 0; i < n ; i++)
    {
        tat[i] = proc[i].duration + wt[i];
    }
}
 
// function to calculate average time
void findAverageTime(Process proc[], int n)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
 
    // function to find waiting time of all processes
    findWaitingTime(proc, n,wt);
 
    // function to find turn around time for all processes
    findTurnAroundTime(proc, n, wt, tat);
 
    // display processes along with all details
    cout << " Course code  "<< " Arrival time "<<" Duration "<<" Waiting time " << " Turn around time\n";
 
    // calculate total waiting time and total turn around time
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << proc[i].ccode<<"\t\t" <<proc[i].arrival_time <<"\t\t" << proc[i].duration<<"\t    "<< wt[i] <<"\t\t  " << tat[i] <<endl;
    }
 
    cout << "Average waiting time = "<< (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "<< (float)total_tat / (float)n;
}
 
// main function
int main()
{
    // process ids
    
    Process proc[] = {{2201,3,1}, {3401, 2,2}, {1103, 1,3}};
    int n = sizeof proc / sizeof proc[0];
 
    // sorting classes by arrival time.
    sort(proc, proc + n, sortArrivalTime);
    
    findAverageTime(proc, n);
    
    return 0;
}
