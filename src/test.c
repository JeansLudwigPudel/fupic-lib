#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "functional.h"
#include "data/maybe.h"

instance_show(int, 
	char* str = malloc(sizeof(char)*12); //painful leak
	sprintf(str, "%d", arg);
	return str;)

maybe(int)

instance_read(maybe_int, 
	int num = 0;
	if (sscanf(str, "%d", &num) == 1) {
		container get just    = num;
		container get nothing = 0;
		return container;
	} else {
		container get nothing = 1;
		container get just	  = 0;
		return container;
	});
	

int main(void) {
	maybe_int maybe = maybe_int_construct();
	maybe get just = 3;
	read_maybe_int(maybe, "41");
	fmap_maybe_int($(int, (int x) _l return x + 1;), maybe);
	puts(show_maybe_int(maybe));
	read_maybe_int(maybe, "not readable");
	puts(show_maybe_int(maybe));
	return 0;
}
