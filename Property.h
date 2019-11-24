#pragma once
#include "DXUT.h"
#include "Enum.h"
namespace Property
{
	static bool		UseVSync = true; // 수직 동기화
	static WINMODE	WinMode  = WINMODE::WINDOWED;
	static Vector2	WinSize  = Vector2(1280, 720);
	static wstring	WinTitle = L"EmptyProject";
}

using namespace Property;