#pragma once
#include <string>
class Process
{
public:
	Process(const std::string& name, double start_time)
		: name(name),
		  startTime(start_time)
	{
	}

	std::string get_name() const;
	void set_name(const std::string& name);
	double get_start_time() const;
	void set_start_time(const double start_time);
private:
	std::string name;
	double startTime;
};

