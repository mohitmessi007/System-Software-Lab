%{
#include<stdio.h>
int lines=0, words=0, characters=0, num=0,spaces=0, spl_char=0;
%}
%%

\n { lines++; words++;}
[' '] {words++; spaces++; }
[A-Za-z0-9] characters++;
. spl_char++;
%%

main(void)
{
yyin= fopen("myfile.txt","r");
yylex();
printf(" This File contains ...");
printf("\n\t%d lines", lines);
printf("\n\t%d words",words);
printf("\n\t%d characters", characters);
printf("\n\t%d spaces", spaces);
printf("\n\t%d special characters\n",spl_char);
}

int yywrap()
{
return(1);
}
