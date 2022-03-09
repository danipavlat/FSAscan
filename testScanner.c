/*
 *		Dani Pavlat
 *		03/07/2022
 *		CMP SCI 4280
 *
 *		testScanner.c:
 *			contains a testing driver for the scanner program
 *			prints token details with each call to the scanner
 *
 */

#include <stdio.h>
#include "scanner.h"
#include "token.h"

void testScanner() {
	Token token;

	printf("Now starting scanner:\n\n");
	while (!feof(fInput)) {
		token = scanner();
		printf("%s token '%s' on line %d\n", token.tokenType, token.token, lineNum);
	}
	// end of file
	token.tokenType = tokenIDs[fEOF - 200];
	token.lineNum = lineNum;
	printf("%s token on line %d\n", token.tokenType, lineNum);

	printf("\nScanning complete. Now terminating.\n");
};
