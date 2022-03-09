/*
 *		Dani Pavlat
 *	 	03/06/2022
 *	 	CMP SCI 4280
 *
 *	 	scanner.c:
 * 			embedded scanner program - scans the input
 * 			stream for a valid token in the given
 * 			course programming language (returning a single
 * 			token each time it is called)
 *
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "errors.h"
#include "scanner.h"
#include "token.h"

int getCol(char currentChar, char * tokenStr);
char filter(char currentChar);

FILE * fInput;		// input file
int lineNum = 1;	// line counter
int isEOF;			// EOF flag (initially false)
int inComment;		// comments flag (initially false)

Token scanner() {

	Token token;				// full token details
	char * tokenStr = "";		// token string
	char currentChar = '\0';	// current character
	int currentState = s1;		// current state
	int currentCol;				// current column

	isEOF = 0;			// EOF flag (initially false)
	inComment = 0;		// comments flag (initially false)

	tokenStr = (char*) malloc(sizeof(char) * 8);
	do {
		currentChar = fgetc(fInput);

		// handle comments, whitespace, newlines
		do {
			currentChar = filter(currentChar);
		} while (currentChar == '#' || currentChar == ' '
				|| currentChar == '\t' || currentChar == '\n');

		// get the column index based on character
		currentCol = getCol(currentChar, tokenStr);
		// set state to the next in table
		currentState = FSA_Table[currentState][currentCol];
		if (currentState < 200) {
			// add current char to token string (allocating memory first)
			strncat(tokenStr, &currentChar, 1);
		}
		// repeats until a final state is reached
	} while (currentState < 200);

	// final state
	if (currentState == fId) {
		// if token is an identifier
		if (strlen(tokenStr) > 9) {
			invalidStringLengthError();
		}
		int i;
		for (i = 0; i < NUM_KEYWORDS; i++) {
			if ( strcmp(tokenStr, keywords[i]) == 0 ) {
				// string is a keyword
				currentState = fKey;
			}
		}
	}

	token.token = tokenStr;
	token.tokenType = tokenIDs[currentState - 200];
	token.lineNum = lineNum;

	return token;
}

char filter(char currentChar) {
	// skips over whitespace, comments, newlines
	char lookAhead = '\0';		// next character

	// handle comments
	if (currentChar == '#') {
		// check next character for valid comment (##)
		lookAhead = fgetc(fInput);
		if (lookAhead == '#') {
			inComment = 1;		// set comment flag to true
			lookAhead = '\0';	// reset lookAhead
			while (lookAhead != '#') {
				// move through chars until comment is closed
				lookAhead = fgetc(fInput);
			}
			if (fgetc(fInput) != '#') {
				// comment not closed property
				invalidCommentError();
			}
			// return the next char after closed comment
			return fgetc(fInput);
		} else {
			// just one # encountered, outside of comment
			invalidCharError();
		}

	} else if (currentChar == ' ' || currentChar == '\t') {
		// handle whitespace
		do {
			lookAhead = fgetc(fInput);
		} while (lookAhead == ' ' || currentChar == '\t');
	} else if (currentChar == '\n') {
		// handle newlines
		do {
			lineNum++;
			lookAhead = fgetc(fInput);
		} while (lookAhead == '\n');
	}

	if (lookAhead == '\0') {
		return currentChar;
	}
	return lookAhead;
};

int getCol(char currentChar, char * tokenStr) {
	// checks character against FSA table to get current col
	if (currentChar == EOF) {
		isEOF = 1;
		return EOFch;
	} else if (currentChar == '_') {
		// only valid char if first in token
		if ( strcmp(tokenStr, "") == 0 ) {
			return underscore;
		}
	} else if ( isalpha(currentChar) > 0 ) {
		if ( islower(currentChar) > 0 ) {
			return lowercase;
		}
		return uppercase;
	} else if ( isdigit(currentChar) > 0 ) {
		return digit;
	} else if (currentChar == '=') {
		return equals;
	} else if (currentChar == '<') {
		return lessThan;
	} else if (currentChar == '>') {
		return greaterThan;
	} else if (currentChar == '!') {
		return exclamation;
	} else if (currentChar == ':') {
		return colon;
	} else if (currentChar == '+') {
		return plus;
	} else if (currentChar == '-') {
		return minus;
	} else if (currentChar == '*') {
		return asterisk;
	} else if (currentChar == '/') {
		return forwardSlash;
	} else if (currentChar == '%') {
		return modulo;
	} else if (currentChar == '.') {
		return period;
	} else if (currentChar == '(') {
		return leftParen;
	} else if (currentChar == ')') {
		return rightParen;
	} else if (currentChar == ',') {
		return comma;
	} else if (currentChar == '{') {
		return leftBrace;
	} else if (currentChar == '}') {
		return rightBrace;
	} else if (currentChar == ';') {
		return semicolon;
	} else if (currentChar == '[') {
		return leftBracket;
	} else if (currentChar == ']') {
		return rightBracket;
	}
	return other;
};
