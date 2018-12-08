#ifndef TABLE_VIEW_HPP
#define TABLE_VIEW_HPP

#include <QTableView>

class QHeaderView;

class table_view : public QTableView
{
	Q_OBJECT

public:

	// @brief Constructor
	table_view(QWidget* p = nullptr);

public:
	void set_focus();
	void set_header_data(int, Qt::Orientation, const QString&, int role = Qt::EditRole);

private slots:
	void edit_horizontal_header(int);

private:
	void edit_header(QHeaderView*, int);
};

#endif // TABLE_VIEW_HPP