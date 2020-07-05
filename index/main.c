#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "Index.h"

#define MAX_LINE_SIZE 300




//main program
int main(int argc, char *argv[]) {
			
	//variable declaration

    FILE *inf = NULL;
	char line[MAX_LINE_SIZE];
	uint32_t linecounter=1;
	
    if (argc != 2)
    {
        printf("\nusage: %s source \n", argv[0]);
        exit(EXIT_FAILURE);
    }
	
	//create tree
	Create();

	//file handling	
    inf = fopen(argv[1], "r");

    if (inf == NULL){
    
        printf("\n cannot open given file: %s", argv[1]);
        exit(EXIT_FAILURE);
	
    }else{
		
	while (!feof(inf)){
	
		memset(line,0,sizeof(line));
		fgets(line, sizeof(line), inf);
				
		if (line != NULL){
		
			AddItemsFromBuffer(line, linecounter);
			linecounter++;	
		}
		
	}
	
	  fclose (inf);
	}


		
	//print tree
	Print();


	//delete tree
	Delete();
	
	return 0;

}

