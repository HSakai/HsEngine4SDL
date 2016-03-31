/*
 * シーンのベースとなるIF
 */
#pragma once

#include <SDL.h>

namespace HsEngine
{
	class Scene
	{
	public:
		Scene ();
		virtual ~Scene ();
		virtual void IsKeyDown (const SDL_Keycode& inputKey);
		virtual void ProcessInitialize ();
		virtual void ProcessBegin ();
		virtual void ProcessUpdate (const uint deltaTime, const bool isEnterSub);
	protected:
		void JumpScene (int sceneId);
		void CallSubScene (int sceneId);
		void CallScene (int sceneId);
		void ReturnScene ();
	};
}
