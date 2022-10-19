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
		Breakup the area details into two parts, name and index e.g. "A0,0,53" becomes {"A0","0","53"}
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

		Area *currArea = new Area(areaParts.at(0), stoi(areaParts.at(1)), stoi(areaParts.at(2)), stoi(areaParts.at(2)) != 94);
		currArea->attach(this);
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

void Map::createTransportRoute(Area *area1, Area *area2)
{
	if (adjacencies[area1->getIndex()][area2->getIndex()] != NULL)
	{
		adjacencies[area1->getIndex()][area2->getIndex()]->create();
		adjacencies[area2->getIndex()][area1->getIndex()]->create();
	}
}

Area *Map::chooseArea()
{
	// TODO - implement Map::chooseArea
	throw "Not yet implemented";
}

void Map::destroyTransportRoute(Area *area1, Area *area2)
{
	if (adjacencies[area1->getIndex()][area2->getIndex()] != NULL)
	{
		adjacencies[area1->getIndex()][area2->getIndex()]->destroy();
		adjacencies[area2->getIndex()][area1->getIndex()]->destroy();
	}
}

void Map::update()
{
	// TODO - implement Map::update
	throw "Not yet implemented";
}
vector<Area *> Map::listAdjacent(Area *area, bool transportRoute)
{
	string out = "Areas adjacent to " + to_string(area->getIndex()) + ": ";
	vector<Area *> adjacentAreas = {};
	for (int i = 0; i < allAreas.size(); i++)
	{
		if (adjacencies[area->getIndex()][i] != NULL)
		{
			if (transportRoute)
			{
				if (transportRouteisAvailable(area, allAreas.at(i)))
				{
					out += to_string(i) + ",";
					adjacentAreas.push_back(allAreas.at(i));
				}
			}
			else
			{
				out += to_string(i) + ",";
				adjacentAreas.push_back(allAreas.at(i));
			}
		}
	}
	out += "\n";
	cout << out;
	return adjacentAreas;
}

Area *Map::getAreaByIndex(int index)
{
	for (int i = 0; i < allAreas.size(); i++)
	{
		if (allAreas.at(i)->getIndex() == index)
		{
			return allAreas.at(i);
		}
	}
	cout << "Area could not be found" << endl;
	return NULL;
}

bool Map::transportRouteisAvailable(Area *point1, Area *point2)
{
	if (adjacencies[point1->getIndex()][point2->getIndex()] == NULL)
	{
		return false;
	}
	else
	{
		return adjacencies[point1->getIndex()][point2->getIndex()]->isAvailable();
	}
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
	for (int i = 0; i < gridXSize; i++)
	{
		output += "----- ";
	}
	output += "\n";
	for (int j = 0; j < gridYSize; j++)
	{

		for (int i = 0; i < gridXSize; i++)
		{
			int colour = 39;
			string symbol = " ";
			symbol += grid[i][j];
			if (grid[i][j] != "X")
			{
				colour = allAreas.at(stoi(grid[i][j]))->getColour();
			}

			while (symbol.length() < 3)
			{
				symbol += " ";
			}

			if (i - 1 >= 0 && grid[i - 1][j] == grid[i][j])
			{
				output += "\033[48;5;" + to_string((colour)) + "m";
			}

			if (i - 1 >= 0 && grid[i - 1][j] != "X" && grid[i][j] != "X" && transportRouteisAvailable(getAreaByIndex(stoi(grid[i][j])), getAreaByIndex(stoi(grid[i - 1][j]))))
			{
				output += "┤";
			}
			else
			{
				output += "|";
			}

			output += "\033[48;5;" + to_string((colour)) + "m" + symbol + "\033[0m";
			if (grid[i][j] != "X" && i + 1 < gridXSize && grid[i + 1][j] != "X")
			{
				if (transportRouteisAvailable(getAreaByIndex(stoi(grid[i][j])), getAreaByIndex(stoi(grid[i + 1][j]))))
				{
					output += "├═";
				}
				else
				{
					if (grid[i][j] == grid[i + 1][j])
					{
						output += "\033[48;5;" + to_string((colour)) + "m";
					}

					output += "| \033[0m";
				}
			}
			else
			{
				if (i + 1 < gridXSize && grid[i][j] == grid[i + 1][j])
				{
					output += "\033[48;5;" + to_string((colour)) + "m";
				}

				output += "| \033[0m";
			}
		}
		output += "\n";

		for (int i = 0; i < gridXSize; i++)
		{
			int colour = 39;
			string symbol = " ";
			symbol += grid[i][j];
			if (grid[i][j] != "X")
			{
				colour = allAreas.at(stoi(grid[i][j]))->getColour();
			}
			if (grid[i][j] != "X" && j + 1 < gridYSize && grid[i][j + 1] != "X")
			{
				if (transportRouteisAvailable(getAreaByIndex(stoi(grid[i][j])), getAreaByIndex(stoi(grid[i][j + 1]))))
				{
					output += "--║-- ";
				}
				else
				{
					if (i - 1 >= 0 && j < gridYSize)
					{
						if (grid[i][j] == grid[i - 1][j] && grid[i][j] == grid[i][j + 1] && grid[i][j] == grid[i - 1][j + 1])
						{
							output += "\033[48;5;" + to_string((colour)) + "m" + "----\033[0m";
							if (i + 1 < gridXSize && grid[i][j] == grid[i + 1][j] && grid[i][j] == grid[i + 1][j + 1])
							{
								output += "\033[48;5;" + to_string((colour)) + "m" + "- \033[0m";
							}
							else
							{
								output += "- ";
							}
						}
						else if (grid[i][j] == grid[i][j + 1])
						{
							output += "-\033[48;5;" + to_string((colour)) + "m" + "---\033[0m";
							if (i + 1 < gridXSize && grid[i][j] == grid[i + 1][j] && grid[i][j] == grid[i + 1][j + 1])
							{
								output += "\033[48;5;" + to_string((colour)) + "m" + "- \033[0m";
							}
							else
							{
								output += "- ";
							}
						}
						else
						{

							output += "----- ";
						}
					}
					else
					{
						output += "----- ";
					}
				}
			}
			else
			{
				if (i - 1 >= 0 && j < gridYSize)
				{
					if (grid[i][j] == grid[i - 1][j] && grid[i][j] == grid[i][j + 1] && grid[i][j] == grid[i - 1][j + 1])
					{
						output += "\033[48;5;" + to_string((colour)) + "m" + "----\033[0m";
						if (i + 1 < gridXSize && grid[i][j] == grid[i + 1][j] && grid[i][j] == grid[i + 1][j + 1])
						{
							output += "\033[48;5;" + to_string((colour)) + "m" + "- \033[0m";
						}
						else
						{
							output += "- ";
						}
					}
					else if (grid[i][j] == grid[i][j + 1])
					{
						output += "-\033[48;5;" + to_string((colour)) + "m" + "---\033[0m";
						if (i + 1 < gridXSize && grid[i][j] == grid[i + 1][j] && grid[i][j] == grid[i + 1][j + 1])
						{
							output += "\033[48;5;" + to_string((colour)) + "m" + "- \033[0m";
						}
						else
						{
							output += "- ";
						}
					}
					else
					{

						output += "----- ";
					}
				}
				else
				{
					if (j < gridYSize && grid[i][j + 1] == grid[i][j])
					{
						output += "-\033[48;5;" + to_string((colour)) + "m" + "---- \033[0m";
					}
					else
					{

						output += "----- ";
					}
				}
			}
		}
		output += "\n";
	}

	cout << output << endl;

	// ----- -----
	// | 3 |=| 5 |
	// ---- -----
	// | 4 |
	// -----
}

void Map::printColourMap()
{
	string output = "";
	for (int i = 0; i < gridXSize; i++)
	{
		output += "----- ";
	}
	output += "\n";
	for (int j = 0; j < gridYSize; j++)
	{

		for (int i = 0; i < gridXSize; i++)
		{
			int colour = -2;
			string symbol = " ";
			symbol += grid[i][j];
			if (grid[i][j] != "X")
			{
				colour = stoi(grid[i][j]);
			}

			while (symbol.length() < 3)
			{
				symbol += " ";
			}

			output += "|\033[" + to_string(41 + (colour % 7)) + "m" + symbol + "\033[0m|";
			if (grid[i][j] != "X" && i + 1 < gridXSize && grid[i + 1][j] != "X")
			{
				if (transportRouteisAvailable(getAreaByIndex(stoi(grid[i][j])), getAreaByIndex(stoi(grid[i + 1][j]))))
				{
					output += "═";
				}
				else
				{
					output += " ";
				}
			}
			else
			{
				output += " ";
			}
		}
		output += "\n";

		for (int i = 0; i < gridXSize; i++)
		{
			if (grid[i][j] != "X" && j + 1 < gridYSize && grid[i][j + 1] != "X")
			{
				if (transportRouteisAvailable(getAreaByIndex(stoi(grid[i][j])), getAreaByIndex(stoi(grid[i][j + 1]))))
				{
					output += "--║-- ";
				}
				else
				{
					output += "----- ";
				}
			}
			else
			{
				output += "----- ";
			}
		}
		output += "\n";
	}

	cout << output << endl;

	// ----- -----
	// | 3 |=| 5 |
	// ---- -----
	// | 4 |
	// -----
}

Map::~Map()
{
	for (int i = 0; i < gridXSize; i++)
	{
		delete[] grid[i];
	}
	delete[] grid;

	for (int i = 0; i < allAreas.size(); i++)
	{
		for (int j = 0; j < allAreas.size(); j++)
		{
			delete adjacencies[i][j];
		}
		delete[] adjacencies[i];
	}
	delete[] adjacencies;

	while (!allAreas.empty())
	{
		delete allAreas.back();
		allAreas.pop_back();
	}
}