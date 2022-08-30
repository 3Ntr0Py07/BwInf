#pragma once
#include <SFML/Graphics.hpp>
#include <stdio.h>

#include "HModules.hpp"
#include "constants.hpp"

namespace HexLab
{
	class Border
	{
	public:
		
		Type type;
		double size = 1;
		States state = undefined;
		sf::Vector2f format;
		sf::RectangleShape border;
	
		void RotateRect()
		{
			switch(this->type)
			{
				case Top:
					this->border.rotate(0);
					break;
				case TopLeft:
					this->border.rotate(300);
					break;
				case TopRight:
					this->border.rotate(60);
					break;
				case Bottom:
					this->border.rotate(180);
					break;
				case BottomLeft:
					this->border.rotate(240);
					break;
				case BottomRight:
					this->border.rotate(120);
					break;
				case Last:
					break;
			}
		}
		
		void PosRect()
		{
			//offset to middle
			switch (this->type)
			{
				case Top:
					this->border.setPosition(this->size * -0.5, this->size *  -0.8660254037844);
					break;
				case TopLeft:
					this->border.setPosition(this->size * -1, 0);
					break;
				case TopRight:
					this->border.setPosition(this->size * 0.5, this->size * -0.8660254037844);
					break;
				case Bottom:
					this->border.setPosition(this->size * 0.5, this->size * 0.8660254037844);
					break;
				case BottomLeft:
					this->border.setPosition(this->size * -0.5, this->size * 0.8660254037844);
					break;
				case BottomRight:
					this->border.setPosition(this->size, 0);
					break;
				default:
					this->border.setPosition(this->size * 2, this->size * 2);
					break;
			}
		}
	
		
		void setFormat()
		{
			this->format = sf::Vector2f(1 * this->size, 0.05 * this->size);
		}
	
		void Init(int type, double size, States state, Point2 position = Default)
		{
			this->type = converter::ToType(type);
			this->size = size;
			this->state = state;
			setFormat();
			border = sf::RectangleShape(this->format);
			PosRect();
			RotateRect();
			this->border.move(position.x, position.y);
		}
		void move (sf::Vector2f vec)
		{
			this->border.move(vec);
		}
	};
};
