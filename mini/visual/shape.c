#include <stdio.h>

#include "raylib.h"

int main(){
	const int screen_width = 800;
	const int screen_height = 600;

	InitWindow(screen_width, screen_height, "My first graphics lib");

	SetTargetFPS(60);

	while (!WindowShouldClose()){
		
		BeginDrawing();
			ClearBackground(RAYWHITE);
			DrawCircle(screen_width/2, screen_height/2, 20, RED);
			DrawText("Hello World!", screen_width/2, screen_height/2, 20, LIGHTGRAY);
		EndDrawing();
	}
	CloseWindow();
	return 0;
}
