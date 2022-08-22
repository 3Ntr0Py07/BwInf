#ifndef ClassLessFunc_h
#define ClassLessFunc_h

#include "enums.hpp"

namespace HexLab {
	class converter
	{
	public:

		static Type ToType(int i)
		{
			switch (i) {
			case 0:
				return Top;
			case 1:
				return TopLeft;
			case 2:
				return TopRight;
			case 3:
				return Bottom;
			case 4:
				return BottomLeft;
			case 5:
				return BottomRight;
			default:
				throw "Border Type not found";
			}
		}

		static int TypeToInt(Type t)
		{
			switch (t) {
			case Top:
				return 0;
			case TopLeft:
				return 1;
			case TopRight:
				return 2;
			case Bottom:
				return 3;
			case BottomLeft:
				return 4;
			case BottomRight:
				return 5;
			default:
				throw "Border Type not found";
			}
		}
	};
};

#endif /* ClassLessFunc_h */
