#include <stdio.h>

const int height = 60;
const int width = 141;


void return_cursor(int w, int h) 
{
    for (int i = 0; i < h; ++i)
    {
        printf("\033[F");
    }
}

void render_cross(int w, int x, int y, char* buffer)
{
    buffer[(y * w) + x] = 'X';
}

void clear_buffer(int w, int h, char* buffer) 
{
    for (int i = 0; i < h; ++i) 
    {
        for (int j = 0; j < w; ++j) buffer[(i * w) + j] = (i == 0 || i == h - 1) ? '-' : ' ';
        buffer[(i * w)] = '|';
        buffer[(i * w) + w - 2] = '|';
        buffer[(i * w) + w - 1] = '\n';
    }
    buffer[w * h] = '\0';
}


int main() 
{
    char screen_buffer[width * height + 1];
    int x = width / 2, y = height / 2;
    while (true) 
    {
        clear_buffer(width, height, screen_buffer);
        render_cross(width, x, y, screen_buffer);
        return_cursor(width, height);
        printf(screen_buffer);
        if (getchar() == 27)
        {
            if (getchar() == 91)
            {
                switch (getchar()) 
                {
                    case 65:
                        if (y >= 2) y--;
                        break;
                    case 66:
                        if (y < height - 2) y++;
                        break;
                    case 67:
                        if (x < width - 3) x++;
                        break;
                    case 68:
                        if (x >= 2) x--;
                        break;
                }
            }
            else
            {
                break;
            }
        }
        printf("\r\033[K\033[F");
    }
    return 0;
}