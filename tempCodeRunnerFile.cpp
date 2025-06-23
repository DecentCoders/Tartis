#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>

using namespace std;

const int width = 10;
const int height = 20;
int field[height][width] = {0};
int score = 0;
bool gameOver = false;

// Tetromino shapes (4x4 grid, encoded as 16-character strings)
string tetromino[7] = {
    "...."
    "XXXX"
    "...."
    "....", // I

    ".X.."
    ".X.."
    ".XX."
    "....", // L

    "..X."
    "..X."
    ".XX."
    "....", // J

    "...."
    ".XX."
    ".XX."
    "....", // O

    ".X.."
    "XXX."
    "...."
    "....", // T

    "..XX"
    ".XX."
    "...."
    "....", // S

    ".XX."
    "..XX"
    "...."
    "...." // Z
};

int currentPiece, rotation = 0;
int x = width / 2 - 2, y = 0;

// Rotate index in 4x4
int rotate(int px, int py, int r)
{
    switch (r % 4)
    {
    case 0:
        return py * 4 + px;
    case 1:
        return 12 + py - (px * 4);
    case 2:
        return 15 - (py * 4) - px;
    case 3:
        return 3 - py + (px * 4);
    }
    return 0;
}

bool doesFit(int n, int r, int posX, int posY)
{
    for (int py = 0; py < 4; py++)
        for (int px = 0; px < 4; px++)
        {
            int pi = rotate(px, py, r);
            int fi = posY + py;
            int fj = posX + px;
            if (tetromino[n][pi] == 'X')
            {
                if (fj < 0 || fj >= width || fi >= height)
                    return false;
                if (fi >= 0 && field[fi][fj])
                    return false;
            }
        }
    return true;
}

void draw()
{
    system("cls");
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (field[i][j] == 0)
                cout << ".";
            else
                cout << "#";
        }
        cout << endl;
    }

    // Draw current block
    for (int py = 0; py < 4; py++)
        for (int px = 0; px < 4; px++)
        {
            if (tetromino[currentPiece][rotate(px, py, rotation)] == 'X')
            {
                int fx = x + px;
                int fy = y + py;
                if (fy >= 0 && fy < height && fx >= 0 && fx < width)
                {
                    COORD pos = {(SHORT)fx, (SHORT)fy};
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
                    cout << "O";
                }
            }
        }

    // Show score
    COORD scorePos = {0, height + 1};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), scorePos);
    cout << "Score: " << score;
}

void lockPiece()
{
    for (int py = 0; py < 4; py++)
        for (int px = 0; px < 4; px++)
        {
            if (tetromino[currentPiece][rotate(px, py, rotation)] == 'X')
            {
                int fx = x + px;
                int fy = y + py;
                if (fy >= 0 && fy < height && fx >= 0 && fx < width)
                    field[fy][fx] = 1;
            }
        }

    // Line clear
    for (int i = height - 1; i >= 0; i--)
    {
        bool full = true;
        for (int j = 0; j < width; j++)
        {
            if (field[i][j] == 0)
            {
                full = false;
                break;
            }
        }

        if (full)
        {
            for (int k = i; k > 0; k--)
                for (int j = 0; j < width; j++)
                    field[k][j] = field[k - 1][j];
            for (int j = 0; j < width; j++)
                field[0][j] = 0;

            score += 100;
            i++; // check same row again
        }
    }
}

void spawnPiece()
{
    currentPiece = rand() % 7;
    rotation = 0;
    x = width / 2 - 2;
    y = 0;
    if (!doesFit(currentPiece, rotation, x, y))
        gameOver = true;
}

void input()
{
    if (_kbhit())
    {
        char key = _getch();
        if (key == 'a' && doesFit(currentPiece, rotation, x - 1, y))
            x--;
        if (key == 'd' && doesFit(currentPiece, rotation, x + 1, y))
            x++;
        if (key == 's' && doesFit(currentPiece, rotation, x, y + 1))
            y++;
        if (key == 'w' && doesFit(currentPiece, rotation + 1, x, y))
            rotation++;
    }
}

void logic()
{
    static int tick = 0;
    tick++;
    if (tick >= 10)
    {
        if (doesFit(currentPiece, rotation, x, y + 1))
            y++;
        else
        {
            lockPiece();
            spawnPiece();
        }
        tick = 0;
    }
}

int main()
{
    srand(time(0));
    spawnPiece();

    while (!gameOver)
    {
        draw();
        input();
        logic();
        Sleep(50);
    }

    COORD endPos = {0, height + 3};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), endPos);
    cout << "Game Over! Final Score: " << score << endl;
    system("pause");
    return 0;
}
