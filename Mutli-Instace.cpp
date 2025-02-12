#include <iostream>
#include <Windows.h>

HANDLE roblox_mutex = CreateMutexW(0, TRUE, L"Lua-Ware Single");

int main()
{
    SetConsoleTitle(L"Lua-Ware MultiInstance [Waiting]");

    

    printf("Starting Multi-Instance...\n");

    if (roblox_mutex == NULL) {
        printf("[error] MUTEX ERROR\n");
        system("PAUSE > nul");
        return -1;
    }

    if (GetLastError() == ERROR_ALREADY_EXISTS) {
        printf("[error] Already Exists\n");
        system("PAUSE > nul");
        return -1;
    }

    
    printf("STARTED.\n");
    HWND consoleWindow = GetConsoleWindow();
    ShowWindow(consoleWindow, SW_HIDE);
    while (true) {
        
        Sleep(1000);  // PREVENTS CPU OVERRIDE
    }
    system("PAUSE");
    return 0;
}
