#include <iostream>
#include <myQueue.h>
#include <fstream>

using namespace std;

const int wall = -1;
const int space = -2;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

bool isSpace(int **field, int w, int h, int x, int y)
{
    return (x >= 0 && y >= 0 && x < h && y < w && field[x][y] == space);
}

bool Lee(int **field, int height, int width, int x0, int y0, int x1, int y1)
{
    if (field[x0][y0] == wall || field[x1][y1] == wall)
    {
        return false;
    }
    bool result = false;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (field[i][j] != wall)
                field[i][j] = space;
        }
    }
    Queue *pointsX = getNewQueue();
    Queue *pointsY = getNewQueue();
    push(pointsX, x0);
    push(pointsY, y0);
    field[x0][y0] = 0;
    while (!isEmpty(pointsX))
    {
        int x = pop(pointsX);
        int y = pop(pointsY);
        if (x == x1 && y == y1)
        {
            result = true;
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (isSpace(field, width, height, newX, newY))
            {
                field[newX][newY] = field[x][y] + 1;
                push(pointsX, newX);
                push(pointsY, newY);
            }
        }
    }
    removeQueue(pointsX);
    removeQueue(pointsY);
    return result;
}

void restorePath(int **field, int x, int y, int *&pathX, int *&pathY)
{
    if (field[x][y] < 0)
        return;
    int distance = field[x][y];
    pathX = new int[distance + 1];
    pathY = new int[distance + 1];
    pathX[distance] = x;
    pathY[distance] = y;
    while (distance > 0)
    {
        for (int i = 0; i < 4; i++)
        {
            if (field[x + dx[i]][y + dy[i]] == distance - 1)
            {
                x = x + dx[i];
                y = y + dy[i];
                distance--;
                pathX[distance] = x;
                pathY[distance] = y;
                break;
            }
        }
    }
}

int main()
{
    ifstream fin("file.txt");
    int n, m;
    fin >> n >> m;
    int **field = new int*[n];
    for (int i = 0; i < n; i++)
    {
        field[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            fin >> field[i][j];
        }
    }
    int x0, y0, x1, y1;
    fin >> x0 >> y0 >> x1 >> y1;
    Lee(field, n, m, x0, y0, x1, y1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%2d ", field[i][j]);
        }
        printf("\n");
    }
    int *pathX;
    int *pathY;
    restorePath(field, x1, y1, pathX, pathY);
    for (int i = 0; i <= field[x1][y1]; i++)
    {
        cout << pathX[i] << " " << pathY[i] << endl;
    }
    return 0;
}
