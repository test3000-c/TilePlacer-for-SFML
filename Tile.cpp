#include "Tile.h"



Tile::Tile(std::string FileName)
{
	fName = FileName;
	rectMap.clear();
	spriteMap.clear();
	rectList.clear();
	spriteList.clear();
}


Tile::~Tile()
{
}
void Tile::defineChar(char ch, sf::RectangleShape rect) {
	if (rectMap.find(ch) == rectMap.end() && spriteMap.find(ch) == spriteMap.end()) {  //checks if you already put in a character
		rectMap.insert(std::pair<char, sf::RectangleShape>(ch, rect));  //inserts your char and rectangle into a map
	}
	else {
		std::cout << "char has already been reserved" << std::endl; 
	}
}

void Tile::defineChar(char ch, sf::Sprite sprite) {
	if (rectMap.find(ch) == rectMap.end() && spriteMap.find(ch) == spriteMap.end()) {  //checks if you already put in a character
		spriteMap.insert(std::pair<char, sf::Sprite>(ch, sprite));                     //inserts your char and Sprite into a map
	}
	else {
		std::cout << "char has already been reserved" << std::endl;
	}
}

void Tile::createTiles(float tileSizex, float tileSizeY) {  //set the size for each tile 
	                                                       //note: does not actaully change the size of your sprites and rectangles
	char c;                                                //the char that is going to get the input from the file
	float posx, posy;                                      //used to place your tiles
	posx = posy = 0.f;                                     
	std::ifstream file(fName, std::ios::in | std::ios::binary); // opening your file
	if (!file.is_open()) {                                       //checks if file opened
		std::cout << "File could not be opened" << std::endl;
	}
	else {
		while (!file.eof()) {                                   //while the file didnt end this will loop
			file.get(c);                                        // char c gets input from file
			if (!file.eof()) {                                  // since the get() function automatically moves the iterator the while loop might
				                                                //go one more time before ending
				if (rectMap.find(c) != rectMap.end()) {         //checks if the char from the file is defined by you int the rectangle map
					rectMap.find(c)->second.setPosition(sf::Vector2f(posx, posy));      //sets the position of a tile  
					rectList.push_back(rectMap.find(c)->second);  //puts into rectangle list the rectangle list
				}                                                                       
				else if (spriteMap.find(c) != spriteMap.end()) {  //checks if the char from the file is defined by you int the sprite map
					spriteMap.find(c)->second.setPosition(sf::Vector2f(posx, posy));   //sets the position of a tile
					spriteList.push_back(spriteMap.find(c)->second);
				}
				if (c == '\n') {                                           //checks if there is a new line
					posx = 0.f;                                            //sets the position of the next sprite/rectangle x to zero
					posy += tileSizeY;                                     //sets the position of the next sprite/rectangle one tile down
				}
				else{
					posx += tileSizeY;                                     //sets the position of the next sprite/rectangle 
					                                                      //one tile left so it was adjecent 
					                                                      //to the previous rectangle/sprite
				}
			}
		}
	}
}

void Tile::drawTiles(sf::RenderWindow *window) {
	std::list<sf::RectangleShape>::iterator Rit;
	std::list<sf::Sprite>::iterator Sit;

	for (Rit = rectList.begin(); Rit != rectList.end(); Rit++) {
		window->draw(*Rit);
	}

	for (Sit = spriteList.begin(); Sit != spriteList.end(); Sit++) {
		window->draw(*Sit);
	}

}
