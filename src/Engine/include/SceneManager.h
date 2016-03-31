/*
 * シーン管理クラス
 */
#pragma once

#include <vector>
#include "Utils.h"

namespace HsEngine
{
	class Scene;
	class SceneManager
	{
	public:
		static void Initialize ();
		static void Destroy ();
		static SceneManager* GetInstance ();
		void OnUpdate (const uint deltaTime);
		void OnGameExit ();
		void ReserveNextScene (const int sceneId);
		void ReserveAddSubScene (const int sceneId);
		void ReserveReplaceScene (const int sceneId);
		void ReserveReturnScene ();
	private:
		SceneManager ();
		~SceneManager ();
		static SceneManager* instance;
		class SceneManagementParam;
		std::vector<Scene*> sceneStack;
		SceneManagementParam* sceneMngParam;
	};
}
