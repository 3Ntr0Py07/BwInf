#pragma once
#include "Point2.cpp"
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <vector>

namespace HexLab {
struct Line2
{
	Point2 startPos;
	Point2 endPos;
public:
	void setCoords(double xarg1, double yarg1, double xarg2, double yarg2)
	{
		this->startPos.setCoords(xarg1,yarg1);
		this->endPos.setCoords(xarg2,yarg2);
	}
	std::vector<sf::Vertex> toVertexArray(double size = 1, Point2 position = Point2::returnCoords(0, 0)) const
	{
		std::vector<sf::Vertex> result;
		result.resize(2);
		result[0] = sf::Vertex(sf::Vector2f(this->startPos.x * size + position.x, this->startPos.y * size + position.y));
		result[0].color = sf::Color::White;
		result[1] = sf::Vertex(sf::Vector2f(this->endPos.x * size + position.x,this->endPos.y * size + position.y));
		result[1].color = sf::Color::White;
		return result;
	}
};
};
