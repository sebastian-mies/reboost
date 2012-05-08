//-----------------------------------------------------------------------------
// Part of reboost (http://reboost.org).  Released under the
// BSD 2-clause license (http://www.opensource.org/licenses/bsd-license.php).
// Copyright 2012, Sebastian Mies <mies@reboost.org> --- All rights reserved.
//-----------------------------------------------------------------------------

#include "tlv.hpp"
#include "tlv_list.hpp"

namespace reboost {

using namespace std;


// nil tlv
const tlv_t tlv_t::nil;
const tlv_t tlv_t::truetlv(tlv_t::TRUE,0,"");
const tlv_t tlv_t::falsetlv(tlv_t::FALSE,0,"");


ostream& operator<<(ostream& os, const tlv_t& tlv) {
	switch (tlv.type()) {
	case tlv_t::TEXT: {
		os << "\"";
		for (size_t i=0; i<tlv.size(); i++) os << (const char)tlv[i];
		return os << "\"";
	}
	case tlv_t::SINT:
	case tlv_t::UINT:
	case tlv_t::VINTPOS: {
		uintmax_t value = 0;
		for (size_t i=0; i<tlv.size(); i++) value |= tlv[i]<<(i*8);
		if (tlv.type()==tlv_t::SINT && tlv[tlv.size()-1] >= 0x80) {
			for (size_t i=tlv.size(); i<sizeof(uintmax_t); i++) value |= 0xFF << (i*8);
			intmax_t neg = value;
			return os << neg;
		} else
			return os << value;
	}
	case tlv_t::VINTNEG: {
		uintmax_t value = 0;
		for (size_t i=0; i<tlv.size(); i++) value |= tlv[i]<<(i*8);
		return os << "-" << value;
	}
	case tlv_t::FLOAT: {
		if (tlv.size() == sizeof(float)) {
			float f; memcpy(&f, tlv.data(), sizeof(float));
			return os << f;
		} else
		if (tlv.size() == sizeof(double)) {
			double f; memcpy(&f, tlv.data(), sizeof(double));
			return os << f;
		} else
			return os << "<FLOAT UNKNOWN>";
	}
	case tlv_t::ARRAY:
	case tlv_t::LIST: {
		tlv_list list = tlv_list::unpacki(tlv.type(), tlv);
		return os << list;
	}

	default: {
		return os << "(type="<< tlv.type()
				<< ":" << static_cast<const buffer_t>(tlv) << ")";
	}
	}
}



}




