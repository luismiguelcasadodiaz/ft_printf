digit [0-9]
letter [A-Za-z]
arg_number [[:digit:]]+$
flag [-#0+']
width [[:digit:]]+
precision .[[:digit:]]+
modifier  (hh|h|l|ll|L|j|t|z|q|v|vh|hv|vl|lv|vll|llv)
type (c|s|p|d|i|u|x|X|%)
%%

{letter}({letter}|{digit})*  printf(" identificador %s\n", yytext);

%%
//functions

