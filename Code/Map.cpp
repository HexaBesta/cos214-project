#include "Map.h"

Map::Map(string setupFile)
{
	std::string filename(setupFile);
	std::vector<std::string> lines;
	std::string line;

	std::ifstream inputFile(setupFile);

	while (getline(inputFile, line))
	{
		lines.push_back(line);
	}
	// for (int i = 0; i < lines.size(); i++)
	// 	cout << lines.at(i) << endl;

	inputFile.close();

	int fileIndex = 0;

	/*
		Initialising the adjacency matrix
	*/
	int totalAreas = stoi(lines.at(0));
	this->adjacencies = new TransportRoute **[totalAreas];
	for (int i = 0; i < totalAreas; i++)
	{
		adjacencies[i] = new TransportRoute *[totalAreas];
	}

	for (int i = 0; i < totalAreas; i++)
	{
		for (int j = 0; j < totalAreas; j++)
		{
			adjacencies[i][j] = NULL;
		}
	}
	fileIndex++;

	/*
	Initialising grid size
	*/
	this->gridXSize = stoi(lines.at(1));
	this->gridYSize = stoi(lines.at(2));
	this->grid = new string *[gridXSize];
	for (int i = 0; i < gridXSize; i++)
	{
		grid[i] = new string[gridYSize];
	}

	for (int i = 0; i < gridXSize; i++)
	{
		for (int j = 0; j < gridYSize; j++)
		{
			grid[i][j] = "X";
		}
	}
	fileIndex += 2;

	for (int k = 0; k < totalAreas; k++)
	{
		/*
		Breakup the line into three parts, area details and its neighbors e.g. "A0,0:1,2,3:0,0;1,0" becomes {"A0,0","1,2,3","0,0;1,0"}
		*/
		std::vector<std::string> lineParts = {};
		std::string temp = "";
		for (int i = 0; i < lines.at(fileIndex).length(); i++)
		{
			if (lines.at(fileIndex).at(i) == ':')
			{
				lineParts.push_back(temp);
				temp = "";
			}
			else
			{
				temp += (lines.at(fileIndex).at(i));
				if (i == lines.at(fileIndex).length() - 1)
				{
					lineParts.push_back(temp);
					temp = "";
				}
			}
		}
		/*
		Breakup the area details into two parts, name and index e.g. "A0,0" becomes {"A0","0"}
		*/
		std::vector<std::string> areaParts = {};
		temp = "";
		for (int i = 0; i < lineParts.at(0).length(); i++)
		{
			if (lineParts.at(0).at(i) == ',')
			{
				areaParts.push_back(temp);
				temp = "";
			}
			else
			{
				temp += (lineParts.at(0).at(i));
				if (i == lineParts.at(0).length() - 1)
				{
					areaParts.push_back(temp);
					temp = "";
				}
			}
		}
		/*
		Breakup the neighbors into individual numbers e.g. "1,2,3" becomes {"1","2","3"}
		*/
		std::vector<std::string> areaAdjacencies = {};
		temp = "";
		for (int i = 0; i < lineParts.at(1).length(); i++)
		{
			if (lineParts.at(1).at(i) == ',')
			{
				areaAdjacencies.push_back(temp);
				temp = "";
			}
			else
			{
				temp += (lineParts.at(1).at(i));
				if (i == lineParts.at(1).length() - 1)
				{
					areaAdjacencies.push_back(temp);
					temp = "";
				}
			}
		}
		/*
		Breakup the coordinates into individual pairs e.g. "0,0;1,0" becomes {"0,0","1,0"}
		*/
		std::vector<std::string> areaCoordinates = {};
		temp = "";
		for (int i = 0; i < lineParts.at(2).length(); i++)
		{
			if (lineParts.at(2).at(i) == ';')
			{
				areaCoordinates.push_back(temp);
				temp = "";
			}
			else
			{
				temp += (lineParts.at(2).at(i));
				if (i == lineParts.at(2).length() - 1)
				{
					areaCoordinates.push_back(temp);
					temp = "";
				}
			}
		}
		fileIndex++;
		/*
		Add area to all areas
		*/
		Area *currArea = new Area(stoi(areaParts.at(1)));
		allAreas.push_back(currArea);
		
		/*
		Set adjacencies in the adjacency matrix
		*/
		for (int i = 0; i < areaAdjacencies.size(); i++)
		{
			adjacencies[stoi(areaParts.at(1))][stoi(areaAdjacencies.at(i))] = new TransportRoute();
		}
		for (int i = 0; i < areaCoordinates.size(); i++)
		{
			currArea->addCell(areaCoordinates.at(i));
		}
	}

	setAllEndPoints();
	setAllGridAreas();
}

string Map::createTransportRoutes(Area *area1, Area *area2)
{
	// TODO - implement Map::createTransportRoutes
	throw "Not yet implemented";
}

Area *Map::chooseArea()
{
	// TODO - implement Map::chooseArea
	throw "Not yet implemented";
}

string Map::destroyTransportRoute(Area *area1)
{
	// TODO - implement Map::destroyTransportRoute
	throw "Not yet implemented";
}

vector<Area *> Map::listAdjacent(::Area *area)
{
	// TODO - implement Map::listAdjacent
	throw "Not yet implemented";
}

void Map::update()
{
	// TODO - implement Map::update
	throw "Not yet implemented";
}

void Map::setAllEndPoints()
{
	for (int i = 0; i < allAreas.size(); i++)
	{
		for (int j = 0; j < allAreas.size(); j++)
		{
			if (adjacencies[i][j] != NULL)
			{
				adjacencies[i][j]->setEndPoints(allAreas.at(i), allAreas.at(j));
			}
		}
	}
}

void Map::setAllGridAreas()
{
	for (int i = 0; i < allAreas.size(); i++)
	{
		vector<Coordinate *> areaCoords = allAreas.at(i)->getAreaCoordinates();
		for (int j = 0; j < areaCoords.size(); j++)
		{
			grid[areaCoords.at(j)->x][areaCoords.at(j)->y] = to_string(allAreas.at(i)->getIndex());
		}
	}
}

void Map::printMap()
{
	string output = "";

	for (int j = 0; j < gridYSize; j++)
	{

		for (int i = 0; i < gridXSize; i++)
		{
			output += "---- ";
		}
		output += "\n";
		for (int i = 0; i < gridXSize; i++)
		{
			int colour=-2;
			string symbol=grid[i][j];
			if (grid[i][j]!="X")
			{
				colour=stoi(grid[i][j]);
			}

			while (symbol.length()<2)
			{
				symbol+=" ";
			}
			
			
			output += "|\033["+to_string(41+(colour%7))+"m" + symbol + "\033[0m| ";
		}
		output += "\n";
	}
	for (int i = 0; i < gridXSize; i++)
	{
		output += "---- ";
	}

	cout << output << endl;

	// --- ---
	// |3| |5|
	// --- ---
	// |4|
	// ---
}
