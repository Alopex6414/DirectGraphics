================================================================================
    TEAM SHANGHAI DREAM EQUINOX : DirectGraphics Project Overview
================================================================================
ReadMe.txt �ļ��������е�һЩ�����������н��ͺͱ�ע

// DirectGraphics��Ҫ���D3D��ʼ������Ⱦ�������ʼ���������ύ����

// ����Direct3D��ؽӿں�����������

//-------------------------------------------------------------
// ����: IDirect3D9* WINAPI Direct3DCreate9(UINT SDKVersion)
// ����: ����Direct3D9����ָ��
// ����: ֻ�ܴ���D3D_SDK_VERSION
// ����: IDirect3D9*����(Direct3D9����ָ��)(NULL������ִ��ʧ��)
//-------------------------------------------------------------

//----------------------------------------------------------------------------------------------
// ����: HRESULT IDirect3D9::GetDeviceCaps(UINT Adapter, D3DDEVTYPE DeviceType, D3DCAPS9* pCaps)
// ����: У���Կ�Ӳ����������
// ����1: UINT Adapter ָ�������Կ���� Ĭ��D3DADAPTER_DEFAULT
// ����2: D3DDEVTYPE DeviceType ָ���豸����(D3DDEVTYPE_HAL: Ӳ���豸 D3DDEVTYPE_REF: ����豸)
// ����3: D3DCAPS9* pCaps ���س�ʼ�����豸���ܽṹ��
// ����: HRESULT(��ʼ��״̬:�ɹ�:S_OK,ʧ��:E_FAIL)
//----------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------
// ����: D3DPRESENT_PARAMETERS�ṹ��
// ����: UINT BackBufferWidth ��̨�����б�����(��λ������)
// ����: UINT BackBufferHeight ��̨�����б���߶�(��λ������)
// ����: _D3DFORMAT BackBufferFormat ��̨�����б�������ظ�ʽ
//		 D3DFMT_R8G8B8: 24λ���ظ�ʽRGB��8λ
//		 D3DFMT_X8R8G8B8: 32λ���ظ�ʽ8λδʹ��,RGB��8λ
//		 D3DFMT_A8R8G8B8: 32λ���ظ�ʽARGB��8λ
//		 D3DFMT_A16B16G16R16F: 64λ���ظ�ʽA16λB16λG16λR16λ
//		 D3DFMT_A32B32G32R32F: 128λ���ظ�ʽA32λB32λG32λR32λ
// ����: UINT BackBufferCount ��̨�����б�������
// ����: _D3DMULTISAMPLE_TYPE MultiSampleType ��̨�����б�����ʹ�õĶ��ز���
//		 D3DMULTISAMPLE_NONE: ��ʹ�ö��ز���
// ����: DWORD MultiSampleQuality ��̨�����б�����ʹ�õĶ��ز�������ˮƽ
// ����: D3DSWAPEFFECT SwapEffect ���������õĻ���ҳ���û���ʽ
//		 D3DSWAPEFFECT_DISCARD: �û�Ч�����
// ����: HWND hDeviceWindow ���ھ��
// ����: BOOL Windowed ��������ģʽ
//		 true: ����ģʽ
//		 false: ȫ��ģʽ
// ����: BOOL EnableAutoDepthStencil Direct3D�Զ�������ά����Ȼ����ģ�建��
// ����: D3DFORMAT AutoDepthStencilFormat Direct3D��Ȼ����ģ�建������ظ�ʽ
//		 D3DFMT_D24S8: ��Ȼ����ģ�建������ظ�ʽ
// ����: DWORD Flags Direct3D��������(0:�޸�������)
//		 D3DPRESENTFLAG_LOCKABLE_DEPTHBUFFER: �������ĺ�̨���� ���ܻή������
//		 D3DPRESENTFLAG_DISCARD_DEPTHBUFFER: ָ����һ����̨�����ύʱ,�ĸ���Ȼ����ģ�建��ᱻ����
// ����: UINT FullScreen_RefreshRateInHz Direct3Dˢ��Ƶ��
//		 D3DPRESENT_RATE_DEFAULT: Ĭ��ˢ��Ƶ��60Hz
// ����: UINT PresentationInterval Direct3D�ύƵ��
//		 D3DPRESENT_INTERVAL_DEFAULT: Ĭ���ύƵ��60Hz
//		 D3DPRESENT_INTERVAL_IMMEDIATE: �����ύ
//----------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// ����: HRESULT IDirect3D9::CreateDevice(UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS* pPresentationParameters, IDirect3DDevice9** ppReturnedDeviceInterface)
// ����: ����D3D9�豸����ָ��
// ����1: UINT Adapter ָ�������Կ���� Ĭ��D3DADAPTER_DEFAULT
// ����2: D3DDEVTYPE DeviceType ָ���豸����(D3DDEVTYPE_HAL: Ӳ���豸 D3DDEVTYPE_REF: ����豸)
// ����3: HWND hFocusWindow ���ھ��
// ����4: DWORD BehaviorFlags ��Ϊ��־
//	      D3DCREATE_HARDWARE_VERTEXPROCESSING Direct3DӲ����������
//	      D3DCREATE_SOFTWARE_VERTEXPROCESSING Direct3D�����������
// ����5: D3DPRESENT_PARAMETERS* pPresentationParameters D3DPRESENT_PARAMETERS�ṹ�����
// ����6: IDirect3DDevice9** ppReturnedDeviceInterface ����Direct3D�豸����ָ��
// ����: HRESULT(��ʼ��״̬:�ɹ�:S_OK,ʧ��:E_FAIL)
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------------------
// ����: HRESULT IDirect3DDevice9::Clear(DWORD Count, CONST D3DRECT* pRects, DWORD Flags, D3DCOLOR Color, float Z, DWORD Stencil)
// ����: D3D9�����Ļ
// ����1: DWORD Count pRect�����о��ε���Ŀ
// ����2: CONST D3DRECT* pRects Ҫ�������Ļ��������
// ����3: DWORD Flags ָ������Ҫ����ı���
//        D3DCLEAR_TARGET: Ŀ����� ��̨����
//        D3DCLEAR_ZBUFFER: ��Ȼ���
//        D3DCLEAR_STENCIL: ģ�建��
// ����4: D3DCOLOR Color ����Ŀ������Ϊʲô��ɫ
// ����5: float Z ��Ȼ����趨ֵ
// ����6: DWORD Stencil ģ�建���趨ֵ
// ����: HRESULT(��ʼ��״̬:�ɹ�:S_OK,ʧ��:E_FAIL)
//------------------------------------------------------------------------------------------------------------------------------

// ����DirectGraphics��ؽӿں�����������

// DirectGraphicsBegin������DirectGraphicsEnd����֮�������Ⱦ