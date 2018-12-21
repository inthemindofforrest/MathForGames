#include "Ball.h"
//#include "ParticleSpawner.h"
#include "Rand.h"
#include <time.h>
#include "Matrix3.h"
#include "Matrix4.h"


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
	//srand(time(NULL));

	//int screenWidth = 1920;
	//int screenHeight = 1080;

	//InitWindow(screenWidth, screenHeight, "no.... no... no");
	//SetTargetFPS(60);
	//std::vector<vec2> Lines;
	//std::vector<Color>LineColors;
	//std::vector<int> SizeOfLine;


	//float timer = 0;
	//Color LineColor = BLACK;

	///*Rectangle p0{ 0, 300,30,30 }, p1{ 300, 200,30,30 }, p2{ 100, 50,30,30 };
	//bool p0Grabbed = false, p1Grabbed = false, p2Grabbed = false;
	//Ball Player;
	//
	//Player.tex = LoadTexture("Ball.png");
	//Player.Position = {p0.x, p0.y};

	//

	//int turn = 0;*/
	//RandomNumber num;
	//Ball Player;
	//Player.tex = LoadTexture("Ball.png");
	/*ParticleSpawner newSpawner;
	
	Rectangle Button{200,200,200,50};
	Color ButtonColor = GREEN;

	float timer = 0;

	
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
	


	//while (!WindowShouldClose())
	//{
	//	int sizelinesize = num.rand(50, 200);
	//	/*Player.Update();
	//	newSpawner.Update();

	//	if (IsKeyPressed(KEY_SPACE))
	//		newSpawner.AddParticle(Player.Position);
	//	timer += GetFrameTime();

	//	if (CheckCollisionPointRec(GetMousePosition(), Button))
	//	{
	//		ButtonColor.b = lerp(ButtonColor.b, (unsigned char)0, timer );
	//		ButtonColor.g = lerp(ButtonColor.g, (unsigned char)0, timer);
	//		ButtonColor.r = lerp(ButtonColor.r, (unsigned char)255, timer);
	//		if (ButtonColor.r == 255)
	//			timer = 0;
	//	}
	//	else
	//	{
	//		ButtonColor.b = lerp(ButtonColor.b, (unsigned char)255, timer);
	//		ButtonColor.g = lerp(ButtonColor.g, (unsigned char)255, timer);
	//		ButtonColor.r = lerp(ButtonColor.r, (unsigned char)255, timer);
	//		if (ButtonColor.r == 255 && ButtonColor.b == 255)
	//			timer = 0;
	//	}*/
	//	timer += GetFrameTime();
	//	//if (turn == 0)
		//{
		//	Player.Position = { quadraticBezier(p0.x, p2.x, p1.x, timer * .75f), quadraticBezier(p0.y, p2.y, p1.y, timer * .75f) };
		//	if (abs(Player.Position.x - p1.x) <= 1 && abs(Player.Position.y - p1.y) <= 1)
		//	{
		//		turn = 1;
		//		timer = 0;
		//	}
		//}
		//else if (turn == 1)
		//{
		//	Player.Position = { quadraticBezier(p1.x, p0.x, p2.x, timer * .75f), quadraticBezier(p1.y, p0.y, p2.y, timer * .75f) };
		//	if (abs(Player.Position.x - p2.x) <= 1 && abs(Player.Position.y - p2.y) <= 1)
		//	{
		//		turn = 2;
		//		timer = 0;
		//	}
		//}
		//else
		//{
		//	Player.Position = { quadraticBezier(p2.x, p1.x, p0.x, timer * .75f), quadraticBezier(p2.y, p1.y, p0.y, timer * .75f) };
		//	if (abs(Player.Position.x - p0.x) <= 1 && abs(Player.Position.y - p0.y) <= 1)
		//	{
		//		turn = 0;
		//		timer = 0;
		//	}
		//}


		//if (timer - (int)timer < 2)
		//{

	//	Lines.push_back(Player.Position);
	//	LineColors.push_back(LineColor);
	//	SizeOfLine.push_back(sizelinesize);
	//	//}

	//	num.seedRand(time(NULL));
	//	int MinNu = num.rand(50,100);
	//	int MaxNu = num.rand(101, 150);
	//	Player.Position += {num.rand(0,100) < 50 ? (float)num.rand(MinNu, MaxNu) : -(float)num.rand(MinNu, MaxNu), num.rand(0, 100) < 50 ? (float)num.rand(MinNu, MaxNu) : -(float)num.rand(MinNu, MaxNu)};


	//	/*if (Player.Position.x < 0)
	//		Player.Position.x = 0;
	//	if (Player.Position.y < 0)
	//		Player.Position.y = 0;
	//	if (Player.Position.x > GetScreenWidth() - 10)
	//		Player.Position.x = GetScreenWidth() - 10;
	//	if (Player.Position.y > GetScreenHeight() - 10)
	//		Player.Position.y = GetScreenHeight() - 10;*/
	//	if (Player.Position.y > GetScreenHeight() + 10 || Player.Position.y < 0)
	//		Player.Position.y = GetScreenHeight() / 2;
	//	if (Player.Position.x > GetScreenWidth() + 10 || Player.Position.x < 0)
	//		Player.Position.x = GetScreenWidth() / 2;
	//	/*if (Player.Position.y >= GetScreenHeight() + 10 || Player.Position.y <= 0)
	//		Player.Position.y *= -1;
	//	if (Player.Position.x >= GetScreenWidth() + 10 || Player.Position.x <= 0)
	//		Player.Position.x *= -1; */

	//	//if (CheckCollisionPointRec(GetMousePosition(), p0) &&
	//	//	IsMouseButtonDown(MOUSE_LEFT_BUTTON) &&
	//	//	p0Grabbed == p1Grabbed == p2Grabbed == false)
	//	//{
	//	//	p0Grabbed = true;
	//	//}
	//	//if (CheckCollisionPointRec(GetMousePosition(), p1) &&
	//	//	IsMouseButtonDown(MOUSE_LEFT_BUTTON) &&
	//	//	p0Grabbed == p1Grabbed == p2Grabbed == false)
	//	//{
	//	//	p1Grabbed = true;
	//	//}
	//	//if (CheckCollisionPointRec(GetMousePosition(), p2) &&
	//	//	IsMouseButtonDown(MOUSE_LEFT_BUTTON) &&
	//	//	p0Grabbed == p1Grabbed == p2Grabbed == false)
	//	//{
	//	//	p2Grabbed = true;
	//	//}

	//	//if (p0Grabbed)
	//	//{
	//	//	p0.x = GetMouseX() - 15;
	//	//	p0.y = GetMouseY() - 15;
	//	//}
	//	//if (p1Grabbed)
	//	//{
	//	//	p1.x = GetMouseX() - 15;
	//	//	p1.y = GetMouseY() - 15;
	//	//}
	//	//if (p2Grabbed)
	//	//{
	//	//	p2.x = GetMouseX() - 15;
	//	//	p2.y = GetMouseY() - 15;
	//	//}

	//	//if (IsMouseButtonUp(MOUSE_LEFT_BUTTON))
	//	//	p0Grabbed = p1Grabbed = p2Grabbed = false;

	//	////std::cout << Player.Position.x << "," << Player.Position.y << std::endl;

	//	if (Lines.size() > 25000)
	//	{
	//		for (int i = 0; i < Lines.size() - 1; i++)
	//		{
	//			Lines[i] = Lines[i + 1];
	//			LineColors[i] = LineColors[i + 1];
	//			SizeOfLine[i] = SizeOfLine[i + 1];
	//		}
	//		Lines.pop_back();
	//		LineColors.pop_back();
	//		SizeOfLine.pop_back();
	//	}
	//	{
	//		/*if (LineColor.r < 255 && LineColor.b == 0 && LineColor.g == 0)
	//			LineColor.r++;
	//		else if (LineColor.r >= 255 && LineColor.b < 255 && LineColor.g == 0)
	//			LineColor.b++;
	//		else if (LineColor.r >= 255 && LineColor.b >= 255 && LineColor.g < 255)
	//			LineColor.g++;
	//		else if (LineColor.r > 0)
	//			LineColor.r--;
	//		else if (LineColor.b > 0)
	//			LineColor.b--;
	//		else if (LineColor.g > 0)
	//			LineColor.g--;*/
	//		LineColor = { (unsigned char)num.rand(0,255) ,(unsigned char)num.rand(0,255),(unsigned char)num.rand(0,255),(unsigned char)num.rand(0,255) };
	//	}
	//	BeginDrawing();
	//	ClearBackground(BLACK);

	//	/*DrawRectangle(p1.x, p1.y, p1.width, p1.height, WHITE);
	//	DrawRectangle(p2.x, p2.y, p2.width, p2.height, WHITE);
	//	DrawRectangle(p0.x, p0.y, p0.width, p2.height, WHITE);
	//	*/
	//	
	//	if (Lines.size() > 2)
	//		for (int i = 0; i < Lines.size() - 3; i++)
	//		{
	//			DrawLineEx({ Lines[i].x, Lines[i].y }, { Lines[i + 1].x, Lines[i + 1].y }, SizeOfLine[i]/4, LineColors[i]);
	//			DrawText(std::to_string(i).c_str(), Lines[i].x, Lines[i].y, SizeOfLine[i], LineColors[i]);
	//			DrawCircle(Lines[i].x, Lines[i].y, SizeOfLine[i]/2, LineColors[i]);
	//			DrawRectangleLinesEx({ (float)(Lines[i].x - SizeOfLine[i] / 2), (float)(Lines[i].y - SizeOfLine[i] / 2),(float)SizeOfLine[i],(float)SizeOfLine[i] }, 10, LineColors[i]);
	//			Texture2D ballt = LoadTexture("Ball.png");
	//			DrawTextureEx(ballt, { Lines[i].x - ballt.width / 2, Lines[i].y - ballt.height / 2}, 0, SizeOfLine[i] / 10, LineColors[i]);
	//			DrawLineEx({ Lines[i + 1].x, Lines[i+ 1].y }, { Lines[Lines.size() - 1].x, Lines[Lines.size() - 1].y }, SizeOfLine[i] / 4, LineColors[i]);
	//			DrawCircleGradient(Lines[i].x, Lines[i].y, SizeOfLine[i] / 2, LineColors[i], { LineColors[i].b,LineColors[i].r, LineColors[i].b, LineColors[i].a });
	//			DrawLineBezier({ Lines[i].x, Lines[i].y }, { Lines[i + 1].x, Lines[i + 1].y }, SizeOfLine[i] / 4, LineColors[i]);
	//			DrawPixel(Lines[i].x, Lines[i].y, LineColors[i]);
	//			DrawTriangle({ Lines[i].x, Lines[i].y }, { Lines[i + 1].x, Lines[i+ 1].y }, { Lines[i+ 2].x, Lines[i+ 2].y }, LineColors[i]);
	//			DrawFPS(Lines[i].x, Lines[i].y);
	//		}
	//	//Player.Draw();
	//	//newSpawner.Draw();
	//	//DrawRectangleRec(Button, ButtonColor);

	//	EndDrawing();
	//}
	//CloseWindow();

	
mat4 First(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16);
mat4 Second(16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1);

vec4 testVec2 = { 5, 3, 5, 3 };

mat4 Tester;
Tester.set(First.getTranspose());

	
	
	return 0;
}