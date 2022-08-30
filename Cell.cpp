#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <vector>

#include "Border.cpp"
#include "structs.hpp"

namespace HexLab
{
class Cell : public sf::Drawable, public sf::Transformable
{
public:

	Point2 position; //middle
    std::vector<HexLab::Border> borders;
	sf::CircleShape CellBase;
    double size;
	bool exists = false;
    
	void move(sf::Vector2f vec)
	{
		for (int i = 0; i < 6; i++)
		{
			this->borders[i].border.move(vec);
		}
		this->CellBase.move(vec);
	}
	
	Cell(double x = 1, double y = 1, double size = 1)
	{
		setPos(x, y);
		setSize(size);
		InitBorders();
		//this->CellBase = sf::CircleShape(size, 6);
		//this->CellBase.setFillColor(sf::Color::Cyan);
	}
	
	void Init(double x, double y, double size = 1)
	{
		setPos(x, y);
		this->size = size;
		InitBorders();
	}
	
    void setPos(Point2 pos)
    {
		this->position = pos;
    }
    
    void setPos(double x, double y)
    {
        Point2 point;
        point.setCoords(x, y);
		CellBase.setPosition(x, y);
        this->position = point;
    }
    
    void setSize(double arg)
	{
		this->size = arg;
	}
    
    void InitBorders()
    {
		borders.resize(6);
		for (int i = 0; i < 6; i++)
		{
			borders[i].Init(i, this->size, undefined, this->position);
		}
    }
	void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const
    {
        for (int i{}; i < 6; i++)
        {
			if (this->borders[i].state == closed)
            {
				sf::RectangleShape line = borders[i].border;
				line.setFillColor(sf::Color::White);
				target.draw(line);
            }
        }
		target.draw(CellBase);
    }
	
	void InitBase(double size = 1)
	{
		this->CellBase = sf::CircleShape(size, 6);
		this->CellBase.setFillColor(sf::Color::Cyan);
		this->CellBase.rotate(30);
		this->CellBase.setOrigin(this->position.x - 1.5 * size, this->position.y - 0.8660254037844 * size);
		//this->CellBase.setPosition(this->position.x, this->position.y);
	}
};


//0.8660254037844
//1.7320508075689
}