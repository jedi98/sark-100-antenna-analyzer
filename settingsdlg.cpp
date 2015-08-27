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

#include "config.h"

#include "settingsdlg.h"
#include "ui_settingsdlg.h"

SettingsDlg::SettingsDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDlg)
{
    ui->setupUi(this);

    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(Slot_Accept()));

    ui->swr_max->setValue(Config::swr_bw_max);
    ui->swr_bw_max->setValue(Config::swr_bw_max);
    ui->Z_Target->setValue(Config::Z_Target);
}

SettingsDlg::~SettingsDlg()
{
    delete ui;
}

void SettingsDlg::Slot_Accept()
{
    using namespace Config;

    swr_max = ui->swr_max->value();
    swr_bw_max = ui->swr_bw_max->value();
    Z_Target = ui->Z_Target->value();
    write();
}

