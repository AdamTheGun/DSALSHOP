#include "Admin.h"


Admin::Admin(void)
{
}


Admin::~Admin(void)
{
}

void Admin::AddGame()
{
	string inTitle, inDescription, inGenre, inDeveloper, inPublisher, inYear;
	int inRatingOneStar, inRatingTwoStar, inRatingThreeStar, inRatingFourStar, inRatingFiveStar;
	float inCost;

	cout << "Title: ";
	getline(cin, inTitle);
	cout << "Description: ";
	getline(cin, inDescription);
	cout << "Genre: ";
	getline(cin, inGenre);
	cout << "Developer: ";
	getline(cin, inDeveloper);
	cout << "Publisher: ";
	getline(cin, inPublisher);

#pragma region int and float
	bool valid = false;
	inRatingOneStar = 0;

	while(!valid)
	{
		cout << "One-Star Rating: ";
		cin >> inRatingOneStar;
		cout << endl;

		if(inRatingOneStar)
		{
			valid = true;
		}
		else
		{
			cout << "Error, not a valid number" << endl;
		}
		cin.clear();
		cin.ignore();
	}

	valid = false;
	inRatingTwoStar = 0;

	while(!valid)
	{
		cout << "Two-Star Rating: ";
		cin >> inRatingTwoStar;
		cout << endl;

		if(inRatingTwoStar)
		{
			valid = true;
		}
		else
		{
			cout << "Error, not a valid number" << endl;
		}
		cin.clear();
		cin.ignore();
	}
	
	valid = false;
	inRatingThreeStar = 0;

	while(!valid)
	{
		cout << "Three-Star Rating: ";
		cin >> inRatingThreeStar;
		cout << endl;

		if(inRatingThreeStar)
		{
			valid = true;
		}
		else
		{
			cout << "Error, not a valid number" << endl;
		}
		cin.clear();
		cin.ignore();
	}
	
	valid = false;
	inRatingThreeStar = 0;

	while(!valid)
	{
		cout << "Four-Star Rating: ";
		cin >> inRatingFourStar;
		cout << endl;

		if(inRatingFourStar)
		{
			valid = true;
		}
		else
		{
			cout << "Error, not a valid number" << endl;
		}
		cin.clear();
		cin.ignore();
	}
	
	valid = false;
	inRatingFiveStar = 0;

	while(!valid)
	{
		cout << "Five-Star Rating: ";
		cin >> inRatingFiveStar;
		cout << endl;

		if(inRatingFiveStar)
		{
			valid = true;
		}
		else
		{
			cout << "Error, not a valid number" << endl;
		}
		cin.clear();
		cin.ignore();
	}
	
	valid = false;
	inCost = 0;

	while(!valid)
	{
		cout << "Cost: ";
		cin >> inCost;
		cout << endl;

		if(inCost)
		{
			valid = true;
		}
		else
		{
			cout << "Error, not a valid number" << endl;
		}
		cin.clear();
		cin.ignore();
	}
#pragma endregion

	cout << "Year: ";
	getline(cin, inYear);
	
	int nextID = 0;
	list<Games> tempList;
	Shop::getGameLibrary(tempList);
	list<Games>::iterator GameItor = tempList.begin();
	list<Games>::iterator GameEnd = tempList.end();
	for(;GameItor != GameEnd; GameItor++)
	{
		if(GameItor->getID() > nextID)
			nextID = GameItor->getID();
	}

	nextID++;

	ofstream newGame;
	newGame.open("gameList.txt", ios_base::app);
	newGame << ",\n"
			<< inTitle << "," << inDescription << "," << inGenre << "," << inDeveloper << "," << inPublisher << "," << nextID << ","
			<< inRatingOneStar << "," << inRatingTwoStar << "," << inRatingThreeStar << "," << inRatingFourStar << "," << inRatingFiveStar
			<< "," << inCost << "," << inYear;
	newGame.close();
}

void Admin::RemoveGame()
{
	list<Games> tempList;
	Shop::getGameLibrary(tempList);
	Shop::displayAllGames();
	
	bool valid = false;
	int id;
	cout << "Remove game (1 - " << tempList.size() << "): ";

	while(valid == false)
	{
		cin >> id;

		if(id > 0 && id < tempList.size())
		{
			valid = true;
		}
		else
		{
			cout << "Remove game (1 - " << tempList.size() << "): ";
			cin.clear();
			cin.ignore();
		}
	}

	cout << endl;
	
	string tempS;
	int num = 1;
	string removedGameTitle;

	ifstream line("gameList.txt");
	ofstream temp;
	temp.open("temp.txt", ios_base::app);

	system("cls");
	cout << "Removed game id: " << id << endl;

	list<Games>::iterator GameItor = tempList.begin();
	list<Games>::iterator GameEnd = tempList.end();
	for(;GameItor != GameEnd; GameItor++)
	{
		getline(line, tempS);

		if(num != id)
		{
			if(tempS.back() == ',')
			{
				tempS = tempS.substr(0, tempS.size() - 1);
			}

			if((id == 1 && num == 2) || num == 1) // For removal of first line of the list, and for copying the first line
			{
				temp << tempS;
			}
			else
			{
				temp << ",\n" << tempS;
			}
		}
		else
		{
			removedGameTitle = GameItor->getTitle();
			GameItor = tempList.erase(GameItor);
			GameItor--;
		}

		num++;
	}
	// Closing all files for further modifications
	temp.close();
	line.close();
	
	// Replace old file with updated list
	remove("gameList.txt");
	rename("temp.txt", "gameList.txt");

	num = 1;
	system("cls");

	cout << "Removed " << removedGameTitle << endl << endl;
	cout << "New list of games" << endl;

	GameItor = tempList.begin();
	GameEnd = tempList.end();
	for(;GameItor != GameEnd; GameItor++)
	{
		cout << num << ". " << GameItor->getTitle() << endl;
		num++;
	}
}

void Admin::EditDetail()
{
	string inTitle, inDescription, inGenre, inDeveloper, inPublisher, inYear;
	int inRatingOneStar, inRatingTwoStar, inRatingThreeStar, inRatingFourStar, inRatingFiveStar;
	float inCost;

	list<Games> tempList;
	Shop::getGameLibrary(tempList);
	Shop::displayAllGames();

	bool valid = false;
	int id;
	cout << "Edit game (1 - " << tempList.size() << "): ";

	while(valid == false)
	{
		cin >> id;

		if(id > 0 && id < tempList.size())
		{
			valid = true;
		}
		else
		{
			cout << "Edit game (1 - " << tempList.size() << "): ";
			cin.clear();
			cin.ignore();
		}
	}

	cout << endl;

	string tempS;
	int num = 1;
	int gameID;
	int times = 0;
	string removedGameTitle;

	ifstream line("gameList.txt");
	ofstream temp;
	temp.open("temp.txt", ios_base::app);

	list<Games>::iterator GameItor = tempList.begin();
	list<Games>::iterator GameEnd = tempList.end();
	for(;GameItor != GameEnd; GameItor++)
	{
		getline(line, tempS);

		if(num != id)
		{
			if(tempS.back() == ',')
			{
				tempS = tempS.substr(0, tempS.size() - 1);
			}

			if(num == 1)
			{
				temp << tempS;
			}
			else
			{
				temp << ",\n" << tempS;
			}
		}
		else
		{
			valid = false;
			int edit = 0;
			string sect = "";

			cout << "Editing " << GameItor->getTitle() << endl;
			cout << "Select a section to edit" << endl;
			cout << "1. Title: " << GameItor->getTitle() << endl;
			cout << "2. Description: " << GameItor->getDescription() << endl;
			cout << "3. Genre: " << GameItor->getGenre() << endl;
			cout << "4. Developer: " << GameItor->getDeveloper() << endl;
			cout << "5. Publisher: " << GameItor->getPublisher() << endl;
			getline(line, sect, ','); // Game ID
			cout << "6. One-Star Rating" << endl;
			cout << "7. Two-Star Rating" << endl;
			cout << "8. Three-Star Rating" << endl;
			cout << "9. Four-Star Rating" << endl;
			cout << "10. Five-Star Rating" << endl;
			cout << "11. Cost: " << GameItor->getCost() << endl;
			cout << "12. Year: " << GameItor->getYear() << endl;

			//cout << "Editing " << GameItor->getTitle() << endl;
			//cout << "Select a section to edit" << endl;
			//cout << "1. Title: " << getline(line, sect, ',') << endl;
			//cout << "2. Description: " << getline(line, sect, ',') << endl;
			//cout << "3. Genre: " << getline(line, sect, ',') << endl;
			//cout << "4. Developer: " << getline(line, sect, ',') << endl;
			//cout << "5. Publisher: " << getline(line, sect, ',') << endl;
			//getline(line, sect, ','); // Game ID
			//cout << "6. One-Star Rating: " << getline(line, sect, ',') << endl;
			//cout << "7. Two-Star Rating: " << getline(line, sect, ',') << endl;
			//cout << "8. Three-Star Rating: " << getline(line, sect, ',') << endl;
			//cout << "9. Four-Star Rating: " << getline(line, sect, ',') << endl;
			//cout << "10. Five-Star Rating: " << getline(line, sect, ',') << endl;
			//cout << "11. Cost: " << getline(line, sect, ',') << endl;
			//cout << "12. Year: " << getline(line, sect, ',') << endl;

			string editName = "";

			while (valid == false)
			{
				cout << "Edit (1 - 12): ";
				cin >> edit;

				if(edit > 0 && edit < 13)
				{
					switch(edit)
					{
					case 1: editName = "Title";
						break;
					case 2: editName = "Description";
						break;
					case 3: editName = "Genre";
						break;
					case 4: editName = "Developer";
						break;
					case 5: editName = "Publisher";
						break;
					case 6: editName = "One-Star Rating";
						break;
					case 7: editName = "Two-Star Rating";
						break;
					case 8: editName = "Three-Star Rating";
						break;
					case 9: editName = "Four-Star Rating";
						break;
					case 10: editName = "Five-Star Rating";
						break;
					case 11: editName = "Cost";
						break;
					case 12: editName = "Year";
						break;
					}

					valid = true;
				}
				else
				{
					cout << "Edit (1 - 12): " << endl;
					cin.clear();
					cin.ignore();
				}
			}

			cout << endl;

			bool confirm = false;
			bool correct = false;
			string editString = "";
			int editInt = 0;
			float editFloat = 0;
			string confirmEdit= "";

			system("cls");
			cout << "Editing " << editName << " of " << GameItor->getTitle() << endl;
			if(edit > 0 && edit < 6)
			{
				while(confirm == false)
				{
					cout << "Enter edit:" << endl;
					cin >> editString;
					cout << endl;

					while(correct == false)
					{
						cout << "Confirm edit?(Y/N): ";
						cin >> confirmEdit;

						if(confirmEdit == "Y" || confirmEdit == "y")
						{
							confirm = true;
							correct = true;
						}
						else if(confirmEdit == "N" || confirmEdit == "n")
						{
							correct = true;
						}
					}
				}

				switch(edit)
				{
					case 1: inTitle = editString;
						break;
					case 2: inDescription = editString;
						break;
					case 3: inGenre = editString;
						break;
					case 4: inDeveloper = editString;
						break;
					case 5: inPublisher = editString;
						break;
				}
			}
			else if(edit > 5 && edit < 11)
			{
				while(confirm == false)
				{
					bool validInt = false;

					while(validInt = false)
					{
						cout << "Enter edit (integers only):" << endl;
						cin >> editInt;

						if(editInt)
						{
							validInt = true;
						}
						else
						{
							cin.clear();
							cin.ignore();
						}
					}

					while(correct == false)
					{
						cout << "Confirm edit?(Y/N): ";
						cin >> confirmEdit;

						if(confirmEdit == "Y" || confirmEdit == "y")
						{
							confirm = true;
							correct = true;
						}
						else if(confirmEdit == "N" || confirmEdit == "n")
						{
							correct = true;
						}
					}
				}

				switch(edit)
				{
					case 6: inRatingOneStar = editInt;
						break;
					case 7: inRatingTwoStar = editInt;
						break;
					case 8: inRatingThreeStar = editInt;
						break;
					case 9: inRatingFourStar = editInt;
						break;
					case 10: inRatingFiveStar = editInt;
						break;
				}
			}
			else if(edit == 11)
			{
				while(confirm == false)
				{
					bool validInt = false;

					while(validInt = false)
					{
						cout << "Enter edit (integer only):" << endl;
						cin >> editFloat;

						if(editFloat)
						{
							printf("%.2f", editFloat);
							validInt = true;
						}
						else
						{
							cin.clear();
							cin.ignore();
						}
					}

					while(correct == false)
					{
						cout << "Confirm edit?(Y/N): ";
						cin >> confirmEdit;

						if(confirmEdit == "Y" || confirmEdit == "y")
						{
							confirm = true;
							correct = true;
						}
						else if(confirmEdit == "N" || confirmEdit == "n")
						{
							correct = true;
						}
					}
				}

				inCost = editFloat;
			}
			else
			{
				while(confirm == false)
				{
					cout << "Enter edit:" << endl;
					cin >> editString;
					cout << endl;

					while(correct == false)
					{
						cout << "Confirm edit?(Y/N): ";
						cin >> confirmEdit;

						if(confirmEdit == "Y" || confirmEdit == "y")
						{
							confirm = true;
							correct = true;
						}
						else if(confirmEdit == "N" || confirmEdit == "n")
						{
							correct = true;
						}
					}
				}

				inYear = editString;
			}

			gameID = GameItor->getID();

			for(times = 0; times < 12; times++)
			{
				if(times != edit)
				{
					switch(edit)
					{
					case 1: inTitle = GameItor->getTitle();
						break;
					case 2: inDescription = GameItor->getDescription();
						break;
					case 3: inGenre = GameItor->getGenre();
						break;
					case 4: inDeveloper = GameItor->getDeveloper();
						break;
					case 5: inPublisher = GameItor->getPublisher();
						break;
					case 6: inRatingOneStar = GameItor->getStarRating(1);
						break;
					case 7: inRatingTwoStar = GameItor->getStarRating(2);
						break;
					case 8: inRatingThreeStar = GameItor->getStarRating(3);
						break;
					case 9: inRatingFourStar = GameItor->getStarRating(4);
						break;
					case 10: inRatingFiveStar = GameItor->getStarRating(5);
						break;
					case 11: inCost = GameItor->getCost();
						break;
					case 12: inYear = GameItor->getYear();
						break;
					}
				}
			}

			if(num != 1) // Everything in between
			{
				temp << ",\n"
					 << inTitle << "," << inDescription << "," << inGenre << "," << inDeveloper << "," << inPublisher << "," << gameID << ","
					 << inRatingOneStar << "," << inRatingTwoStar << "," << inRatingThreeStar << "," << inRatingFourStar << "," << inRatingFiveStar
					 << "," << inCost << "," << inYear;
			}
			else if(id == tempList.size()) // last line
			{
				temp << ",\n"
					 << inTitle << "," << inDescription << "," << inGenre << "," << inDeveloper << "," << inPublisher << "," << gameID << ","
					 << inRatingOneStar << "," << inRatingTwoStar << "," << inRatingThreeStar << "," << inRatingFourStar << "," << inRatingFiveStar
					 << "," << inCost << "," << inYear;
			}
			else // first line
			{
				temp << inTitle << "," << inDescription << "," << inGenre << "," << inDeveloper << "," << inPublisher << "," << gameID << ","
					 << inRatingOneStar << "," << inRatingTwoStar << "," << inRatingThreeStar << "," << inRatingFourStar << "," << inRatingFiveStar
					 << "," << inCost << "," << inYear;
			}
		}

		num++;
	}
	// Closing all files for further modifications
	temp.close();
	line.close();
}