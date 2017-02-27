// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ZylTimer.pas' rev: 24.00 (Win32)

#ifndef ZyltimerHPP
#define ZyltimerHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Zyltimer
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TZylTimer;
class PASCALIMPLEMENTATION TZylTimer : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	bool FRegistered;
	double FVersion;
	double FInterval;
	System::Classes::TNotifyEvent FOnTimer;
	bool FEnabled;
	System::Classes::TThread* FTimerThread;
	bool FCycled;
	unsigned FRepeatCount;
	unsigned FCounter;
	System::Classes::TThreadPriority FPriority;
	bool FNeedSynchronization;
	void __fastcall SetEnabled(bool Value);
	void __fastcall SetInterval(double Value);
	void __fastcall SetPriority(System::Classes::TThreadPriority Value);
	void __fastcall SetOnTimer(System::Classes::TNotifyEvent Value);
	bool __fastcall RunningInTheIDE(void);
	void __fastcall DoTimer(void);
	
public:
	__property bool NeedSynchronization = {read=FNeedSynchronization, write=FNeedSynchronization, default=0};
	__property double Version = {read=FVersion};
	__fastcall virtual TZylTimer(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TZylTimer(void);
	unsigned __fastcall GetCycleNumber(void);
	void __fastcall Start(void);
	void __fastcall Restart(void);
	void __fastcall Stop(void);
	
protected:
	void __fastcall UpdateTimer(void);
	
__published:
	__property bool Enabled = {read=FEnabled, write=SetEnabled, default=1};
	__property double Interval = {read=FInterval, write=SetInterval};
	__property bool Cycled = {read=FCycled, write=FCycled, default=1};
	__property unsigned RepeatCount = {read=FRepeatCount, write=FRepeatCount, default=0};
	__property System::Classes::TNotifyEvent OnTimer = {read=FOnTimer, write=SetOnTimer};
	__property System::Classes::TThreadPriority Priority = {read=FPriority, write=SetPriority, default=3};
};


class DELPHICLASS TTimerThread;
class PASCALIMPLEMENTATION TTimerThread : public System::Classes::TThread
{
	typedef System::Classes::TThread inherited;
	
private:
	TZylTimer* Owner;
	
protected:
	virtual void __fastcall Execute(void);
	void __fastcall CustomSleep(unsigned Interval);
	
public:
	__fastcall TTimerThread(TZylTimer* AOwner);
	__fastcall virtual ~TTimerThread(void);
};


struct DECLSPEC_DRECORD TTimeCaps
{
public:
	unsigned wPeriodMin;
	unsigned wPeriodMax;
};


typedef TTimeCaps *PTimeCaps;

//-- var, const, procedure ---------------------------------------------------
static const int MAX_UINT = int(0x7fffffff);
static const unsigned MAX_CARDINAL = unsigned(0xffffffff);
static const System::Word TIMER_RESOLUTION = System::Word(0x3e8);
extern PACKAGE unsigned __stdcall (*_timeBeginPeriod)(unsigned period);
extern PACKAGE unsigned __stdcall (*_timeEndPeriod)(unsigned period);
extern PACKAGE unsigned __stdcall (*_timeGetDevCaps)(PTimeCaps lpTimeCaps, unsigned uSize);
extern PACKAGE void * __fastcall LinkAPI(const System::UnicodeString module, const System::UnicodeString functionname);
extern PACKAGE void __fastcall Register(void);
}	/* namespace Zyltimer */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_ZYLTIMER)
using namespace Zyltimer;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ZyltimerHPP
