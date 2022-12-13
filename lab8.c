#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <ctype.h>
#include <stdio_ext.h>

int mygetch()
{
    struct termios oldt, newt;
    int c;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    c = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return c;
}

int main()
{
    int counter=0, checker;
    while (1){
        char a = mygetch();
        printf("%c", a);
        checker = isalpha(a);
        // printf("%d", checker);
        if (a==53){
            printf("\n");
            printf("%d\n", counter);
            break;
        }
        else if (checker!=0){
            //printf("%d", isalpha(a));
            counter++;
        }
    }
    return 0;
}
 
//27 91 53 126