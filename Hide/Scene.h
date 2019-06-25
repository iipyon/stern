#pragma once

enum class SceneType {
	title,
	stageselect,
	game,
	gameover,
	clear,
	pause,
	demo
};

class Scene {
	static SceneType scene;
public:
	static void set_scene(SceneType type);
	static SceneType get_scene();
};