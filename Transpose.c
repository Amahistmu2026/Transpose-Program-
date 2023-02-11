/*C program by Abdullah Mohammad Mahi for CS 1311

 o            o
  \          /
   \        /
    :-'""'-:
 .-'  ____  `-.
( (  (_()_)  ) )
 `-.   ^^   .-'
    `._==_.'
    __)(___
*this program reads from name_in.txt file, printing names 
*in verticle downard format in the output window and name_out.txt
*/
#include <stdio.h>
#include <stdlib.h>


char names[20][60]; /* 2-dimensional characters array*/

void main(void)
{
	FILE *In, *Out; /*pointers for file opening and file closing*/ 
	int m, n; /*i represents row, j for represents column */
	
	printf(" This program reads names from name_in.txt and print in window and name_out.txt \n\n");
	
	In = fopen("name_in.txt", "r"); /*open name_in.txt in reading mode*/
	Out = fopen("name_out.txt", "w"); /*open name_out.txt in reading mode*/
			
	printf(" The names located in name_in.txt are looks like this :\n\n");
	
	for(m = 0; m < 20; m++) /*for loop to read names and prints it into the window*/
	{
		fgets(names[m], 59, In);
		strtok(names[m], "\n");
		printf(" %s\n", names[m]);
	}
	
	printf("\n\n");
	printf(" The transpose form of names from name_in.txt are look like this: \n\n");
	
	/*double-for loop to go in each row and column to print character by charcter 
	from name_in.txt and print these in downwards into output and name_out.txt*/
	for(n = 0; n < 60; n++)
	{         
		for(m = 0; m < 20; m++)    
		{
			printf("  %c  ", names[m][n]);
			fprintf(Out, "  %c  ", names[m][n]);	
		}
		
		printf("\n"); /* the program prints a newline at the end of each line into 
		output and to name_out.txt*/
		fprintf(Out, "\n");	
	}
	
	/*closing flies using pointers*/
	fclose(In);
	fclose(Out);
}
