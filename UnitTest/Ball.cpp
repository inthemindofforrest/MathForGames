#include "Ball.h"
void Ball::Update()
{

	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		newPosition.push_back({ (float)GetMouseX(), (float)GetMouseY() });
	if (IsKeyPressed(KEY_Q))
			LerpHealth < 90 ? LerpHealth += 10 : LerpHealth = 100;

	if (newPosition.size() > 0)
	{
		timer += GetFrameTime();
		Position = lerp(Position, newPosition[currentNewPosition], timer * speed);
		if (Position == newPosition[currentNewPosition])
		{
			if (currentNewPosition == newPosition.size() - 1)
				currentNewPosition = 0;
			else
				currentNewPosition++;
			timer = 0;
		}
	}
	if (LerpHealth != health)
	{
		AnotherFuckingTimer += GetFrameTime();
		health = lerp(health, LerpHealth, AnotherFuckingTimer);
	}
	else
	{
		AnotherFuckingTimer = 0;
		if (IsKeyDown(KEY_E))
			LerpHealth > 10 ? LerpHealth -= 10 : LerpHealth = 0;
		
	}
}

void Ball::Draw()
{
	DrawTexture(tex, Position.x, Position.y, WHITE);
	for (int i = 0; i < newPosition.size(); i++)
		DrawTexture(tex, newPosition[i].x, newPosition[i].y, GRAY);
	//DrawRectangle(10, 10, (int)((health / 100) * (GetScreenWidth() - 20)), 40, RED);
	//DrawRectangle(10, 10, (int)((LerpHealth / 100) * (GetScreenWidth() - 20)), 40, GREEN);
	//DrawRectangleLinesEx({10,10,(float)GetScreenWidth() - 20, 40},5, WHITE);
}