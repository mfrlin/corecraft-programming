#include "shirostr.h"
#include <stdio.h>

int main(void) {
	struct sstr *a;
	struct sstr *b;

	a = ss_alloc_cstring("The shiro string");

	b = ss_alloc();
	ss_set_cstring(b, " works!");

	ss_concat_cstring(a, " library");
	ss_concat(a, b);
	ss_delete(a, 4, 6);

	printf("%s\n", ss_cstring(a));

	ss_free(a);
	ss_free(b);
	
	return 0;
}