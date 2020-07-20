#ifndef __UTIL_H__
#define __UTIL_H__

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#define die(...) { fprintf(stderr, __VA_ARGS__); exit(EXIT_FAILURE); }
#define ARRAY_INITIAL_SIZE 5

enum PNGMETA_OP {
	PNGMETA_OP_NONE,
	PNGMETA_OP_ADD_TEXT,
	PNGMETA_OP_DUMP_TEXT,
	PNGMETA_OP_REMOVE_TEXT
};

unsigned int
endianswap(unsigned int value)
{
	unsigned int b0, b1, b2, b3;
	unsigned int res;

	b0 = (value & 0x000000ff) << 24u;
	b1 = (value & 0x0000ff00) << 8u;
	b2 = (value & 0x00ff0000) >> 8u;
	b3 = (value & 0xff000000) >> 24u;

	res = b0 | b1 | b2 | b3;

	return res;
}

char*
getfilename(char* path)
{
	char* lastoccur = strrchr(path, '\\');
	if (lastoccur == NULL)
		lastoccur = strrchr(path, '/');
	if (lastoccur == NULL)
		return path;
	else
		return lastoccur;
}

char* custom_strdup(char* str)
{
	int slen = strlen(str);
	char* outstr = malloc((slen + 1) * sizeof(char));
	strncpy(outstr, str, slen);
	outstr[slen] = '\0';
	return outstr;
}
#endif