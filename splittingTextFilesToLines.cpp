#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main() {
	FILE* file;
	char fileName[20];
	char** lines;
	
	char currentChar;
	
	int sum = 1;
	
	int pointerPositionCount = 0;
	
	int positionCount = 0;
	
	int numberOfCharactersInSingleLine = 100;
	
	printf("Enter the file name : ");
	scanf(" %s", fileName);
	
	file = fopen(fileName,"r");
	
	if(file == NULL) {
		printf("=== Something Went Wrong ===");
		return 1;
	}
	
	printf("Reading...\n\n");
	
	currentChar = getc(file);
	
	while(currentChar != EOF) {
		if(currentChar == '\n') {
			sum += 1;
		}
		currentChar = getc(file);
	}
	
	rewind(file);
	
	printf("The number of lines in file is : %d \n\n", sum);
	
	lines = (char **) malloc(sizeof(char*) * sum );
	
	for(int i = 0; i<sum; i++) {
		*(lines + i) =(char *) malloc(sizeof(char) * numberOfCharactersInSingleLine);
	}
	
	for(int i = 0; i<sum ; i++)
		for(int j = 0; j< numberOfCharactersInSingleLine; j++)
			*(*(lines + i) + j) = ' ';
		
	
	currentChar = getc(file);
	
	while(currentChar != EOF) {
		if(currentChar == '\n'){
			positionCount = 0;
			pointerPositionCount++;
		}
		
		*(*(lines + pointerPositionCount) + positionCount) = currentChar;
//		printf("%c", *(*(lines + pointerPositionCount) + positionCount));
		
		positionCount++;
		currentChar = getc(file);
	}
	
	for(int i = 0; i<sum ; i++)
		for(int j = 0; j< numberOfCharactersInSingleLine; j++) 
			printf("%c", *(*(lines + i) + j));
	
	fclose(file);
	free(lines);
	
	printf("\n");
	
	getch();
	
	return 0;
	
}
