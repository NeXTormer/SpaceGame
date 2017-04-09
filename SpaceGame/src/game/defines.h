#pragma once

#include <iostream>

#ifdef SP_DEBUG
	#define LOG(x)						std::cout << x << std::endl;
	#define LOG1(x, y)					printf(x, y);
	#define LOG2(x, spy1, y2)			printf(x, spy1, y2);
	#define LOG3(x, spy1, y2, y3)		printf(x, spy1, y2, y3);
	#define LOG4(x, spy1, y2, y3, y4)	printf(x, spy1, y2, y3, y4);
#else
	#define LOG(x)
	#define LOG1(x, y)
	#define LOG2(x, spy1, y2)
	#define LOG3(x, spy1, y2, y3)
	#define LOG4(x, spy1, y2, y3, y4)
#endif
