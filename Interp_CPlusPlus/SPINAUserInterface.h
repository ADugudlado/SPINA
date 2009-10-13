#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
#include "Interp_main.h"


namespace Interp_CPlusPlus {

	/// <summary>
	/// Summary for SPINAUserInterface
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class SPINAUserInterface : public System::Windows::Forms::Form
	{
	public:
		SPINAUserInterface(void)
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
		~SPINAUserInterface()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  buttonRun;
	protected: 
	private: System::Windows::Forms::GroupBox^  groupBoxOptions;
	private: System::Windows::Forms::Button^  buttonSave;
	private: System::Windows::Forms::Button^  buttonload;
	private: System::Windows::Forms::GroupBox^  groupBoxOutput;

	private: System::Windows::Forms::GroupBox^  groupBoxCommandLine;
	private: System::Windows::Forms::RichTextBox^  richTextBoxCmdLine;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialogFileLoc;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialogFileLoc;
	private: System::Text::StringBuilder^ strbuilder;
	private: System::Windows::Forms::RichTextBox^  richTextBoxOutput;


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
			this->buttonRun = (gcnew System::Windows::Forms::Button());
			this->groupBoxOptions = (gcnew System::Windows::Forms::GroupBox());
			this->buttonSave = (gcnew System::Windows::Forms::Button());
			this->buttonload = (gcnew System::Windows::Forms::Button());
			this->groupBoxOutput = (gcnew System::Windows::Forms::GroupBox());
			this->richTextBoxOutput = (gcnew System::Windows::Forms::RichTextBox());
			this->groupBoxCommandLine = (gcnew System::Windows::Forms::GroupBox());
			this->richTextBoxCmdLine = (gcnew System::Windows::Forms::RichTextBox());
			this->openFileDialogFileLoc = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialogFileLoc = (gcnew System::Windows::Forms::SaveFileDialog());
			this->groupBoxOptions->SuspendLayout();
			this->groupBoxOutput->SuspendLayout();
			this->groupBoxCommandLine->SuspendLayout();
			this->SuspendLayout();
			// 
			// buttonRun
			// 
			this->buttonRun->Enabled = false;
			this->buttonRun->Location = System::Drawing::Point(15, 129);
			this->buttonRun->Name = L"buttonRun";
			this->buttonRun->Size = System::Drawing::Size(84, 41);
			this->buttonRun->TabIndex = 5;
			this->buttonRun->Text = L"Run";
			this->buttonRun->UseVisualStyleBackColor = true;
			this->buttonRun->Click += gcnew System::EventHandler(this, &SPINAUserInterface::buttonRun_Click);
			// 
			// groupBoxOptions
			// 
			this->groupBoxOptions->Controls->Add(this->buttonSave);
			this->groupBoxOptions->Controls->Add(this->buttonload);
			this->groupBoxOptions->Location = System::Drawing::Point(5, 181);
			this->groupBoxOptions->Name = L"groupBoxOptions";
			this->groupBoxOptions->Size = System::Drawing::Size(100, 156);
			this->groupBoxOptions->TabIndex = 6;
			this->groupBoxOptions->TabStop = false;
			this->groupBoxOptions->Text = L"File Options";
			// 
			// buttonSave
			// 
			this->buttonSave->Enabled = false;
			this->buttonSave->Location = System::Drawing::Point(8, 100);
			this->buttonSave->Name = L"buttonSave";
			this->buttonSave->Size = System::Drawing::Size(84, 41);
			this->buttonSave->TabIndex = 2;
			this->buttonSave->Text = L"Save";
			this->buttonSave->UseVisualStyleBackColor = true;
			this->buttonSave->Click += gcnew System::EventHandler(this, &SPINAUserInterface::buttonSave_Click);
			// 
			// buttonload
			// 
			this->buttonload->Location = System::Drawing::Point(7, 31);
			this->buttonload->Name = L"buttonload";
			this->buttonload->Size = System::Drawing::Size(84, 41);
			this->buttonload->TabIndex = 1;
			this->buttonload->Text = L"Load";
			this->buttonload->UseVisualStyleBackColor = true;
			this->buttonload->Click += gcnew System::EventHandler(this, &SPINAUserInterface::buttonload_Click);
			// 
			// groupBoxOutput
			// 
			this->groupBoxOutput->Controls->Add(this->richTextBoxOutput);
			this->groupBoxOutput->Location = System::Drawing::Point(107, 120);
			this->groupBoxOutput->Name = L"groupBoxOutput";
			this->groupBoxOutput->Size = System::Drawing::Size(325, 217);
			this->groupBoxOutput->TabIndex = 4;
			this->groupBoxOutput->TabStop = false;
			this->groupBoxOutput->Text = L"Output";
			// 
			// richTextBoxOutput
			// 
			this->richTextBoxOutput->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->richTextBoxOutput->DetectUrls = false;
			this->richTextBoxOutput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->richTextBoxOutput->Location = System::Drawing::Point(9, 17);
			this->richTextBoxOutput->Name = L"richTextBoxOutput";
			this->richTextBoxOutput->ReadOnly = true;
			this->richTextBoxOutput->Size = System::Drawing::Size(308, 194);
			this->richTextBoxOutput->TabIndex = 0;
			this->richTextBoxOutput->Text = L"";
			this->richTextBoxOutput->WordWrap = false;
			// 
			// groupBoxCommandLine
			// 
			this->groupBoxCommandLine->Controls->Add(this->richTextBoxCmdLine);
			this->groupBoxCommandLine->Location = System::Drawing::Point(9, 4);
			this->groupBoxCommandLine->Name = L"groupBoxCommandLine";
			this->groupBoxCommandLine->Size = System::Drawing::Size(421, 110);
			this->groupBoxCommandLine->TabIndex = 3;
			this->groupBoxCommandLine->TabStop = false;
			this->groupBoxCommandLine->Text = L"Command line";
			// 
			// richTextBoxCmdLine
			// 
			this->richTextBoxCmdLine->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->richTextBoxCmdLine->Location = System::Drawing::Point(4, 20);
			this->richTextBoxCmdLine->Name = L"richTextBoxCmdLine";
			this->richTextBoxCmdLine->Size = System::Drawing::Size(411, 84);
			this->richTextBoxCmdLine->TabIndex = 0;
			this->richTextBoxCmdLine->Text = L"";
			this->richTextBoxCmdLine->TextChanged += gcnew System::EventHandler(this, &SPINAUserInterface::richTextBoxCmdLine_TextChanged);
			// 
			// openFileDialogFileLoc
			// 
			this->openFileDialogFileLoc->AddExtension = false;
			this->openFileDialogFileLoc->FileName = L"openFileDialogFileLoc";
			this->openFileDialogFileLoc->Filter = L"Text files(*.txt)|*.txt|All files(*.*)|*.*";
			// 
			// saveFileDialogFileLoc
			// 
			this->saveFileDialogFileLoc->Filter = L"Text files (*.txt)|*.txt";
			// 
			// SPINAUserInterface
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(443, 345);
			this->Controls->Add(this->buttonRun);
			this->Controls->Add(this->groupBoxOptions);
			this->Controls->Add(this->groupBoxOutput);
			this->Controls->Add(this->groupBoxCommandLine);
			this->Name = L"SPINAUserInterface";
			this->Text = L"SPINA";
			this->groupBoxOptions->ResumeLayout(false);
			this->groupBoxOutput->ResumeLayout(false);
			this->groupBoxCommandLine->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void buttonload_Click(System::Object^  sender, System::EventArgs^  e) {
				openFileDialogFileLoc->FileName="";
				//richTextBoxCmdLine->Text="";
    			 if(openFileDialogFileLoc->ShowDialog()==System::Windows::Forms::DialogResult::OK){
					 System::IO::StreamReader^ st= System::IO::File::OpenText(openFileDialogFileLoc->FileName);
					 if(st!=nullptr){
						 for(System::String^ temp=st->ReadLine();temp!=nullptr;){
							richTextBoxCmdLine->Text+=temp;
							temp=st->ReadLine();
						 }
					 }else{
						 richTextBoxOutput->AppendText("Cannot open file");
					 }
				 }				 
			 }
private: System::Void buttonSave_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(richTextBoxCmdLine->Text!=""){
				if(saveFileDialogFileLoc->ShowDialog()==System::Windows::Forms::DialogResult::OK){
					 String^ temp=saveFileDialogFileLoc->FileName;
					 System::IO::StreamWriter^ st= gcnew StreamWriter(temp);
					 if(st!=nullptr){
						 temp=richTextBoxCmdLine->Text;
						 st->Write(temp);
					 }else{
						 richTextBoxOutput->AppendText("Cannot open file");
					 }
					 st->Close();
				 }	
			 }
		 }
private: System::Void richTextBoxCmdLine_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(richTextBoxCmdLine->Text!=""){
				 buttonSave->Enabled=true;
				 buttonRun->Enabled=true;
			 }else{
				 buttonSave->Enabled=false;
				 buttonRun->Enabled=false;
			 }
		 }
private: System::Void buttonRun_Click(System::Object^  sender, System::EventArgs^  e) {
			 Main themain;
			 //StringWriter^ sw=gcnew StringWriter(sb);
			 
			 //IO::Stream^ st=gcnew StreamWriter();

//			 DWORD tid;int *i =0;
//			 hthread=CreateThread(NULL,0,&Interp_CPlusPlus::SPINAUserInterface::getOutput,&i,TRUE,&tid);
			 strbuilder=gcnew System::Text::StringBuilder();
			 TextWriter^ temp=Console::Out;
			 StringWriter^ stw=gcnew StringWriter(strbuilder);			 
			 Console::SetOut(stw);			 
			 strbuilder->Remove(0,strbuilder->Length);
			 stw->Flush();
			 themain.VisitLine(richTextBoxCmdLine->Text);			 
			 String^ tempstr=strbuilder->ToString();
			 richTextBoxOutput->AppendText(tempstr);
			 stw->Close();
//			 CloseHandle(hthread);
		
			 
		 }
private: System::Void listBoxOutput_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
