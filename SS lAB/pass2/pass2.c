#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
char a[10],ad[10],mnemonic[10],symbol[10],label[10],opcode[10],operand[10];
int length,actual_length(),address,code,xcode,i;
FILE *fp1, *fp2, *fp3, *fp4;
fp1 = fopen("assmlist.dat","w");
fp2 = fopen("symtab.dat","r");
fp3 = fopen("optab.dat","r");
fp4 = fopen("intermediate.dat","r");
fscanf(fp4,"%s%s%s",label,opcode,operand);
if(strcmp(opcode,"START")==0)
{
 fprintf(fp1,"%s\t%s\t%s\n",label,opcode,operand);
 fscanf(fp4,"%d%s%s%s",&address,label,opcode,operand);
}
while(strcmp(opcode,"END")!=0)
  {
	if(strcmp(opcode,"BYTE")==0)
	{
	    fprintf(fp1,"%d\t%s\t%s\t%s\t",address,label,opcode,operand);
		length = strlen(operand);
		length = length - 3;
		for(i=2;i<length+2;i++)
		{
			sprintf(a,"%d",operand[i]);
			fprintf(fp1,"%s",a);
	    }
	    fprintf(fp1,"\n");
	 }
	 else if(strcmp(opcode,"WORD")==0)
	 {
	 	sprintf(ad,"%d",atoi(operand));
	 	fprintf(fp1,"%d\t%s\t%s\t%s\t00000%s\n",address,label,opcode,operand,ad);
	 }
	 else if((strcmp(opcode,"RESB")==0) || (strcmp(opcode,"RESW")==0))
	  {
	   fprintf(fp1,"%d\t%s\t%s\t%s\n",address,label,opcode,operand);
	  }
	  else
	   {
	  	rewind(fp3);
	  	fscanf(fp3,"%s%d",mnemonic,&code);
	  	while(strcmp(opcode,mnemonic)!=0)
	  	{
	  	fscanf(fp3,"%s%d",mnemonic,&code);
	  	}
	  	rewind(fp2);
	  	fscanf(fp2,"%s%d",symbol,&xcode);
	  	while(strcmp(operand,symbol)!=0)
	  	{
	  	fscanf(fp2,"%s%d",symbol,&xcode);
	  	}
	  	fprintf(fp1,"%d\t%s\t%s\t%s\t%d%d\n",address,label,opcode,operand,code,xcode);
	  	}
	  fscanf(fp4,"%d%s%s%s",&address,label,opcode,operand);	  
  }
	 fprintf(fp1,"%d\t%s\t%s\t%s\n",address,label,opcode,operand);
	 fclose(fp1);
	 fclose(fp2);
	 fclose(fp3);
	 fclose(fp4);
}
