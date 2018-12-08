#ifndef MODEL_HPP
#define MODEL_HPP

#include <QAbstractTableModel>

#include <vector>

class item;
	
class model : public QAbstractTableModel
{
public:
	// @brief Constructor
	model(QObject* p = nullptr);


	virtual QVariant data(const QModelIndex&, int) const override;

	virtual int rowCount(const QModelIndex&) const override;
	virtual int columnCount(const QModelIndex&) const override;

	virtual QVariant headerData(int section, Qt::Orientation orient, int role = Qt::DisplayRole) const override;
	virtual bool setHeaderData(int section, Qt::Orientation orient, const QVariant& value, int role = Qt::DisplayRole) override;
private:
	//std::vector<item*> m_items;
	std::vector<QString> m_horizontal_headers;
};

#endif // MODEL_HPP
