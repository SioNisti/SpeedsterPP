#pragma once
#include "proc.h"
#include <iostream>
#include <Windows.h>
#include <cstdio>
#include <tchar.h>
#include <vector>
#using <System.dll>
#using <System.Windows.Forms.dll>
#include <iomanip>

namespace SpeedsterPP {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for vaihe
	/// </summary>
	public ref class vaihe : public System::Windows::Forms::Form
	{
	public:
		vaihe(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~vaihe()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
	private: bool dragging;
	private: System::Windows::Forms::ToolStripMenuItem^ frontTransmissionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ useToolStripMenuItem;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ closeToolStripMenuItem;
	private: Point offset;
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(vaihe::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->closeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contextMenuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Lucida Console", 72, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(-12, 2);
			this->label1->Margin = System::Windows::Forms::Padding(0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(98, 96);
			this->label1->TabIndex = 0;
			this->label1->Text = L"5";
			this->label1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &vaihe::label1_MouseDown);
			this->label1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &vaihe::label1_MouseMove);
			this->label1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &vaihe::label1_MouseUp);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &vaihe::timer1_Tick);
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->closeToolStripMenuItem });
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(104, 26);
			// 
			// closeToolStripMenuItem
			// 
			this->closeToolStripMenuItem->Name = L"closeToolStripMenuItem";
			this->closeToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->closeToolStripMenuItem->Text = L"Close";
			this->closeToolStripMenuItem->Click += gcnew System::EventHandler(this, &vaihe::closeToolStripMenuItem_Click);
			// 
			// vaihe
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(69, 86);
			this->ContextMenuStrip = this->contextMenuStrip1;
			this->Controls->Add(this->label1);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(69, 86);
			this->Name = L"vaihe";
			this->Text = L"Gear";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &vaihe::vaihe_Load);
			this->contextMenuStrip1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void vaihe_Load(System::Object^ sender, System::EventArgs^ e) {
		this->Width = 69;
		this->Height = 86;
		this->dragging = false;
		timer1->Interval = 1;
		timer1->Start();
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		DWORD procId = GetProcId(L"RallyTrophy.exe");

		uintptr_t moduleBase = GetModuleBaseAddress(procId, L"RallyTrophy.exe");

		HANDLE hProcess = 0;
		hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procId);

		uintptr_t dynamicPtrBaseAddr = moduleBase + 0x00163F40;

		std::vector<unsigned int> Offsets = { 0x130, 0xF8C };
		uintptr_t vaiheAddr = FindMDMAAddy(hProcess, dynamicPtrBaseAddr, Offsets);

		int vaihe = 0;

		ReadProcessMemory(hProcess, (BYTE*)vaiheAddr, &vaihe, sizeof(vaihe), nullptr);

		if (vaihe == 0) {
			this->label1->Text = L"N";
		}
		else if (vaihe == 4294967295) {
			this->label1->Text = L"R";
		}
		else {
			this->label1->Text = vaihe.ToString("0");
		}

	}
	private: System::Void label1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left)
		{
			this->dragging = true;
			this->offset = Point(e->X, e->Y);
		}
	}
private: System::Void label1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (this->dragging) {
		Point currentScreenPos = PointToScreen(e->Location);
		Location = Point(currentScreenPos.X - this->offset.X, currentScreenPos.Y - this->offset.Y);
	}
}
private: System::Void label1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	this->dragging = false;
}
private: System::Void closeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
}
};
}
