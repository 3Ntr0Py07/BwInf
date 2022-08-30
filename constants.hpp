#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include "HModules.hpp"

namespace HexLab {
	const std::map<int, double> weights = { //Openings, Wheigt
		{1, 350},
		{2, 500},
		{3, 540},
		{4, 590},
		{5, 600}
	};

	const Point2 Default(0, 0);

	const double size = 50;
};

