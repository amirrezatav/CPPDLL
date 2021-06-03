#pragma once
#include <string>

namespace Event {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	
	delegate void DelProgressBar(int);
	delegate void DelConsole(int);



	[DllImport("FirstDLL.dll", CallingConvention = CallingConvention::Cdecl)]
	extern IntPtr CreateObject(DelConsole^ k);


	[DllImport("FirstDLL.dll", CallingConvention = CallingConvention::StdCall)]
	extern int ExcK(IntPtr);


	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		
		DelConsole ^ PassFunc;

		DelProgressBar^ ProgressBarEvent;
		MyForm(void)
		{
			InitializeComponent();
			ProgressBarEvent = gcnew DelProgressBar(this, &MyForm::SetProgress);
			PassFunc = gcnew DelConsole(this, &MyForm::ConsolePass);
		}

		void ConsolePass(int a)
		{
			MessageBox::Show(a.ToString());
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ BtnStart;
	protected:
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::Label^ LabProgress;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->BtnStart = (gcnew System::Windows::Forms::Button());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->LabProgress = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// BtnStart
			// 
			this->BtnStart->Cursor = System::Windows::Forms::Cursors::Cross;
			this->BtnStart->Location = System::Drawing::Point(104, 72);
			this->BtnStart->Name = L"BtnStart";
			this->BtnStart->Size = System::Drawing::Size(75, 23);
			this->BtnStart->TabIndex = 0;
			this->BtnStart->Text = L"Start";
			this->BtnStart->UseVisualStyleBackColor = true;
			this->BtnStart->Click += gcnew System::EventHandler(this, &MyForm::BtnStart_Click);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(12, 24);
			this->progressBar1->MaximumSize = System::Drawing::Size(500, 20);
			this->progressBar1->MinimumSize = System::Drawing::Size(260, 20);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(260, 20);
			this->progressBar1->TabIndex = 1;
			// 
			// LabProgress
			// 
			this->LabProgress->AutoSize = true;
			this->LabProgress->Location = System::Drawing::Point(278, 24);
			this->LabProgress->Name = L"LabProgress";
			this->LabProgress->Size = System::Drawing::Size(35, 13);
			this->LabProgress->TabIndex = 2;
			this->LabProgress->Text = L"label1";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(417, 134);
			this->Controls->Add(this->LabProgress);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->BtnStart);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		void SetProgress(int a)
		{
			if(this->InvokeRequired)
				this->Invoke(ProgressBarEvent, gcnew array<Object^> { a });
			progressBar1->Value = a;
			if (progressBar1->Value == 100)
			{
				BtnStart->Enabled = true;
				
			}
		}
		void ChangeProgress()
		{
			for (int i = 0; i <= 100; i++)
			{
				Thread::Sleep(1000);
				ProgressBarEvent(i);
			}
		}
	private: System::Void BtnStart_Click(System::Object^ sender, System::EventArgs^ e) {
		BtnStart->Enabled = false;
		ThreadStart^ myfunc = gcnew ThreadStart(this , &MyForm::ChangeProgress);
		Thread^ mythread = gcnew Thread(myfunc);
		mythread->Start();
		try
		{
			IntPtr obj = CreateObject(PassFunc);
			auto a = ExcK(obj);
			LabProgress->Text = a.ToString();
		}
		catch (std::string ex)
		{
			MessageBox::Show(gcnew String(ex.c_str()));
		}
	}
	};
}
