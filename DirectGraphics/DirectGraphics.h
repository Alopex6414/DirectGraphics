/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		DirectGraphics.h
* @brief	This Program is DirectGraphics DLL Project.
* @author	Alopex/Helium
* @version	v1.21a
* @date		2017-11-2	v1.00a	alopex	Create Project.
* @date		2017-12-2	v1.01a	alopex	Add D3DXFont.
* @date		2017-12-8	v1.11a	alopex	Code Do Not Rely On MSVCR Library.
* @date		2018-1-10	v1.20a	alopex	Code Add dxerr & d3dcompiler Library and Modify Verify.
* @date		2018-1-10	v1.21a	alopex	Add Thread Safe File & Variable(DirectThreadSafe).
*/
#pragma once

#ifndef __DIRECTGRAPHICS_H_
#define __DIRECTGRAPHICS_H_

//Macro Definition
#ifdef	DIRECTGRAPHICS_EXPORTS
#define DIRECTGRAPHICS_API	__declspec(dllexport)
#else
#define DIRECTGRAPHICS_API	__declspec(dllimport)
#endif

#ifndef USER_SCREENWIDTH
#define USER_SCREENWIDTH	640		//UserScreenWidth
#endif

#ifndef USER_SCREENHEIGHT
#define USER_SCREENHEIGHT	480		//UserScreenHeight
#endif

#define ADAPTERTYPESIZE	50	//AdapterType Size

//Struct Definition

//CallBack Definition

//Class Definition
class DIRECTGRAPHICS_API DirectGraphics
{
private:
	IDirect3D9* m_pD3D9;	//The Direct3D 9 Main Object
	IDirect3DDevice9* m_pD3D9Device;	//The Direct3D 9 Render Device
	D3DCAPS9 m_D3D9Caps;	//The Direct3D 9 Caps
	D3DPRESENT_PARAMETERS m_D3D9pp;		//The Direct3D 9 Parameters
	ID3DXFont* m_pD3DXFont;	//The Direct3D 9 Font
	wchar_t m_wcD3D9AdapterType[ADAPTERTYPESIZE];	//The Direct3D 9 AdapterType(eg:NVIDIA GeForce GT750M)

	CRITICAL_SECTION m_cs;	//Thread Safe(CriticalSection)
	bool m_bThreadSafe;		//Thread Safe Status

public:
	DirectGraphics();	//DirectGraphics Constructor Function
	~DirectGraphics();	//DirectGraphics Destructor	Function

	IDirect3D9* WINAPI DirectGraphicsGetObject(void) const;	//DirectGraphics Get Object
	IDirect3DDevice9* WINAPI DirectGraphicsGetDevice(void) const;	//DirectGraphics Get Device
	const D3DCAPS9* WINAPI DirectGraphicsGetCaps(void) const;	//DirectGraphics Get Caps
	const D3DPRESENT_PARAMETERS* WINAPI DirectGraphicsGetPresentParameters(void) const;	//DirectGraphics Get Present Parameters
	const wchar_t* WINAPI DirectGraphicsAdapterType(void) const;	//DirectGraphics Get Adapter Type

	HRESULT WINAPI DirectGraphicsInit(HWND hWnd);	//DirectGraphics Initialization(W:640 H:480 Windowed)
	HRESULT WINAPI DirectGraphicsInit(HWND hWnd, bool bIsWindowed);	//DirectGraphics Initialization
	HRESULT WINAPI DirectGraphicsInit(HWND hWnd, bool bIsWindowed, int nScreenWidth, int nScreenHeight);	//DirectGraphics Initialization
	HRESULT WINAPI DirectGraphicsInit(D3DPRESENT_PARAMETERS D3D9pp);	//DirectGraphics Initialization
	HRESULT WINAPI DirectGraphicsBeginScene(void);	//DirectGraphics Begin Render
	HRESULT WINAPI DirectGraphicsEndScene(void);	//DirectGraphics End Render
	HRESULT WINAPI DirectGraphicsBegin(void);	//DirectGraphics Begin Render
	HRESULT WINAPI DirectGraphicsEnd(void);		//DirectGraphics End Render
	HRESULT WINAPI DirectGraphicsPresent(void);	//DirectGraphics Present Render
	HRESULT WINAPI DirectGraphicsClear(void);	//DirectGraphics Clear Screen
	HRESULT WINAPI DirectGraphicsClear(DWORD dwColor);	//DirectGraphics Clear Screen
	
	HRESULT WINAPI DirectGraphicsFontInit();	//DirectGraphicsFont Initialization
	HRESULT WINAPI DirectGraphicsFontInit(int nFontSize);	//DirectGraphicsFont Initialization
	HRESULT WINAPI DirectGraphicsFontInit(int nFontSize, LPWSTR lpszFontType);	//DirectGraphicsFont Initialization
	void WINAPI DirectGraphicsFontDrawText(HWND hWnd);	//DirectGraphicsFont Draw Text
	void WINAPI DirectGraphicsFontDrawText(HWND hWnd, D3DXCOLOR dwColor);	//DirectGraphicsFont Draw Text
};

//Variable Definition

//Function Definition

#endif