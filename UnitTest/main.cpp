#include <iostream>
#include "Vec2.h"
#include "raylib.h"
#include <string>
#include <cassert>

struct Ball
{
	Texture2D tex;
	vec2 Position{100,100};
	vec2 Forward{ 0,-1 };
	vec2 Right{ 1,0 };
	vec2 Direction{1,1};
	vec2 Center;
	bool IsActive = false;
	float Rotation;
	float timer = 0;

	float DistanceMultiplier = 50;
	float SpinSpeed = 3;

	void Update(vec2 Origin, float Timer, int Offset);
};

int main()
{
	int screenWidth = 800;
	int screenHeight = 450;

	const int Amount = 10;

	Ball TheBall[Amount];
	Ball Player;

	InitWindow(screenWidth, screenHeight, "Not Planet Destroyers");
	SetTargetFPS(60);
	HideCursor();

	float SpawnTimer = 1;
	float timer = 0;
	bool Crazy = false;


	Player.tex = LoadTexture("Ball.png");
	for(int i = 0; i < Amount; i++)
		TheBall[i].tex = LoadTexture("Ball.png");

	while (!WindowShouldClose())
	{
		//Timers
		{
			SpawnTimer -= GetFrameTime();
			timer += GetFrameTime();
		}

		if (Crazy)
		{
			for (int i = 0; i < Amount; i++)
			{
				TheBall[i].Center = { TheBall[i].Position.x + TheBall[i].tex.width / 2, TheBall[i].Position.y + TheBall[i].tex.height / 2 };
				TheBall[i].Position += TheBall[i].Direction * GetFrameTime() * 50;

				if (TheBall[i].Position.y >= GetScreenHeight() - TheBall[i].tex.height || TheBall[i].Position.y < 0)
				{
					TheBall[i].Direction.y *= -1;
					if(TheBall[i].Direction.x > 0)
						TheBall[i].Direction.x -= 15 * GetFrameTime();
					else
						TheBall[i].Direction.x += 15 * GetFrameTime();
				}
				if (TheBall[i].Position.x >= GetScreenWidth() - TheBall[i].tex.width || TheBall[i].Position.x < 0)
					TheBall[i].Direction.x *= -1;


				if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
				{
					//TheBall[i].Direction = ((MoveTo = { (float)GetMouseX(), (float)GetMouseY() }) - TheBall[i].Center).getNormalized();
					//DrawLineEx({ TheBall[i].Center.x, TheBall[i].Center.y }, { MoveTo.x, MoveTo.y }, 5, RED);
					//int dist = (MoveTo - TheBall[i].Center).magnitude();
					//DrawText(std::to_string(dist).c_str(),
					//	TheBall[i].Center.x + (MoveTo.x - TheBall[i].Center.x) / 2 - MeasureText(std::to_string(dist).c_str(),20) / 2,
					//	TheBall[i].Center.y + (MoveTo.y - TheBall[i].Center.y) / 2, 20, WHITE);
				}
				TheBall[i].Direction.y += 10 * GetFrameTime();


				if (TheBall[i].Position.y > GetScreenHeight() - TheBall[i].tex.height)
					TheBall[i].Position.y = GetScreenHeight() - TheBall[i].tex.height;
				if (TheBall[i].Position.y < 0)
					TheBall[i].Position.y = 0;
			}
		}
		if (!Crazy)
		{
			//Movement
			{
				Player.Position = { (float)GetMouseX() - Player.tex.width, (float)GetMouseY() - Player.tex.height };
			}

			//UpdateObjects
			{
				Player.Center = { (float)GetMouseX(), (float)GetMouseY()};

				if (SpawnTimer < 0)
				{
					SpawnTimer = .2f;
					for (int i = 0; i < Amount; i++)
						if (TheBall[i].IsActive == false)
						{
							TheBall[i].IsActive = true;
							break;
						}
				}
				for (int i = 0; i < Amount; i++)
					if (TheBall[i].IsActive)
						TheBall[i].Update(Player.Center, timer, 0);
				{
					if (IsKeyDown(KEY_PAGE_UP))
						for (int i = 0; i < Amount; i++)
							TheBall[i].SpinSpeed += 1 * GetFrameTime();
					if (IsKeyDown(KEY_PAGE_DOWN))
						for (int i = 0; i < Amount; i++)
							TheBall[i].SpinSpeed -= 1 * GetFrameTime();
				}
			}

			//std::cout << TheBall.Forward.angleBetween((Player.Position - TheBall.Position).getNormalized()) * RAD2DEG << std::endl;
			//if (IsKeyPressed(KEY_F) && TheBall.Forward.getNormalized().dot((Player.Position - TheBall.Position).getNormalized()) < 0) //&& Player.Position.getNormalized().dot(TheBall.Forward.getNormalized()) < 0)
			//{
			//	DrawBall = false;
			//	
			//}
		}
		//Draw
		{
			BeginDrawing();
			ClearBackground(BLACK);

			for (int i = 0; i < Amount; i++)
				if (TheBall[i].IsActive)
					DrawTextureEx(TheBall[i].tex, { TheBall[i].Position.x, TheBall[i].Position.y }, TheBall[i].Rotation, 1, WHITE);
			DrawTexture(Player.tex, Player.Position.x, Player.Position.y, PURPLE);

			EndDrawing();
		}


		if (IsKeyPressed(KEY_SPACE))
		{
			Crazy = !Crazy;
			for (int i = 0; i < Amount; i++)
				TheBall[i].Direction = { TheBall[i].SpinSpeed,1 };
		}
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

void Ball::Update(vec2 Origin, float Timer, int Offset)
{
	timer += GetFrameTime();
	Position = { (Origin.x - tex.width / 2 + sin((timer * SpinSpeed) + Offset) * DistanceMultiplier),
		(Origin.y - tex.height/2 + cos((timer * SpinSpeed) + Offset) * DistanceMultiplier)};
}
/*Position = { (Origin.x + sin(Timer * SpinSpeed* Offset) * DistanceMultiplier) + tex.width / 2 ,
		(Origin.y + cos(Timer * SpinSpeed) * DistanceMultiplier* Offset) + tex.height / 2  };*/