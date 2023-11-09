init [%]
point [.]
dolar [$]
digit [0-9]
letter [A-Za-z]
arg_number [[:digit:]]+$
flag ([-#0+'])*
width {[1-9]}([[:digit:]])*
modifier  (.hh.|h|l|.ll.|L|j|t|z|q|v|.vh.|.hv.|.vl.|.lv.|.vll.|.llv.)
type (c|s|p|d|i|u|x|X|%)
arg {digit}+{dolar}
precision {point}({digit})+  
%%

{arg} printf(" arg number %s\n", yytext);
{flag}{type} printf(" flagged type  %s\n", yytext);
{precision} printf(" precision %s\n", yytext);
{modifier} printf(" modifier %s\n", yytext);
{type} printf(" only type %s\n", yytext);
%%
//functions

//{init}({arg})*({flag})*({width})*({precision})*({modifier})*{type} printf(" Full format %s\n", yytext);
