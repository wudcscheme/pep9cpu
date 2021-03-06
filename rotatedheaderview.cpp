#include "rotatedheaderview.h"
#include <QPainter>
RotatedHeaderView::RotatedHeaderView(Qt::Orientation orientation, QWidget *parent):QHeaderView(orientation,parent)
{

}
#include <math.h>
#include <QDebug>
void RotatedHeaderView::paintSection(QPainter *painter, const QRect &rect, int logicalIndex) const
{
    painter->save();
    qreal angle=-90;
    qint32 nx=-rect.bottom(),
            ny=rect.x()+rect.width()/2-5; //Frankly, I'm not sure why 4 looks the best, but it does
    QRect nRect = QRect(nx,ny,rect.height(),rect.width());
    painter->rotate(angle);
    painter->drawText(nRect,this->model()->headerData(logicalIndex,Qt::Horizontal).toString());
    painter->restore();
}

QSize RotatedHeaderView::sectionSizeFromContents(int logicalIndex) const
{
    QSize old = QHeaderView::sectionSizeFromContents(logicalIndex);
    return QSize(old.height(),old.width()-3);
}


