================================================================================
    TEAM SHANGHAI DREAM EQUINOX : DirectGraphics Project Overview
================================================================================
ReadMe.txt 文件对于类中的一些函数参数进行解释和备注

// DirectGraphics主要完成D3D初始化与渲染清除、开始、结束、提交工作

// 关于Direct3D相关接口函数作用描述

//-------------------------------------------------------------
// 名称: IDirect3D9* WINAPI Direct3DCreate9(UINT SDKVersion)
// 作用: 创建Direct3D9对象指针
// 参数: 只能传入D3D_SDK_VERSION
// 返回: IDirect3D9*类型(Direct3D9对象指针)(NULL代表函数执行失败)
//-------------------------------------------------------------

//----------------------------------------------------------------------------------------------
// 名称: HRESULT IDirect3D9::GetDeviceCaps(UINT Adapter, D3DDEVTYPE DeviceType, D3DCAPS9* pCaps)
// 作用: 校验显卡硬件顶点运算
// 参数1: UINT Adapter 指定物理显卡序号 默认D3DADAPTER_DEFAULT
// 参数2: D3DDEVTYPE DeviceType 指定设备类型(D3DDEVTYPE_HAL: 硬件设备 D3DDEVTYPE_REF: 软件设备)
// 参数3: D3DCAPS9* pCaps 返回初始化的设备性能结构体
// 返回: HRESULT(初始化状态:成功:S_OK,失败:E_FAIL)
//----------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------
// 名称: D3DPRESENT_PARAMETERS结构体
// 参数: UINT BackBufferWidth 后台缓存中表面宽度(单位是像素)
// 参数: UINT BackBufferHeight 后台缓存中表面高度(单位是像素)
// 参数: _D3DFORMAT BackBufferFormat 后台缓存中表面的像素格式
//		 D3DFMT_R8G8B8: 24位像素格式RGB各8位
//		 D3DFMT_X8R8G8B8: 32位像素格式8位未使用,RGB各8位
//		 D3DFMT_A8R8G8B8: 32位像素格式ARGB各8位
//		 D3DFMT_A16B16G16R16F: 64位像素格式A16位B16位G16位R16位
//		 D3DFMT_A32B32G32R32F: 128位像素格式A32位B32位G32位R32位
// 参数: UINT BackBufferCount 后台缓存中表面数量
// 参数: _D3DMULTISAMPLE_TYPE MultiSampleType 后台缓存中表面所使用的多重采样
//		 D3DMULTISAMPLE_NONE: 不使用多重采样
// 参数: DWORD MultiSampleQuality 后台缓存中表面所使用的多重采样质量水平
// 参数: D3DSWAPEFFECT SwapEffect 交换链采用的缓存页面置换方式
//		 D3DSWAPEFFECT_DISCARD: 置换效率最高
// 参数: HWND hDeviceWindow 窗口句柄
// 参数: BOOL Windowed 窗口运行模式
//		 true: 窗口模式
//		 false: 全屏模式
// 参数: BOOL EnableAutoDepthStencil Direct3D自动创建并维护深度缓存或模板缓存
// 参数: D3DFORMAT AutoDepthStencilFormat Direct3D深度缓存或模板缓存的像素格式
//		 D3DFMT_D24S8: 深度缓存或模板缓存的像素格式
// 参数: DWORD Flags Direct3D附加特性(0:无附加特性)
//		 D3DPRESENTFLAG_LOCKABLE_DEPTHBUFFER: 可锁定的后台缓存 可能会降低性能
//		 D3DPRESENTFLAG_DISCARD_DEPTHBUFFER: 指定下一个后台缓存提交时,哪个深度缓存或模板缓存会被丢弃
// 参数: UINT FullScreen_RefreshRateInHz Direct3D刷新频率
//		 D3DPRESENT_RATE_DEFAULT: 默认刷新频率60Hz
// 参数: UINT PresentationInterval Direct3D提交频率
//		 D3DPRESENT_INTERVAL_DEFAULT: 默认提交频率60Hz
//		 D3DPRESENT_INTERVAL_IMMEDIATE: 立即提交
//----------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// 名称: HRESULT IDirect3D9::CreateDevice(UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS* pPresentationParameters, IDirect3DDevice9** ppReturnedDeviceInterface)
// 作用: 创建D3D9设备对象指针
// 参数1: UINT Adapter 指定物理显卡序号 默认D3DADAPTER_DEFAULT
// 参数2: D3DDEVTYPE DeviceType 指定设备类型(D3DDEVTYPE_HAL: 硬件设备 D3DDEVTYPE_REF: 软件设备)
// 参数3: HWND hFocusWindow 窗口句柄
// 参数4: DWORD BehaviorFlags 行为标志
//	      D3DCREATE_HARDWARE_VERTEXPROCESSING Direct3D硬件顶点运算
//	      D3DCREATE_SOFTWARE_VERTEXPROCESSING Direct3D软件顶点运算
// 参数5: D3DPRESENT_PARAMETERS* pPresentationParameters D3DPRESENT_PARAMETERS结构体参数
// 参数6: IDirect3DDevice9** ppReturnedDeviceInterface 返回Direct3D设备对象指针
// 返回: HRESULT(初始化状态:成功:S_OK,失败:E_FAIL)
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------------------
// 名称: HRESULT IDirect3DDevice9::Clear(DWORD Count, CONST D3DRECT* pRects, DWORD Flags, D3DCOLOR Color, float Z, DWORD Stencil)
// 作用: D3D9清除屏幕
// 参数1: DWORD Count pRect数组中矩形的数目
// 参数2: CONST D3DRECT* pRects 要清除的屏幕矩形数组
// 参数3: DWORD Flags 指定所需要清除的表面
//        D3DCLEAR_TARGET: 目标表面 后台缓存
//        D3DCLEAR_ZBUFFER: 深度缓存
//        D3DCLEAR_STENCIL: 模板缓存
// 参数4: D3DCOLOR Color 绘制目标设置为什么颜色
// 参数5: float Z 深度缓存设定值
// 参数6: DWORD Stencil 模板缓存设定值
// 返回: HRESULT(初始化状态:成功:S_OK,失败:E_FAIL)
//------------------------------------------------------------------------------------------------------------------------------

// 关于DirectGraphics相关接口函数作用描述

// DirectGraphicsBegin函数与DirectGraphicsEnd函数之间进行渲染