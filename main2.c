#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 20
#define COLS 50

char canvas[ROWS][COLS];

void initializeCanvas() 
{
    for (int i = 0; i < ROWS; i++) 
    {
        for (int j = 0; j < COLS; j++)
         {
            canvas[i][j] = '_';
        }
    }
}

void clearCanvas()
{
    initializeCanvas();
}

void displayCanvas() 
{
    for (int i = 0; i < ROWS; i++) 
    {
        for (int j = 0; j < COLS; j++) 
        {
            printf("%c ", canvas[i][j]);
        }
        printf("\n");
    }
}

void drawRectangle(int x, int y, int width, int height) 
{
    for (int i = y; i < y + height; i++) 
    {
        for (int j = x; j < x + width; j++) 
        {
            if(i >= 0 && i < ROWS && j >= 0 && j < COLS)
            {
                canvas[i][j] = '*';
            }
        }
    }
}

void drawLine(int x1, int y1, int x2, int y2) 
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1) 
    {
        if(x1 >= 0 && x1 < COLS && y1 >= 0 && y1 < ROWS)
        {
            canvas[y1][x1] = '*';
        }
        if (x1 == x2 && y1 == y2) 
        {
            break;
        }
        int err2 = err * 2;
        if (err2 > -dy) 
        {
            err -= dy;
            x1 += sx;
        }
        if (err2 < dx) 
        {
            err += dx;
            y1 += sy;
        }
    }
}

void draw(int x1, int y1, int x2, int y2,int x3,int y3)
{
    drawLine(x1, y1, x2, y2);
    drawLine(x2, y2, x3, y3);
    drawLine(x3, y3, x1, y1);
}

void drawCircle(int cX, int cY, int radius) 
{
    for (int y = 0; y < ROWS; y++) 
    {
        for (int x = 0; x < COLS; x++) 
        {
            double dx=x-cX;
            double dy=(y-cY)*2;
            double dist=sqrt(dx*dx+dy*dy);

            if(fabs(dist-radius)<0.6)
            {
                canvas[y][x]='*';
            }

        }
    }
}

int main()
{
    int choice;
    initializeCanvas();
    while(1)
    {
        printf("\n=====2D GRAPHICS EDITOR=====\n");
        printf("1. Draw Rectangle\n");
        printf("2. Draw Line\n");
        printf("3. Draw Triangle\n");
        printf("4. Draw Circle\n");
        printf("5. Display Canvas\n");
        printf("6. Delete All Objects\n");
        printf("7. Modify Canvas\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                {
                    int x, y, width, height;
                    printf("Enter x, y, width and height of the rectangle: ");
                    scanf("%d %d %d %d", &x, &y, &width, &height);
                    drawRectangle(x, y, width, height);
                    printf("Rectangle Added\n");
                    break;
                }
            case 2:
                {
                    int x1, y1, x2, y2;
                    printf("Enter x1, y1 and x2, y2 of the line: ");
                    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                    drawLine(x1, y1, x2, y2);
                    printf("Line Added\n");
                    break;
                }
            case 3:
                {
                    int x1, y1, x2, y2,x3,y3;
                    printf("Enter x1,y1,x2,y2,x3,y3 of the triangle: ");
                    scanf("%d %d %d %d %d %d", &x1,&y1,&x2,&y2,&x3,&y3);
                    draw(x1,y1,x2,y2,x3,y3);
                    printf("Triangle Added\n");
                    break;
                }
            case 4:
                {
                    int cX,cY,radius;
                    printf("Enter center (cX,cY) and radius of the circle: ");
                    scanf("%d %d %d", &cX,&cY,&radius);
                    drawCircle(cX,cY,radius);
                    printf("Circle Added\n");
                    break;
                }
            case 5:
                {
                    printf("\n=======CANVAS=======\n");
                    displayCanvas();
                    break;
                }
            case 6:
                { 
                    clearCanvas();
                    printf("All objects deleted\n");
                    break;
                }
            case 7:
                {
                    clearCanvas();
                    printf("Canvas cleared. Draw new objects.\n");
                    break;
                }
            case 8:
                {
                   printf("Exiting program...\n");
                   return 0;
                }
            default:
               {
                   printf("Invalid choice!\n"); 
               }
        }
    }
}