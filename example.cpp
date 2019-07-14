#include "Tile.h"
int main() {
	Tile test("test.txt");
	sf::Texture tile1;
	tile1.loadFromFile("tile1.jpg");
	sf::RectangleShape test2;
	test2.setTexture(&tile1);
	test2.setSize(sf::Vector2f(40.f,40.f));
	test.defineChar('2', test2);

	sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		test.createTiles(40.f, 40.f);
		window.clear();
		test.drawTiles(&window);
		window.display();
	}

	return 0;
}
