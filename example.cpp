#include "Tile.h"
int main() {
	Tile tile("test.txt");
	sf::RectangleShape rect;
	rect.setFillColor(sf::Color::Green);
	rect.setSize(sf::Vector2f(40.f,40.f));
	tile.defineChar('2', rect);
	tile.createTiles(40.f, 40.f);

	sf::RenderWindow window(sf::VideoMode(800, 800), "Tiles Work!");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		window.clear();
		tile.drawTiles(&window);
		window.display();
	}

	return 0;
}
