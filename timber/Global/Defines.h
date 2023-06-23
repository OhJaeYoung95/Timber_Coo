#pragma once

enum class SceneId
{
	None = -1,
	Title,
	GameMode,
	Select,
	Play,
	Game,
	Count,
};

enum class ResourceTypes
{
	Texture,
	Font,
	SoundBuffer,
};

enum class SceneType
{
	Title,
	GameMode,
	Select,
	Play
};

enum class Sides
{
	Left,
	Right
};

enum class Origins	// ÇÇ¹þ
{
	TL,
	TC,
	TR,
	ML,
	MC,
	MR,
	BL,
	BC,
	BR
};

enum class ModeSelect
{
	Solo,
	Multi
};