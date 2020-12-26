#include "SceneManager.h"

SceneManager::SceneManager()
{
	worldOutliner = WorldOutliner();
}

void SceneManager::Create()
{
}

void SceneManager::Render(float dt)
{
}

void SceneManager::Resize(int x, int y)
{
}

void SceneManager::Input(float dt)
{
}

void SceneManager::Pause()
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::UploadMap(Object* o)
{
	mapPointer->SetPartOfMap(PositionTools::FPtoIP(o->GetPosition()), o->GetShape(), o->GetArea());
}

void SceneManager::UploadMap(std::vector<Object*> obs)
{
	for (auto o : obs)
	{
		try
		{
			mapPointer->SetPartOfMap(PositionTools::FPtoIP(o->GetPosition()), o->GetShape(), o->GetArea());
		}
		catch (std::exception e)
		{
			std::cout << "ERROR : out of Map" << std::endl;
		}
	}
}

WorldOutliner SceneManager::getWorldOutliner()
{
	return worldOutliner;
}

void SceneManager::SceneChange(SceneManager* scene)
{
	nextScene = scene;
}
