#include "message.hpp"
#include<iostream>

struct to_stream {
	std::ostream& os;
	int i;
	inline void operator()(buffer_t buf) {
		if (i!=0) os <<",";
		os << buf;
		i++;
	}
};

std::ostream& operator<<(std::ostream& os, const message_t m) {
	struct to_stream ts = { os, 0 };
	os << "message({size=" << m.size() << ",buffers=" << (int) m.length()
			<< ",hash=" << m.hash() << "},";
	m.foreach(ts);
	os << ")";
	return os;
}
