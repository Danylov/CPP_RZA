// CodeGear C++Builder
// Copyright (c) 1995, 2016 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DaqUtils.pas' rev: 31.00 (Windows)

#ifndef DaqutilsHPP
#define DaqutilsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.Windows.hpp>
#include <Vcl.Graphics.hpp>
#include <System.Classes.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Controls.hpp>
#include <System.SysUtils.hpp>
#include <System.StrUtils.hpp>
#include <System.Math.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <System.SyncObjs.hpp>
#include <System.Types.hpp>
#include <System.UITypes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Daqutils
{
//-- forward type declarations -----------------------------------------------
struct TWaveParam;
class DELPHICLASS TWaveGenerator;
class DELPHICLASS TPortPanel;
class DELPHICLASS TEventCheckThread;
class DELPHICLASS TSimpleGraph;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TWaveStyle : unsigned char { Sine, Triangle, Square };

struct DECLSPEC_DRECORD TWaveParam
{
public:
	TWaveStyle Style;
	double HiLevel;
	double LoLevel;
	int PtsPerPeriod;
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TWaveGenerator : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod double __fastcall GetOnePoint(const TWaveParam &wave, int ptIndex);
	__classmethod void __fastcall GetWaveform(int waveCount, const TWaveParam *wave, const int wave_High, int dataCount, double *data, const int data_High);
public:
	/* TObject.Create */ inline __fastcall TWaveGenerator(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TWaveGenerator(void) { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TPortPanel : public Vcl::Extctrls::TPanel
{
	typedef Vcl::Extctrls::TPanel inherited;
	
private:
	System::Classes::TNotifyEvent m_stateChanged;
	Vcl::Stdctrls::TLabel* m_portLabel;
	Vcl::Stdctrls::TEdit* m_hexEditor;
	Vcl::Stdctrls::TGroupBox* m_highGrpBox;
	Vcl::Stdctrls::TGroupBox* m_lowGrpBox;
	System::StaticArray<Vcl::Extctrls::TImage*, 8> m_stateBoxes;
	System::StaticArray<Vcl::Graphics::TGraphic*, 3> m_stateImages;
	System::Byte m_mask;
	bool __fastcall getEditable(void);
	void __fastcall setEditable(bool value);
	System::Byte __fastcall getMask(void);
	void __fastcall setMask(System::Byte value);
	int __fastcall getPortNum(void);
	System::Byte __fastcall getState(void);
	void __fastcall setState(System::Byte value);
	void __fastcall HexEditor_Exit(System::TObject* sender);
	void __fastcall HexEditor_KeyDown(System::TObject* sender, System::Word &key, System::Classes::TShiftState shift);
	void __fastcall StateBox_Clicked(System::TObject* sender);
	
public:
	__fastcall virtual TPortPanel(System::Classes::TComponent* AOwner);
	void __fastcall Initialize(int port, Vcl::Graphics::TGraphic* *images, const int images_High);
	bool __fastcall ShowPortLabel(bool show);
	bool __fastcall ShowHexEditor(bool show);
	__property bool Editable = {read=getEditable, write=setEditable, nodefault};
	__property System::Byte Mask = {read=getMask, write=setMask, nodefault};
	__property int Port = {read=getPortNum, nodefault};
	__property System::Byte State = {read=getState, write=setState, nodefault};
	__property System::Classes::TNotifyEvent OnChange = {read=m_stateChanged, write=m_stateChanged};
public:
	/* TCustomControl.Destroy */ inline __fastcall virtual ~TPortPanel(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TPortPanel(HWND ParentWindow) : Vcl::Extctrls::TPanel(ParentWindow) { }
	
};


typedef void __fastcall (__closure *TEventCheckNotify)(int id, NativeUInt obj);

class PASCALIMPLEMENTATION TEventCheckThread : public System::Classes::TThread
{
	typedef System::Classes::TThread inherited;
	
private:
	System::StaticArray<int, 63> m_ids;
	System::StaticArray<NativeUInt, 63> m_handles;
	System::StaticArray<TEventCheckNotify, 63> m_notifies;
	System::StaticArray<bool, 63> m_synced;
	int m_count;
	NativeUInt m_syncObj;
	System::Syncobjs::TCriticalSection* m_lock;
	int syncId;
	NativeUInt syncObj;
	TEventCheckNotify syncProc;
	void __fastcall SyncNotify(void);
	
protected:
	virtual void __fastcall Execute(void);
	
public:
	__fastcall TEventCheckThread(bool createSuspended)/* overload */;
	__fastcall virtual ~TEventCheckThread(void);
	void __fastcall Add(int id, NativeUInt handle, TEventCheckNotify notify, bool synced);
	void __fastcall Remove(NativeUInt handle);
	void __fastcall Clear(void);
	void __fastcall Stop(void);
	__property int Count = {read=m_count, nodefault};
public:
	/* TThread.Create */ inline __fastcall TEventCheckThread(void)/* overload */ : System::Classes::TThread() { }
	
};


enum DECLSPEC_DENUM TOverOneScreenMode : unsigned char { BeginScreen, EndScreen };

class PASCALIMPLEMENTATION TSimpleGraph : public System::TObject
{
	typedef System::TObject inherited;
	
	
private:
	typedef System::DynamicArray<double> _TSimpleGraph__1;
	
	typedef System::DynamicArray<System::Types::TPoint> _TSimpleGraph__2;
	
	typedef System::DynamicArray<System::DynamicArray<System::Types::TPoint> > _TSimpleGraph__3;
	
	
private:
	Vcl::Extctrls::TPaintBox* m_hostCtrl;
	double m_YCordMax;
	double m_YCordMin;
	double m_xIncByTime;
	_TSimpleGraph__1 m_plotData;
	_TSimpleGraph__3 m_dataPoint;
	double m_XCordDivRate;
	double m_XCordTimeDiv;
	double m_XCordTimeOffset;
	int m_plotCount;
	int m_shiftCount;
	int m_dataCachedPerPlot;
	int m_mapIndexPerPlot;
	int m_pointPerScreen;
	TOverOneScreenMode m_overOneScreenMode;
	void __fastcall HostCtrlPaint(System::TObject* sender);
	void __fastcall SaveData(const double *data, const int data_High, int dataPerPlot);
	void __fastcall Redraw(void);
	void __fastcall CalcDrawParams(double xIncBySec);
	void __fastcall MapDataPoints(void);
	void __fastcall DrawOnePlot(Vcl::Graphics::TCanvas* canvas, const System::Types::TPoint *data, const int data_High, int count);
	
public:
	__fastcall TSimpleGraph(Vcl::Extctrls::TPaintBox* hostCtrl);
	__fastcall virtual ~TSimpleGraph(void);
	void __fastcall Clear(void);
	void __fastcall Chart(const double *data, const int data_High, int plotCount, int dataPerPlot, double xIncBySec);
	void __fastcall ScaleXCord(int DivValue);
	void __fastcall Shift(int shiftTime);
	void __fastcall PaintTo(Vcl::Graphics::TCanvas* canvas);
	System::Uitypes::TColor __fastcall GetPlotColor(int plot);
	__property double XCordTimeDiv = {read=m_XCordTimeDiv, write=m_XCordTimeDiv};
	__property double XCordOffset = {read=m_XCordTimeOffset, write=m_XCordTimeOffset};
	__property double YCordMax = {read=m_YCordMax, write=m_YCordMax};
	__property double YCordMin = {read=m_YCordMin, write=m_YCordMin};
	__property TOverOneScreenMode OverOneScreenMode = {read=m_overOneScreenMode, write=m_overOneScreenMode, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE int STATE_DISABLE_IMG_IDX;
extern DELPHI_PACKAGE int STATE_HI_IMG_IDX;
extern DELPHI_PACKAGE int STATE_LO_IMG_IDX;
extern DELPHI_PACKAGE int EVENT_MAX_ALLOWED;
extern DELPHI_PACKAGE Vcl::Imaging::Jpeg::TJPEGImage* __fastcall LoadJPEGFromResource(NativeUInt resHandle, System::UnicodeString name);
}	/* namespace Daqutils */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DAQUTILS)
using namespace Daqutils;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DaqutilsHPP
