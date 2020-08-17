# Group Members
## 1.Sumaio Abdullahi Rage (1713874).
## 2.Hamid Mashal (1824220).
## 3.Furqan Said Hassan(1724546).

# Introduction
CPU Scheduling is a process of determining which process will use the CPU for execution while another process waits. One of CPU scheduling’s aims is to make the system efficient, fast, and fair amongst tasks. The main task of CPU scheduling is to ensure that the Operating System will select one of the processes available in the ready queue for execution which will be carried out by the CPU scheduler whenever the CPU remains idle. There are two types of CPU scheduling which are pre-emptive and non-pre-emptive. However, for this project, our focus is going to be on non-preemptive scheduling and the Algorithms that we chose were SJF (Shortest Job First) and Priority Scheduling. 


# Consideration
We have considered that the algorithms we choose must be non-preemptive scheduling because the class in the process has to be ended first so we can let another class start.  Hence non-preemptive scheduling would work better for the class scheduling as it will let the classes not be interrupted halfway. We also considered that the average waiting time and turnaround time should be less thus SJF would be the best choice for that, as it will let the classes with the shorter period to be started first so they do not have to wait for long.

# Analysis
Below is an analysis of the three algorithms we used FCFS, SJF and Priority Scheduling 

## FCFS
FCFS just like how the name suggests is based on the concept of First come First Serve where it puts the process requests in a queue and executes it one by one just like how a queue would work in real-life situations. Eventually, each process will get a chance to run, so that starvation doesn’t occur. Whereas when you compare it with SJF, the shortest processes are executed first and then followed by longer processes. Lastly for Priority-based scheduling, the priority of a process is based on memory requirement, time requirement, or user preference.
So the class duration doesn’t matter only the order in which the classes are matters.
Hence our results for the scheduling are 
The Average waiting time = 2.66667 
The Average turnaround time = 4.66667


## SJF
For SJF the shortest processes are executed first and then followed by the longer process so the order of the processes doesn’t matter here nor does the memory and time requirement as it does for FCFS and Priority Scheduling respectively. SJF throughput is increased because more processes can be executed in less amount of time. However, longer processes will have a larger waiting time, as eventually, they’ll suffer starvation whereas for FCFS and starvation doesn’t occur.
So the class with the shortest duration time will be served first as in SJF the class duration does matter
Hence our results for the scheduling are 
The Average waiting time = 1.33333  
The Average turnaround time= 3.33333
Comparing this algorithm with the other algorithms, it produced more satisfying results with a lesser average waiting time and average turnaround time.


## Priority Schedulling
Priority Scheduling, the priority of a process can be determined by the requirements of memory and time or the user preference. So in our case priority would be given to the class duration which is the most so for the average turnaround time and average waiting time it has the similar result of FCFS approximately 4.66667 and 2.66667 respectively 


