#include "table_view.hpp"

#include <QHeaderView>
#include <QLineEdit>
#include <QKeyEvent>

#include <iostream>

class header_view_editor : public QLineEdit
{
public:
	header_view_editor(QWidget* p, table_view* view, int section, const QString& value) 
		: QLineEdit(p), m_view(view), m_section(section)
	{
		setText(value);
		setFocusProxy(this);
		setAttribute(Qt::WA_DeleteOnClose);
	}

	virtual void keyPressEvent(QKeyEvent* e) override
	{
		Qt::Key key = static_cast<Qt::Key>(e->key());
		if (key == Qt::Key_Enter || key == Qt::Key_Return) {
			//m_view->set_focus();
			apply();
			close();
		}
		QLineEdit::keyPressEvent(e);
	}

	virtual void focusOutEvent(QFocusEvent* e) override
	{
		apply();
		close();
		QLineEdit::leaveEvent	(e);
	}

	void apply()
	{
		m_view->set_header_data(m_section, Qt::Horizontal, text());
	}

private:
	table_view* m_view;
	int m_section;
};

table_view::table_view(QWidget* p)
	: QTableView(p)
{
	setAlternatingRowColors(true);
	setEditTriggers(QAbstractItemView::AllEditTriggers);
	setSelectionMode(QAbstractItemView::SingleSelection);
	QHeaderView* hh = horizontalHeader();
	hh->setSectionsClickable(true);
	connect(hh, SIGNAL(sectionPressed(int)), this, SLOT(edit_horizontal_header(int)));
}

void table_view::edit_horizontal_header(int logicalIndex)
{
	edit_header(horizontalHeader(), logicalIndex);
}

void table_view::edit_header(QHeaderView* h, int logicalIndex)
{
	QVariant value = model()->headerData(logicalIndex, Qt::Horizontal);
	header_view_editor* edit = new header_view_editor(h->viewport(), this, logicalIndex, value.toString());
	QRect rec = h->viewport()->geometry();
	int size = h->sectionSize(logicalIndex);
	int offset = h->sectionViewportPosition(logicalIndex);
	edit->setGeometry(rec.left() + offset, rec.top(), size, rec.height());
	edit->show();
	edit->setFocus();
}

void table_view::set_focus()
{
	horizontalHeader()->setFocus();
}

void table_view::set_header_data(int section, Qt::Orientation o, const QString& text, int role)
{
	model()->setHeaderData(section, o, text, role);
}