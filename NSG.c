
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<window.h>





#define RESET        "\033[0m"
#define RED           "\x1b[31m"
#define GREEN        "\033[0;32m"
#define BRIGHT_WHITE "\033[1;37m" 
#define BRIGHT_YELLOW "\033[1;33m"  


int readEnteredKey()
{
     char c;
     c=getch();
     if(c==-32)
     c=getch();

     return c;
}

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
    int x=readEnteredKey();
  
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






void swap(int *x, int *y)
{
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
    printf("");
}
 


int shiftDown(int arr[][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            if (arr[i][j] == 0)
                break;
        if (j < 4)
            break;
    }
    if (i == 0) 
        return 0;


    swap(&arr[i][j], &arr[i - 1][j]); 
    return 1; 
}

int shiftUp(int arr[][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            if (arr[i][j] == 0)
                break;
        if (j < 4)
            break;
    }
    if (i == 3)
        return 0;
    swap(&arr[i][j], &arr[i + 1][j]); 

    return 1; 
}

int shiftRight(int arr[][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            if (arr[i][j] == 0)
                break;
        if (j < 4)
            break;
    }
    if (j == 0) 
        return 0;

    swap(&arr[i][j], &arr[i][j - 1]);

    return 1;
}

int shiftLeft(int arr[][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            if (arr[i][j] == 0)
                break;
        if (j < 4)
            break;
    }

    if (j == 3) 
        return 0;

    swap(&arr[i][j], &arr[i][j + 1]);
    return 1;
}


int winner(int arr[][4])
{
    int i, j, k = 1;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++, k++)
        {
            if (arr[i][j] != k && k != 16)
                break;
        }
        if (j < 4)
            break;
    }

    if (j < 4)
        return 0;
    return 1;
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
    while(1){
        createMatrix(arr);
    
        while(!winner(arr))
        {

            system("cls");
            if(!moves)
            break;
            printf("Player Name : %s  \n\n",name);
            printf("Left Moves:  Moves : %d\n\n\n",moves);
            showMatrix(arr);
            int key= readEnteredKey();
            switch (key)  {
                case 101: 
    
                case 69:
                    printf("\a\a\a\a\a\a\n     Thanks for Playing ! \n\a");
                    printf("\nHit 'Enter' to exit the game \n");
                    key = readEnteredKey();
                    return 0;

                case 72: // arrow up
                    if (shiftUp(arr))
                        moves--;
                    break; 
                case 80: // arrow down
                    if (shiftDown(arr))
                        moves--;
                    break;
                case 75: // arrow left
                    if (shiftLeft(arr))
                        moves--;
                    break;
                case 77: // arrow  right
                    if (shiftRight(arr))
                        moves--;
                    break;
                default:

                    printf("\n\n      \a\a Not Allowed \a");
                }

        }
            
            if (!moves)
                printf(RED "\n\a          YOU LOSE !          \a\a\n"RESET);
            else
                printf(GREEN "\n\a!!!!!!!!!!!!!Congratulations  %s for winning this game !!!!!!!!!!!!!\n\a"RESET, name);
        
            fflush(stdin); 
            char check;
            printf(GREEN "\nWant to play again ? \n"RESET);
            printf("enter 'y' to play again:  ");
            scanf("%c", &check);

    
            if((check!='y')&&(check!='Y'))
            break;

            moves=1000;
    }

    return 0;
    


}



