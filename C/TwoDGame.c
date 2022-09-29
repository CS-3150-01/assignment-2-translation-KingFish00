#include <stdio.h>
// Constants for program
const int XSIZE = 100;
const int YSIZE = 20;
const int STARTX = 4;
const int STARTY = 4;

// Removed fuctions that I never got to work

/*
numbers for displaying things
1 = up ^
2 = right >
3 = down v
4 = left <
4 = traveled path *

numbers for directions
0 = north
1 = east
2 = south
3 = west
*/

int main()
{
    // Size of map created with null slots
    int map[20][100] = {NULL}; // Y,X

    // Direction Strings array
    char directions[4][6] =
    {
        "North\0 ",
        "East\0 ",
        "South\0 ",
        "West\0 "
    };
    // Linked number values
    int directionX[] = {0, -1, 0, 1};
    int directionY[] = {1, 0, -1, 0};

    map[STARTY][STARTX] = 1; // Set starting point
    int currentLocation[2] = {STARTX,STARTY}; // X,Y
    //printf("%d\n", map[2][2]);

    int loopProceed = 1; // if 1 then it will loop, if anyhting else it won't
    int currentDirection = 0; // Starts the player looking up

    while (loopProceed == 1) // loop until exit
    {
        for (int y = 0; y < YSIZE; y++) // loop through the y axis (rows)
        {
            for (int x = 0; x < XSIZE; x++) // loop through the x axis (columns)
            {
                if (map[y][x] == NULL) // If it hasn't been touched yet set as #
                {
                    printf("#");
                }
                else if (map[y][x] == 1) // Display direction up
                {
                    printf("^");
                }
                else if (map[y][x] == 2) // Display direction right
                {
                    printf(">");
                }
                else if (map[y][x] == 3) // Display direction down
                {
                    printf("v");
                }
                else if (map[y][x] == 4) // Display direction left
                {
                    printf("<");
                }
                else if (map[y][x] == 5) // Display previously ocupied spaces
                {
                    printf("*");
                }
            }
            printf("\n"); // new line for each row
        }

        // Using numbers instead of wasd 
        printf("Please traverse the world and explore using these commands:\n  1 - Walk Forward\n  2 - Turn Left\n  3 - Turn Right\n  4 - Check Direction\n  5 - Quit the Game\n");
        printf("Input: ");
        int input = 7; // Og solution to inputing the wrong type of character, didn't work but doesnt hurt
        fflush(stdin); // Flush the input stream, solves the wrong type of character problem so if people enter w it wont break forever
        scanf("%1d", &input); // Get input from user
        printf("\n"); // make a space

        switch(input) // switch statement
        {
            case 1 : // if they want to move forward
                map[currentLocation[1]][currentLocation[0]] = 5; // set the current location to the explored path

                    if(!((currentLocation[0] - directionX[currentDirection] < 0) || (currentLocation[0] - directionX[currentDirection] > XSIZE-1)||(currentLocation[1] - directionY[currentDirection] < 0) || (currentLocation[1] - directionY[currentDirection] > YSIZE-1)))
                    {
                        //checks if you're bumping into the edge and if your not
                        currentLocation[0] = currentLocation[0] - directionX[currentDirection]; // change current location by the direction it needs in x and y
                        currentLocation[1] = currentLocation[1] - directionY[currentDirection];
                    }

                    map[currentLocation[1]][currentLocation[0]] = currentDirection+1; // set new location to the current direction
                break;
            case 2 :
                currentDirection--; // Turn left
                //moves your index up or down the 3 arrays listed above
                if(currentDirection < 0) // If it goes far enough around then reset to three
                {
                    currentDirection = 3;
                }
                map[currentLocation[1]][currentLocation[0]] = currentDirection+1; // reset current location with the new direction indicator
                break;
            case 3 :
                currentDirection++; // Turn right
                //moves your index up or down the 3 arrays listed above
                if(currentDirection > 3) // If it goes far enough around then reset to zero
                {
                    currentDirection = 0;
                }
                map[currentLocation[1]][currentLocation[0]] = currentDirection+1; // reset current location with the new direction indicator
                break;
            case 4 :
                printf("You are facing %s \n", directions[currentDirection]); // Tell them the current direction they are facing
                break;
            case 5 :
                loopProceed = 2; // set to exit the loop
                printf("Bye"); // tell them fairwell
                break;
            default :
                printf("Invalid value\n" ); // make them do it again
        }
    }

    return 0;
}