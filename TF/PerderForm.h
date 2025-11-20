#pragma once 
namespace TF {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Media;

    /// <summary>
    /// Summary for PerderForm
    /// </summary>
    public ref class PerderForm : public System::Windows::Forms::Form
    {
    private:
        SoundPlayer^ player;

    public:
        PerderForm(void)
        {
            InitializeComponent();
            player = gcnew SoundPlayer("Images/Perdimos.wav"); 
            this->Load += gcnew System::EventHandler(this, &PerderForm::ReproducirMusica);
        }

    private:
       
        void ReproducirMusica(System::Object^ sender, System::EventArgs^ e)
        {
            player->PlayLooping(); 
        }

        
        void DetenerMusica()
        {
            if (player != nullptr)
            {
                player->Stop(); 
            }
        }

    protected:
       
        ~PerderForm()
        {
            if (components)
            {
                delete components;
            }
            DetenerMusica(); 
        }

    private: System::Windows::Forms::PictureBox^ pictureBox1;
    private: System::Windows::Forms::Button^ button1;

    protected:

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
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(PerderForm::typeid));
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->button1 = (gcnew System::Windows::Forms::Button());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->SuspendLayout();
            // 
            // pictureBox1
            // 
            this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
            this->pictureBox1->Location = System::Drawing::Point(-5, -1);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(1113, 745);
            this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox1->TabIndex = 0;
            this->pictureBox1->TabStop = false;
            this->pictureBox1->Click += gcnew System::EventHandler(this, &PerderForm::pictureBox1_Click);
            // 
            // button1
            // 
            this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
            this->button1->Location = System::Drawing::Point(938, 671);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(155, 52);
            this->button1->TabIndex = 1;
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &PerderForm::button1_Click_1);
            // 
            // PerderForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1105, 735);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->pictureBox1);
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Name = L"PerderForm";
            this->Text = L"PERDISTE";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->ResumeLayout(false);

        }
#pragma endregion

    private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) 
    {
    }
    private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) 
    {
        DetenerMusica();  
        this->Close();
    }
    };
}
