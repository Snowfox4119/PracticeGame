#include <iostream>
#include <raylib.h>
#include <vector>

using namespace std;

float boardCord[4][4] = {
    {100, 550, 100, 550},
    {100, 100, 550, 550},
    {350, 350, 350, 350},
    {350, 350, 350, 350}
};


class Game {
public:    

    void Draw() {
        int x = 0;
        while (x < 4) {
            DrawRectangleLinesEx(Rectangle{boardCord[0][x], boardCord[1][x], boardCord[2][x], boardCord[3][x]}, 2, WHITE);
            x += 1;
        }
    }
};

int main () {

    InitWindow(1000, 1000, "Practice Game");
    SetTargetFPS(60);

    Game game = Game();

    while (WindowShouldClose() == false){
        BeginDrawing();
        ClearBackground(BLACK);
        //game.Draw();
        
        game.Draw();

        DrawText("Score: 0", 100, 50, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}