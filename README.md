# TilePlacer-for-SFML
use a text file to place down tiles

example:

test.txt
/||||||||||||||||||||||||||||||\
2222
2222
/||||||||||||||||||||||||||||||\

your code:
main.cpp
#include <SFML/Graphics.hpp>
#include "Tile.h"
int main() {
	Tile tile("test.txt");
	sf::Texture tiletexture;
	tile1.loadFromFile("tile1.jpg");
	sf::RectangleShape rect;
	rect.setTexture(&tile1);
	rect.setSize(sf::Vector2f(40.f,40.f));
	test.defineChar('2', rect);
  test.createTiles(40.f, 40.f);
	sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		window.clear();
		test.drawTiles(&window);
		window.display();
	}

	return 0;
}

To make tiles you have to include 
