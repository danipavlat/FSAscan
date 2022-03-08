/*
 *		Dani Pavlat
 *		03/06/2022
 *		CMP SCI 4280
 *
 *		token.h:
 *			header file containing the FSA table used by the scanner
 *			as well as the necessary column, state, and token enums
 *
 */

#ifndef TOKEN_H
#define TOKEN_H

#define NUM_STATES 27		// state array length
#define NUM_COLS 25			// column array length
#define NUM_TOKENS 29		// num token strings (+2 to align with state enum)
#define NUM_KEYWORDS 17		// total number of keywords

#define ERROR -1			// flag for errors
#define FINAL 200			// flag for final state

typedef struct Token {
	char * token;		// token string
	char * tokenType;	// token type
	int lineNum;		// line number
} Token;

typedef enum {
	s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14, s15,
	s16, s17, s18, s19, s20, s21, s22, s23, s24, s25, s26, s27
} state;

typedef enum {
	EOFch, underscore, lowercase, uppercase, digit, equals, lessThan,
	greaterThan, exclamation, colon, plus, minus, asterisk, forwardSlash,
	modulo, period, leftParen, rightParen, comma, leftBrace, rightBrace,
	semicolon, leftBracket, rightBracket, other
} col;

typedef enum {
	fEOF = 200, fId, fInt, fEq, fDeq, fLtE = 206,
	fGte = 208, fNe = 210, fCo, fCoE, fAdd,
	fSub, fMul, fDiv, fMod, fDot, fLpar,
	fRpar, fCom, fLbr, fRbr, fSco,
	fLbrk, fRbrk, fKey
} finalVals;

extern int FSA_Table [NUM_STATES] [NUM_COLS];

// tokenIDs adjusted to match state index
extern char * tokenIDs [NUM_TOKENS];

extern char * keywords [NUM_KEYWORDS];

#endif
