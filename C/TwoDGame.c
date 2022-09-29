#include <stdio.h>
const int XSIZE = 100;
const int YSIZE = 20;
const int STARTX = 4;
const int STARTY = 4;


int** createMap(int xSize, int ySize)
{
    
}

void displayMap(int** mapDisplay)
{
    for (int y = 0; y < YSIZE; y++)
    {
        for (int x = 0; x < XSIZE; x++)
        {
            printf("%d", mapDisplay[y][x]);
        }
        printf("\n");
    }
}

/*
1 = up ^
2 = right >
3 = down v
4 = left <
4 = traveled path *
*/



int main()
{
    int map[20][100] = {NULL}; // Y,X

    char directions[4][6] =
    {
        "North\0 ",
        "East\0 ",
        "South\0 ",
        "West\0 "
    };
    int directionX[] = {0, -1, 0, 1};
    int directionY[] = {1, 0, -1, 0};

    map[STARTY][STARTX] = 1; // Set starting point
    int currentLocation[2] = {STARTX,STARTY}; // X,Y
    //printf("%d\n", map[2][2]);

    int loopProceed = 1;
    int currentDirection = 0; // Starts looking up

    while (loopProceed == 1)
    {
        for (int y = 0; y < YSIZE; y++)
        {
            for (int x = 0; x < XSIZE; x++)
            {
                if (map[y][x] == NULL)
                {
                    printf("#");
                }
                else if (map[y][x] == 1)
                {
                    printf("^");
                }
                else if (map[y][x] == 2)
                {
                    printf(">");
                }
                else if (map[y][x] == 3)
                {
                    printf("v");
                }
                else if (map[y][x] == 4)
                {
                    printf("<");
                }
                else if (map[y][x] == 5)
                {
                    printf("*");
                }
            }
            printf("\n");
        }

        printf("Please traverse the world and explore using these commands:\n  1 - Walk Forward\n  2 - Turn Left\n  3 - Turn Right\n  4 - Check Direction\n  5 - Quit the Game\n");
        printf("Input: ");
        int input = 7;
        fflush(stdin);
        scanf("%1d", &input);
        printf("\n");

        switch(input)
        {
            case 1 :
                map[currentLocation[1]][currentLocation[0]] = 5;
                    //saves the trail of where you have been
                    if(!((currentLocation[0] - directionX[currentDirection] < 0) || (currentLocation[0] - directionX[currentDirection] > XSIZE-1)||(currentLocation[1] - directionY[currentDirection] < 0) || (currentLocation[1] - directionY[currentDirection] > YSIZE-1))){
                        //checks if you're bumping into the edge
                        currentLocation[0] = currentLocation[0] - directionX[currentDirection];
                        currentLocation[1] = currentLocation[1] - directionY[currentDirection];
                    }

                    map[currentLocation[1]][currentLocation[0]] = currentDirection+1;
                break;
            case 2 :
                currentDirection--; // Turn left
                    //moves your index up or down the 3 arrays listed above
                if(currentDirection < 0){
                    currentDirection = 3;
                }
                map[currentLocation[1]][currentLocation[0]] = currentDirection+1;
                break;
            case 3 :
                currentDirection++; // Turn right
                    //moves your index up or down the 3 arrays listed above

                if(currentDirection > 3){
                    currentDirection = 0;
                }
                map[currentLocation[1]][currentLocation[0]] = currentDirection+1;
                break;
            case 4 :
                printf("You are facing %s \n", directions[currentDirection]);
                break;
            case 5 :
                loopProceed = 2;
                printf("Bye");
                break;
            default :
                printf("Invalid value\n" );
        }
    }


    return 0;
}