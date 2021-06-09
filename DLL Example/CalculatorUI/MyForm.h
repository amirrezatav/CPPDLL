#pragma once
#include <string>

namespace CalculatorUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;




	[UnmanagedFunctionPointerAttribute(CallingConvention::Cdecl)]
	delegate void DelResult(std::string);

	[UnmanagedFunctionPointerAttribute(CallingConvention::Cdecl)]
	delegate int DelTest(std::string);

	[DllImport("CalculatorDLL.dll", CallingConvention = CallingConvention::Cdecl)]
	extern IntPtr CreateObject(DelResult^);

	[DllImport("CalculatorDLL.dll", CallingConvention = CallingConvention::Cdecl)]
	extern int SUM(IntPtr, int a, int b);

	[DllImport("CalculatorDLL.dll", CallingConvention = CallingConvention::Cdecl)]
	extern int MINE(IntPtr, int a, int b);

	[DllImport("CalculatorDLL.dll", CallingConvention = CallingConvention::Cdecl)]
	extern int DIVIDE(IntPtr, int a, int b);

	[DllImport("CalculatorDLL.dll", CallingConvention = CallingConvention::Cdecl)]
	extern int MULT(IntPtr, int a, int b, DelResult^);

	[DllImport("CalculatorDLL.dll", CallingConvention = CallingConvention::Cdecl)]
	extern  void Start(DelTest^);

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		DelResult^ Event_DelResult;
		DelTest^ Event_DelTest;
		IntPtr CalObject;
		MyForm(void)
		{
			InitializeComponent();
			Event_DelResult += gcnew DelResult(this, &MyForm::Res);
			Event_DelTest += gcnew DelTest(this, &MyForm::_test);
			Start(Event_DelTest);
			CalObject = CreateObject(Event_DelResult);
		}

		void Res(std::string str)
		{
			MessageBox::Show(gcnew String(str.c_str()));
		}
		int _test(std::string str)
		{
			MessageBox::Show(gcnew String(str.c_str()));
			return 0;
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
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox3;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(98, 183);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"CalCulator";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(123, 56);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(123, 102);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(55, 60);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(53, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Number 1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(55, 106);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Number 2";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(86, 148);
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 5;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		MULT(CalObject, Convert::ToInt32(textBox1->Text), Convert::ToInt32(textBox2->Text), Event_DelResult);
	}
	};
}
