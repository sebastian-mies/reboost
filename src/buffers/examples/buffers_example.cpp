//-----------------------------------------------------------------------------
// Part of reboost (http://reboost.org).  Released under the
// BSD 2-clause license (http://www.opensource.org/licenses/bsd-license.php).
// Copyright 2012, Sebastian Mies <mies@reboost.org> --- All rights reserved.
//-----------------------------------------------------------------------------

#include <iostream>
#include <ctype.h>

using namespace std;

#include "../buffers.hpp"

using namespace reboost;

int main() {
	message_t m = (shared_buffer_t("Hello") + "World");
	cout << m << endl;
	m.push_back("Hello again!");
	message_t cm = m;
	cout << m << endl;
	return 0;
}
