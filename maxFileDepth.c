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
		printf("Error, too many or not enough arguments entered!\n");
		exit(-1);					// this line was taken from your code on the board
	}

	else{
		
		FILE * inputFile;

		inputFile = fopen(argv[1], "r");

		if (inputFile != NULL){

			int depth_count = 0;
			int maxdepth = 1;

			char c = getc(inputFile);

			while(c != EOF){

				if (depth_count > maxdepth){
					maxdepth = depth_count;
				}

				if (c == '{'){
					depth_count++;

				}
				else{

					if (c == '}'){
						depth_count--;
					}
				}

				c = getc(inputFile);

			}

			fclose(inputFile);
			printf("Max nested depth is: %i\n", maxdepth);

			
			return 0;
		}

	}

}
