#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
 char input[10],bitmask[10],opcode[10];
 int start,length,address,actual,ad,i,a;
 printf("enter the actual starting aadress\n");
 scanf("%d",&actual);
 FILE *f1, *f2;
 f1 = fopen("relinput.dat","r");
 f2 = fopen("output.dat","w");
 fscanf(f1,"%s",input);
 while(strcmp(input,"E")!=0)
 {
 	if(strcmp(input,"H")==0)
 	{
 		fscanf(f1,"%d",&start);
 		fscanf(f1,"%d",&length);
 		fscanf(f1,"%s",input);
 	}
 	else if(strcmp(input,"T")==0)
 	{
 		fscanf(f1,"%d",&ad);
 		fscanf(f1,"%s",bitmask);
 		ad = ad + actual-start;
 		for(i=0;i<strlen(bitmask);i++)
 		{
 			fscanf(f1,"%s",opcode);
 			fscanf(f1,"%d",&a);
 			if(bitmask[i]=='1')
 			   a = a + (actual-start);
 			fprintf(f2,"%d\t%s%d\n",ad,opcode,a);
 			ad = ad+3;
 		}
 		fscanf(f1,"%s",input);
 	}
 }
 fclose(f1);
 fclose(f2);
}	
 			
