#pragma once
#include <iostream>;
#include <fstream>;
#include "GameObject.h";
class fileReader {
public:
	fileReader();
	~fileReader();

	void readFile(std::string filename, float startX, float startY, float startZ);

	vector<Vector3> cubes;
	vector<Vector3> pointPickups;
	vector<Vector3> Doors;
	vector<Vector3> Keys;
	Vector3 playerPos;
	Vector3 objPos;
	vector<Vector3> destPos;
	vector<Vector3> enemies;
	Vector3 goosePos;


	float minX;
	float maxX;
	float minZ;
	float maxZ;
};