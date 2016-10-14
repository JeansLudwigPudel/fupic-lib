/* Copyright © 2016 Andrey Bova. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla
 * Public License, v. 2.0. If a copy of the MPL was not distributed
 * with this file, You can obtain one at http://mozilla.org/MPL/2.0/.*/

#include "functional.h"

void apply_partial_func(func_partial_t function, void** args, size_t argc) {
	size_t i;
	void* all[function.argc + argc];

	for (i = 0; i < function.argc; i++)
		all[i] = *(function.args + i);
	for (i = 0; i < argc; i++)
		all[i + function.argc] = *(args + i);
	argc += function.argc;

	asm("movq (%%rax), %%rdi;"
	    "decq %%rbx;"
		"jz   .skip;"
		"movq 8(%%rax), %%rsi;"
		"decq %%rbx;"
		"jz   .skip;"
		"movq 16(%%rax), %%rdx;"
		"decq %%rbx;"
		"jz   .skip;"
		"movq 24(%%rax), %%rcx;"
		"decq %%rbx;"
		"jz   .skip;"
		"movq 32(%%rax), %%r8;"
		"decq %%rbx;"
		"jz   .skip;"
		"movq 40(%%rax), %%r9;"
		"decq %%rbx;"
		"jz   .skip;"
		"decq %%rbx;"
		".stack:"
		"pushq (%%rax, %%rbx);"
		"decq   %%rbx;"
		"js    .skip;"
		"jmp   .stack;"
		".skip:"
		"call *%2;"
		:
		: "a" (all), "b" (argc), "g" (function.func)
		: "rdi", "rsi", "rdx", "rcx", "r8", "r9");
}
