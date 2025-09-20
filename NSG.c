
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>




#define RESET        "\033[0m"
#define GREEN        "\033[0;32m"
#define BRIGHT_WHITE "\033[1;37m" 
#define BRIGHT_YELLOW "\033[1;33m"  

void gameRule()
{
    system("cls");
    printf(BRIGHT_WHITE"\t\t\t\t\t\t\t\t\tNumber Shifting Game - A Matrix Puzzle\n"RESET);
    printf(BRIGHT_WHITE"\t\t\t\t\t\t\t\t\t\tRule of this Game\n\n\n\n\n\n"RESET);
    printf(GREEN"1-You can move only 1 step at a time by using arrow key :\n"RESET);
    printf(BRIGHT_WHITE"   Move Up : By Using Up arrow key\n"RESET);
    printf(BRIGHT_WHITE"   Move Down : By Using Down arrow key\n"RESET);
    printf(BRIGHT_WHITE"   Move Left : By Using Left arrow key \n"RESET);
    printf(BRIGHT_WHITE"   Move Right : By Using Right arrow key \n\n"RESET);
    printf(GREEN"2-You can move number at empty position only\n\n"RESET);
    printf(GREEN"3-For each valid move : your move is going to decrease by 1 so try to win in minimum no of move\n\n"RESET);
    printf(GREEN"4-Winning condition :Number in 4*4 matrix should be in order from 1-15\n\n"RESET);
    printf(BRIGHT_WHITE"Wining Situation : \n"RESET);
    printf(BRIGHT_YELLOW"-------------\n"RESET);
   
    int k=1;
    for(int i=0;i<4;i++)
    {
        printf(BRIGHT_YELLOW"|"RESET);
        for(int j=0;j<4;j++)
        {
            if(i==3 && j==3)
            printf("  ");
            else
            printf("%2d",k++); 
            printf(BRIGHT_YELLOW"|"RESET);
        }
        printf("\n");
    }
    printf(BRIGHT_YELLOW"-------------\n\n"RESET);
    printf(GREEN"5-You can exit the game by pressing 'E' or 'e'\n\n"RESET);
    printf(BRIGHT_WHITE"Enter any key to start.....\n"RESET);
    getch();
  
}

void createMatrix(int arr[][4])
{
    int n=15;
    int nums[n];
    for(int i=0;i<15;i++)
     nums[i]=i+1;

    int lastIndex=n-1;

    
    srand(time(NULL));
    

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(lastIndex>=0)
            {
                int index= rand() % (lastIndex+1);
                arr[i][j]=nums[index];
                nums[index]=nums[lastIndex--];
            }
        }
      
    }
    arr[3][3]=0;

}


void showMatrix(int arr[][4])
{
    int i, j;
    printf("--------------------\n");
    for (i = 0; i < 4; i++)
    {
        printf("|");
        for (j = 0; j < 4; j++)
        {
            if (arr[i][j] != 0)
                printf("%2d | ", arr[i][j]);
            else
                printf("   | ");
        }
        printf("\n");
    }

    printf("--------------------\n");
}



 
int main() 
{
    int arr[4][4];
    printf("\t\t\t\t\t\t\t\t\tWelcome to Number Shifting Game\n");
    printf("\n\n\n\n\n\n\n\n");
    char name[30];
    printf("\t\t\t\t");
    printf("Player Name: ");
    fgets(name,30,stdin);
    int moves=1000;
    gameRule();
    system("cls");
    createMatrix(arr);
    printf("\n\nPlayer Name : %s                                                       Moves : %d\n\n",name,moves);
    showMatrix(arr);
    system("pause");
 
    

}



