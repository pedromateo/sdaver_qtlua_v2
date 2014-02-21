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
#include "usecaseselector.h"
#include "ui_usecaseselector.h"
#include <QTreeWidgetItem>

namespace csu {
namespace qt {
namespace dialog {
namespace usecaseselector {


UseCaseSelector::UseCaseSelector(const UseCaseList & usecaseList,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UseCaseSelector)
{
    ui->setupUi(this);
    selectedUseCase_=NULL;

    ui->usecaseTree->setHeaderLabel(QString("Available Use Cases"));

    if (usecaseList.size()==0)
        ui->selectButton->setEnabled(false);
    else{

        UseCaseList::const_iterator it=usecaseList.begin();

        for (;it!=usecaseList.end();it++)
        {
            QTreeWidgetItem * usecase=new QTreeWidgetItem();
            usecase->setText(0,(*it)->name().c_str());
            ui->usecaseTree->addTopLevelItem(usecase);
        }

        ui->usecaseTree->setCurrentItem(ui->usecaseTree->topLevelItem(0));
    }
    usecaseList_=usecaseList;
}

UseCaseSelector::~UseCaseSelector()
{
    delete ui;
}

void UseCaseSelector::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void UseCaseSelector::on_cancelButton_clicked()
{
    selectedUseCase_=NULL;
    this->close();
}

//Select the use case to play
void UseCaseSelector::on_selectButton_clicked()
{

    selectedUseCase_=NULL;

    UseCaseList::const_iterator it=usecaseList_.begin();

    for (;it!=usecaseList_.end();it++)
    {
        if ((*it)->name()==ui->usecaseTree->currentItem()->text(0).toStdString())
        {
            selectedUseCase_=(*it);
            break;
        }
    }

    this->close();
}

const UseCase * UseCaseSelector::selected() const
{
    return selectedUseCase_;
}

}
}
}
}




