#include "DXUT.h"
#include "CLoadScene.h"


CLoadScene::CLoadScene()
{
}


CLoadScene::~CLoadScene()
{
}

void CLoadScene::Init()
{
	//MODEL.AddShader("TOON", "./Shader/ToonShader.fx");
	LoadSprite("FLOOR", "Floor");
	LoadSprite("BACKGROUND_1", "Map/Background_1");
	LoadSprite("BACKGROUND_2", "Map/Background_2");
	LoadSprite("BACKGROUND_3", "Map/Background_3");
	LoadSprite("BACKGROUNDOBJECT_1", "Map/BackgroundObject_1");
	LoadSprite("BACKGROUNDOBJECT_2", "Map/BackgroundObject_2");
	LoadSprite("BACKGROUNDOBJECT_3", "Map/BackgroundObject_3");
	LoadSprite("BACKGROUNDOBJECT_4", "Map/BackgroundObject_4");
	LoadSprite("BACKGROUNDOBJECT_5", "Map/BackgroundObject_5");
	LoadSprite("FLOOR", "Floor");

	LoadSprite("PLAYER_GUN_3_HAND", "Player/Gun/Gun_3_Hand");
	LoadSprite("PLAYER_GUN", "Player/Gun/Gun");

	LoadSprite("PLAYER_IDLE", "Player/Idle/Idle", 15);
	LoadSprite("PLAYER_RUN", "Player/Run/Run", 8);
	LoadSprite("PLAYER_UP", "Player/Jump/Up", 2);
	LoadSprite("PLAYER_DOWN", "Player/Jump/Down", 2);
	LoadSprite("PLAYER_DASH", "Player/Dash/Dash", 12);
	LoadSprite("ENEMY01_MOVE", "Enemy/Enemy01/Move/Move", 8);
	LoadSprite("ENEMY01_EFFECT", "Enemy/Enemy01/Effect/Boom", 10);
	LoadSprite("ENEMY01_ATTACK", "Enemy/Enemy01/Attack/Attack", 13);
	//2
	LoadSprite("ENEMY05_MOVE", "Enemy/Enemy02/Move/Move", 2);

	
	//LoadSprite("ENEMY02_ATTACK", "Enemy/Enemy02/Attack/Attack", 13);
	LoadSprite("ENEMY03_MOVE", "Enemy/Enemy03/Move/Move", 2);
	//LoadSprite("ENEMY03_ATTACK", "Enemy/Enemy03/Attack/Attack", 13);
	LoadSprite("ENEMY04_MOVE", "Enemy/Enemy04/Move/Move", 2);
	//5
	LoadSprite("ENEMY02_MOVE", "Enemy/Enemy02/Move/Move", 8);
	LoadSprite("ENEMY02_ATTACK", "Enemy/Enemy02/Attack/Attack", 12);
	//LoadSprite("ENEMY04_ATTACK", "Enemy/Enemy04/Attack/Attack", 13);
	//LoadSprite("GUN1", "Enemy/Enemy02/Move/Move (1)");
	LoadSprite("BULLET1", "Gun/PlayerBullet");
	LoadSprite("ENEMY01_BULLET", "Enemy/Enemy01/Bullet/Bullet");
	LoadSprite("Title", "./Title/Title");

	m_LoadImageMax = m_vecImageLoad.size(); 
	m_LoadModelMax = m_vecMeshLoad.size();
	m_LoadSoundMax = m_vecSoundLoad.size();

	m_LoadImageSize = 0;
	m_LoadModelSize = 0;
	m_LoadSoundSize = 0;

	m_LoadMax = m_LoadImageMax + m_LoadModelMax + m_LoadSoundMax;
	DEBUG_LOG("Now Loading Resources...");
}

void CLoadScene::Update()
{
	if (m_LoadImageFinished == false)
	{
		if (m_LoadImageSize >= m_LoadImageMax) 
		{
			m_LoadImageFinished = true;
			return;
		}
		for (int i = 0; i < 8; i++)
		{
			m_ImageLoadThread[i] = thread(&CLoadScene::LoadImageFirst, m_vecImageLoad[m_LoadImageSize]);
			m_ImageLoadThread[i].join();
			m_LoadImageSize++;
			DEBUG_LOG("Loading Status %d / %d (%.1f%%)", m_LoadImageSize, m_LoadImageMax, 100.f *  (float)m_LoadImageSize / (float)m_LoadImageMax);
			if (m_LoadImageSize >= m_LoadImageMax ) 
			{
				m_LoadImageFinished = true;
				return;
			}

			LoadImageFirst(m_vecImageLoad[m_LoadImageSize]);
			m_LoadImageSize++;

			DEBUG_LOG("Loading Status %d / %d (%.1f%%)", m_LoadImageSize, m_LoadImageMax, 100.f *  (float)m_LoadImageSize / (float)m_LoadImageMax);
			if (m_LoadImageSize >= m_LoadImageMax )
			{
				m_LoadImageFinished = true;
				return;
			}
		}
	}
	else if (!m_LoadModelFinished)
	{
		if (m_LoadModelSize >= m_LoadModelMax) { m_LoadModelFinished = true;  return; }
		for (int i = 0; i < 8; i++)
		{
			m_MeshLoadThread[i] = thread(&CLoadScene::LoadMeshFirst, m_vecMeshLoad[m_LoadModelSize]);
			m_MeshLoadThread[i].join();
			m_LoadModelSize++;
			if (m_LoadModelSize >= m_LoadModelMax) { m_LoadModelFinished = true;  return; }
			DEBUG_LOG("Loading Status %d / %d (%.1f%%)", m_LoadModelSize, m_LoadModelMax, 100.f *  (float)m_LoadModelSize / (float)m_LoadModelMax);

			LoadMeshFirst(m_vecMeshLoad[m_LoadModelSize++]);
			m_LoadModelSize++;
			if (m_LoadModelSize >= m_LoadModelMax ) { m_LoadModelFinished = true;  return; }
			DEBUG_LOG("Loading Status %d / %d (%.1f%%)", m_LoadModelSize, m_LoadModelMax, 100.f *  (float)m_LoadModelSize / (float)m_LoadModelMax);
		}


	}
	else
	{


		SCENE.ChangeScene("S_TITLE");
	}







}

void CLoadScene::Render()
{
}

void CLoadScene::Release()
{
}

void CLoadScene::LoadSprite(CRString _Key, CRString _Path, int _iSize)
{
	if (_iSize == 1)
	{
		char Path[100];
		sprintf(Path, "./resource/%s.png", _Path.c_str());
		m_vecImageLoad.push_back(ImageLoadData(_Key, Path));
	}
	else
	{
		for (int i = 1; i <= _iSize; i++)
		{
			char Path[100];
			char Key[100];
			sprintf(Path, "./resource/%s (%d).png", _Path.c_str(), i);
			sprintf(Key, "%s (%d)", _Key.c_str(), i);

			m_vecImageLoad.push_back(ImageLoadData(Key, Path));
		}
	}
}

void CLoadScene::LoadMesh(CRString _Key, CRString _Path, CRString _MapPath, int _iSize)
{
	if (_iSize == 1)
	{
		char Path[100];
		sprintf(Path, "./resource/%s.obj", _Path.c_str());
	
		char MapPath[100];
		sprintf(Path, "./resource/%s", _MapPath.c_str());

		
		m_vecMeshLoad.push_back(MeshLoadData(_Key, Path, MapPath));
	}
	else
	{
		for (int i = 1; i <= _iSize; i++)
		{
			char Key[100];
			sprintf(Key, "%s (%d)", _Key.c_str(), i);

			char Path[100];
			sprintf(Path, "./resource/%s (%d).obj", _Path.c_str(), i);

			char MapPath[100];
			sprintf(MapPath, "./resource/%s", _MapPath.c_str());


			m_vecMeshLoad.push_back(MeshLoadData(Key, Path, MapPath));
		}
	}
}

void CLoadScene::LoadSound(CRString _Key, CRString _Path, int _iSize)
{
	if (_iSize == 1)
	{
		char Path[100];
		sprintf(Path, "./resource/%s.mp3", _Path.c_str());
		m_vecSoundLoad.push_back(SoundLoadData(_Key, Path));
	}
	else
	{
		for (int i = 1; i <= _iSize; i++)
		{
			char Path[100];
			char Key[100];
			sprintf(Path, "./resource/%s (%d).mp3", _Path.c_str(), i);
			sprintf(Key, "%s (%d)", _Key.c_str(), i);
			m_vecSoundLoad.push_back(SoundLoadData(Key, Path));
		}
	}
}

void CLoadScene::LoadMeshFirst(MeshLoadData& _Handle)
{	
	std::this_thread::sleep_for(Second(1) / 1000);
	MODEL.AddModel(_Handle.m_Key, _Handle.m_Path, _Handle.m_MapPath);

}

void CLoadScene::LoadImageFirst(ImageLoadData & _Handle)
{
	std::this_thread::sleep_for(Second(1) / 1000);
	IMAGE.AddTexture(_Handle.m_Key, _Handle.m_Path);
}


