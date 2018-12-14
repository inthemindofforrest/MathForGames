#include "Ball.h"
#include "ParticleSpawner.h"

#include <time.h>


/*
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
	assert(moveTowards(1, 5, 6) == 5);
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

int main()
{
	srand(time(NULL));

	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "YES!");
	SetTargetFPS(60);

	float timer = 0;


	Rectangle p0{ 0, 300,30,30 }, p1{ 300, 200,30,30 }, p2{ 100, 50,30,30 };
	bool p0Grabbed = false, p1Grabbed = false, p2Grabbed = false;
	Ball Player;
	std::vector<vec2> Lines;
	std::vector<Color>LineColors;
	Player.tex = LoadTexture("Ball.png");
	Player.Position = {p0.x, p0.y};

	Color LineColor = BLACK;

	int turn = 0;

	/*ParticleSpawner newSpawner;
	Ball Player;
	Rectangle Button{200,200,200,50};
	Color ButtonColor = GREEN;

	float timer = 0;

	Player.tex = LoadTexture("Ball.png");
	Player.speed = .5f;*/

	//Utils
	/*{
		assert("true is true", true);
		assert("the opposite of false is true", !false);
		assert("1+1=2", 1 + 1 == 2);
		assert("1+2=4", 1 + 2 == 4);


		assert("sum I", 3, sum(1, 2));
		assert("sum II", 5, sum(2, 3));
		assert("min", 3, min(3, 7));
		assert("max", 7, max(3, 7));
		assert("clamp", 5, clamp(5, 3, 7));


		vec3 a = { 2, 2, 2 };
		vec3 b = { 1, 1, 1 };
		vec3 diff = a - b;

		assert("diff x", 1.0f, diff.x, 0.0001f);
		assert("diff y", 1.0f, diff.y, 0.0001f);
		assert("diff z", 1.0f, diff.z, 0.0001f);
	}*/

	while (!WindowShouldClose())
	{
		/*Player.Update();
		newSpawner.Update();

		if (IsKeyPressed(KEY_SPACE))
			newSpawner.AddParticle(Player.Position);
		timer += GetFrameTime();

		if (CheckCollisionPointRec(GetMousePosition(), Button))
		{
			ButtonColor.b = lerp(ButtonColor.b, (unsigned char)0, timer );
			ButtonColor.g = lerp(ButtonColor.g, (unsigned char)0, timer);
			ButtonColor.r = lerp(ButtonColor.r, (unsigned char)255, timer);
			if (ButtonColor.r == 255)
				timer = 0;
		}
		else
		{
			ButtonColor.b = lerp(ButtonColor.b, (unsigned char)255, timer);
			ButtonColor.g = lerp(ButtonColor.g, (unsigned char)255, timer);
			ButtonColor.r = lerp(ButtonColor.r, (unsigned char)255, timer);
			if (ButtonColor.r == 255 && ButtonColor.b == 255)
				timer = 0;
		}*/
		timer += GetFrameTime();
		if (turn == 0)
		{
			Player.Position = { quadraticBezier(p0.x, p2.x, p1.x, timer * .75f), quadraticBezier(p0.y, p2.y, p1.y, timer * .75f) };
			if (abs(Player.Position.x - p1.x) <= 1 && abs(Player.Position.y - p1.y) <= 1)
			{
				turn = 1;
				timer = 0;
			}
		}
		else if (turn == 1)
		{
			Player.Position = { quadraticBezier(p1.x, p0.x, p2.x, timer * .75f), quadraticBezier(p1.y, p0.y, p2.y, timer * .75f) };
			if (abs(Player.Position.x - p2.x) <= 1 && abs(Player.Position.y - p2.y) <= 1)
			{
				turn = 2;
				timer = 0;
			}
		}
		else
		{
			Player.Position = { quadraticBezier(p2.x, p1.x, p0.x, timer * .75f), quadraticBezier(p2.y, p1.y, p0.y, timer * .75f) };
			if (abs(Player.Position.x - p0.x) <= 1 && abs(Player.Position.y - p0.y) <= 1)
			{
				turn = 0;
				timer = 0;
			}
		}


		//if (timer - (int)timer < 2)
		//{

		Lines.push_back(Player.Position);
		LineColors.push_back(LineColor);
		//}


		if (CheckCollisionPointRec(GetMousePosition(), p0) &&
			IsMouseButtonDown(MOUSE_LEFT_BUTTON) &&
			p0Grabbed == p1Grabbed == p2Grabbed == false)
		{
			p0Grabbed = true;
		}
		if (CheckCollisionPointRec(GetMousePosition(), p1) &&
			IsMouseButtonDown(MOUSE_LEFT_BUTTON) &&
			p0Grabbed == p1Grabbed == p2Grabbed == false)
		{
			p1Grabbed = true;
		}
		if (CheckCollisionPointRec(GetMousePosition(), p2) &&
			IsMouseButtonDown(MOUSE_LEFT_BUTTON) &&
			p0Grabbed == p1Grabbed == p2Grabbed == false)
		{
			p2Grabbed = true;
		}

		if (p0Grabbed)
		{
			p0.x = GetMouseX() - 15;
			p0.y = GetMouseY() - 15;
		}
		if (p1Grabbed)
		{
			p1.x = GetMouseX() - 15;
			p1.y = GetMouseY() - 15;
		}
		if (p2Grabbed)
		{
			p2.x = GetMouseX() - 15;
			p2.y = GetMouseY() - 15;
		}

		if (IsMouseButtonUp(MOUSE_LEFT_BUTTON))
			p0Grabbed = p1Grabbed = p2Grabbed = false;

		//std::cout << Player.Position.x << "," << Player.Position.y << std::endl;

		{
			if (LineColor.r < 255 && LineColor.b == 0 && LineColor.g == 0)
				LineColor.r++;
			else if (LineColor.r >= 255 && LineColor.b < 255 && LineColor.g == 0)
				LineColor.b++;
			else if (LineColor.r >= 255 && LineColor.b >= 255 && LineColor.g < 255)
				LineColor.g++;
			else if (LineColor.r > 0)
				LineColor.r--;
			else if (LineColor.b > 0)
				LineColor.b--;
			else if (LineColor.g > 0)
				LineColor.g--;
		}
		BeginDrawing();
		

		DrawRectangle(p1.x, p1.y, p1.width, p1.height, WHITE);
		DrawRectangle(p2.x, p2.y, p2.width, p2.height, WHITE);
		DrawRectangle(p0.x, p0.y, p0.width, p2.height, WHITE);
		ClearBackground(BLACK);
		if (Lines.size() > 2)
			for (int i = 0; i < Lines.size() - 2; i++)
				DrawLineEx({ Lines[i].x, Lines[i].y }, { Lines[i + 1].x, Lines[i + 1].y }, 20, LineColors[i]);
		//Player.Draw();
		//newSpawner.Draw();
		//DrawRectangleRec(Button, ButtonColor);

		EndDrawing();
	}
	CloseWindow();

	return 0;
}
