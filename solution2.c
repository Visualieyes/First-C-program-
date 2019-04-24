/*
 *	Hello World with a command line argument
 *
 *	Author:		Keyann Al-Kheder
 *	Date: 		Jan 8th, 2019
 *
 */

#include <stdio.h>
#include <stdlib.h>




int main(int argc, char* argv[])
{

	if (argc != 2){
		printf("Error, too many or not enough args supplied");
		exit(-1);
	}

	else{

		FILE * inputFile = fopen(argv[1], "r");

		if (inputFile != NULL){

			int unmatched_brace;

			char c = getc(inputFile);

			while(c != EOF){

				if(c == '{'){
					unmatched_brace++;
				}

				if(c == '}'){
					unmatched_brace--;
				}

				c = getc(inputFile);
			}

			fclose(inputFile);

			if (unmatched_brace != 0){
			printf("Error, unmatched number of braces in file: count = %i\n", unmatched_brace);
			}
			else{
			printf("All braces match\n");
			}

			return 0;
      
		}
	}
}
