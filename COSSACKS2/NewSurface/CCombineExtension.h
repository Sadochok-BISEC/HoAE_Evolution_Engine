#ifndef __CCOMBINEEXTENSION__
#define __CCOMBINEEXTENSION__

#include "..\stdheader.h"
#include "..\GameExtension.h"
#include "Surface.h"

class CCombineExtension : public GameExtension
{
public:
	CCombineExtension(UniversalMap *pUniversalMap)
	{
		Release();
		m_pUniversalMap = pUniversalMap;
	}
	~CCombineExtension() { Release(); }
	void Release(void)
	{
		Clear();
		m_pUniversalMap = NULL;
	}
	void Clear(void)
	{
		m_bActive = false;
		m_bRedden = false;
		m_bBrowseForModel = true;
		m_CoordX = m_CoordY = m_CoordZ = 0;
		m_fScale = m_fScaleMin = m_fScalingSpeed = 0.0f;
		m_T.setIdentity();
		m_Mesh.Free(), m_Cache.Free();
	}
	virtual bool CheckActivityOfEditor() { return m_bActive; }
	virtual void ClearActivityOfEditor() { m_bActive = false; }
	virtual void ActivateEditor()
	{
		if(m_bActive) return;
		if(m_bBrowseForModel) BrowseForModel();
		if(!LoadModel()) return;
//		m_Mesh.Release(); // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//		m_Mesh.CreateSphere(Vector3D::null, 100, 0xFFFFFFFF, 0, 4); // <<<<<<<<<<
//		m_Mesh.CreateSphere(Vector3D(100, 100, 100), 300, 0&000077, 1, 4);

		if(!m_Mesh.Vert.NValues || !m_Mesh.Idxs.NValues) return;
		m_CoordX = m_CoordY = m_CoordZ = 0;
		extern int LastMx, LastMy;
		m_CoordZ = UniversalMap::THMapZ(LastMx, LastMy);
		m_T.setIdentity();
		m_bActive = true;
		m_bRedden = false;
	}
	bool BrowseForModel();
	bool LoadModel();
	void Cache();

	virtual bool OnMouseHandling(int mx, int my, bool &LeftPressed, bool &RightPressed,
		int MapCoordX, int MapCoordY, bool OverMiniMap);
	virtual void OnDrawOnMapOverAll();
	virtual bool OnMouseWheel(int Delta);

	bool m_bBrowseForModel;
private:
	UniversalMap *m_pUniversalMap;
	bool m_bActive, m_bRedden;
	int m_CoordX, m_CoordY, m_CoordZ;
	float m_fScale, m_fScaleMin, m_fScalingSpeed;
	Matrix4D m_T;
//	_str m_ModelName;
	cStr m_sFileName;
	VertexBasedMesh m_Mesh, m_Cache;
};

#endif