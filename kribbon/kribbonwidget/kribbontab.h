#ifndef KRIBBONTAB_H
#define KRIBBONTAB_H

#include <QWidget>
#include <QTabWidget>

class KRibbonTab : public QWidget
{
	Q_OBJECT
public:
	explicit KRibbonTab(QWidget *parent = nullptr);

	//parser ui
	void addChildWidgetNames(const QStringList& childs);
	QStringList childWidgetNames() const;

signals:

private:
	QStringList m_childWidgetNames;

};

#endif // KRIBBONTAB_H
