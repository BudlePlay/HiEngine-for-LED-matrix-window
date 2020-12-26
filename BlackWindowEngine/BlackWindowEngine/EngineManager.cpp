#include "EngineManager.h"


#include <iomanip>
#include <string>


EngineManager::EngineManager()
{
	this->EngineManager::EngineManager(new BasicScene());
	time = Time();
}

EngineManager::EngineManager(SceneManager* scene)
{
	ser = new Serial("\\\\.\\COM3");
	if (ser->IsConnected()) {
		cout << "Serial Communication Connected." << endl;
		ser->ReadData(message, sizeof(message));
		cout << "Message from Arduino: " << message << endl;
	}
	else {
		cout << "Device can not be found or can not be configured." << endl;
		return;
	}
	
	this->scene = scene;
	Game();
}

void EngineManager::Game()
{
	scene->Create();
	scene->mapPointer->Print();


	while (true)
	{
		time.StartMeasure();


		scene->mapPointer->CopyCurrentMapANDRemoveCurrentMap();


		//Game
		scene->Render(time.deltaTime); 
		Work();
		//end

	
		BoomCheck();

		Print_Map();

		if (scene->nextScene)		//nextScene is not null
		{
			system("cls");
			WorldOutliner::AllDestroy();
			this->scene = scene->nextScene;
			scene->Create();
			scene->nextScene = nullptr;
			scene->mapPointer->Print();
		}
		time.EndMeasure();
	}
}

void EngineManager::BoomCheck()
{
	// 충돌검사
	for (auto my : scene->worldOutliner.GetObjects())
	{
		for (auto other : scene->worldOutliner.GetObjects())
		{
			if (my != other)
			{
				Position myP = PositionTools::FPtoIP(my->GetPosition());
				Area myA = my->GetArea();
				Position otherP = PositionTools::FPtoIP(
					other->GetPosition());
				Area otherA = other->GetArea();

				if (myP.x + myA.width > otherP.x && myP.x < otherP.x + otherA.width)
				{
					if (myP.y + myA.height > otherP.y && myP.y < otherP.y + otherA.height)
					{
						my->OnCollision(other);
					}
				}
			}
		}
	}
}

void EngineManager::Work()
{
	//Work
	for (auto o : scene->worldOutliner.GetObjects())
	{
		o->Work();
	}
}

void EngineManager::Print_Map()
{
	scene->SceneManager::UploadMap(scene->worldOutliner.GetObjects());

	std::vector<Position> v = scene->mapPointer->ModifiedMap();
	for (Position i : v)
	{

		string str = "";
		

		{
			char num[3];
			snprintf(num, 3, "%02d", i.x);
			str.append(num);
		}
		{
			char num[3];
			snprintf(num, 3, "%02d", i.y);
			str.append(num);
		}
		
		int comparestr = scene->mapPointer->GetPartOfMap({ i.x, i.y }).compare("  ");
		if(comparestr == 0)
		{
			cout << "ii";
			str.append(std::to_string(0));
		}
		else
		{
			cout << scene->mapPointer->GetPartOfMap({ i.x, i.y });
			str.append(std::to_string(1));
		}

		
		ser->WriteData(str.c_str(), strlen(str.c_str()) + 1);
		//ser->ReadData(message, sizeof(message));
		//cout << "Message from Arduino: " << message << endl;

	}
}

EngineManager::~EngineManager()
{
	
}
