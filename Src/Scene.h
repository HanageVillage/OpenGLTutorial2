/**
* @file Scene.h
*/

#ifndef SCENE__H__INCLUDED
#define SCENE__H__INCLUDED

#include <memory>
#include <string>

class SceneStack;


/**
* シーンの基底クラス
*/

class Scene
{
public:
	Scene(const char* name);
	Scene(const Scene&) = delete;
	Scene& operator=(const Scene&) = delete;
	virtual ~Scene();

	virtual bool Initialize() = 0 {}
	virtual void PricessInput() = 0 {}
	virtual void Update() = 0 {}
	virtual void Render() = 0 {}
	virtual void Finalize() = 0 {}

	virtual void Play();
	virtual void Stop();
	virtual void Show();
	virtual void Hide();

	const std::string& Name() const;
	bool IsActive() const;
	bool IsVisible() const;


private:
	std::string name;
	bool isActive = true;
	bool isVisible = true;
};

using ScenePtr = std::shared_ptr<Scene>;

#endif // !SCENE__H__INCLUDED
