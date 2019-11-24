#pragma once
#include "DXUT.h"


enum class WINMODE
{
	FULLSCREEN = 0,
	WINDOWED = 1
};

enum SoundType
{
	ST_BACKGROUND,
	ST_EFFECT
};

enum class SortingLayer
{
	Default = 0,
	Player,
	Bullet,
	Enemy,
	Background
};
enum ObjectTag
{
	Start = 0,
	Untagged,
	Player,
	Enemy,
	Floor,
	Gun,
	Bullet,
	EnemyBullet,
	BoundBullet,
	UI,
	End
}typedef Tag;