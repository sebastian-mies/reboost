
#include <cstdio>
#include <iostream>

#include "buffer.hpp"

std::ostream& operator<<( std::ostream& os, const buffer_t& buf ) {
	os << "{";
	for (unsigned i=0; i<(buf.size()/8)+1; i++) {
		if (i!=0) os << ",";
		os << "[";
		for (unsigned j=0; j<8; j++) {
			if ((i*8+j) < buf.size()) {
				if (j!=0) os << " ";
				char str[8];
				int v = buf.data()[i*8+j];
				sprintf(str,"%02x", v);
				os << str;
			}
		}
		os << "|";
		for (unsigned j=0; j<8; j++) {
			if (i*8+j < buf.size()) {
				char c = buf.data()[i*8+j];
				if (c<32) c='.';
				os << c;
			}
		}
		os <<"]";
	}
	os << "}";
	return os;
}
