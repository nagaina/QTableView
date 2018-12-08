#include "model.hpp"

model::model(QObject* p)
	: QAbstractTableModel(p)
{
	m_horizontal_headers.resize(2);
}

QVariant model::data(const QModelIndex& i, int c) const
{
	return QVariant();
}

int model::rowCount(const QModelIndex& i) const
{
	if (i.isValid()) {
		return i.row();
	}
	return 2;
}

int model::columnCount(const QModelIndex& i) const
{
	if (i.isValid()) {
		return i.column();
	}
	return 2;
}

QVariant model::headerData(int section, Qt::Orientation orient, int role) const
{
	if (orient == Qt::Horizontal && (role == Qt::DisplayRole || role == Qt::EditRole)) {
		if (m_horizontal_headers.size() > section) {
			return m_horizontal_headers[section];
		}
	}
	return QAbstractItemModel::headerData(section, orient, role);
}

bool model::setHeaderData(int section, Qt::Orientation orient, const QVariant& value, int role)
{
	if (orient == Qt::Horizontal && (role == Qt::DisplayRole || role == Qt::EditRole)) {
		m_horizontal_headers[section] = value.toString();
	}
	return QAbstractItemModel::setHeaderData(section, orient, value, role);
}