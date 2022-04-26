#include <stdio.h>
#include "string.h"
#include "raylib.h"

struct Ball {
    float x, y;
    float speedX, speedY;
    float radius;
};

struct Puddle {
    float x, y;
    float speed;
    float width, height;
};

int main() {
    InitWindow(800, 600, "First");

    // Ball data
    struct Ball ball;
    ball.x = GetScreenWidth()/2;
    ball.y = GetScreenHeight()/2;
    ball.radius = 5;

    ball.speedX = 300;
    ball.speedY = 300;

    // PuddleOne data
    struct Puddle puddleOne;
    puddleOne.x = 50;
    puddleOne.y = GetScreenHeight()/2 - 50;

    puddleOne.width = 10;
    puddleOne.height = 100;

    puddleOne.speed = 500;

    // PuddleTwo data
    struct Puddle puddleTwo;
    puddleTwo.x = GetScreenWidth() - 50 - 10;
    puddleTwo.y = GetScreenHeight() / 2 - 50;

    puddleTwo.width = 10;
    puddleTwo.height = 100;

    puddleTwo.speed = 500;

    while (!WindowShouldClose()) {
        ball.x += ball.speedX * GetFrameTime();
        ball.y += ball.speedY * GetFrameTime();

        if (ball.y > GetScreenHeight()) {
            ball.y = GetScreenHeight();
            ball.speedY *= -1;
        } else if (ball.y < 0) {
            ball.y = 0;
            ball.speedY *= -1;
        }

        if (ball.x > GetScreenWidth() || ball.x < 0) {
            ball.x = GetScreenWidth()/2;
            ball.y = GetScreenHeight()/2;
        }

        if (IsKeyDown(KEY_W)) {
            puddleOne.y -= puddleOne.speed * GetFrameTime();
        } else if (IsKeyDown(KEY_S)) {
            puddleOne.y += puddleOne.speed * GetFrameTime();
        }

        if (IsKeyDown(KEY_UP)) {
            puddleTwo.y -= puddleTwo.speed * GetFrameTime();
        } else if (IsKeyDown(KEY_DOWN)) {
            puddleTwo.y += puddleTwo.speed * GetFrameTime();
        }

        if (ball.x < puddleTwo.x + puddleTwo.width &&
            ball.x + ball.radius * 2 > puddleTwo.x &&
            ball.y < puddleTwo.y + puddleTwo.height &&
            ball.radius * 2 + ball.y > puddleTwo.y) {
            ball.speedX *= -1;
        }

        if (ball.x < puddleOne.x + puddleOne.width &&
            ball.x + ball.radius * 2 > puddleOne.x &&
            ball.y < puddleOne.y + puddleOne.height &&
            ball.radius * 2 + ball.y > puddleOne.y) {
            ball.speedX *= -1;
        }

        BeginDrawing();
            ClearBackground(BLACK);

            DrawCircle((int) ball.x, (int) ball.y, (int) ball.radius, WHITE);
            DrawRectangle(puddleOne.x, puddleOne.y, puddleOne.width, puddleOne.height, WHITE);
            DrawRectangle(puddleTwo.x, puddleTwo.y, puddleTwo.width, puddleTwo.height, WHITE);

            DrawFPS(10, 10);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
