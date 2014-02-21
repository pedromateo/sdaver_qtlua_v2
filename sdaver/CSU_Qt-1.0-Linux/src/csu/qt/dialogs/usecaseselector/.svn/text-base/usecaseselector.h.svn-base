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

#ifndef USECASESELECTOR_H
#define USECASESELECTOR_H

#include <QtGui/QDialog>
#include <csu/base/usecases/use_case.h>

namespace Ui {
    class UseCaseSelector;
}

namespace csu {
namespace qt {
namespace dialog {
namespace usecaseselector {

using namespace csu::base::usecases;

class UseCaseSelector : public QDialog {
    Q_OBJECT
public:
    UseCaseSelector(const UseCaseList &,QWidget *parent = 0);
    ~UseCaseSelector();
    const UseCase * selected() const;

protected:
    void changeEvent(QEvent *e);

private:
    Ui::UseCaseSelector *ui;
    UseCase * selectedUseCase_;
    UseCaseList usecaseList_;

private slots:
    //Select the use case to play
    void on_selectButton_clicked();
    void on_cancelButton_clicked();
};

}
}
}
}

#endif // USECASESELECTOR_H
