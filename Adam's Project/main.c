#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100   // maximum number of lines you expect in the file
#define MAX_LENGTH 100     // maximum expected length for any character in the file

int countSteps(char input[100]);
int main()
{

    char data[MAX_LINES][MAX_LENGTH];

    // PROGRAM TO OPEN THE FILE
    FILE * file;
    file = fopen("input.txt","r");
    if(file == NULL){
        printf("Error opening file!\n");
        return 1;
    }

    // PROGRAM TO COUNT THE NUMBER OF LINES IN THE FILE AND STORE DATA IN AN ARRAY
    int numOfLines = 0;
    while(!feof(file) && !ferror(file)){
        if(fgets(data[numOfLines], MAX_LENGTH, file) != NULL){
            numOfLines++;
        }
    }

    fclose(file);

    // PROGRAM TO PRINT OUT EACH LINE IN THE FILE
    for(int i=0; i<numOfLines; i++){
        printf("%s", data[i]);
    }

    // ARRAY TO STORE THE VALUES OF THE NUMBER OF STEPS FOR EACH INPUT
    int result[numOfLines];


    // LOOP THROUGH THE ARRAY OF DATA AND APPLY THE FUNCTION countSteps to each input, count number of steps and store result in RESULT array
    for(int j=0; j<numOfLines; j++){
        result[j] = countSteps(data[j]);
    }

    // OUTPUT THE RESULT
    printf("\nSTANDARD OUTPUT:\n");
    printf("%d\n", numOfLines);

    for(int x=0; x<numOfLines; x++){
        printf("%d\n", result[x]);
    }


    return 0;
}
int countSteps(char input[100]){
    int strlength = strlen(input);

    int steps = 0;
    for(int b=0; b<strlength;b++){
        if(input[b] == 'D' || input[b] == '\n'){
            break;
        }
        else{
            steps++;
        }
    }
    return steps;
}
