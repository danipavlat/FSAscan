/*
 *		Dani Pavlat
 *		03/06/2022
 *		CMP SCI 4280
 *
 *		scanner.h:
 *			header file variables + structs necessary
 *			to scan input for valid tokens
 *
 */

#ifndef SCANNER_H
#define SCANNER_H

#include "token.h"

extern FILE * fInput;		// input file
extern int lineNum;			// line counter
extern int isEOF;			// EOF flag (initially false)
extern int inComment;		// comments flag (initially false)

Token scanner();
void testScanner();

#endif
