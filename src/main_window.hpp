#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOE_HPP

#include <QMainWindow>

class table_view;

class main_window : public QMainWindow
{
public:

	// @brief Constructor
	main_window(QMainWindow* p = nullptr);

private:
	table_view* m_view;
};

#endif // MAIN_WINDOW_HPP
