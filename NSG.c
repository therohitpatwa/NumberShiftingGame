#include<stdio.h>
#include<"stdlib.h">

void gameRule()
{
    printf("\t\t\t\t\t\t\t\t\tNumber Shifting Game - A Matrix Puzzle\n");
    printf("\t\t\t\t\t\t\t\t\t\tRule of this Game\n\n\n\n\n\n");
    printf("1-You can move only 1 step at a time by using arrow key :\n");
    printf("   Move Up : By Using Up arrow key\n");
    printf("   Move Down : By Using Down arrow key\n");
    printf("   Move Left : By Using Left arrow key \n");
    printf("   Move Right : By Using Right arrow key \n\n");
    printf("2-You can move number at empty position only\n\n");
    printf("3-For each valid move : your move is going to decrease by 1 so try to win in minimum no of move\n\n");
    printf("4-Winning condition :Number in 4*4 matrix should be in order from 1-15\n\n");
    printf("Wining Situation : \n");
    printf("-------------\n");
   
    int k=1;
    for(int i=0;i<4;i++)
    {
        printf("|");
        for(int j=0;j<4;j++)
        {
            if(i==3 && j==3)
            printf("  ");
            else
            printf("%2d",k++); 
            printf("|");
        }
        printf("\n");
    }
    printf("-------------\n\n");
    printf("5-You can exit the game by pressing 'E' or 'e'\n\n");
    printf("Enter any key to start.....\n");
    getch();

}

void createMatrix(int arr[][])
{
    int num[15];
    for(int i=0;i<15;i++)
     nums[i]=i+1;

    lastIndex=14;

    
    srand(time(NULL));
    

    int num=rand();
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {

            index= rand() % (lastIndex+1);
            arr[i][j]=nums[index];
            nums[index]=nums[lastIndex--];
        }

    }

}




int main() 
{
    int arr[][]=new int[4][4];
    printf("\t\t\t\t\t\t\t\t\tWelcome to Number Shifting Game\n");
    printf("\n\n\n\n\n\n\n\n");
    char name[30];
    printf("\t\t\t\t");
    printf("Player Name: ");
    fgets(name,30,stdin);
    system("cls");
    

    gameRule();

    createMatrix(arr);

    

}



