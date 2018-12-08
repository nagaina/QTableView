#include "main_window.hpp"
#include "model.hpp"
#include "table_view.hpp"


main_window::main_window(QMainWindow* p)
	: QMainWindow(p)
{
	model* m = new model(this);
	m_view = new table_view(this);
	m_view->setModel(m);
	m_view->setMinimumSize(QSize(400, 400));
	setMinimumSize(QSize(400, 400));
}