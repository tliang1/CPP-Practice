#include "Stopwatch.h"

Stopwatch::Stopwatch() : start_time(0), running(false), elapsed_time(0.0) {}

bool Stopwatch::is_running() const
{
	return running;
}

void Stopwatch::start() 
{
	if (!running) 
	{
		running = true;
		start_time = clock();
	}
}

void Stopwatch::stop() 
{
	if (running) 
	{
		clock_t stop_time = clock();
		running = false;

		elapsed_time += static_cast<double>((stop_time - start_time)) / CLOCKS_PER_SEC;
	}
}

double Stopwatch::elapsed() const 
{
	return elapsed_time;
}

double Stopwatch::lap() 
{
	stop();
	double l_time = elapsed_time - lap_time;
	lap_time = elapsed_time;
	start();
	return l_time;
}

void Stopwatch::reset() 
{
	running = false;
	elapsed_time = 0.0;
	lap_time = 0.0;
}