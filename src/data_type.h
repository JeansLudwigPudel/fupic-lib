/* Copyright © 2016 Andrey Bova. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla
 * Public License, v. 2.0. If a copy of the MPL was not distributed
 * with this file, You can obtain one at http://mozilla.org/MPL/2.0/.*/
#ifndef __FUNCTIONAL_DATA_TYPE__
#define __FUNCTIONAL_DATA_TYPE__

//#include "stdint.h"
#include "util/macro.h"

/* Format of data type description:
 * 
 * Name       
 * Constructor
 * Empty constructor
 * Instance
 *
 */

/* 
 * Utilitarian macroses
 *
 * GET_DATA_NAME(D)           -- substitute by given description's name
 * APPLY_TO_DATA_*(D, ACTION) -- apply macro-action to given 
 *                               description's fields
 *
 */
#define GET_DATA_NAME(D)                      D(ID, SKIP, SKIP, SKIP)
#define APPLY_TO_DATA_NAME(D, ACTION)         D(ACTION, SKIP, SKIP, SKIP)
#define APPLY_TO_DATA_CONSTR(D, ACTION)       D(SKIP, ACTION, SKIP, SKIP)
#define APPLY_TO_DATA_EMPTY_CONSTR(D, ACTION) D(SKIP, SKIP, ACTION, SKIP)
#define APPLY_TO_DATA_INSTANCE(D, ACTION)     D(SKIP, SKIP, SKIP, DESCR)


/*
 * Macro generators
 *
 */
#define GEN_DATA_CONSTR(DATA_NAME, DATA_ARGS)                               \
    struct DATA_NAME {                                                      \
        DATA_ARGS                                                           \
    };

#define GEN_DATA_CONSTR_STATE( DATA_NAME)                                   \
    

/*
 * General data_type generator
 */
#define DATA_TYPE(DESCR)                                                    \
    struct _SNAKE(data, GET_DATA_NAME(DESCR)) {                             \
        APPLY_TO_DATA_CONSTR(DESCR, GEN_DATA_CONSTR)\
        enum {                                                              \
            APPLY_TO_DATA_EMPTY_CONSTR(DESCR, GEN_DATA_CONSTR_STATE)        \
        } state;                                                            \
    };                                                                      \

#endif

