#pragma once

// ==========================================
// ГЛОБАЛЬНЫЕ ДАННЫЕ (КООРДИНАТЫ РИСУНКОВ)
// ==========================================

// 0. ЗАЯЦ (Пример)
float lines0[] = {
	// голова
	0.5f, 3.1f, 1.1f, 4.5f,  1.1f, 4.5f, 0.5f, 6.1f,  0.5f, 6.1f, 0.5f, 7.5f,
	0.5f, 7.5f, 1.1f, 8.1f,  1.1f, 8.1f, 1.5f, 8.1f,  1.5f, 8.1f, 2.1f, 7.5f,
	2.1f, 7.5f, 1.5f, 6.1f,  1.5f, 6.1f, 1.5f, 4.5f,  1.5f, 4.5f, 3.1f, 4.5f,
	3.1f, 4.5f, 3.1f, 6.1f,  3.1f, 6.1f, 2.5f, 7.5f,  2.5f, 7.5f, 3.1f, 8.1f,
	3.1f, 8.1f, 3.5f, 8.1f,  3.5f, 8.1f, 4.1f, 7.5f,  4.1f, 7.5f, 4.1f, 6.1f,
	4.1f, 6.1f, 3.5f, 4.5f,  3.5f, 4.5f, 4.1f, 3.1f,
	// скулы и подбородок
	4.1f, 3.1f, 3.5f, 1.5f,  3.5f, 1.5f, 2.5f, 1.1f,  2.5f, 1.1f, 2.1f, 1.1f,
	2.1f, 1.1f, 1.1f, 1.5f,  1.1f, 1.5f, 0.5f, 3.1f,
	// туловище
	4.1f, 3.1f, 5.5f, 3.5f,  5.5f, 3.5f, 7.5f, 3.5f,  7.5f, 3.5f, 7.5f, 2.5f,
	7.5f, 2.5f, 8.1f, 2.5f,  8.1f, 2.5f, 8.1f, 2.1f,  8.1f, 2.1f, 7.5f, 2.1f,
	// ноги
	7.5f, 2.1f, 7.5f, 0.5f,  7.5f, 0.5f, 6.5f, 0.5f,  6.5f, 0.5f, 6.5f, 1.1f,
	6.5f, 1.1f, 6.1f, 1.1f,  6.1f, 1.1f, 6.1f, 0.5f,  6.1f, 0.5f, 5.1f, 0.5f,
	5.1f, 0.5f, 5.1f, 1.1f,  5.1f, 1.1f, 4.1f, 1.1f,  4.1f, 1.1f, 4.1f, 0.5f,
	4.1f, 0.5f, 3.1f, 0.5f,  3.1f, 0.5f, 3.1f, 1.1f,  3.1f, 1.1f, 2.5f, 1.1f,
	2.5f, 1.1f, 2.5f, 0.5f,  2.5f, 0.5f, 1.5f, 0.5f,  1.5f, 0.5f, 1.5f, 1.25f,
	// глаза
	1.5f, 3.5f, 1.5f, 3.1f,  1.5f, 3.1f, 2.1f, 3.1f,  2.1f, 3.1f, 2.1f, 3.5f,  2.1f, 3.5f, 1.5f, 3.5f,
	2.5f, 3.5f, 2.5f, 3.1f,  2.5f, 3.1f, 3.1f, 3.1f,  3.1f, 3.1f, 3.1f, 3.5f,  3.1f, 3.5f, 2.5f, 3.5f,
	// уши и нос
	1.1f, 5.5f, 1.1f, 7.1f,  3.5f, 5.5f, 3.5f, 7.1f,
	2.1f, 2.5f, 2.5f, 2.5f,  2.5f, 2.5f, 2.25f, 2.1f, 2.25f, 2.1f, 2.1f, 2.5f
};
float vx0 = 8.5f, vy0 = 8.5f;

// 1. ГРИБ (Вариант №6)
// 1. ГРИБ (Вариант №6) - Точная копия по клеткам
float lines1[] = {
	0.5f,0.5f, 1.0f,2.0f,   1.0f,2.0f, 1.5f,0.5f,   1.5f,0.5f, 2.0f,1.5f,   2.0f,1.5f, 2.5f,0.5f,   2.5f,0.5f, 3.0f,0.5f,
	5.0f,0.5f, 5.5f,0.5f,   5.5f,0.5f, 6.0f,1.5f,   6.0f,1.5f, 6.5f,0.5f,   6.5f,0.5f, 7.0f,2.0f,   7.0f,2.0f, 7.5f,0.5f,
	3.0f,0.5f, 5.0f,0.5f,
	3.0f,0.5f, 3.0f,2.0f,   3.5f,0.5f, 3.5f,2.0f,   4.0f,0.5f, 4.0f,2.0f,   4.5f,0.5f, 4.5f,2.0f,   5.0f,0.5f, 5.0f,2.0f,
	3.0f,2.0f, 1.0f,3.0f,   3.5f,2.0f, 2.5f,3.0f,   4.0f,2.0f, 4.0f,3.25f,  4.5f,2.0f, 5.5f,3.0f,   5.0f,2.0f, 7.0f,3.0f,
	0.5f,3.0f, 2.5f,3.0f,   2.5f,3.0f, 4.0f,3.25f,  4.0f,3.25f, 5.5f,3.0f,  5.5f,3.0f, 7.5f,3.0f,
	0.5f,3.0f, 1.0f,4.5f,   1.0f,4.5f, 2.0f,6.0f,   2.0f,6.0f, 3.0f,7.0f,   3.0f,7.0f, 4.0f,7.5f,
	4.0f,7.5f, 5.0f,7.0f,   5.0f,7.0f, 6.0f,6.0f,   6.0f,6.0f, 7.0f,4.5f,   7.0f,4.5f, 7.5f,3.0f,
	2.0f,4.0f, 2.0f,5.0f,   2.0f,5.0f, 2.5f,5.5f,   2.5f,5.5f, 3.0f,5.0f,   3.0f,5.0f, 3.0f,4.0f,   3.0f,4.0f, 2.5f,3.5f,   2.5f,3.5f, 2.0f,4.0f,
	5.0f,4.0f, 5.0f,5.0f,   5.0f,5.0f, 5.5f,5.5f,   5.5f,5.5f, 6.0f,5.0f,   6.0f,5.0f, 6.0f,4.0f,   6.0f,4.0f, 5.5f,3.5f,   5.5f,3.5f, 5.0f,4.0f,
	3.5f,6.0f, 3.5f,6.5f,   3.5f,6.5f, 4.0f,7.0f,   4.0f,7.0f, 4.5f,6.5f,   4.5f,6.5f, 4.5f,6.0f,   4.5f,6.0f, 4.0f,5.5f,   4.0f,5.5f, 3.5f,6.0f
};
float vx1 = 8.0f, vy1 = 8.0f; 

float lines2[] = {
	3.0f,0.5f, 6.0f,0.5f,   6.0f,0.5f, 7.5f,2.0f,   7.5f,2.0f, 6.5f,4.0f,   6.5f,4.0f, 2.5f,4.0f,   2.5f,4.0f, 1.5f,2.0f,   1.5f,2.0f, 3.0f,0.5f,
	3.0f,4.0f, 6.0f,4.0f,   6.0f,4.0f, 7.0f,5.5f,   7.0f,5.5f, 5.5f,7.0f,   5.5f,7.0f, 3.5f,7.0f,   3.5f,7.0f, 2.0f,5.5f,   2.0f,5.5f, 3.0f,4.0f,
	3.5f,7.0f, 5.5f,7.0f,   5.5f,7.0f, 6.5f,8.5f,   6.5f,8.5f, 5.5f,9.5f,   5.5f,9.5f, 3.5f,9.5f,   3.5f,9.5f, 2.5f,8.5f,   2.5f,8.5f, 3.5f,7.0f,
	2.5f,9.5f, 6.5f,9.5f,  
	3.5f,9.5f, 3.5f,11.5f,  3.5f,11.5f, 5.5f,11.5f,  5.5f,11.5f, 5.5f,9.5f,
	4.5f,8.0f, 7.0f,7.5f,   7.0f,7.5f, 4.5f,7.5f,   4.5f,7.5f, 4.5f,8.0f,
	3.5f,7.5f, 4.0f,7.25f,  4.0f,7.25f, 5.0f,7.25f,  5.0f,7.25f, 5.5f,7.5f,
	3.75f,8.5f, 4.25f,8.5f,  5.25f,8.5f, 4.75f,8.5f,
	4.5f,2.0f, 5.0f,2.5f,  5.0f,2.5f, 4.5f,3.0f,  4.5f,3.0f, 4.0f,2.5f,  4.0f,2.5f, 4.5f,2.0f,
	4.5f,5.0f, 5.0f,5.5f,  5.0f,5.5f, 4.5f,6.0f,  4.5f,6.0f, 4.0f,5.5f,  4.0f,5.5f, 4.5f,5.0f,
	2.0f,5.5f, 0.5f,4.5f,   0.5f,4.5f, 0.0f,5.0f,   0.5f,4.5f, 0.0f,4.0f,
	7.0f,5.5f, 8.5f,6.5f,   8.5f,6.5f, 9.0f,7.0f,   8.5f,6.5f, 9.0f,6.0f,
	1.0f,0.5f, 1.0f,7.5f,
	0.5f,7.5f, 1.5f,7.5f,   1.5f,7.5f, 2.0f,10.0f,  2.0f,10.0f, 0.0f,10.0f,  0.0f,10.0f, 0.5f,7.5f,
	0.75f,7.5f, 0.5f,10.0f,  1.0f,7.5f, 1.0f,10.0f,  1.25f,7.5f, 1.5f,10.0f
};
float vx2 = 10.0f, vy2 = 12.0f;


namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		// Добавленные переменные для работы приложения
		bool keepAspectRatio;
		int currentDrawing;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = gcnew System::ComponentModel::Container();
			this->Size = System::Drawing::Size(600, 600); // Сделал окно чуть больше для удобства
			this->Text = L"MyForm";
			this->Padding = System::Windows::Forms::Padding(0);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;

			// Привязка событий!
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
		}
#pragma endregion

		// --- НАШИ ОБРАБОТЧИКИ СОБЫТИЙ ---

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		keepAspectRatio = true;
		currentDrawing = 0; // Начинаем с зайца
	}

	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::M) {
			keepAspectRatio = !keepAspectRatio;
		}
		if (e->KeyCode == Keys::N) {
			currentDrawing++;
			if (currentDrawing > 2) {
				currentDrawing = 0;
			}
		}
		this->Refresh(); // Перерисовываем при каждом нажатии
	}

	private: System::Void MyForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ g = e->Graphics;
		g->Clear(Color::Aquamarine); // Фон как в методичке
		Pen^ blackPen = gcnew Pen(Color::Black, 2);

		float* lines;
		int count;
		float vx, vy;

		// Выбор рисунка
		if (currentDrawing == 0) {
			lines = lines0; count = sizeof(lines0) / sizeof(float); vx = vx0; vy = vy0;
		}
		else if (currentDrawing == 1) {
			lines = lines1; count = sizeof(lines1) / sizeof(float); vx = vx1; vy = vy1;
		}
		else {
			lines = lines2; count = sizeof(lines2) / sizeof(float); vx = vx2; vy = vy2;
		}

		float Wx = (float)this->ClientRectangle.Width;
		float Wy = (float)this->ClientRectangle.Height;
		float aspectFig = vx / vy;
		float aspectForm = Wx / Wy;

		float Sx, Sy;

		// Расчет масштаба
		if (keepAspectRatio) {
			Sx = Sy = (aspectFig < aspectForm) ? (Wy / vy) : (Wx / vx);
		}
		else {
			Sx = Wx / vx;
			Sy = Wy / vy;
		}

		float Ty = Sy * vy; // Смещение по оси Y вниз

		// Отрисовка
		for (int i = 0; i < count; i += 4) {
			g->DrawLine(blackPen,
				Sx * lines[i], Ty - Sy * lines[i + 1],
				Sx * lines[i + 2], Ty - Sy * lines[i + 3]);
		}
	}
	};
}