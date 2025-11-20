#pragma once
#include "Juego.h"
#include "PerderForm.h"
#include "Ganaste.h"
namespace TF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class ElJuego : public System::Windows::Forms::Form
	{
	private:
		SoundPlayer^ player;
	public:
		Graphics^ canvas;
		BufferedGraphicsContext^ context;
		BufferedGraphics^ buffer;
		Label^ lblTimer;
		int totalTimer = 20 /*1000/50*/;
		int currentTimer = 0;
		int timer = 90;
	private: System::Windows::Forms::Timer^ timer1;
	public:
		Juego* juego;
		ElJuego(void)
		{
			InitializeComponent();
			canvas = this->CreateGraphics();
			context = BufferedGraphicsManager::Current;
			buffer = context->Allocate(canvas, this->ClientRectangle);
			juego = new Juego(
				buffer->Graphics->VisibleClipBounds.Width,
				buffer->Graphics->VisibleClipBounds.Height);
			lblTimer = gcnew Label();
			lblTimer->AutoSize = true;
			lblTimer->Text = "Timer " + timer;
			lblTimer->Font =
				gcnew System::Drawing::Font("Arial", 25,
					FontStyle::Bold);

			lblTimer->Location = System::Drawing::Point(
				buffer->Graphics->VisibleClipBounds.Width
				- lblTimer->Width - 100, 50);
			this->Controls->Add(lblTimer);
			player = gcnew SoundPlayer("Images/Gameplay.wav");
			this->Load += gcnew System::EventHandler(this, &ElJuego::ReproducirMusica);
			this->FormClosing += gcnew FormClosingEventHandler(this, &ElJuego::OnFormClosing);


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

		void OnFormClosing(System::Object^ sender, FormClosingEventArgs^ e)
		{
			// Detener la música al cerrar el formulario del menú
			DetenerMusica();
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ElJuego()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ElJuego::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 50;
			this->timer1->Tick += gcnew System::EventHandler(this, &ElJuego::timer1_Tick);
			// 
			// ElJuego
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1105, 735);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"ElJuego";
			this->Text = L"TIERRA ARIA 2";
			this->Load += gcnew System::EventHandler(this, &ElJuego::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &ElJuego::MyForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		buffer->Graphics->Clear(Color::White);
		juego->mostrar(buffer->Graphics);
		juego->mover(buffer->Graphics);
		buffer->Render(canvas);
		currentTimer++;

		if (currentTimer >= totalTimer) {
			currentTimer = 0;
			timer--;
			lblTimer->Text = "Timer " + timer;

			if (timer <= 0) {
				timer1->Stop();
				this->Hide(); 
				PerderForm^ perderform = gcnew PerderForm();
				perderform->FormClosed += gcnew FormClosedEventHandler(this, &ElJuego::OnFormClosed); 
				perderform->ShowDialog(); 
			}
		}

		if (juego->getGameOver()) {
			timer1->Stop();
			this->Hide(); 
			PerderForm^ perderform = gcnew PerderForm();
			perderform->FormClosed += gcnew FormClosedEventHandler(this, &ElJuego::OnFormClosed); 
			perderform->ShowDialog(); 
		}

		if (juego->getGanamos()) {
			timer1->Stop();
			this->Hide(); 
			Ganaste^ ganaste = gcnew Ganaste();
			ganaste->FormClosed += gcnew FormClosedEventHandler(this, &ElJuego::OnFormClosed);
			ganaste->ShowDialog(); 
		}
	}

	private: System::Void OnFormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
		
		this->Close(); 
	}
	private: System::Void MyForm_KeyDown(
		System::Object^ sender,
		System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::W) {
			juego->moverTeclas(buffer->Graphics, Arriba);
		}
		if (e->KeyCode == Keys::S) {
			juego->moverTeclas(buffer->Graphics, Abajo);
		}
		if (e->KeyCode == Keys::A) {
			juego->moverTeclas(buffer->Graphics, Izquierda);
		}
		if (e->KeyCode == Keys::D) {
			juego->moverTeclas(buffer->Graphics, Derecha);
		}
		if (e->KeyCode == Keys::Q) {
			juego->agregarArbol();
		}
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) 
	{
	}
	};
}
