#pragma once
#include <map>
#include <list>
#include <string>
#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>
class Tile
{
public:
	Tile(std::string FileName);
	~Tile();
	void defineChar(char ch, sf::RectangleShape rect);
	void defineChar(char ch, sf::Sprite sprite);
	void createTiles(float tileSizex, float tileSizeY);
	void drawTiles(sf::RenderWindow *window);
private:
	std::string fName; // your file name
	std::map<char, sf::RectangleShape> rectMap; //what defineChar uses to assign your characters to tiles
	std::map<char, sf::Sprite> spriteMap; //
	std::list<sf::RectangleShape> rectList;//used in draw tiles to draw your rectangles
	std::list<sf::Sprite> spriteList;//


};




