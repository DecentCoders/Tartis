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

WORD colors[7] = {11, 6, 9, 14, 13, 10, 12};

int currentPiece, rotation = 0;
int x = width / 2 - 2, y = 0;

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
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (field[i][j] == 0)
            {
                SetConsoleTextAttribute(console, 7);
                cout << ".";
            }
            else
            {
                SetConsoleTextAttribute(console, colors[field[i][j] - 1]);
                cout << "#";
            }
        }
        cout << endl;
    }

    SetConsoleTextAttribute(console, colors[currentPiece]);
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
                    SetConsoleCursorPosition(console, pos);
                    cout << "O";
                }
            }
        }
    SetConsoleTextAttribute(console, 15);

    COORD scorePos = {0, height + 1};
    SetConsoleCursorPosition(console, scorePos);
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
                    field[fy][fx] = currentPiece + 1;
            }
        }

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
            i++;
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
        int key = _getch();
        if (key == 0 || key == 224)
        { // Arrow key prefix
            key = _getch();
            if (key == 75)
            { // Left arrow
                if (doesFit(currentPiece, rotation, x - 1, y))
                    x--;
            }
            else if (key == 77)
            { // Right arrow
                if (doesFit(currentPiece, rotation, x + 1, y))
                    x++;
            }
            else if (key == 72)
            { // Up arrow (rotate)
                if (doesFit(currentPiece, rotation + 1, x, y))
                    rotation++;
            }
            else if (key == 80)
            { // Down arrow (soft drop)
                if (doesFit(currentPiece, rotation, x, y + 1))
                    y++;
            }
        }
        else
        {
            // Handle other keys if needed
        }
    }
}

void logic()
{
    static int tick = 0;
    int level = score / 1000;
    int speed = max(10 - level, 1);

    tick++;
    if (tick >= speed)
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