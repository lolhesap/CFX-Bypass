#pragma once
#include "common.hpp"

class trace
{
public:
	void setup();
};

inline std::unique_ptr<trace> g_trace;