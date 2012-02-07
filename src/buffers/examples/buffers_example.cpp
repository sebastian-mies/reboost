//-----------------------------------------------------------------------------
// Part  of  the  re:boost project  (http://reboost.org).  Released under the
// BSD 2-clause license (http://www.opensource.org/licenses/bsd-license.php).
// Copyright 2012, Sebastian Mies <mies@reboost.org>.    All rights reserved.
//-----------------------------------------------------------------------------

#include <iostream>
#include <ctype.h>

using namespace std;

#include "../buffers.hpp"

using namespace reboost;

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
