%token NUMBER ID NL
%left '+' '-'
%left '*' '/'

%%
stmt : exp NL { printf("value = %d\n",$1); exit(0);}
;
exp : exp '+' exp { $$=$1+$3; }
| exp '-' exp { $$=$1-$3; }
| exp '*' exp { $$=$1*$3; }
| exp '/' exp { if($3==0)
{
printf("Cannot divide by 0");
exit(0);
}
else
$$=$1/$3;
}
| '(' exp ')' { $$=$2; }
| ID { $$=$1; }
| NUMBER { $$=$1; }
;
%%

int yyerror(char *msg)
{
printf("Invalid Expression\n");
exit(0);
}

main ()
{
printf("Enter the expression\n");
yyparse();
}