#pragma once
#include <ostream>
#include <string>
class Process
{
public:
	Process(const std::string& name, double start_time, double completionTime)
		: name(name),
		  startTime(start_time),
		  completionTime(completionTime)
	{
	}

	std::string get_name() const;
	void set_name(const std::string& name);
	double get_start_time() const;
	void set_start_time(const double start_time);

	friend bool operator<(const Process& lhs, const Process& rhs)
	{
		return lhs.startTime > rhs.startTime;
	}

	friend bool operator<=(const Process& lhs, const Process& rhs)
	{
		return !(rhs < lhs);
	}

	friend bool operator>(const Process& lhs, const Process& rhs)
	{
		return rhs < lhs;
	}

	double get_completion_t_ime() const;
	void set_completion_t_ime(const double completion_t_ime);

	friend std::ostream& operator<<(std::ostream& os, const Process& obj)
	{
		return os
			<< "name: " << obj.name
			<< " startTime: " << obj.startTime
			<< " completionTime: " << obj.completionTime;
	}

private:
	std::string name;
	double startTime;
	double completionTime;
};

