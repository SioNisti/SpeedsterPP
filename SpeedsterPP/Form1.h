#pragma once
#include "proc.h"
#include "vaihe.h"
#include "rpm.h"
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
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ changeColorDependingOnSpeedToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ showHighestSpeedToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ resetHighestSpeedToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
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
	private: System::Windows::Forms::ToolStripMenuItem^ fastRedToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ showWindowToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ rPMToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ gearToolStripMenuItem;
	private: Point offset;

		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->frontTransmissionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->useToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->changeColorDependingOnSpeedToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fastRedToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->showHighestSpeedToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->resetHighestSpeedToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->showWindowToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->rPMToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->gearToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contextMenuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Lucida Console", 74.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(-18, 2);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(402, 99);
			this->label1->TabIndex = 0;
			this->label1->Text = L"000Kmh";
			this->label1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::label1_MouseDown);
			this->label1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::label1_MouseMove);
			this->label1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::label1_MouseUp);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Lucida Console", 74.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(-18, 84);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(402, 99);
			this->label2->TabIndex = 1;
			this->label2->Text = L"000Kmh";
			this->label2->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::label2_MouseDown);
			this->label2->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::label2_MouseMove);
			this->label2->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::label2_MouseUp);
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {
				this->frontTransmissionToolStripMenuItem,
					this->useToolStripMenuItem, this->changeColorDependingOnSpeedToolStripMenuItem, this->fastRedToolStripMenuItem, this->showHighestSpeedToolStripMenuItem,
					this->resetHighestSpeedToolStripMenuItem, this->showWindowToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(257, 202);
			// 
			// frontTransmissionToolStripMenuItem
			// 
			this->frontTransmissionToolStripMenuItem->CheckOnClick = true;
			this->frontTransmissionToolStripMenuItem->Name = L"frontTransmissionToolStripMenuItem";
			this->frontTransmissionToolStripMenuItem->Size = System::Drawing::Size(256, 22);
			this->frontTransmissionToolStripMenuItem->Text = L"Rear-wheel drive";
			// 
			// useToolStripMenuItem
			// 
			this->useToolStripMenuItem->CheckOnClick = true;
			this->useToolStripMenuItem->Name = L"useToolStripMenuItem";
			this->useToolStripMenuItem->Size = System::Drawing::Size(256, 22);
			this->useToolStripMenuItem->Text = L"Use Mph";
			this->useToolStripMenuItem->CheckedChanged += gcnew System::EventHandler(this, &Form1::useToolStripMenuItem_CheckedChanged);
			// 
			// changeColorDependingOnSpeedToolStripMenuItem
			// 
			this->changeColorDependingOnSpeedToolStripMenuItem->CheckOnClick = true;
			this->changeColorDependingOnSpeedToolStripMenuItem->Name = L"changeColorDependingOnSpeedToolStripMenuItem";
			this->changeColorDependingOnSpeedToolStripMenuItem->Size = System::Drawing::Size(256, 22);
			this->changeColorDependingOnSpeedToolStripMenuItem->Text = L"Legal speed limits";
			// 
			// fastRedToolStripMenuItem
			// 
			this->fastRedToolStripMenuItem->CheckOnClick = true;
			this->fastRedToolStripMenuItem->Name = L"fastRedToolStripMenuItem";
			this->fastRedToolStripMenuItem->Size = System::Drawing::Size(256, 22);
			this->fastRedToolStripMenuItem->Text = L"Change color depending on speed";
			// 
			// showHighestSpeedToolStripMenuItem
			// 
			this->showHighestSpeedToolStripMenuItem->CheckOnClick = true;
			this->showHighestSpeedToolStripMenuItem->Name = L"showHighestSpeedToolStripMenuItem";
			this->showHighestSpeedToolStripMenuItem->Size = System::Drawing::Size(256, 22);
			this->showHighestSpeedToolStripMenuItem->Text = L"Show highest speed";
			this->showHighestSpeedToolStripMenuItem->CheckedChanged += gcnew System::EventHandler(this, &Form1::showHighestSpeedToolStripMenuItem_CheckedChanged);
			// 
			// resetHighestSpeedToolStripMenuItem
			// 
			this->resetHighestSpeedToolStripMenuItem->Name = L"resetHighestSpeedToolStripMenuItem";
			this->resetHighestSpeedToolStripMenuItem->Size = System::Drawing::Size(256, 22);
			this->resetHighestSpeedToolStripMenuItem->Text = L"Reset highest speed";
			this->resetHighestSpeedToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::resetHighestSpeedToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(256, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::exitToolStripMenuItem_Click);
			// 
			// showWindowToolStripMenuItem
			// 
			this->showWindowToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->rPMToolStripMenuItem,
					this->gearToolStripMenuItem
			});
			this->showWindowToolStripMenuItem->Name = L"showWindowToolStripMenuItem";
			this->showWindowToolStripMenuItem->Size = System::Drawing::Size(256, 22);
			this->showWindowToolStripMenuItem->Text = L"Show window";
			// 
			// rPMToolStripMenuItem
			// 
			this->rPMToolStripMenuItem->Name = L"rPMToolStripMenuItem";
			this->rPMToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->rPMToolStripMenuItem->Text = L"RPM";
			this->rPMToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::rPMToolStripMenuItem_Click);
			// 
			// gearToolStripMenuItem
			// 
			this->gearToolStripMenuItem->Name = L"gearToolStripMenuItem";
			this->gearToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->gearToolStripMenuItem->Text = L"Gear";
			this->gearToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::gearToolStripMenuItem_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(355, 86);
			this->ContextMenuStrip = this->contextMenuStrip1;
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"Speedster++";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->contextMenuStrip1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
		this->dragging = false;

		vaihe^ vaihe1 = gcnew vaihe;
		vaihe1->Show();
		rpm^ rpm1 = gcnew rpm;
		rpm1->Show();

		timer1->Interval = 1;
		timer1->Start();
	}

	float highest = 0.0f;
	int clspd = 0;

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		DWORD procId = GetProcId(L"RallyTrophy.exe");

		uintptr_t moduleBase = GetModuleBaseAddress(procId, L"RallyTrophy.exe");

		HANDLE hProcess = 0;
		hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procId);

		uintptr_t dynamicPtrBaseAddr = moduleBase + 0x00163F40;
		uintptr_t dynamicPtrBaseAddr2 = moduleBase + 0x00163F40;

		//std::cout << "dynamicPtrBaseAddr: " << "0x" << std::hex << dynamicPtrBaseAddr << std::endl;

		std::vector<unsigned int> spdOffsets = { 0x130, 0xC3C };
		std::vector<unsigned int> spdOffsets2 = { 0x130, 0x2AC};
		uintptr_t spdAddr = FindMDMAAddy(hProcess, dynamicPtrBaseAddr, spdOffsets);
		uintptr_t spdAddr2 = FindMDMAAddy(hProcess, dynamicPtrBaseAddr2, spdOffsets2);

		//std::cout << "spdAddr: " << "0x" << std::hex << spdAddr << std::endl;

		float spdValue = 0.0f;

		if (frontTransmissionToolStripMenuItem->Checked) {
			ReadProcessMemory(hProcess, (BYTE*)spdAddr2, &spdValue, sizeof(spdValue), nullptr);
		}
		else {
			ReadProcessMemory(hProcess, (BYTE*)spdAddr, &spdValue, sizeof(spdValue), nullptr);
		}

		if (useToolStripMenuItem->Checked) {
			spdValue = spdValue / 1.609;
		}

		if (spdValue > 999.4 && spdValue < 9999.4) {
			this->label1->Font = (gcnew System::Drawing::Font(L"Lucida Console", 65.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		}
		else if (spdValue > 9999.4) {
			this->label1->Font = (gcnew System::Drawing::Font(L"Lucida Console", 55.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		}
		else {
			this->label1->Font = (gcnew System::Drawing::Font(L"Lucida Console", 74.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		}

		if (highest > 999.4 && highest < 9999.4) {
			this->label2->Font = (gcnew System::Drawing::Font(L"Lucida Console", 65.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		}
		else if (highest > 9999.4) {
			this->label2->Font = (gcnew System::Drawing::Font(L"Lucida Console", 55.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		}
		else {
			this->label2->Font = (gcnew System::Drawing::Font(L"Lucida Console", 74.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		}

		if (!useToolStripMenuItem->Checked) {
			if (spdValue < -.5) {
				this->label1->Text = spdValue.ToString("00") + L"Kmh";
			}
			else {
				this->label1->Text = spdValue.ToString("000") + L"Kmh";
			}
		}
		else {
			if (spdValue < -.5) {
				this->label1->Text = spdValue.ToString("00") + L"Mph";
			}
			else {
				this->label1->Text = spdValue.ToString("000") + L"Mph";
			}
		}
		if (spdValue > highest)
		{
			/*
			std::cout << "highest: " << "0x" << std::hex << highest << std::endl;
			std::cout << "spdValue: " << "0x" << std::hex << spdValue << std::endl;
			char s1[256];
			sprintf(s1, "highest: %f\n", highest);
			OutputDebugStringA(s1);
			sprintf(s1, "spdValue: %f\n", spdValue);
			OutputDebugStringA(s1);*/

			highest = spdValue;
			if (!useToolStripMenuItem->Checked) {
				this->label2->Text = spdValue.ToString("000") + "Kmh";
			}
			else {
				this->label2->Text = spdValue.ToString("000") + "Mph";
			}
		}

		if (fastRedToolStripMenuItem->Checked) {
			int spdX17 = spdValue * 1.7;
			int mspdX17 = fabs(spdValue) * 1.7;

			if (useToolStripMenuItem->Checked) {
				spdX17 = spdValue * 2.7;
				mspdX17 = fabs(spdValue) * 2.7;
			}

			if (spdX17 <= 255 && spdX17 >= -255) {
				if (spdX17 >= 0) {
					label1->ForeColor = Color::FromArgb(255, 255, 255 - spdX17, 255 - spdX17);
				}
				else {
					label1->ForeColor = Color::FromArgb(255, 255, 255 - mspdX17, 255 - mspdX17);
				}
			}
			else {
				label1->ForeColor = Color::FromArgb(255, 255, 0, 0);
			}
		}
		else if (changeColorDependingOnSpeedToolStripMenuItem->Checked)
		{
			if (spdValue < 30)
			{
				label1->ForeColor = System::Drawing::ColorTranslator::FromHtml("#FFD700");
			}
			else if (spdValue > 30 && spdValue < 50)
			{
				label1->ForeColor = System::Drawing::ColorTranslator::FromHtml("#FF961B");
			}
			else if (spdValue > 50 && spdValue < 60)
			{
				label1->ForeColor = System::Drawing::ColorTranslator::FromHtml("#FF6B2D");
			}
			else if (spdValue > 60 && spdValue < 70)
			{
				label1->ForeColor = System::Drawing::ColorTranslator::FromHtml("#FF3045");
			}
			else if (spdValue >= 70)
			{
				label1->ForeColor = System::Drawing::ColorTranslator::FromHtml("#FF0059");
			}
		}
		else
		{
			label1->ForeColor = System::Drawing::Color::White;
		}
	}
private: System::Void showHighestSpeedToolStripMenuItem_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (showHighestSpeedToolStripMenuItem->Checked) {
		this->Width = 355;
		this->Height = 170;
	}
	else {
		this->Width = 355;
		this->Height = 86;
	}
}
private: System::Void resetHighestSpeedToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	highest = 0;
	if (!useToolStripMenuItem->Checked) {
		this->label2->Text = L"000Kmh";
	}
	else {
		this->label2->Text = L"000Mph";
	}
}
private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	Close();
}
private: System::Void label1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (e->Button == System::Windows::Forms::MouseButtons::Left)
	{
		this->dragging = true;
		this->offset = Point(e->X, e->Y);
	}
}
private: System::Void label1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	this->dragging = false;
}
private: System::Void label1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (this->dragging) {
		Point currentScreenPos = PointToScreen(e->Location);
		Location = Point(currentScreenPos.X - this->offset.X, currentScreenPos.Y - this->offset.Y);
	}
}
private: System::Void useToolStripMenuItem_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	highest = 0;
	if (!useToolStripMenuItem->Checked) {
		this->label2->Text = L"000Kmh";
	}
	else {
		this->label2->Text = L"000Mph";
	}
}
private: System::Void label2_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (e->Button == System::Windows::Forms::MouseButtons::Left)
	{
		this->dragging = true;
		this->offset = Point(e->X, e->Y);
	}
}
private: System::Void label2_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (this->dragging) {
		Point currentScreenPos = PointToScreen(e->Location);
		Location = Point(currentScreenPos.X - this->offset.X, currentScreenPos.Y - this->offset.Y);
	}
}
private: System::Void label2_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	this->dragging = false;
}
private: System::Void rPMToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	rpm^ rpm1 = gcnew rpm;
	rpm1->Show();
}
private: System::Void gearToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	vaihe^ vaihe1 = gcnew vaihe;
	vaihe1->Show();
}
};
}
