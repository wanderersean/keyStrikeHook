#define _WIN32_WINNT 0x0500 //for hiding the console window
#include <Windows.h>
#include <iostream>
using namespace std;

HHOOK keyboardHook = 0; //the global hook
bool bBlock = false; //determine whether to block the key strike
unsigned int timerID = 0;// timer hook identification
int timerInterval = 60;// time interval in ms


LRESULT CALLBACK TimerCallback(HWND Arg1,UINT Arg2,UINT_PTR Arg3,DWORD Arg4){
    //cout<< "time up"<<endl;
    bBlock = false;
    KillTimer(NULL, timerID);
}


LRESULT CALLBACK HookCallback(int code, WPARAM wParam, LPARAM lParam)
{
    static DWORD lastkey = 0;

    KBDLLHOOKSTRUCT *ks = (KBDLLHOOKSTRUCT*)lParam;
    
    if(wParam == WM_KEYDOWN){
        if(bBlock == true && lastkey == ks->vkCode){  //the same key is pressed very fast
            lastkey = ks->vkCode;
            cout << "[INFO]double strock!" <<endl;
            return 1;

        }else if(bBlock == true && lastkey != ks->vkCode){  // different keys are pressed
            lastkey = ks->vkCode;
            timerID = SetTimer(NULL, timerID, timerInterval, (TIMERPROC)TimerCallback);
            //cout<< "[TEST] set new timer " << ks->vkCode << endl;
            return CallNextHookEx(0, code, wParam, lParam);

        }else{ // bBlock is false
            lastkey = ks->vkCode;
            //cout<< "[TEST] " << ks->vkCode << endl;
            bBlock = true;
            timerID = SetTimer(NULL, 0, timerInterval, (TIMERPROC)TimerCallback);
            return CallNextHookEx(0, code, wParam, lParam);

        }

    }else{ //other wParam 
        return CallNextHookEx(0, code, wParam, lParam);

    }
    
}


int main()
{
	//hide the console window
    if(IsWindowVisible(GetConsoleWindow()) == true){
        ShowWindow(GetConsoleWindow(), SW_HIDE);
    }
	
	//set the low-level keyboard hook which doesn't need DLL programming
    keyboardHook = SetWindowsHookExA(WH_KEYBOARD_LL, HookCallback, GetModuleHandleA(NULL), 0);
    if (keyboardHook == 0)
    {
        cout << "failed" << endl;
        return -1;
    }
    cout << "hook ok" << endl;

	//don't foget the window loop
    MSG msg;
    while(GetMessage(&msg, NULL, 0, 0)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

	//unhook
    UnhookWindowsHookEx(keyboardHook);

    return 0;
}
