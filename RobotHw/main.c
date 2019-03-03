#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Stroing start time
    clock_t start_time = clock();

    // looping till required time is not acheived
    while (clock() < start_time + milli_seconds)
        ;
}
int randomFunction()
{
	int random = rand();
	// if the random number is even, return 0
	// if the random number is odd, return 1
	return (random % 2);
}
// Return 1 and 0 with 75% and 25% probability respectively
int create()
{
	int x = randomFunction();
	int y = randomFunction();
	return (x | y);
}
void print(int row,int column,char**lab){
    int i,j;
    printf("\n");
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
            printf(" %c  ",lab[i][j]);
        }
        printf("\n");
    };
    printf("\n");
}
int main()
{
    char **lab,buf[3];
    int i,j,flag,row,column,startRow,startColumn,finishRow,finishColumn,exit=0;
    do{
        //User enter row and column number of labyrinth
        printf("Enter the row and column number respectively:\n");
        scanf("%d %d",&row,&column);
        //memory allocation of row of matrix
        lab=(char**)malloc(row*sizeof(char*));
        for(i=0;i<row;i++){
            *(lab+i)=(char*)malloc(column*sizeof(char));//memory allocation of column of matrix
        };printf("\n");

        for(i=0;i<row;i++){
            for(j=0;j<column;j++){
                itoa(create(), buf, 2);//convert integer to string in order to store in char array
                lab[i][j]=buf[0];
                printf(" %c  ",lab[i][j]);
            }
            printf("\n");
        };printf("\n");

        printf("Enter the row and column numbers of start position respectively:\n");
        scanf("%d %d",&startRow,&startColumn);
        printf("\nEnter the row and column numbers of finish position respectively:\n");
        scanf("%d %d",&finishRow,&finishColumn);
        //in order to start matrix indexing process from 0
        startColumn--; startRow--; finishRow--; finishColumn--;
        //determine position of robot
        lab[startRow][startColumn]='R';//START POSITION OF LABYHRINTH
        print(row,column,lab);//print matrix;

        while(lab[finishRow][finishColumn]!='R'){
            if((startColumn+1!=column)&&(lab[startRow][startColumn+1]=='1')){
                lab[startRow][startColumn]='+';
                lab[startRow][startColumn+1]='R';
                startColumn++;
                print(row,column,lab);//print matrix;
                delay(1);
            }
            else if((startRow+1!=row)&&(lab[startRow+1][startColumn]=='1')){
                lab[startRow][startColumn]='+';
                lab[startRow+1][startColumn]='R';
                startRow++;
                print(row,column,lab);//print matrix;
                delay(1);
            }
            else if((lab[startRow][startColumn-1]=='1')&&(startColumn-1>=0)){
                lab[startRow][startColumn]='+';
                lab[startRow][startColumn-1]='R';
                startColumn--;
                print(row,column,lab);//print matrix;
                delay(1);
            }
            else if((lab[startRow-1][startColumn]=='1')&&(startRow-1>=0)){
                lab[startRow][startColumn]='+';
                lab[startRow-1][startColumn]='R';
                startRow--;
                print(row,column,lab);//print matrix;
                delay(1);
            }
            //converse
            else if((lab[startRow-1][startColumn]!='1')&&(lab[startRow-1][startColumn]=='+')&&(startRow-1>=0)){
                lab[startRow][startColumn]='-';
                lab[startRow-1][startColumn]='R';
                startRow--;
                print(row,column,lab);//print matrix;
                delay(1);
            }
            else if((lab[startRow][startColumn-1]!='1')&&(lab[startRow][startColumn-1]=='+')&&(startColumn-1>=0)){
                lab[startRow][startColumn]='-';
                lab[startRow][startColumn-1]='R';
                startColumn--;
                print(row,column,lab);//print matrix;
                delay(1);
            }
            else if((lab[startRow+1][startColumn]!='1')&&(lab[startRow+1][startColumn]=='+')&&(startRow+1<row)){
                lab[startRow][startColumn]='-';
                lab[startRow+1][startColumn]='R';
                startRow++;
                print(row,column,lab);//print matrix;
                delay(1);
            }
            else if((lab[startRow][startColumn+1]!='1')&&(lab[startRow][startColumn+1]=='+')&&(startColumn+1<column)){
                lab[startRow][startColumn]='-';
                lab[startRow][startColumn+1]='R';
                startColumn++;
                print(row,column,lab);//print matrix;
                delay(1);
            }
        };

        printf("If you want to finish program please enter 1, otherwise enter 0 : ");
        scanf("%d",&exit);
        printf("\n");

    }while(exit==0);
    return 0;
}
