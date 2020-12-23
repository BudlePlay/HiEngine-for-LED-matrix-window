#include "EngineManager.h"


EngineManager::EngineManager()
{
	this->EngineManager::EngineManager(new BasicScene());
	time = Time();
}

EngineManager::EngineManager(SceneManager* scene)
{
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
		Tools::cersorMoveTo({i.x, i.y});
		
		int comparestr = scene->mapPointer->GetPartOfMap({ i.x, i.y }).compare("  ");
		if(comparestr == 0)
		{
			cout << "ii";
		}
		else
		{
			cout << scene->mapPointer->GetPartOfMap({ i.x, i.y });
		}
	}
	Tools::backCusor();
}

EngineManager::~EngineManager()
{
	
}
