#ifndef __FUNCTIONAL_MACRO_ARG__
#define __FUNCTIONAL_MACRO_ARG__ 


/*concatenation*/
#define SNAKE(x, y) _SNAKE_(x, y) 
#define _SNAKE_(x, y) x##_##y

#define _SNAKE(x, y) __SNAKE__(x, y)
#define __SNAKE__(x, y) _##x##_##y


/*macro arguments work*/
#define ID(x) x
#define GET_FIRST(X, ...) 
#define SKIP(...)

#endif
