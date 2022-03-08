#include "Form1.h"
#include "proc.h"
#include <iostream>
#include <Windows.h>
#include <cstdio>
#include <tchar.h>
#include <vector>
#using <System.dll>
#using <System.Windows.Forms.dll>

using namespace System;
using namespace System::Windows::Forms;
[STAThread]

void main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    SpeedsterPP::Form1 form;
    Application::Run(% form);
	/*
	DWORD procId = GetProcId(L"RallyTrophy.exe");

	uintptr_t moduleBase = GetModuleBaseAddress(procId, L"RallyTrophy.exe");

	HANDLE hProcess = 0;
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procId);

	uintptr_t dynamicPtrBaseAddr = moduleBase + 0x00163FDC;

	std::cout << "dynamicPtrBaseAddr: " << "0x" << std::hex << dynamicPtrBaseAddr << std::endl;

	std::vector<unsigned int> spdOffsets = { 0x284 };
	uintptr_t spdAddr = FindMDMAAddy(hProcess, dynamicPtrBaseAddr, spdOffsets);

	std::cout << "spdAddr: " << "0x" << std::hex << spdAddr << std::endl;

	float spdValue = 0.0f;

	while (true) {
		ReadProcessMemory(hProcess, (BYTE*)spdAddr, &spdValue, sizeof(spdValue), nullptr);

		//std::cout << "spd: " << std::dec << spdValue << std::endl;
	}*/
}
