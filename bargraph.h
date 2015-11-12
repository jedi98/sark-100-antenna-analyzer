/*
(C) Copyright 2015 Jeremy Burton

This file is part of Sark-100-antenna-analyzer.

Sark-100-antenna-analyzer is free software: you can redistribute it
and/or modify it under the terms of the GNU General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

Sark-100-antenna-analyzerr is distributed in the hope that it will be
useful, but WITHOUT ANY WARRANTY; without even the implied warranty
of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef BARGRAPH_H
#define BARGRAPH_H

#include <QWidget>
#include <QPen>
#include <QBrush>
//#include <QMouseEvent>

//#include "graph.h"
//#include "graphcursor.h"

class BarGraph : public QWidget
{
    Q_OBJECT
public:
    explicit BarGraph(QWidget *parent = 0);
    ~BarGraph();

    //GraphCursor *cursor;

    //Graph graph;
    //GraphScale *xscale,*yscale1, *yscale2;
    //GraphTrace *swrtrace, *ztrace, *xtrace, *rtrace;
    //GraphVertLine *swrminline;
    //GraphHorizLine *ZZeroLine, *ZTargetline,*SWRTargetline;
    void Draw(QPainter &painter);
    void SetIncAuto();

    int margin,labdps;
    QPen pen;
    QBrush brush;
    double vmin, vmax, vinc, value, labdiv, vorig;
    QString labsuffix;
    QFont font;

signals:
    //void cursorMoved(double pos);

public slots:

private:
    int font_h;

    void paintEvent(QPaintEvent *);
    //void mouseMoveEvent(QMouseEvent *ev);
};

#endif // BARGRAPH_H
