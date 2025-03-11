#include<windows.h>
#include<time.h>
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
const int Time=5;
int getMouse(int x){
    POINT pt;
    GetCursorPos(&pt);
    if(x==1) return pt.x;
    return pt.y;
}
void TopWindow(HWND &hWnd) {
    SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
}
bool pressed(){
    return GetAsyncKeyState(VK_CONTROL) & 0x8000 && GetAsyncKeyState(VK_MENU) & 0x8000;
}
bool _break(){
	return GetAsyncKeyState(VK_F3);
}
int main()
{
	POINT p;
    GetCursorPos(&p);
    HWND hWnd=GetForegroundWindow();
    if (hWnd) {
//        ShowWindow(hWnd, SW_HIDE);
    }
    bool flag=true;
    while(1){
        ::mouse_event(MOUSEEVENTF_LEFTDOWN,p.x,p.y,0,0);
        ::mouse_event(MOUSEEVENTF_LEFTUP,p.x,p.y,0,0);
        ::Sleep(Time);
        while(flag){
        	if(_break()){
        		ShowWindow(hWnd, SW_SHOW);
        		exit(0);
        	}
        	while(pressed()){
        		TopWindow(hWnd);
        		flag=false;
        	}
        	TopWindow(hWnd);
        }
        if(_break()){
        	ShowWindow(hWnd, SW_SHOW);
        	exit(0);
       	}
        while(pressed()){
        	TopWindow(hWnd);
			flag=true;
        }
        TopWindow(hWnd);
	}
    return 0;
}