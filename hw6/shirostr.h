/*
* file: 				shirostr.h
* comment: 				the shiro string library
* prefix on functions: 	ss_
* extra note:
* 	implementations of all functions should be in
* 	shirostr.c, which is for you to provide!
*/
#ifndef SHIRO_STR_H
#define SHIRO_STR_H

#include <stddef.h>

/* TODO: figure out how much
you want your string to grow,
try to keep a balance that assures
not too many reallocs, but not
too much wasted memory */
#define GROWTH_FACTOR 1.2

struct sstr { 
	char *textp;
	size_t len;
	size_t size;
};

/*
* creating and destroying:
*/

/* empty shiro string */
struct sstr* ss_alloc();

/* shiro string from c string */
struct sstr* ss_alloc_cstring(const char*);

/* 	allocate a new shiro str that is a copy of
	the parameter */
struct sstr* ss_alloc_ss(const struct sstr*);

/* free shiro string */
void ss_free(struct sstr*);

/*
* everything else:
*/

/* 	Note: most functions here return an int, to indicate
	success or error. See the test code for usage. */

/* intuitively: shiro_str = c_string */
int ss_set_cstring(struct sstr*, const char*);

/* intuitively: shiro_str = shiro_str */
int ss_set(struct sstr*, const struct sstr*);

/* intuitively: shiro_str += shiro_str */
int ss_concat(struct sstr*, const struct sstr*);

/* intuitively: shiro_str += c_string */
int ss_concat_cstring(struct sstr*, const char*);

/* should work the same as strcmp for c strings */
int ss_cmp(const struct sstr*, const struct sstr*);

/* 	deletes from pos to pos+len, shifting what's behind
	pos+len (the tail) down to pos */
int ss_delete(struct sstr*, size_t pos, size_t len);

/* get a pointer to the raw c string */
const char* ss_cstring(const struct sstr*);

/* get the length of the string */
size_t ss_strlen(const struct sstr*);

#endif