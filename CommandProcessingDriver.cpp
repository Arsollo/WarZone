#include "CommandProcessing.h"
#include "GameEngine.h"

using namespace std;

int main(int argc, char* argv[])
{
	//if no argument
	if (argc == 1)
	{
		cout << "no argumnet" << endl;
		CommandProcessing::CommandProcessor cp;

		while (true)
		{
			cp.getCommand();
		}
	}
	//if console
	else if (argc == 2 && strcmp(argv[1], "-console") == 0)
	{
		cout << "argssss" << endl;
		CommandProcessing::CommandProcessor cp;

		while (true)
		{
			cp.getCommand();
		}
	}
	//if filename is mentioned
	else if (argc == 3 && strcmp(argv[1], "-file") == 0)
	{
		//CommandProcessing::CommandProcessor cp;
		CommandProcessing::FileCommandProcessorAdapter fcp(argv[2]);

		while (true)
		{
			fcp.getCommand();
		}
	}
	//If tournament mode
	else if (strcmp(argv[1], "tournament") == 0)
	{
		cout << "tournament command" << endl;

		string mapfiles = argv[3];
		string playerstrategies = argv[5];
		int numberofgames = atoi(argv[7]);
		int maxnumberofturns = atoi(argv[9]);

		vector<string> listmapfiles;
		vector<string> listplayerstrategies;


		//Splitting mapfiles argument into a vector
		int start = 0;
		do {
			// Find the index of occurrence
			int idx = mapfiles.find(".map", start);
			if (idx == string::npos) {
				break;
			}
			int length = idx - start;
			listmapfiles.push_back(mapfiles.substr(start, length+4));
			start += (length+4);
		} while (true);
		listmapfiles.push_back(mapfiles.substr(start));


		//Splitting mapfiles argument into a vector
		start = 0;
		do {
			// Find the index of occurrence
			int idx = playerstrategies.find(".p", start);
			if (idx == string::npos) {
				break;
			}
			int length = idx - start;
			listplayerstrategies.push_back(playerstrategies.substr(start, length));
			start += (length+2);
		} while (true);
		listplayerstrategies.push_back(playerstrategies.substr(start));

		for(string t: listplayerstrategies)
			cout << t <<endl;

		//Calling GameEngine
		GameEngine::GameEngine ge;
		ge.tournament(listmapfiles, listplayerstrategies, numberofgames, maxnumberofturns);

		CommandProcessing::CommandProcessor cp;
		cp.getCommand();


	}
	//else
	else
	{

		cout << argc << endl;
		cout << "asdsada" << endl;
		cout << argv[0] << endl;
		cout << argv[1] << endl;
		cout << argv[2] << endl;

		cout << "Invalid command line arguments." << endl;
	}

}
