#include <windows.h> 
using namespace std;

int main() {
	SetProcessAffinityMask(GetCurrentProcess(), 0x04);
	const DWORD busyTime = 10;
	//const DWORD int idleTime = busyTime;
	const DWORD idleTime = busyTime;

	//INT64 startTime = 0;
	while (true) {
		DWORD startTime = GetTickCount();
		while ((GetTickCount() - startTime) <= busyTime)
			;
		Sleep(idleTime);
	}	
	return 0;
}