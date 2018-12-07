#include <iostream>
#include "Vec2.h"
#include "raylib.h"
#include <string>
#include <cassert>

struct Ball
{
	Texture2D tex;
	vec2 Position{100,100};
	vec2 Direction{1,1};
	vec2 Center;
};

int main()
{
	int screenWidth = 800;
	int screenHeight = 450;
	int speed = 250;
	Ball TheBall;
	Ball Player;
	vec2 MoveTo{0,0};

	InitWindow(screenWidth, screenHeight, "Not Planet Destroyers");
	SetTargetFPS(60);

	TheBall.tex = LoadTexture("Ball.png");
	Player.tex = LoadTexture("Ball.png");

	while (!WindowShouldClose())
	{
		TheBall.Center = { TheBall.Position.x + TheBall.tex.width / 2, TheBall.Position.y + TheBall.tex.height / 2 };
		TheBall.Position += TheBall.Direction * GetFrameTime() * speed;
		Player.Position += (MoveTo - Player.Position).getNormalized();

		if (TheBall.Position.y >= GetScreenHeight() - TheBall.tex.height || TheBall.Position.y < 0)
		{
			TheBall.Direction.y *= -1;
			if(TheBall.Direction.x > 0)
				TheBall.Direction.x -= 15 * GetFrameTime();
			else
				TheBall.Direction.x += 15 * GetFrameTime();
		}
		if (TheBall.Position.x >= GetScreenWidth() - TheBall.tex.width || TheBall.Position.x < 0)
			TheBall.Direction.x *= -1;


		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
		{
			TheBall.Direction = ((MoveTo = { (float)GetMouseX(), (float)GetMouseY() }) - TheBall.Center).getNormalized();
			DrawLineEx({ TheBall.Center.x, TheBall.Center.y }, { MoveTo.x, MoveTo.y }, 5, RED);
			int dist = (MoveTo - TheBall.Center).magnitude();
			DrawText(std::to_string(dist).c_str(),
				TheBall.Center.x + (MoveTo.x - TheBall.Center.x) / 2 - MeasureText(std::to_string(dist).c_str(),20) / 2,
				TheBall.Center.y + (MoveTo.y - TheBall.Center.y) / 2, 20, WHITE);
		}
		TheBall.Direction.y += 10 * GetFrameTime();
		

		if (TheBall.Position.y > GetScreenHeight() - TheBall.tex.height)
			TheBall.Position.y = GetScreenHeight() - TheBall.tex.height;
		if (TheBall.Position.y < 0)
			TheBall.Position.y = 0;

		BeginDrawing();
		ClearBackground(BLACK);

		DrawTexture(TheBall.tex, TheBall.Position.x, TheBall.Position.y, WHITE);
		//DrawTexture(Player.tex, Player.Position.x, Player.Position.y, PURPLE);


		EndDrawing();
	}

	CloseWindow();



	/*assert(min(10, 1) == 1);
	assert(max(1, 10) == 10);
	assert(clamp(1, 10, 100) == 10);
	assert(abs(-10) == 10);
	assert(pow(3, 3) == 27);
	assert(isPowerOfTwo(64) == true);
	assert(nextPowerOfTwo(14) == 16);
	assert(moveTowards(1, 5, 6) == 5);*/
	return 0;
}