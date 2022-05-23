/*! \file FCFS
	\brief Main file

	Main file. Contains the algorithm and the reading phase.
*/


#include <iostream>

#include <queue>

#include "Process.h"

//! FCFS algorithm. All results (total execution time, total wait time, total idle time) are printed
/*!
  \param processQueue min-heap that contains processes
  \return void
*/

void firstComeFirstServed(std::priority_queue<Process> processQueue)
{
	double totalTime = 0;
	double totalWaitTime = 0;
	double totalIdleTime = 0;

	while (!processQueue.empty())
	{
		Process process = processQueue.top();
		processQueue.pop();
		std::cout << process << std::endl;
		double waitTime = 0;
		double idleTime = 0;
		if (process.get_start_time() > totalTime)
		{
			idleTime = process.get_start_time() - totalTime;
			totalIdleTime += idleTime;
		}
		else
		{
			waitTime = totalTime - process.get_start_time();
			totalWaitTime += waitTime;
		}
		totalTime += idleTime + waitTime + process.get_completion_t_ime();
	}

	std::cout << "Total execution time: " << totalTime << std::endl;
	std::cout << "Total wait time: " << totalWaitTime << std::endl;
	std::cout << "Total idle time: " << totalIdleTime << std::endl;
}

//! Function used to read processes.
/*!
  \return processQueue min-heap that contains processes
*/
std::priority_queue<Process> getProcessQueue()
{
	std::priority_queue<Process> processQueue;
	size_t numberOfProcesses;
	std::cout << "Number of processes: ";
	std::cin >> numberOfProcesses;
	for (int _ = 0; _ < numberOfProcesses; ++_)
	{
		double startTime, completionTime;
		std::string name;
		std::cout << "Name: ";
		std::cin >> name;
		std::cout << "Start time: ";
		std::cin >> startTime;
		std::cout << "Completion time: ";
		std::cin >> completionTime;
		Process process = Process(name, startTime, completionTime);
		processQueue.push(process);
	}
	return  processQueue;
}

//! Main function. Calles getProcessQueue and firstComeFirstServed.
/*!
  \return 0
*/
int main()
{
	std::priority_queue<Process> processQueue = getProcessQueue();
	firstComeFirstServed(processQueue);
	return 0;
}
