/*
Background:
this kata is sort of educational too so, it you don't want to learn go away!
CPU scheduling is a process which allows one process to use the CPU while the execution of another process is on hold (or in waiting state) due to unavailability of any resource like I/O etc, thereby making full use of CPU.
The aim of CPU scheduling is to make the system efficient, fast and fair.read more about scheduling in operating system

Non-Preemptive Scheduling:
Under non-preemptive scheduling, once the CPU has been allocated to a process, the process keeps the CPU until it releases the CPU either by terminating or by switching to the waiting state.
Preemptive Scheduling
In this type of Scheduling, the tasks are usually assigned with priorities. At times it is necessary to run a certain task that has a higher priority before another task although it is running. 
Therefore, the running task is interrupted for some time and resumed later when the priority task has finished its execution.
Scheduling Algorithms
To decide which process to execute first and which process to execute last to achieve maximum CPU utilisation, you will implement these algorithms in follow-up series, they are
First Come First Serve(FCFS) Scheduling (current kata)
Shortest-Job-First(SJF) Scheduling (Non Pre-emptive)
Shortest-Job-First(SJF) Scheduling (Pre-emptive)
Priority Scheduling (Non Pre-emptive)
Priority Scheduling (Pre-emptive)
Round Robin(RR) Scheduling
Multilevel Queue Scheduling
Multilevel Feedback Queue Scheduling
Task: First Come First Serve(FCFS) Scheduling
Input:
Implement a function fcfs with given processes processes(vector) which consist of arrival time and burst time as single pair for each process and given processes will be sorted by arrival time.(i.e [Arrival time, Burst time]). 
(No two processes will have the same arrival time)
Terms:
As the name suggests, the process which arrives first, gets executed first, or we can say that the process which requests the CPU first, gets the CPU allocated first. (just like FIFO if you will)

Arrival time : Point of time at which process enters into ready queue (or ram).
Burst Time : Time duration required by process to get executed on CPU.
Completion Time : Point of time at which process completes it's execution.
Response Time : RT = Time at which the CPU starts the execution of the process - Arrival Time
Turn Around Time : total time taken by process to get executed (including waiting time and all), formula : TAT = Completion TIme - Arrival Time
Waitng Time : WT = Turn Around Time (total time) - Burst Time(useful time)
Throughput : Throughput means the efficiency of the scheduling algo that is the average "useful time" (time where the CPU is actually used) per process.
Note: for the current task, RT and WT are actually the very same value.

General Steps:
CPU locates very first process arrived in ready queue and start executing it and complete it;s execution depending upon Burst time of that process and if there;s 
no process arrived in ready queue then CPU have to wait until next process arrives in ready queue. (NOTE: note various timing to get expected output (see example below))
Start again for next process in ready queue.
Output:
Return Average Completion Time, Average Turn Around Time, Average Waiting Time and Throughput in vector (A-CT, A-TAT, A-WT, Throughput) all rounded to two decimal places.
*/


double round2decimal(double x){
	x = x * 100;
	x = round(x);
	return x / 100;
	
}



std::vector<double> fcfs(const std::vector<std::pair<int, int>> &processes){
	// Initializing variables
	int T = 0;
	int All_TAT = 0;
	int All_WT = 0;
	int All_CT = 0;
	int Throughput = 0;
	int num_of_jobs = 0;
	// Begin iterations on the jobs
	for(auto it = processes.begin(); it != processes.end(); ++it){
		// Update number of jobs
		num_of_jobs++;
		// Update time
		if(it -> first > T){
			T = it -> first;
		}
		// handle a job
		int TAT = T + it->second - it -> first; // Calc TAT for job
		int WT = TAT - it->second; // Calc WT for job
		T = T + it->second; // Update time
		
		// By this point the job has been completed
		
		All_TAT += TAT;
		All_WT += WT;
		All_T += T;
		Throughput += it->second;
	}
	std::vector <double> ret{(double)(round2decimal(All_CT/num_of_jobs)), (double)(round2decimal(All_TAT/num_of_jobs)), (double)(round2decimal(All_WT/num_of_jobs)),(double)Throughput};
	return ret;	
}