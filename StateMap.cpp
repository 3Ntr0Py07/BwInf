#include <map>

#include "enums.hpp"
#include "TypeConverter.cpp"

namespace HexLab {
struct StateMap : std::map<Type, States>
{
	int count{};
	
	StateMap()
	{
		this->insert(std::pair<Type, States>(Top, undefined));
		this->insert(std::pair<Type, States>(TopLeft, undefined));
		this->insert(std::pair<Type, States>(TopRight, undefined));
		this->insert(std::pair<Type, States>(Bottom, undefined));
		this->insert(std::pair<Type, States>(BottomRight, undefined));
		this->insert(std::pair<Type, States>(BottomLeft, undefined));

	}
	
	States at(Type type)
	{
		return this->find(type)->second;
	}
	
	States operator[] (Type type)
	{
		return this->at(type);
	}
	
	States operator[] (int i)
	{
		return this->at(converter::ToType(i));
	}
	
    int Closed()
	{
		int counter{};
		for (int i = 0; i < 6; i++)
			if (this->at(converter::ToType(i)) == closed)
				counter += 1;
		this->count = counter;
		return counter;
	}
};
};
