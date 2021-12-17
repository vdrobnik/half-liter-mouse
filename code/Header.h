#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

namespace disp
{
	class DisplayLayers
	{
	public:
		bool First = true, Second = false, Third = false;

		unsigned int X_Width = 1280, Y_Height = 768;

		Sprite S_mouse_1;
		Sprite S_mouse_2_1;
		Sprite S_mouse_2_2;
		Sprite S_mouse_3_1;
		Sprite S_mouse_3_2;

		bool key = true;
		float Timer_forABC = 1, Timer_forRU = 1;


		Sprite Layers(bool key, double time, bool PressedABC);
	};

}
