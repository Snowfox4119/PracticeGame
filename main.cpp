#include <iostream>
#include <raylib.h>

using namespace std;

int main () {

    const int screenWidth = 800;
    const int screenHeight = 600;

    cout << "Hello World" << endl;

    InitWindow(screenWidth, screenHeight, "Practice Game");
    SetTargetFPS(60);

    while (WindowShouldClose() == false){
        BeginDrawing();
        ClearBackground(WHITE);
        DrawText("Text", 100, 100, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}