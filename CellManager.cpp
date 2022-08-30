#pragma once
#include <stdio.h>
#include <vector>
#include <iostream>
#include <random>
#include <set>
#include <iterator>

#include "HModules.hpp"
#include "Cell.cpp"

namespace HexLab
{
class BorderGenerator
{
public:
	static int RandomWheighted(int seed)
	{
		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> dist(seed, 600);
		return Weighter(dist(rng));
	}
	
	static int Weighter(int rnumber)
	{
		int openings = 0;
		if (rnumber <= weights.at(1)){return 1;}
		else if (rnumber <= weights.at(2)){return 2;}
		else if (rnumber <= weights.at(3)){return 3;}
		else if (rnumber <= weights.at(4)){return 4;}
		else if (rnumber <= weights.at(5)){return 5;}
		else{throw "Wheighting Failed";}
	}
	
	static StateMap RandomTypes(int seed,  StateMap compStates)
	{
		int i = 0;
		int iterator = 0;
		StateMap::iterator node;
		while (i < seed) {
			std::random_device dev;
			std::mt19937 rng(dev());
			std::uniform_int_distribution<std::mt19937::result_type> dist(0, 5);
			Type type = converter::ToType(dist(rng));
			
			if (compStates[type] == undefined)
			{
				node = compStates.find(type);
				node->second = closed;
				i++;
			}
			//iterator++;
			//if (iterator == 100) break;
		}
		return compStates;
	}
	
	StateMap GetBorderStates(std::vector<std::vector<Cell>> mainGrid)
	{
		
	}

	static StateMap CNE(std::vector<std::vector<Cell>> mainGrid, int x, int y, int width, int depth) //Compare Neigbors Even
	{
		StateMap BorderStates;
		
		if (y > 1) //Top
			BorderStates.insert(std::pair<Type, States>(Top, mainGrid[x][y-2].borders[0].state));
		
		if (y > 0) //TR
			BorderStates.insert(std::pair<Type, States>(TopRight, mainGrid[x][y-1].borders[2].state));
		
		if (y < depth - 1) //BR
			BorderStates.insert(std::pair<Type, States>(BottomRight, mainGrid[x][y+1].borders[5].state));
		
		if (y < depth - 2) //Bot
			BorderStates.insert(std::pair<Type, States>(Bottom, mainGrid[x][y+2].borders[3].state));
		
		if (x > 0 and y < depth - 1) //BL
			BorderStates.insert(std::pair<Type, States>(BottomLeft, mainGrid[x-1][y+1].borders[4].state));
		
		if (x > 0 and y > 0) //LT
			BorderStates.insert(std::pair<Type, States>(TopLeft, mainGrid[x-1][y-1].borders[1].state));
		
		return BorderStates;
	}
	
	static StateMap CNO(std::vector<std::vector<Cell>> mainGrid, int x, int y, int width, int depth) //Compare Neigbors Odd
	{
		StateMap BorderStates;
		
		if (y > 1) //Top
			BorderStates.insert(std::pair<Type, States>(Top, mainGrid[x][y-2].borders[0].state));
		
		if (y > 0 and x < width - 1) //TR
			BorderStates.insert(std::pair<Type, States>(TopRight, mainGrid[x+1][y-1].borders[2].state));
		
		if (y < depth - 1 and x < width - 1) //BR
			BorderStates.insert(std::pair<Type, States>(BottomRight, mainGrid[x+1][y+1].borders[5].state));
		
		if (y < depth - 2) //Bot
			BorderStates.insert(std::pair<Type, States>(Bottom, mainGrid[x][y+2].borders[3].state));
		
		if (y < depth - 1) //BL
			BorderStates.insert(std::pair<Type, States>(BottomLeft, mainGrid[x][y+1].borders[4].state));
		
		if (y > 0) //LT
			BorderStates.insert(std::pair<Type, States>(TopLeft, mainGrid[x][y-1].borders[1].state));
		
		return BorderStates;
	}
};

class CellGrid : public sf::Drawable, public sf::Transformable
{
	
public:
	std::vector<std::vector<Cell>> mainGrid;

	double size;
	int width;
	int depth;
	
	void operator= (std::vector<std::vector<Cell>> grid)
	{
		this->mainGrid = grid;
	}
	
	void move(sf::Vector2f vec)
	{
		for (int x = 0; x < this->width; x++)
			for (int y = 0; y < this->depth; y++)
			{
				this->mainGrid[x][y].move(vec);
			}
	}
	
    
	/*
	std::vector<std::vector<Cell>> CreateCells (std::vector<std::vector<Cell>> mainGrid)
	{
		for (int x = 0; x < this->width; x++)
		{
			for (int y = 0; y < this->depth; y++)
			{
				if (y%2 == 0)
				{
					mainGrid[x][y].size = this->size;
					mainGrid[x][y].setPos(this->size * x * 3, this->size * 0.4330127018922 + this->size * y * 0.8660254037844);
					mainGrid[x][y].exists = true;
					CreateBorders(false, mainGrid[x][y], x, y);
				}
				else
				{
					mainGrid[x][y].size = size;
					mainGrid[x][y].setPos(this->size * 1.5 + this->size * x * 3, this->size * 0.8660254037844 + this->size * y * 0.8660254037844);
					mainGrid[x][y].exists = true;
					CreateBorders(true, mainGrid[x][y], x, y);
				}
			}
		}
		return mainGrid;
	}
	*/
	void CreateBorders(bool odd, Cell currentCell, int x, int y)
	{
		StateMap borderStates;
		std::vector<Border> borders;
		borders.resize(6);
		int remaining;
		int count;
		if (x == 0 and y == 0)
			count = 0;
		else
		{
			if (odd)
				borderStates = BorderGenerator::CNO(this->mainGrid, x, y, this->width, this->depth);
			else
				borderStates = BorderGenerator::CNE(this->mainGrid, x, y, this->width, this->depth);
			count = borderStates.Closed();
		}
		remaining = BorderGenerator::RandomWheighted(count);
		borderStates = BorderGenerator::RandomTypes(remaining, borderStates);
		for (int i = 0; i < 6; i++)
		{
			borders[i].Init(borders[i].type, this->size, borderStates.at(converter::ToType(i)));
//			borders[i].state = borderStates.at(converter::ToType(i));
			if (borderStates.at(converter::ToType(i)) == undefined) borders[i].state = open;
//			borders[i].size = this->size;
			
		}
		this->mainGrid[x][y].borders = borders;
	}
	
	CellGrid(int width = 1, int depth = 1, double size = 1)
	{
		this->size = size;
		this->width = width;
		this->depth = depth;
		
		this->mainGrid.resize(width);
		for (int x = 0; x < width; x++)
		{
			this->mainGrid[x].resize(depth);
		}
		
		for (int x = 0; x < this->width; x++)
		{
			for (int y = 0; y < this->depth; y++)
			{
				if (y%2 == 0)
				{
					mainGrid[x][y].size = this->size;
//					mainGrid[x][y].setPos(this->size * x * 3,					 this->size * 0.4330127018922 + this->size * y * 0.8660254037844);
//					mainGrid[x][y].setPos(this->size * x, this->size + this->size * y);
					mainGrid[x][y].setPos(this->size * x, this->size * y);
					mainGrid[x][y].exists = true;
					mainGrid[x][y].InitBorders();
//					CreateBorders(false, mainGrid[x][y], x, y);
					mainGrid[x][y].InitBase(this->size);
				}
				else
				{
					mainGrid[x][y].size = this->size;
//					mainGrid[x][y].setPos(this->size * x * 3 + this->size * 1.5, this->size * 0.4330127018922 + this->size * y * 0.8660254037844);
//					mainGrid[x][y].setPos(this->size + this->size * x, this->size + this->size * y);
					mainGrid[x][y].setPos(this->size * x, this->size * y);
					mainGrid[x][y].exists = true;
					mainGrid[x][y].InitBorders();
					//CreateBorders(true, mainGrid[x][y], x, y);
					mainGrid[x][y].InitBase(this->size);
				}
			}
		}

	}
	
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		for (int x = 0; x < this->width; x++)
		{
			for (int y = 0; y < this->depth; y++)
			{
				target.draw(this->mainGrid[x][y]);
			}
		}
	}
};
};
