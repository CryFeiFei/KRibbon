#include "kribbontab.h"

KRibbonTab::KRibbonTab(QWidget *parent) : QWidget(parent)
{

}

void KRibbonTab::addChildWidgetNames(const QStringList& childs)
{
	m_childWidgetNames = childs;
}

QStringList KRibbonTab::childWidgetNames() const
{
	return m_childWidgetNames;
}

//Q_DECLARE_METATYPE(KRibbonTab);
