#include<Windows.h>
#include"NNS_cell.h"
#include"NNS_rand_core.h"
#include"NNS_god.h"
#include<time.h>
#pragma comment( linker, "/subsystem:\"console\" /entry:\"WinMainCRTStartup\"")
NNS_god God;
//NNS_cell * pc=NULL;
NNS_rand_core * pr=NULL;
void CALLBACK Sig(HWND hwnd,UINT umsg,UINT_PTR id,DWORD dwtime){
	printf("1---");
	pr->infoIn(1);
	pr->live();
	pr->infoOut();
}

int _stdcall WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow
	)
{
		printf("hello world");
		pr=new NNS_rand_core();
//		int tid=SetTimer(NULL,0,1000,Sig);
		printf("1---");
	pr->infoIn(1);
	pr->live();
	pr->infoOut();
	printf("1---");
	pr->infoIn(1);
	pr->live();
	pr->infoOut();
	printf("1---");
	pr->infoIn(1);
	pr->live();
	pr->infoOut();
	printf("1---");
	pr->infoIn(1);
	pr->live();
	pr->infoOut();
		BOOL bRet;
		MSG msg;
		while(   (bRet = GetMessage(&msg,NULL,0,0))!= 0) 
			{   
				TranslateMessage(&msg);   
				DispatchMessage(&msg);   
			}
//		KillTimer(NULL,tid);
		system("pause");
		return 0;
}