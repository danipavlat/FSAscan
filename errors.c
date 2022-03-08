/*
 *		Dani Pavlat
 *		03/07/2022
 *		CMP SCI 4280
 *
 *		errors.c:
 *			contains functions for error handling
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "scanner.h"

void invalidCommentError() {
	printf("ERROR - line %d: comments must start and end with '##'", lineNum);
	exit(EXIT_FAILURE);
};

void invalidCharError() {
	printf("ERROR - line %d: invalid character", lineNum);
	exit(EXIT_FAILURE);
};

void invalidStringLengthError() {
	printf("Error - line %d: token strings can not exceed 8 characters in length", lineNum);
	exit(EXIT_FAILURE);
};
