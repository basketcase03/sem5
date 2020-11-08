%{
#include<stdio.h>
#include<math.h>
int yylex();
void yyerror(char *s;);
%}
%union
{double p;}
%token<p>num

%left '+''-'
%left '*''/'
%left '('')'
%nonassoc uminu
%type<p>exp
%%

ss: exp {printf(" Answer is=%g\n",$1);};

exp : exp'+'exp		{$$=$1+$3;}
	| exp'-'exp	{$$=$1-$3;}
	| exp'*'exp	{$$=$1*$3;}
	| exp'/'exp	{if($3==0)
			{ printf("Divide by Zero");}
			else $$=$1/$3;
			}
	|'-'exp		{$$=-$2;}
	|'('exp')'	{$$=$2;}
	|num		{$$=$1;}
;

%%

void main()
{
	do
	{
	printf("\n Enter expression: ");
	yyparse();
	}
	while(1);
}

void yyerror(char *s;)
{
printf("Syntax error");
}

