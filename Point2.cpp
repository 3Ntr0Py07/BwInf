#pragma once

namespace HexLab
{
	struct Point2
	{
	public:
		double x{};
		double y{};

		Point2(double xarg = 0, double yarg = 0)
		{
			this->x = xarg;
			this->y = yarg;
		}

		void setCoords(double xarg, double yarg)
		{
			this->x = xarg;
			this->y = yarg;
		}

		static Point2 returnCoords(double xarg, double yarg)
		{
			Point2 result;
			result.setCoords(xarg, yarg);
			return result;
		}

	};
};