#include <stdio.h>
#include <stdbool.h>

#include "raylib.h"

int main(){
	const int screen_width = 800;
	const int screen_height = 600;

	int x = 0;
	int y = 200;
	
	size_t pressed = false;
	
	InitWindow(screen_width, screen_height, "My first graphics lib");
	SetTargetFPS(60);

	while (!WindowShouldClose()){
			
		BeginDrawing();
			ClearBackground(RAYWHITE);

			DrawText("Press Start to begin!", x++, y, 20, LIGHTGRAY);

			pressed = IsKeyPressed(KEY_SPACE) ? ~pressed : pressed;
			if (pressed)
				DrawCircle(screen_width/2, 100 + screen_height/2, 50, RED);
			else
				DrawCircle(screen_width/2, screen_height/2, 50, RED);

		EndDrawing();

	}
	CloseWindow();
	return 0;
}
