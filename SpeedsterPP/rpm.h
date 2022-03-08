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
	/// Summary for rpm
	/// </summary>
	public ref class rpm : public System::Windows::Forms::Form
	{
	public:
		rpm(void)
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
		~rpm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ closeToolStripMenuItem;
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
	private: Point offset;
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(rpm::typeid));
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
			this->label1->Location = System::Drawing::Point(-18, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(446, 96);
			this->label1->TabIndex = 0;
			this->label1->Text = L"0000RPM";
			this->label1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &rpm::label1_MouseDown);
			this->label1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &rpm::label1_MouseMove);
			this->label1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &rpm::label1_MouseUp);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &rpm::timer1_Tick);
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
			this->closeToolStripMenuItem->Click += gcnew System::EventHandler(this, &rpm::closeToolStripMenuItem_Click);
			// 
			// rpm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(404, 86);
			this->ContextMenuStrip = this->contextMenuStrip1;
			this->Controls->Add(this->label1);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"rpm";
			this->Text = L"RPM";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &rpm::rpm_Load);
			this->contextMenuStrip1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void rpm_Load(System::Object^ sender, System::EventArgs^ e) {
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

		std::vector<unsigned int> Offsets = { 0x130, 0xF88 };
		uintptr_t vaiheAddr = FindMDMAAddy(hProcess, dynamicPtrBaseAddr, Offsets);

		float rpm = 0;

		ReadProcessMemory(hProcess, (BYTE*)vaiheAddr, &rpm, sizeof(rpm), nullptr);

		this->label1->Text = rpm.ToString("0000RPM");

	}
private: System::Void closeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
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
};
};
