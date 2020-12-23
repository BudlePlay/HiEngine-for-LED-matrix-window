#pragma once


#include "Object.h"
#include "Map.h"

#include "Tools.h"
#include "WorldOutliner.h"


class SceneManager
{
protected:
public:
	SceneManager* nextScene;
	WorldOutliner worldOutliner;
	Map* mapPointer;

	SceneManager();;

	virtual void Create();;			//Called when the Application is first created.
	virtual void Render(float dt);;
	virtual void Resize(int x, int y);;
	virtual void Input(float dt);;
	virtual void Pause();;			//Stop Game
	virtual ~SceneManager();;				//Called when this Game should release all resources.

	void UploadMap(Object* o);

	void UploadMap(std::vector<Object*> obs);

	WorldOutliner getWorldOutliner();

	void SceneChange(SceneManager* scene);
};