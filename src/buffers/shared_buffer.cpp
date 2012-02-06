#include "shared_buffer.hpp"
#include <iostream>

using namespace std;

void shared_buffer_t::onexit() {
	if (allocated_buffers != 0) cerr << "shared_buffer_t: "
			<< allocated_buffers << " leaked buffers." << endl;
}

size_t shared_buffer_t::init() {
	atexit(&shared_buffer_t::onexit);
	return 0;
}

size_t shared_buffer_t::allocated_buffers = init();
