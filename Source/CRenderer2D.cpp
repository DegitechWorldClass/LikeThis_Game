#include "DXUT.h"
#include "CRenderer2D.h"


CRenderer2D::CRenderer2D()
{
}


CRenderer2D::~CRenderer2D()
{
}

void CRenderer2D::SetSortingLayer(SortingLayer _SortingLayer)
{
	OBJECT.UnRegisterRenderer2D(this);
	m_SortingLayer = _SortingLayer; 
	OBJECT.RegisterRenderer2D(this);
}

void CRenderer2D::SetOrderInLayer(int _iOrderInLayer)
{
	OBJECT.UnRegisterRenderer2D(this);
	m_iOrderInLayer = _iOrderInLayer;
	OBJECT.RegisterRenderer2D(this);
}
