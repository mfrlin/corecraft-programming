#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "shirostr.h"

/* empty shiro string */
struct sstr* ss_alloc() {

	struct sstr *sstrp;
	sstrp = malloc(sizeof(struct sstr));
	if (!sstrp) {
		return 0;
	}

	sstrp->textp = malloc(sizeof(char) * 10);
	if (!sstrp->textp) {
        return 0;
    }
	*(sstrp->textp) = '\0';

	sstrp->len = 0;
	sstrp->size = 10;

	return sstrp;
}

/* shiro string from c string */
struct sstr* ss_alloc_cstring(const char *cstring) {
	struct sstr *sstrp;
	sstrp = malloc(sizeof(struct sstr));
	if (!sstrp) {
		return 0;
	}
	int len = strlen(cstring);
	sstrp->textp = malloc(sizeof(char) * (len + 1));
	if (!sstrp->textp) {
        return 0;
    }

	strcpy(sstrp->textp, cstring);

	sstrp->len = len;
	sstrp->size = len + 1;

	return sstrp;
}

int ss_grow(struct sstr* sstrp) {
	size_t new_size = ceil(sstrp->size * GROWTH_FACTOR);
	char *new_textp = realloc(sstrp->textp, new_size);
	if(!new_textp) {
		return 0;
	}
	if (new_textp != sstrp->textp) {
		sstrp->textp = new_textp;
	}
	sstrp->size = new_size;
	return 1;
}

/* free shiro string */
void ss_free(struct sstr* sstrp) {
	free(sstrp->textp);
	free(sstrp);
}

/*
* everything else:
*/

/* 	Note: most functions here return an int, to indicate
	success or error. See the test code for usage. */

/* intuitively: shiro_str = c_string */
int ss_set_cstring(struct sstr* sstrp, const char* cstring) {
	int len = strlen(cstring);
	while (sstrp->size < len + 1) {
		if (!ss_grow(sstrp)) {
			return 0;
		}
	}
	strcpy(sstrp->textp, cstring);
	sstrp->len = len;

	return 1;
}

/* intuitively: shiro_str = shiro_str */
int ss_set(struct sstr* sstrp_dest, const struct sstr* sstrp_source) {
	int len = ss_strlen(sstrp_source);
	while (sstrp_dest->size < len + 1) {
		if (!ss_grow(sstrp_dest)) {
			return 0;
		}
	}

	strcpy(sstrp_dest->textp, sstrp_source->textp);
	sstrp_dest->len = len;

	return 1;
}

/* intuitively: shiro_str += shiro_str */
int ss_concat(struct sstr* sstrp_dest, const struct sstr* sstrp_source) {
	int len = ss_strlen(sstrp_source);
	while (sstrp_dest->size < sstrp_dest->len + len + 1) {
		if (!ss_grow(sstrp_dest)) {
			return 0;
		}
	}

	strcat(sstrp_dest->textp, sstrp_source->textp);
	sstrp_dest->len += len;

	return 1;
}

/* intuitively: shiro_str += c_string */
int ss_concat_cstring(struct sstr* sstrp, const char* cstring) {
	int len = strlen(cstring);
	while (sstrp->size < sstrp->len + len + 1) {
		if (!ss_grow(sstrp)) {
			return 0;
		}
	}

	strcat(sstrp->textp, cstring);
	sstrp->len += len;

	return 1;
}

/* should work the same as strcmp for c strings */
int ss_cmp(const struct sstr* sstrp_a, const struct sstr* sstrp_b) {
	return strcmp(sstrp_a->textp, sstrp_b->textp);
}

/* 	deletes from pos to pos+len, shifting what's behind
	pos+len (the tail) down to pos */
int ss_delete(struct sstr* sstrp, size_t pos, size_t len) {
	if (sstrp->len < pos + len) {
		return 0;
	}

	for (pos; *(sstrp->textp + pos) = *(sstrp->textp + pos + len); pos++)
		;

	return 1;
}

/* get a pointer to the raw c string */
const char* ss_cstring(const struct sstr* sstrp) {
	return sstrp->textp;
}

/* get the length of the string */
size_t ss_strlen(const struct sstr* sstrp) {
	return sstrp->len;
}