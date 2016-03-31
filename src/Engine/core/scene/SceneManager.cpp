/*
 * シーン管理クラス実装
 */
#include "SceneManager.h"
#include "Scene.h"

class HsEngine::SceneManager::SceneManagementParam
{
public:

	// シーンの遷移タイプ
	enum SceneMoveType
	{
		Next,
		CallSub,
		Replace,
		Return,
		ReturnToRoot
	};

	SceneManagementParam ()
	{
	}

	~SceneManagementParam ()
	{
	}
};

namespace HsEngine
{
	const char MAX_SCENE_STACK = 5;

	SceneManager* SceneManager::instance;

	void SceneManager::Initialize ()
	{
		instance = new SceneManager ();
	}

	void SceneManager::Destroy ()
	{
		delete instance;
		instance = nullptr;
	}

	SceneManager* SceneManager::GetInstance ()
	{
		return instance;
	}

	void SceneManager::OnUpdate (const uint deltaTime)
	{
	}

	void SceneManager::OnGameExit ()
	{
	}

	void SceneManager::ReserveNextScene (const int sceneId)
	{
	}

	SceneManager::SceneManager ()
		: sceneStack (std::vector<Scene*> ()),
			sceneMngParam (new SceneManager::SceneManagementParam ())
	{
		sceneStack.reserve(MAX_SCENE_STACK);
	}

	SceneManager::~SceneManager ()
	{
		int sceneLen = sceneStack.size ();
		for (int i = sceneLen - 1; i > -1; --i)
		{
			delete sceneStack[i];
			sceneStack[i] = nullptr;
		}
		sceneStack.clear();
		sceneStack.shrink_to_fit ();

		delete sceneMngParam;
		sceneMngParam = nullptr;
	}
}
