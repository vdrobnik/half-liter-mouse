#include "Header.h"
#include <iostream>
#include <SFML/Graphics.hpp>


sf::Sprite disp::DisplayLayers::Layers(bool key, double time, bool PressedABC)
	{
		if (Timer_forABC >= 10 || Timer_forRU >= 10)
		{
			First = false;
			Second = false;
			Third = true;
		}
		//////////////////////////////////
		if (First == true)
			return S_mouse_1;//
		else
			if (Second == true)
			{
				if (key == true)
				{
					if (PressedABC == 1)
						Timer_forABC = Timer_forABC + (0.000005 * time);
					else
						if (Timer_forRU)
							Timer_forRU = Timer_forRU + (0.000005 * time);
					return S_mouse_2_2;//
				}
				else
					if (key == false)
						return S_mouse_2_1;//
			}
			else
  				if (Third == true)
					if (PressedABC == 1)
						return S_mouse_3_1;//
					else
						if (PressedABC == 0)
							return S_mouse_3_2;//
	}
