#include "karty.h"
#pragma once

namespace BlackJack {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
    using namespace oko;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
  private: System::Windows::Forms::Button^  NovaHra;
  private: System::Windows::Forms::TextBox^  textBoxVystup;
  private: System::Windows::Forms::TextBox^  textBoxMeno;
  private: System::Windows::Forms::Label^  label1;
  protected: 


	private:
    private: System::Windows::Forms::ListView^  listViewBankar;
	private: System::Windows::Forms::ListView^  listViewHrac;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;

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
			this->NovaHra = (gcnew System::Windows::Forms::Button());
			this->textBoxVystup = (gcnew System::Windows::Forms::TextBox());
			this->textBoxMeno = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->listViewBankar = (gcnew System::Windows::Forms::ListView());
			this->listViewHrac = (gcnew System::Windows::Forms::ListView());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// NovaHra
			// 
			this->NovaHra->Location = System::Drawing::Point(444, 12);
			this->NovaHra->Name = L"NovaHra";
			this->NovaHra->Size = System::Drawing::Size(75, 23);
			this->NovaHra->TabIndex = 0;
			this->NovaHra->Text = L"Nova hra";
			this->NovaHra->UseVisualStyleBackColor = true;
			this->NovaHra->Click += gcnew System::EventHandler(this, &MyForm::NovaHra_Click);
			// 
			// textBoxVystup
			// 
			this->textBoxVystup->Location = System::Drawing::Point(12, 136);
			this->textBoxVystup->Multiline = true;
			this->textBoxVystup->Name = L"textBoxVystup";
			this->textBoxVystup->Size = System::Drawing::Size(510, 114);
			this->textBoxVystup->TabIndex = 1;
			// 
			// textBoxMeno
			// 
			this->textBoxMeno->Location = System::Drawing::Point(89, 15);
			this->textBoxMeno->Name = L"textBoxMeno";
			this->textBoxMeno->Size = System::Drawing::Size(100, 20);
			this->textBoxMeno->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(67, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Meno hraca:";
			// 
			// listViewBankar
			// 
			this->listViewBankar->Location = System::Drawing::Point(12, 83);
			this->listViewBankar->Name = L"listViewBankar";
			this->listViewBankar->Size = System::Drawing::Size(244, 33);
			this->listViewBankar->TabIndex = 4;
			this->listViewBankar->UseCompatibleStateImageBehavior = false;
			// 
			// listViewHrac
			// 
			this->listViewHrac->Location = System::Drawing::Point(262, 83);
			this->listViewHrac->Name = L"listViewHrac";
			this->listViewHrac->Size = System::Drawing::Size(260, 33);
			this->listViewHrac->TabIndex = 5;
			this->listViewHrac->UseCompatibleStateImageBehavior = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 67);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(70, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Karty bankar:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(263, 67);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(58, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Karty hrac:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(534, 262);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->listViewHrac);
			this->Controls->Add(this->listViewBankar);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBoxMeno);
			this->Controls->Add(this->textBoxVystup);
			this->Controls->Add(this->NovaHra);
			this->Name = L"MyForm";
			this->Text = L"Oko";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
  private: 
    std::string managedStrToNative(System::String^ sysstr)
    {
      using System::IntPtr;
      using System::Runtime::InteropServices::Marshal;

      IntPtr ip = Marshal::StringToHGlobalAnsi(sysstr);
      std::string outString = static_cast<const char*>(ip.ToPointer());
      Marshal::FreeHGlobal(ip);
      return outString;  
    }

    String ^ StrToTextBox(string old)
    {
      String ^txt = gcnew String(" ");
      char Znak;
      for(unsigned int i = 0; i < old.length(); i++)
      {
          Znak = old[i];
          switch(Znak)
          {// vlozenie UNICODE znakov kariet namiesto ASCII 3,4,5,6 hodnot
            case zelen:
              txt += L"\u2660";
              break;
            case zalud:
              txt += L"\u2663";
              break;
            case srdce:
              txt += L"\u2665";
              break;
            case gula:
              txt += L"\u2666";
              break;
            default:
              txt += (wchar_t)Znak;
              break;
          }
      }
      return txt;
    }
    System::Void NovaHra_Click(System::Object^  sender, System::EventArgs^  e) 
    {
	  // vymazanie 
	  this->textBoxVystup->Clear();
	  this->listViewBankar->Clear();
	  this->listViewHrac->Clear();
	  // kontrola zadania mena
      if(textBoxMeno->Text->Length == 0)
      {
        this->textBoxVystup->AppendText("Zadajte meno hraca.");
        return;
      }
      balicek blackjack;
      hrac hrac1("Bankar"), hrac2(managedStrToNative(this->textBoxMeno->Text));
	  karta novaKarta;

      this->textBoxVystup->AppendText(StrToTextBox(blackjack.VypisBalicek()));
      while((hrac1.VratSkore() < 15)&&(!blackjack.Prazdny()))
	  { //vyber kartu z balicka
		novaKarta = blackjack.DalsiaKarta();
		// vloz kartu do listview
		listViewBankar->Items->Add(StrToTextBox(novaKarta.VypisKartu()));
		// ak je to srdce/gula zobraz cervenym
		if((novaKarta.vratFarbu() == srdce)||(novaKarta.vratFarbu() == gula))
		  listViewBankar->Items[listViewBankar->Items->Count-1]->ForeColor = Color::Red;
		// vloz kartu hracovi
		hrac1.PrijataKarta(novaKarta);
	  }
      while((hrac2.VratSkore() < 14)&&(!blackjack.Prazdny()))
	  { //vyber kartu z balicka
		novaKarta = blackjack.DalsiaKarta();
		// vloz kartu do listview
		listViewHrac->Items->Add(StrToTextBox(novaKarta.VypisKartu()));
		// ak je to srdce/gula zobraz cervenym
		if((novaKarta.vratFarbu() == srdce)||(novaKarta.vratFarbu() == gula))
		  listViewHrac->Items[listViewHrac->Items->Count-1]->ForeColor = Color::Red;
		// vloz kartu hracovi
		hrac2.PrijataKarta(novaKarta);
	  }
      this->textBoxVystup->AppendText(StrToTextBox(hrac1.VypisHraca()));
      this->textBoxVystup->AppendText(StrToTextBox(hrac2.VypisHraca()));
      this->textBoxVystup->AppendText("Vyhral hrac:");
      this->textBoxVystup->AppendText(StrToTextBox((hrac1 < hrac2).VypisHraca()));
     }
};
}
