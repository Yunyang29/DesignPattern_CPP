#pragma once
#include <unordered_map>
#include <iostream>
#include "example.h"

namespace _SingletonPattern
{
	class Scene
	{
	public:
		Scene() {}
		~Scene() = default;
		virtual void on_enter() {}
	};

	class Level_1 : public Scene
	{
	public:
		void on_enter() override
		{
			std::cout << "Entering Level 1" << std::endl;
		}
	};

	class Level_2 : public Scene
	{
	public:
		void on_enter() override
		{
			std::cout << "Entering Level 2" << std::endl;
		}
	};


	class Level_3 : public Scene
	{
	public:
		void on_enter() override
		{
			std::cout << "Entering Level 2" << std::endl;
		}
	};


	class SceneManager
	{
	public:
		// 懒汉式单例模式
		static SceneManager* instance()
		{
			if (!manager)
				manager = new SceneManager();

			return manager;
		}

		void add(const std::string& id, Scene* scene)
		{
			scene_pool[id] = scene;
		}

		void switch_to(const std::string& id)
		{
			current_scene = scene_pool[id];

			if (current_scene)
				current_scene->on_enter();
		}

	private:
		static SceneManager* manager;
		Scene* current_scene = nullptr;
		std::unordered_map<std::string, Scene*> scene_pool;

	private:
		SceneManager() = default;
		~SceneManager() = default;

	};
}


class SingletonPattern : public Example
{
public:
	SingletonPattern();
	~SingletonPattern() = default;
	void on_created() override;
};