// -*- mode: c++; c-basic-offset: 4; c-basic-style: bsd; -*-
/*
 *   This program is free software; you can redistribute it and/or
 *   modify
 *   it under the terms of the GNU Lesser General Public License as
 *   published by the Free Software Foundation; either version 3.0 of
 *   the License, or (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU Lesser General Public License for more details.
 *
 *   You should have received a copy of the GNU Lesser General Public
 *   License along with this library; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
 *   02111-1307 USA
 *
 *   This file is part of the OHTu-Open Usability Evaluation Framework,
 *   http://sourceforge.net/projects/ohtu/
 *
 */
#ifndef USECASERATINGDIALOG_H
#define USECASERATINGDIALOG_H

#include <QDialog>
#include <QTableWidgetItem>
#include <csu/base/usecases/use_case_rate.h>


namespace Ui {
    class UseCaseRatingDialog;
}

namespace csu {
namespace qt {
namespace dialog {
namespace usecaserating {

    using namespace csu::base::usecases;

class UseCaseRatingDialog : public QDialog {
    Q_OBJECT
public:
    UseCaseRatingDialog(UseCaseRateList *,QWidget *parent = 0);
    ~UseCaseRatingDialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::UseCaseRatingDialog *ui;
    UseCaseRateList * rateList_;


private slots:
    void on_exportButton_clicked();
    //Get the Use Case Rate object from a the table widget item at the tree and update graphical widgets
    void on_rateTable_itemClicked(QTableWidgetItem* item);
    void on_closeButton_clicked();
};

}
}
}
}
#endif // USECASERATINGDIALOG_H
