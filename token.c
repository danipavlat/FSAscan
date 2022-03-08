/*
 *		Dani Pavlat
 *		03/06/2022
 *		CMP SCI 4280
 *
 *		token.c:
 *			variable definitions for FSA table used by the scanner
 *
 */

#include "token.h"

int FSA_Table [NUM_STATES] [NUM_COLS] = {
/*			  			EOF	 	_		a-z		A-Z		0-9		=		<		>		!		:		+		-		*		/		%		.		(		)		,		{		}		;		[		]		other	*/
/* s1	EOFtk	*/	{	fEOF,	s2,		s2,		ERROR,	s3,		s4,		s6,		s8,		s10,	s12,	s14,	s15,		s16,		s17,		s18,		s19,		s20,		s21,		s22, 	s23,		s24,		s25,		s26,		s27,		ERROR	},
/* s2	ID_tk	*/	{	fId,	fId,	s2,		s2,		s2,		fId,	fId,	fId,	fId,	fId,	fId,	fId,		fId,		fId,		fId,		fId,		fId,		fId,		fId,		fId,		fId,		fId,		fId,		fId,		fId		},
/* s3	int_tk	*/	{	fInt,	fInt,	fInt,	fInt,	s3,		fInt,	fInt,	fInt,	fInt,	fInt,	fInt,	fInt,	fInt,	fInt,	fInt,	fInt,	fInt,	fInt,	fInt,	fInt,	fInt,	fInt,	fInt,	fInt,	fInt		},
/* s4	=tk		*/	{	fEq,	fEq,	fEq,	fEq,	fEq,	s5,		fEq,	fEq,	fEq,	fEq,	fEq,	fEq,		fEq,		fEq,		fEq,		fEq,		fEq,		fEq,		fEq,		fEq,		fEq,		fEq,		fEq,		fEq,		fEq		},
/* s5	==tk		*/	{	fDeq,	fDeq,	fDeq,	fDeq,	fDeq,	fDeq,	fDeq,	fDeq,	fDeq,	fDeq,	fDeq,	fDeq,	fDeq,	fDeq,	fDeq,	fDeq,	fDeq,	fDeq,	fDeq,	fDeq,	fDeq,	fDeq,	fDeq,	fDeq,	fDeq		},
/* s6	<		*/	{	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	s7,		ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR	},
/* s7	<=tk		*/	{	fLtE,	fLtE,	fLtE,	fLtE,	fLtE,	fLtE,	fLtE,	fLtE,	fLtE,	fLtE,	fLtE,	fLtE,	fLtE,	fLtE,	fLtE,	fLtE,	fLtE,	fLtE,	fLtE,	fLtE,	fLtE,	fLtE,	fLtE,	fLtE,	fLtE		},
/* s8	>		*/	{	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	s9,		ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR	},
/* s9	>=tk		*/	{	fGte,	fGte,	fGte,	fGte,	fGte,	fGte,	fGte,	fGte,	fGte,	fGte,	fGte,	fGte,	fGte,	fGte,	fGte,	fGte,	fGte,	fGte,	fGte,	fGte,	fGte,	fGte,	fGte,	fGte,	fGte		},
/* s10	!		*/	{	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	s11,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR	},
/* s11	!=tk		*/	{	fNe,	fNe,	fNe,	fNe,	fNe,	fNe,	fNe,	fNe,	fNe,	fNe,	fNe,	fNe,		fNe,		fNe,		fNe,		fNe,		fNe,		fNe,		fNe,		fNe,		fNe,		fNe,		fNe,		fNe,		fNe		},
/* s12	:tk		*/	{	fCo,	fCo,	fCo,	fCo,	fCo,	s13,	fCo,	fCo,	fCo,	fCo,	fCo,	fCo,		fCo,		fCo,		fCo,		fCo,		fCo,		fCo,		fCo,		fCo,		fCo,		fCo,		fCo,		fCo,		fCo		},
/* s13	:=tk		*/	{	fCoE,	fCoE,	fCoE,	fCoE,	fCoE,	fCoE,	fCoE,	fCoE,	fCoE,	fCoE,	fCoE,	fCoE,	fCoE,	fCoE,	fCoE,	fCoE,	fCoE,	fCoE,	fCoE,	fCoE,	fCoE,	fCoE,	fCoE,	fCoE,	fCoE		},
/* s14	+tk		*/	{	fAdd,	fAdd,	fAdd,	fAdd,	fAdd,	fAdd,	fAdd,	fAdd,	fAdd,	fAdd,	fAdd,	fAdd,	fAdd,	fAdd,	fAdd,	fAdd,	fAdd,	fAdd,	fAdd,	fAdd,	fAdd,	fAdd,	fAdd,	fAdd,	fAdd		},
/* s15	-tk		*/	{	fSub,	fSub,	fSub,	fSub,	fSub,	fSub,	fSub,	fSub,	fSub,	fSub,	fSub,	fSub,	fSub,	fSub,	fSub,	fSub,	fSub,	fSub,	fSub,	fSub,	fSub,	fSub,	fSub,	fSub,	fSub		},
/* s16	*tk		*/	{	fMul,	fMul,	fMul,	fMul,	fMul,	fMul,	fMul,	fMul,	fMul,	fMul,	fMul,	fMul,	fMul,	fMul,	fMul,	fMul,	fMul,	fMul,	fMul,	fMul,	fMul,	fMul,	fMul,	fMul,	fMul		},
/* s17	/tk		*/	{	fDiv,	fDiv,	fDiv,	fDiv,	fDiv,	fDiv,	fDiv,	fDiv,	fDiv,	fDiv,	fDiv,	fDiv,	fDiv,	fDiv,	fDiv,	fDiv,	fDiv,	fDiv,	fDiv,	fDiv,	fDiv,	fDiv,	fDiv,	fDiv,	fDiv		},
/* s18	%tk		*/	{	fMod,	fMod,	fMod,	fMod,	fMod,	fMod,	fMod,	fMod,	fMod,	fMod,	fMod,	fMod,	fMod,	fMod,	fMod,	fMod,	fMod,	fMod,	fMod,	fMod,	fMod,	fMod,	fMod,	fMod,	fMod		},
/* s19	.tk		*/	{	fDot,	fDot,	fDot,	fDot,	fDot,	fDot,	fDot,	fDot,	fDot,	fDot,	fDot,	fDot,	fDot,	fDot,	fDot,	fDot,	fDot,	fDot,	fDot,	fDot,	fDot,	fDot,	fDot,	fDot,	fDot		},
/* s20	(tk		*/	{	fLpar,	fLpar,	fLpar,	fLpar,	fLpar,	fLpar,	fLpar,	fLpar,	fLpar,	fLpar,	fLpar,	fLpar,	fLpar,	fLpar,	fLpar,	fLpar,	fLpar,	fLpar,	fLpar,	fLpar,	fLpar,	fLpar,	fLpar,	fLpar,	fLpar	},
/* s21	)tk		*/	{	fRpar,	fRpar,	fRpar,	fRpar,	fRpar,	fRpar,	fRpar,	fRpar,	fRpar,	fRpar,	fRpar,	fRpar,	fRpar,	fRpar,	fRpar,	fRpar,	fRpar,	fRpar,	fRpar,	fRpar,	fRpar,	fRpar,	fRpar,	fRpar,	fRpar	},
/* s22	,tk		*/	{	fCom,	fCom,	fCom,	fCom,	fCom,	fCom,	fCom,	fCom,	fCom,	fCom,	fCom,	fCom,	fCom,	fCom,	fCom,	fCom,	fCom,	fCom,	fCom,	fCom,	fCom,	fCom,	fCom,	fCom,	fCom		},
/* s23	{tk		*/	{	fLbr,	fLbr,	fLbr,	fLbr,	fLbr,	fLbr,	fLbr,	fLbr,	fLbr,	fLbr,	fLbr,	fLbr,	fLbr,	fLbr,	fLbr,	fLbr,	fLbr,	fLbr,	fLbr,	fLbr,	fLbr,	fLbr,	fLbr,	fLbr,	fLbr		},
/* s24	}tk		*/	{	fRbr,	fRbr,	fRbr,	fRbr,	fRbr,	fRbr,	fRbr,	fRbr,	fRbr,	fRbr,	fRbr,	fRbr,	fRbr,	fRbr,	fRbr,	fRbr,	fRbr,	fRbr,	fRbr,	fRbr,	fRbr,	fRbr,	fRbr,	fRbr,	fRbr		},
/* s25	;tk		*/	{	fSco,	fSco,	fSco,	fSco,	fSco,	fSco,	fSco,	fSco,	fSco,	fSco,	fSco,	fSco,	fSco,	fSco,	fSco,	fSco,	fSco,	fSco,	fSco,	fSco,	fSco,	fSco,	fSco,	fSco,	fSco		},
/* s26	[tk		*/	{	fLbrk,	fLbrk,	fLbrk,	fLbrk,	fLbrk,	fLbrk,	fLbrk,	fLbrk,	fLbrk,	fLbrk,	fLbrk,	fLbrk,	fLbrk,	fLbrk,	fLbrk,	fLbrk,	fLbrk,	fLbrk,	fLbrk,	fLbrk,	fLbrk,	fLbrk,	fLbrk,	fLbrk,	fLbrk	},
/* s27	]tk		*/	{	fRbrk,	fRbrk,	fRbrk,	fRbrk,	fRbrk,	fRbrk,	fRbrk,	fRbrk,	fRbrk,	fRbrk,	fRbrk,	fRbrk,	fRbrk,	fRbrk,	fRbrk,	fRbrk,	fRbrk,	fRbrk,	fRbrk,	fRbrk,	fRbrk,	fRbrk,	fRbrk,	fRbrk,	fRbrk	}
};

// tokenIDs adjusted to match state index
char * tokenIDs [NUM_TOKENS] = {
	"EOF", "identifier", "integer", "equals", "doubleEquals", "", "lessThanOrEqual",
	"", "greaterThanOrEqual", "", "notEqual", "colon", "colonEqual", "addition",
	"subtraction", "multiplication", "division", "modulo", "dot", "leftParenthesis",
	"rightParenthesis", "comma", "leftBrace", "rightBrace", "semicolon",
	"leftBracket", "rightBracket", "keyword"
};

char * keywords [NUM_KEYWORDS] = {
	"start", "stop", "repeat", "until", "whole", "label", "quit", "listen", "yell",
	"main", "portal", "if", "then", "pick", "declare", "assign", "proc"
};
