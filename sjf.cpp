//SJF
#include <bits/stdc++.h> 
using namespace std; 
  
struct Process
{
   int ccode;     // course code
   int duration;      // class duration
   int arrival_time;   //prefered arrival time
};
  
// Function for finding the waiting time for all processes 

void findWaitingTime(Process proc[], int n, int wt[]) 
{ 
    int rt[n]; 
  
    // Copy the burst time into rt[] 
    for (int i = 0; i < n; i++) 
        rt[i] = proc[i].duration; 
  
    int complete = 0, t = 0, minm = INT_MAX; 
    int shortest = 0, finish_time; 
    bool check = false; 
  
  
    // Process until all processes gets completed 
    while (complete != n) { 
  
        /* Find process with minimum 
        remaining time among the 
        processes that arrives till the 
        current time`*/ 
        
        for (int j = 0; j < n; j++) { 
            if ((proc[j].arrival_time <= t) && 
            (rt[j] < minm) && rt[j] > 0) { 
                minm = rt[j]; 
                shortest = j; 
                check = true; 
            } 
        } 
  
        if (check == false) { 
            t++; 
            continue; 
        } 
  
        // Reduce remaining time by one 
        rt[shortest]--; 
  
        // Update minimum 
        minm = rt[shortest]; 
        if (minm == 0) 
            minm = INT_MAX; 
  
        // If a process gets completely executed 
        if (rt[shortest] == 0) { 
  
            // Increment complete 
            complete++; 
            check = false; 
  
            // Find finish time of current process 
            
            finish_time = t + 1; 
  
            // Calculate waiting time 
            
            wt[shortest] = finish_time - 
                        proc[shortest].duration - 
                        proc[shortest].arrival_time; 
  
            if (wt[shortest] < 0) 
                wt[shortest] = 0; 
        } 
        
        // Increment time 
        t++; 
    } 
} 
  
// Function for calculating turn around time 
void findTurnAroundTime(Process proc[], int n, int wt[], int tat[]) 
{ 
    // calculating turnaround time by adding  bt[i] + wt[i]
	 
    for (int i = 0; i < n; i++) 
        tat[i] = proc[i].duration + wt[i]; 
} 
  
// Function to calculate average time 
void findavgTime(Process proc[], int n) 
{ 
    int wt[n], tat[n], total_wt = 0, 
                    total_tat = 0; 
  
    // Function for finding the waiting time of all processes 
    findWaitingTime(proc, n, wt); 
  
    // Function for finding turn around time for all processes 
    findTurnAroundTime(proc, n, wt, tat); 
  
    // Display processes along with all details 
   cout << "Course code  " << "Arrival Time  "
        << " Duration  "<< " Waiting time  " 
		<< " Turn around time\n";
        
    // Calculate total waiting time and 
    // total turnaround time 
    for (int i = 0; i < n; i++) { 
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i]; 
        cout << " " << proc[i].ccode << "\t\t"
		     << proc[i].arrival_time <<"\t\t"
             << proc[i].duration << "\t\t"
			 << wt[i] << "\t\t" << tat[i] << endl; 
    } 
  
    cout << "\nAverage waiting time = "
         << (float)total_wt / (float)n; 
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n; 
}

// Driver code 
int main() 
{ 
    Process proc[] = {{2201, 3, 1}, {3401, 2, 2}, {1103, 1, 3}};
    int n = sizeof(proc) / sizeof(proc[0]); 
  
    findavgTime(proc, n); 
    
    return 0;
}
