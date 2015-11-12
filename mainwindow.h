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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "config.h"
#include "version.h"
#include "eventreceiver.h"
#include "seriallink.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public EventReceiver
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void RaiseEvent(event_t event, int arg);

    static const Version version;

    SerialLink *link;

private:
    void set_band(double f, double span);
    void set_scan_disp();
    void draw_graph1();
    void populate_table();
    void toDom(QDomDocument &doc);
    void fromDom(QDomElement &e0);

    Ui::MainWindow *ui;
    QTimer montimer;

private slots:
    void Slot_scanBtn_click();
#ifdef ENABLE_TEST_DATA
    void Slot_scanDummyBtn_click();
#endif
    void Slot_cursor_move(double pos);
    void Slot_band_change(int idx);
    void Slot_fcentre_change(double v);
    void Slot_fspan_change(double v);
    void Slot_point_count_change(int);
    void Slot_plot_change(int);
    void Slot_menuDevice_Show();
    void Slot_menuDevice_Select(QAction *act);
    void Slot_Load();
    void Slot_Save();
    void Slot_Settings();
    void Slot_about();
    void Slot_copy();
    void Slot_monStart_click();
    void Slot_monStop_click();
    void Slot_montimer_timeout();
};

#endif // MAINWINDOW_H
