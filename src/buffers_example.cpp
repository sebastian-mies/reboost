//============================================================================
// Name        : newbuffers.cpp
// Author      : Sebastian Mies
// Version     :
// Copyright   : Institut für Telematik, Universität Karlsruhe
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <ctype.h>

using namespace std;

#include "buffers.hpp"

int main() {
	shared_buffer_t b1 = "Hallo";
	b1.mutable_data()[0]='W';
	b1 = b1 + " Welt!";
	cout << b1 << endl;

	message_t m = (shared_buffer_t("Hello") + "World");
	cout << m << endl;
	m.push_back("of mine");
	message_t cm = m;
	cout << m << endl;

	return 0;
}
