/* Copyright © 2016 Andrey Bova. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla
 * Public License, v. 2.0. If a copy of the MPL was not distributed
 * with this file, You can obtain one at http://mozilla.org/MPL/2.0/.*/
#ifndef FUPIC_MAYBE_H_
#define FUPIC_MAYBE_H_

#include "../functional.h"

#define maybe(TYPE) 														\
	data(maybe_##TYPE, TYPE just; int8_t nothing;)							\
																			\
	instance_functor(maybe_##TYPE,  										\
		if (not arg->nothing) 												\
			arg get just = ((TYPE (*)(TYPE))func)(arg get just);) 			\
																			\
	instance_show(maybe_##TYPE, 											\
		if (not arg->nothing) 												\
			return show_##TYPE(arg->just); 									\
		else 																\
			return "nothing";)												

#endif
