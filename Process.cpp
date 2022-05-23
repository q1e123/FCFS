#include "Process.h"

std::string Process::get_name() const
{
	return name;
}

void Process::set_name(const std::string& name)
{
	this->name = name;
}

double Process::get_start_time() const
{
	return startTime;
}

void Process::set_start_time(const double start_time)
{
	startTime = start_time;
}
