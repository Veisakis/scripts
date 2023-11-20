#include <stdio.h>
#include <stdbool.h>

#include "raylib.h"

int main(){
	const int screen_width = 800;
	const int screen_height = 600;

	InitWindow(screen_width, screen_height, "Download Visualizer");
	SetTargetFPS(60);

	while (!WindowShouldClose()){

		BeginDrawing();

			ClearBackground(RAYWHITE);
			DrawCircle(screen_width/2, 100 + screen_height/2, 50, RED);

		EndDrawing();

	}
	CloseWindow();
	return 0;
}
