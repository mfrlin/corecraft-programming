#include <stdlib.h>
#include "shirostr.h"

/* empty shiro string */
struct sstr* ss_alloc() {

	struct sstr *sstrp;
	sstrp = malloc(sizeof(struct sstr));
	if (!sstrp) {
		return 0;
	}

	sstrp->textp = malloc(sizeof(char));
	if (!sstrp->textp) {
        return 0;
    }
	*(sstrp->textp) = '\0';

	sstrp->len = 0;

	return sstrp;
};