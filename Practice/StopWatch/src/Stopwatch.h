#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <ctime>

class Stopwatch {
	clock_t start_time = 0L;
	bool running;
	double elapsed_time = 0.0;
	double lap_time = 0.0;
public:
	Stopwatch();

	bool is_running() const;

	void start();
	void stop();

	double elapsed() const;
	double lap();

	void reset();
};

#endif