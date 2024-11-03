#include <iostream>
#include <raylib.h>

using namespace std;

double lastUpdateTime = 0;

float boardCord[4][4] = {
    {100, 550, 100, 550},
    {100, 100, 550, 550},
    {350, 350, 350, 350},
    {350, 350, 350, 350}
};

bool eventTriggered(double interval) {
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval) {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

class Player {
public:
    float cords[4] = {100, 300, 10, 10};
    bool running = false; 
    int side = -1;

    void Draw() {
        DrawRectangleLinesEx(Rectangle{cords[0], cords[1], cords[2], cords[3]}, 2, WHITE);
    }

    void Update() {
        if (running == true) {
            if (side == -1 && cords[0] > 100) {
                cords[0] -= 10;
                return;
            }
            if (side == 1 && cords[0] < 440) {
                cords[0] += 10;
                return;
            }
            running = false;
        }
    
    }
};

class Spike {
public:
    float cords[4] = {100, 100, 10, 10};

    void Draw() {
        DrawTriangleLines({100, 150}, {100, 160}, {110, 155}, RED);
    }
};
class Game {
public:    
    float position[4];

    void Draw(float x1, float x2, float y1, float y2) {
        DrawRectangleLinesEx(Rectangle{x1, x2, y1, y2}, 2, WHITE);
    }

    void BasicDraw() {
        int x = 1;
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
    Player player = Player();
    Spike spike = Spike();

    while (WindowShouldClose() == false){

        BeginDrawing();

        spike.Draw();

        player.Update();

        if (IsKeyPressed(KEY_F) && player.running == false) {
            player.side *= -1;
            player.running = true;
        }

        ClearBackground(BLACK);

        int x = 0;
        while (x < 4) {
            game.Draw(boardCord[0][x], boardCord[1][x], boardCord[2][x], boardCord[3][x]);
            x += 1;
        }

        player.Draw();

        DrawText("Score: 0", 100, 50, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}