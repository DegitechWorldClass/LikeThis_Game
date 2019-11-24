#include "DXUT.h"
#include "CModelManager.h"


CModelManager::CModelManager()
{
	m_pLoader = new COBJLoader();
}


CModelManager::~CModelManager()
{
	for (auto iter : m_mapModel)
	{
		SAFE_DELETE(iter.second);
	}
	m_mapModel.clear();


	SAFE_DELETE(m_pLoader);
}

CModel * CModelManager::AddModel(CRString _Key, CRString _Path, CRString _MapPath )
{
	auto find = m_mapModel.find(_Key);
	if (find != m_mapModel.end())
	{
		return find->second;
	}
	
	CModel * pModel = new CModel();

	m_pLoader->OBJLoad(pModel, _Path, _MapPath);

	m_mapModel.insert(make_pair(_Key, pModel));
	return pModel;
}

CModel *CModelManager::FindModel(CRString _Key)
{
	auto find = m_mapModel.find(_Key);
	if (find != m_mapModel.end())
	{
		return find->second;
	}
	DEBUG_LOG("Find Model Not Found : %s", _Key.c_str());
	return nullptr;
}

Shader * CModelManager::AddShader(CRString _Key, CRString _Path)
{
	LPD3DXEFFECT lpEffect = NULL;

	if (S_OK == D3DXCreateEffectFromFileA(
		g_Device,
		_Path.c_str(),
		NULL,
		NULL,
		NULL,
		NULL,
		&lpEffect,
		NULL))
	{
		this->m_mapShader.insert(make_pair(_Key, lpEffect));
		return lpEffect;
	}
	DEBUG_LOG("Failed LoadShader! Key : %s | Path : %s", _Key.c_str(), _Path.c_str());
	return NULL;
	

}

vector<CModel*> CModelManager::MakeVecModel(CRString _Key)
{
	vector<CModel*> vecModel;

	for (int i = 1; ; i++)
	{
		char Key[100];
		sprintf(Key, "%s (%d)", _Key.c_str(), i);

		auto Find = FindModel(Key);
		if (Find == nullptr)
			break;

		vecModel.push_back(Find);
	}

	if (vecModel.empty() == true)
	{
		DEBUG_LOG("VECTMODEL IS EMPTY : %s", _Key.c_str());
	}

	return vecModel;
}
void CModelManager::Render(CModel * _pModel, Matrix _matWorld)
{
	g_Device->SetTransform(D3DTS_WORLD, &_matWorld);

	int i = 0;
	for (auto iter : _pModel->m_vecMaterial)
	{
		g_Device->SetMaterial(&(iter->material));

		if (iter->DiffuseMap)
			g_Device->SetTexture(0, iter->DiffuseMap->m_pTexture);

		_pModel->m_pMesh->DrawSubset(i++);
	}

}

