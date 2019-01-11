#include "Assertions.h"
#include "GameObject.h"

int main()
{
	TerryAssertion();

	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "Tank");
	SetTargetFPS(60);

	GameObject TankBase("TankBase.png", true);
	GameObject TankBarrel("TankBarrel.png", &TankBase, true);


	TankBase.addChild(&TankBarrel);
	TankBase.transform.localPos = { (float)((screenWidth / 2) - (TankBase.texture.width / 2)), (float)((screenHeight / 2) - (TankBase.texture.height / 2)) };

	TankBarrel.transform.localPos = { 0,0 };


	while (!WindowShouldClose())
	{
		/*if (IsKeyDown(KEY_LEFT))
			TankBarrel.transform.rotate(-1);
		if (IsKeyDown(KEY_RIGHT))
			TankBarrel.transform.rotate(1);*/
		TankBarrel.transform.lookAt({ (float)GetMouseX(), (float)GetMouseY() });

		if (IsKeyDown(KEY_A))
			TankBase.transform.rotate(-1);
		if (IsKeyDown(KEY_D))
			TankBase.transform.rotate(1);

		if (IsKeyDown(KEY_W))
			TankBase.transform.localPos += TankBase.transform.forward() * 2;
		if (IsKeyDown(KEY_S))
			TankBase.transform.localPos -= TankBase.transform.forward() * 2;


		BeginDrawing();
		ClearBackground(BLACK);

		TankBase.Update();
		
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
