#include "fileReader.h";

fileReader::fileReader() {
	
}

fileReader::~fileReader() {

}

void fileReader::readFile(std::string filename, float startX, float startY, float startZ) {

	cubes.clear();
	pointPickups.clear();
	Doors.clear();
	Keys.clear();
	destPos.clear();
	enemies.clear();

	char character;
	std::string line;
	std::ifstream myReader;
	myReader.open(filename);
	if (myReader.is_open()) {
		while (myReader) {
			character = myReader.get();

			switch(character) {
			case 'W':
				cubes.push_back(Vector3(startX, startY, startZ));
				break;
			case '0':
				break;
			case 'P':
				playerPos = Vector3(startX, startY - 4, startZ);
				break;
			case 'X':
				pointPickups.push_back(Vector3(startX, startY - 3, startZ));
				break;
			case 'D':
				Doors.push_back(Vector3(startX, startY, startZ));
				break;
			case 'K':
				Keys.push_back(Vector3(startX, startY - 3, startZ));
				break;
			case 'G':
				objPos = Vector3(startX, startY - 2, startZ);
				break;
			case 'A':
				destPos.push_back(Vector3(startX, startY, startZ));
				break;
			case 'E':
				enemies.push_back(Vector3(startX, startY - 4, startZ));
				break;
			case 'S':
				goosePos = Vector3(startX, startY - 4, startZ);
				break;
			default:
				startZ += 10;
				startX = -10;
				break;
			}

			startX += 10;
		}
	}
	myReader.close();
}