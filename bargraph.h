/*
(C) Copyright 2015 Jeremy Burton

This file is part of Sark-100-antenna-analyzer.

Sark-100-antenna-analyzer is free software: you can redistribute it
and/or modify it under the terms of the GNU General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

Sark-100-antenna-analyzer is distributed in the hope that it will be
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

#define constrain(v,v1,v2) ((v)<(v1)?v1:((v)>(v2)?v2:v))

class BarGraph : public QWidget
{
    Q_OBJECT
public:
    explicit BarGraph(QWidget *parent = 0);
    ~BarGraph();

    void Draw(QPainter &painter);
    void SetIncAuto();

    int margin,labdps;
    QPen pen;
    QBrush brush;
    double vmin, vmax, vinc, value, labdiv, vorig;
    QString labsuffix;

public slots:

private:
    QFont font;
    int font_h;

    void paintEvent(QPaintEvent *);
};

#endif // BARGRAPH_H
