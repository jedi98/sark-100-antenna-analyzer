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

#include <math.h>
#include <stdio.h>

#include <QPainter>

#include "config.h"
#include "bargraph.h"

//extern ScanData scandata;

BarGraph::BarGraph(QWidget *parent) :
    QWidget(parent)
{
    pen = QPen(Qt::black);
    brush = QBrush(Qt::blue);

    pen.setWidth(0);

    margin=2;
    vmin=value=0;
    vmax=10;
    vinc=1;
    vorig=0;
    labdps=0;
    labdiv=1.0;
    labsuffix="";

    setMinimumHeight(50);

    font = QFont("Arial",9);
    font_h = QFontMetrics(font).height();

    //setAutoFillBackground(true);
}

BarGraph::~BarGraph()
{
}

void BarGraph::SetIncAuto()
{
    double n,span=this->vmax-this->vmin;
    n = pow(10.0,floor(log10(span)));
    if (span<=n) { this->vinc=n/10.0; return; } else n*=2.0;
    if (span<=n) { this->vinc=n/10.0; return; } else n*=2.5;
    if (span<=n) { this->vinc=n/10.0; return; } else n*=2;
    this->vinc=n/10.0;
}

void BarGraph::Draw(QPainter &painter)
{
    double scale;
    int x/*,y*/;

    int xo = margin+font_h, yo=height()-margin-6-font_h,
            h=height()-2*(margin)-6-font_h,
            w=width()-2*margin-2*font_h;

    painter.setPen(Qt::NoPen);
    //painter.setPen(pen);
    painter.setBrush(brush);
    painter.setFont(font);

//Bar
    scale = (w) / (vmax-vmin);
    painter.drawRect(xo+(vorig-vmin)*scale,yo,(constrain(value,vmin,vmax)-vorig)*scale,-h);

//Scale
    painter.setPen(pen);
        painter.setBrush(Qt::NoBrush);
        painter.drawRect(xo,yo,w,-h);
//printf("p=%p,vmin,max,inc=%f,%f,%f\n",this,vmin,vmax,vinc);
        for (double v=vmin;v<=vmax;v+=vinc)
        {
            QString s = (labdps<0 ? QString("%1").arg(v/labdiv) : QString("%1").arg(v/labdiv, 0, 'f', labdps)) + labsuffix;

            x=xo + (v-vmin)*scale;
        //printf("x=%d\n",x);
        //printf("v=%f\n",v);
            painter.drawLine(x,yo,x,yo + 6);

            x=x - QFontMetrics(font).boundingRect(s).width()/2;
            painter.drawText(x,yo + 6 + font_h,s);
        }

}

void BarGraph::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    ////////////////////

    painter.setBackgroundMode(Qt::OpaqueMode); //??
    //painter.setBackground(Qt::white);
    //painter.setAutoFillBackground(true);
    painter.eraseRect(painter.viewport());

    painter.setBackgroundMode(Qt::TransparentMode); //??


    //graph.SetSize(painter.viewport());

    Draw(painter);

    ////////////////////

    //painter.end();
}
