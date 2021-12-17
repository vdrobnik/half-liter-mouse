#include <SFML/Graphics.hpp>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>

#include "Header.h"

using namespace std;
using namespace sf;

int main()
{
	bool PressedABC = 0;
	disp::DisplayLayers LayersMain;
	Clock clock;
	//////////////////////////////////////////////////////////////////
	Texture mouse_1;
	mouse_1.loadFromFile("texture//mouse_first.png");
	LayersMain.S_mouse_1.setTexture(mouse_1);
	LayersMain.S_mouse_1.setTextureRect(IntRect(0, 0, 1280, 768));
	LayersMain.S_mouse_1.setPosition(0, 0); 
	//////////////////////////////////////////////////////////////////
	Texture mouse_2_1;
	mouse_2_1.loadFromFile("texture//mouse_second1.png");
	LayersMain.S_mouse_2_1.setTexture(mouse_2_1);
	LayersMain.S_mouse_2_1.setTextureRect(IntRect(0, 0, 1280, 768));
	LayersMain.S_mouse_2_1.setPosition(0, 0);
	//////////////////////////////////////////////////////////////////
	Texture mouse_2_2;
	mouse_2_2.loadFromFile("texture//mouse_second2.png");
	LayersMain.S_mouse_2_2.setTexture(mouse_2_2);
	LayersMain.S_mouse_2_2.setTextureRect(IntRect(0, 0, 1280, 768));
	LayersMain.S_mouse_2_2.setPosition(0, 0);
	//////////////////////////////////////////////////////////////////
	Texture mouse_3_1;
	mouse_3_1.loadFromFile("texture//mouse_third1.png");
	LayersMain.S_mouse_3_1.setTexture(mouse_3_1);
	LayersMain.S_mouse_3_1.setTextureRect(IntRect(0, 0, 1280, 768));
	LayersMain.S_mouse_3_1.setPosition(0, 0);
	//////////////////////////////////////////////////////////////////
	Texture mouse_3_2;
	mouse_3_2.loadFromFile("texture//mouse_third2.png");
	LayersMain.S_mouse_3_2.setTexture(mouse_3_2);
	LayersMain.S_mouse_3_2.setTextureRect(IntRect(0, 0, 1280, 768));
	LayersMain.S_mouse_3_2.setPosition(0, 0);
	//////////////////////////////////////////////////////////////////
	RenderWindow window(VideoMode(LayersMain.X_Width, LayersMain.Y_Height), " half-liter mouse");
	//////////////////////////////////////////////////////////////////

	while (window.isOpen())//пока окно открыто 
	{
		double time = clock.getElapsedTime().asMicroseconds();
		clock.restart();//часы
		Event event;
		while (window.pollEvent(event))//дождитесь события и верните его
			if (event.type == Event::Closed)
				window.close();

		if (Keyboard::isKeyPressed(Keyboard::Space))
			LayersMain.key = true;
		else
			LayersMain.key = false;//отжата ли клавиша
		/////////////////////////////////////////
		window.clear();
	
		if (Keyboard::isKeyPressed(Keyboard::LAlt))
			if (Keyboard::isKeyPressed(Keyboard::LShift))
				if (PressedABC == 0)
					PressedABC = 1;//переключен на англ
				else
					if (PressedABC == 1)
						PressedABC = 0;//переключен на русский

		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			if (LayersMain.Third == false)
			{
				LayersMain.First = false;
				LayersMain.Second = true;
			}
		}
		window.draw(LayersMain.Layers(LayersMain.key, time, PressedABC));
		window.display();
	}
	_getch();
}