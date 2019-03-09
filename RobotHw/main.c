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
        //User is entering  row and column numbers of labyrinth
        printf("Enter the row and column number respectively:\n");
        scanf("%d %d",&row,&column);
        //memory allocation of row of matrix
        lab=(char**)malloc(row*sizeof(char*));
        for(i=0;i<row;i++){
            *(lab+i)=(char*)malloc(column*sizeof(char));//memory allocation of column of matrix
        };printf("\n");
        //print labyrinth;
        for(i=0;i<row;i++){
            for(j=0;j<column;j++){
                itoa(create(), buf, 2);//convert integer to string in order to store in character array
                lab[i][j]=buf[0];
                printf(" %c  ",lab[i][j]);
            }
            printf("\n");
        };printf("\n");
        //user is defining start and finish positions of labyrinth
        printf("Enter the row and column numbers of start position respectively:\n");
        scanf("%d %d",&startRow,&startColumn);
        printf("\nEnter the row and column numbers of finish position respectively:\n");
        scanf("%d %d",&finishRow,&finishColumn);
        //in order to start matrix indexing process from 0
        startColumn--; startRow--; finishRow--; finishColumn--;
        lab[startRow][startColumn]='>';//START POSITION OF LABYHRINTH
        print(row,column,lab);//print matrix;
        //control the user defined finish position in order to be sure that
        //can robot  find the way to that location
        if(((finishColumn+1!=column)&&(lab[finishRow][finishColumn+1]!='0'))||((finishRow+1!=row)&&(lab[finishRow+1][finishColumn]!='0'))||((finishColumn-1>=0)&&(lab[finishRow][finishColumn-1]!='0'))||((finishRow-1>=0)&&(lab[finishRow-1][finishColumn]!='0'))){
            while((lab[finishRow][finishColumn]!='A')&&(lab[finishRow][finishColumn]!='V')&&(lab[finishRow][finishColumn]!='>')&&(lab[finishRow][finishColumn]!='<')){
                if((startColumn+1!=column)&&(lab[startRow][startColumn+1]=='1')){
                    lab[startRow][startColumn]='+';
                    lab[startRow][startColumn+1]='>';
                    startColumn++;
                    print(row,column,lab);//print matrix;
                    delay(1);
                }
                else if((startRow+1!=row)&&(lab[startRow+1][startColumn]=='1')){
                    lab[startRow][startColumn]='+';
                    lab[startRow+1][startColumn]='V';
                    startRow++;
                    print(row,column,lab);//print matrix;
                    delay(1);
                }
                else if((startColumn-1>=0)&&(lab[startRow][startColumn-1]=='1')){
                    lab[startRow][startColumn]='+';
                    lab[startRow][startColumn-1]='<';
                    startColumn--;
                    print(row,column,lab);//print matrix;
                    delay(1);
                }
                else if((startRow-1>=0)&&(lab[startRow-1][startColumn]=='1')){
                    lab[startRow][startColumn]='+';
                    lab[startRow-1][startColumn]='A';
                    startRow--;
                    print(row,column,lab);//print matrix;
                    delay(1);
                }
                //If there is no way out robot needs to move backward
                //that is why + symbol is changed to - symbol in order to describe the return
                else if((startRow-1>=0)&&(lab[startRow-1][startColumn]=='+')){
                    lab[startRow][startColumn]='-';
                    lab[startRow-1][startColumn]='A';
                    startRow--;
                    print(row,column,lab);//print matrix;
                    delay(1);
                }
                else if((startColumn-1>=0)&&(lab[startRow][startColumn-1]=='+')){
                    lab[startRow][startColumn]='-';
                    lab[startRow][startColumn-1]='<';
                    startColumn--;
                    print(row,column,lab);//print matrix;
                    delay(1);
                }
                else if((startRow+1<row)&&(lab[startRow+1][startColumn]=='+')){
                    lab[startRow][startColumn]='-';
                    lab[startRow+1][startColumn]='V';
                    startRow++;
                    print(row,column,lab);//print matrix;
                    delay(1);
                }
                else if((startColumn+1<column)&&(lab[startRow][startColumn+1]=='+')){
                    lab[startRow][startColumn]='-';
                    lab[startRow][startColumn+1]='>';
                    startColumn++;
                    print(row,column,lab);//print matrix;
                    delay(1);
                }
                //If there is no way out robot needs to move backward again.
                //In order to describe that robot has been moved from here 2 times
                //symbol - has  changed to * symbol
                else if((startColumn+1<column)&&(lab[startRow][startColumn+1]=='-')){
                    lab[startRow][startColumn]='*';
                    lab[startRow][startColumn+1]='>';
                    startColumn++;
                    print(row,column,lab);//print matrix;
                    delay(1);
                }
                else if((startRow+1<row)&&(lab[startRow+1][startColumn]=='-')){
                    lab[startRow][startColumn]='*';
                    lab[startRow+1][startColumn]='V';
                    startRow++;
                    print(row,column,lab);//print matrix;
                    delay(1);
                }
                else if((startColumn-1>=0)&&(lab[startRow][startColumn-1]=='-')){
                    lab[startRow][startColumn]='*';
                    lab[startRow][startColumn-1]='<';
                    startColumn--;
                    print(row,column,lab);//print matrix;
                    delay(1);
                }
                else if((startRow-1>=0)&&(lab[startRow-1][startColumn]=='-')){
                    lab[startRow][startColumn]='*';
                    lab[startRow-1][startColumn]='A';
                    startRow--;
                    print(row,column,lab);//print matrix;
                    delay(1);
                }



                //If there is no way out again we need to convert symbol * to symbol +
                else if((startColumn+1<column)&&(lab[startRow][startColumn+1]=='*')){
                    lab[startRow][startColumn]='+';
                    lab[startRow][startColumn+1]='>';
                    startColumn++;
                    print(row,column,lab);//print matrix;
                    delay(1);
                }
                else if((startRow+1<row)&&(lab[startRow+1][startColumn]=='*')){
                    lab[startRow][startColumn]='+';
                    lab[startRow+1][startColumn]='V';
                    startRow++;
                    print(row,column,lab);//print matrix;
                    delay(1);
                }
                else if((startColumn-1>=0)&&(lab[startRow][startColumn-1]=='*')){
                    lab[startRow][startColumn]='+';
                    lab[startRow][startColumn-1]='<';
                    startColumn--;
                    print(row,column,lab);//print matrix;
                    delay(1);
                }
                else if((startRow-1>=0)&&(lab[startRow-1][startColumn]=='*')){
                    lab[startRow][startColumn]='+';
                    lab[startRow-1][startColumn]='A';
                    startRow--;
                    print(row,column,lab);//print matrix;
                    delay(1);
                }


            }
        }
        else{
            printf("This labyrinth does not have way out! Please try again!\n\n");
        }

        printf("If you want to finish program please enter 1, otherwise enter 0 : ");
        scanf("%d",&exit);
        printf("\n");

    }while(exit==0);
    return 0;
}
