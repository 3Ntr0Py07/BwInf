#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <chrono>
#include <thread>

//#include "Cell.cpp"
#include "CellManager.cpp"

namespace HexLab
{
void iterate()
    {

	sf::RenderWindow window(sf::VideoMode(1,1), "HexLab", sf::Style::Fullscreen);
	int width = 3;
	int depth = 3;
	int itr = 0;
//	sf::CircleShape testcircle(100, 100);
//	testcircle.move(3840, 2160);
	CellGrid grid(width, depth, 10);

	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < depth; y++)
		{
			std::cout << "[" << x << "," << y << "]: " << grid.mainGrid[y][y].position.print() << std::endl;
		}
	}

	grid.move(sf::Vector2f(500 ,500));
        while (window.isOpen())
            {
				window.clear(sf::Color::Black);
				itr++;
                // check all the window's events that were triggered since the last iteration of the loop
                sf::Event event;
                while (window.pollEvent(event))
                {
                    // "close requested" event: we close the window
                    if (event.type == sf::Event::Closed)
                        window.close();
                }

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q));
				//std::cout << itr << std::endl;
				//grid.move(sf::Vector2f(.1, .1));
				//testcircle.move(sf::Vector2f(-.1, -.1));
				window.draw(grid);
	//			window.draw(testcircle);
				// clear the window with black color
                // end the current frame
                window.display();
				std::this_thread::sleep_for(std::chrono::nanoseconds(16666666));
            }
        //return EXIT_SUCCESS;
    }
};

int main(int argc, const char * argv[])
{
	std::cout << "Started";
	HexLab::iterate();
	
	return EXIT_SUCCESS;
}
