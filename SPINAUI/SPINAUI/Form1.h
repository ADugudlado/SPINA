#pragma once
//#include "FileSystem\GetIncludes.h"
//#include "FileSystem\FileSystem.h"
//using namespace WinTools_Extracts;


namespace SPINA {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
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
	private: System::Windows::Forms::GroupBox^  groupBoxCommandLine;
	protected: 

	private: System::Windows::Forms::Button^  buttonload;
	protected: 


	private: System::Windows::Forms::OpenFileDialog^  openFileDialogFileLoc;
	private: System::Windows::Forms::GroupBox^  groupBoxOutput;
	private: System::Windows::Forms::GroupBox^  groupBoxOptions;
	private: System::Windows::Forms::ListBox^  listBoxOutput;
	private: System::Windows::Forms::Button^  buttonSave;
	private: System::Windows::Forms::Button^  buttonRun;
	private: System::Windows::Forms::RichTextBox^  richTextBoxCmdLine;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialogFileLoc;


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
			this->groupBoxCommandLine = (gcnew System::Windows::Forms::GroupBox());
			this->richTextBoxCmdLine = (gcnew System::Windows::Forms::RichTextBox());
			this->buttonload = (gcnew System::Windows::Forms::Button());
			this->openFileDialogFileLoc = (gcnew System::Windows::Forms::OpenFileDialog());
			this->groupBoxOutput = (gcnew System::Windows::Forms::GroupBox());
			this->listBoxOutput = (gcnew System::Windows::Forms::ListBox());
			this->groupBoxOptions = (gcnew System::Windows::Forms::GroupBox());
			this->buttonSave = (gcnew System::Windows::Forms::Button());
			this->buttonRun = (gcnew System::Windows::Forms::Button());
			this->saveFileDialogFileLoc = (gcnew System::Windows::Forms::SaveFileDialog());
			this->groupBoxCommandLine->SuspendLayout();
			this->groupBoxOutput->SuspendLayout();
			this->groupBoxOptions->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBoxCommandLine
			// 
			this->groupBoxCommandLine->Controls->Add(this->richTextBoxCmdLine);
			this->groupBoxCommandLine->Location = System::Drawing::Point(13, 13);
			this->groupBoxCommandLine->Name = L"groupBoxCommandLine";
			this->groupBoxCommandLine->Size = System::Drawing::Size(421, 110);
			this->groupBoxCommandLine->TabIndex = 0;
			this->groupBoxCommandLine->TabStop = false;
			this->groupBoxCommandLine->Text = L"Command line";
			// 
			// richTextBoxCmdLine
			// 
			this->richTextBoxCmdLine->Location = System::Drawing::Point(4, 20);
			this->richTextBoxCmdLine->Name = L"richTextBoxCmdLine";
			this->richTextBoxCmdLine->Size = System::Drawing::Size(411, 84);
			this->richTextBoxCmdLine->TabIndex = 0;
			this->richTextBoxCmdLine->Text = L"";
			// 
			// buttonload
			// 
			this->buttonload->Location = System::Drawing::Point(7, 29);
			this->buttonload->Name = L"buttonload";
			this->buttonload->Size = System::Drawing::Size(84, 41);
			this->buttonload->TabIndex = 1;
			this->buttonload->Text = L"Load";
			this->buttonload->UseVisualStyleBackColor = true;
			this->buttonload->Click += gcnew System::EventHandler(this, &Form1::buttonfileloc_Click);
			// 
			// openFileDialogFileLoc
			// 
			this->openFileDialogFileLoc->AddExtension = false;
			this->openFileDialogFileLoc->FileName = L"openFileDialogFileLoc";
			this->openFileDialogFileLoc->Filter = L"Text files(*.txt)|*.txt|All files(*.*)|*.*";
			// 
			// groupBoxOutput
			// 
			this->groupBoxOutput->AutoSize = true;
			this->groupBoxOutput->Controls->Add(this->listBoxOutput);
			this->groupBoxOutput->Location = System::Drawing::Point(111, 129);
			this->groupBoxOutput->Name = L"groupBoxOutput";
			this->groupBoxOutput->Size = System::Drawing::Size(325, 205);
			this->groupBoxOutput->TabIndex = 1;
			this->groupBoxOutput->TabStop = false;
			this->groupBoxOutput->Text = L"Output";
			// 
			// listBoxOutput
			// 
			this->listBoxOutput->Dock = System::Windows::Forms::DockStyle::Top;
			this->listBoxOutput->FormattingEnabled = true;
			this->listBoxOutput->Location = System::Drawing::Point(3, 16);
			this->listBoxOutput->Name = L"listBoxOutput";
			this->listBoxOutput->Size = System::Drawing::Size(319, 186);
			this->listBoxOutput->TabIndex = 0;
			// 
			// groupBoxOptions
			// 
			this->groupBoxOptions->Controls->Add(this->buttonSave);
			this->groupBoxOptions->Controls->Add(this->buttonload);
			this->groupBoxOptions->Location = System::Drawing::Point(9, 190);
			this->groupBoxOptions->Name = L"groupBoxOptions";
			this->groupBoxOptions->Size = System::Drawing::Size(100, 141);
			this->groupBoxOptions->TabIndex = 2;
			this->groupBoxOptions->TabStop = false;
			this->groupBoxOptions->Text = L"File Options";
			this->groupBoxOptions->Enter += gcnew System::EventHandler(this, &Form1::groupBoxOptions_Enter);
			// 
			// buttonSave
			// 
			this->buttonSave->Location = System::Drawing::Point(8, 88);
			this->buttonSave->Name = L"buttonSave";
			this->buttonSave->Size = System::Drawing::Size(84, 41);
			this->buttonSave->TabIndex = 2;
			this->buttonSave->Text = L"Save";
			this->buttonSave->UseVisualStyleBackColor = true;
			this->buttonSave->Click += gcnew System::EventHandler(this, &Form1::buttonSave_Click);
			// 
			// buttonRun
			// 
			this->buttonRun->Location = System::Drawing::Point(19, 138);
			this->buttonRun->Name = L"buttonRun";
			this->buttonRun->Size = System::Drawing::Size(84, 41);
			this->buttonRun->TabIndex = 1;
			this->buttonRun->Text = L"Run";
			this->buttonRun->UseVisualStyleBackColor = true;
			// 
			// saveFileDialogFileLoc
			// 
			this->saveFileDialogFileLoc->Filter = L"Text files (*.txt)|*.txt";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(440, 343);
			this->Controls->Add(this->buttonRun);
			this->Controls->Add(this->groupBoxOptions);
			this->Controls->Add(this->groupBoxOutput);
			this->Controls->Add(this->groupBoxCommandLine);
			this->Name = L"Form1";
			this->Text = L"SPINA";
			this->groupBoxCommandLine->ResumeLayout(false);
			this->groupBoxOutput->ResumeLayout(false);
			this->groupBoxOptions->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonfileloc_Click(System::Object^  sender, System::EventArgs^  e) {
				openFileDialogFileLoc->FileName="";
				richTextBoxCmdLine->Text="";
    			 if(openFileDialogFileLoc->ShowDialog()==System::Windows::Forms::DialogResult::OK){
					 StreamReader^ st= File::OpenText(openFileDialogFileLoc->FileName);
					 if(st!=nullptr){
						 richTextBoxCmdLine->Text=openFileDialogFileLoc->FileName;
						 for(System::String^ temp=st->ReadLine();temp!=nullptr;){
							richTextBoxCmdLine->Text+=temp;
							temp=st->ReadLine();
						 }
					 }else{
						 richTextBoxCmdLine->Text="Cannot open file";
					 }
				 }
			 }
	private: System::Void richTextBoxCmdLine_TextChanged(System::Object^  sender, System::EventArgs^  e) {
				 if(richTextBoxCmdLine->Text->Length!=0){
						
				 }
			 }
	private: System::Void groupBoxOptions_Enter(System::Object^  sender, System::EventArgs^  e) {

			 }
private: System::Void buttonSave_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(richTextBoxCmdLine->Text!=""){
				saveFileDialogFileLoc->ShowDialog();
			 }else{
			 }
		 }
};
}

