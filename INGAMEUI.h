#pragma once
class INGAMEUI 
{
private:
public:
	void Init();
	void Update();

	void Release();
	void OnCollisionEnter(CObject* _pObject);
	void OnCollisionStay(CObject* _pObject);
	void OnCollisionExit(CObject* _pObject);
	virtual void Render() ;
	INGAMEUI();
	~INGAMEUI();


};