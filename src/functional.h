/* Copyright © 2016 Andrey Bova. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla
 * Public License, v. 2.0. If a copy of the MPL was not distributed
 * with this file, You can obtain one at http://mozilla.org/MPL/2.0/.*/
#ifndef FUPIC_FUNCTIONAL_H_
#define FUPIC_FUNCTIONAL_H_

#include <stdint.h>
#include <stddef.h>
#include "sugar.h"

#define func_function(N, T, R) R    (N)(T)
#define func_consumer(N, T)    void (N)(T)
#define func_predicate(N, T)   int  (N)(T)
#define $(RET, CODE) ({ RET lambda_anon_name CODE } lambda_anon_name; })

typedef void* func_t;
typedef void* any_t;
typedef char* string;

#define data(NAME, FIELDS)  												\
	struct _data_##NAME {													\
		FIELDS																\
	};																		\
	typedef struct _data_##NAME* NAME; 										\
	NAME NAME##_construct() { return malloc(sizeof(struct _data_##NAME)); }	\

#define instance_functor(TYPE, IMPL) 					\
	void fmap_##TYPE (void* func, TYPE arg) { IMPL }
#define instance_show(TYPE, IMPL) 						\
	string show_##TYPE (TYPE arg) { IMPL }
#define instance_read(TYPE, IMPL)						\
	TYPE read_##TYPE (TYPE container, const string const str) { IMPL }

struct _func_partial_t {
	void*   func;
	void**  args;
	size_t  argc;
};

typedef struct _func_partial_t func_partial_t;

void apply_partial_func(func_partial_t function, void** args, size_t argc);

#endif
