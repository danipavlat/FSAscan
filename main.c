/*
 *	 	Dani Pavlat
 * 		03/06/2022
 * 		CMP SCI 4280
 *
 * 		main.c:
 * 			calls scanner.c to scan input for legitimate tokens
 * 			in the course's given programming language
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "scanner.h"

FILE * fInput;		// input file
int lineNum;		// line counter
int isEOF;			// EOF flag (initially false)
int inComment;		// comments flag (initially false)

int main (int argc, char* argv[]) {
	char * inFile;	// input filename

	// check for valid command line arguments
	if (argc > 2) {
		errno = 7;
		perror("ERROR");
		printf("\nUSAGE: \n"
				"scanner \t\t reads from the keyboard until simulated EOF (CTRL + D)\n"
				"scanner < somefile \t same as above but redirecting from somefile instead of keyboard\n"
				"scanner somefile \t reads from somefile.sp2022\n");
		return 1;
	} else if (argc == 2) {
		// allocates space for input filename + file extension
		inFile = malloc(strlen(argv[1]) + strlen(".sp2022") + 1);
		// adds file extension ".sp2022" to input filename, then opens
		strcpy(inFile, argv[1]);
		strcat(inFile, ".sp2022");
		fInput = freopen(inFile, "r", stdin);

		// verify input file exists
		if (fInput == NULL) {
			perror("ERROR");
			return 1;
		}
	} else if(argc == 1) {
		// get input from user to be scanned
		char inChar;
		printf("KEYBOARD INPUT: USE CTRL + D TO STOP WRITING\n");
		FILE * temp = fopen("temp.txt", "w");
		inChar = getc(stdin);

		while (inChar != EOF) {
			fprintf(temp, "%c", inChar);
			inChar = getc(stdin);
		}
		fclose(temp);

		fInput = freopen("temp.txt", "r", stdin);
		if(fInput == NULL) {
			perror("ERROR");
			exit(EXIT_FAILURE);
		}
	} else {
		// Usage: scanner or scanner < xxx.sp2022
		fInput = stdin;
	}

	// verify file is not empty
	if (feof(fInput)) {
		printf("ERROR: input file can not be empty.");
		exit(EXIT_FAILURE);
	}

	// call testScanner to retrieve tokens one at a time
	testScanner();

	fclose(fInput);

	return 0;
}
