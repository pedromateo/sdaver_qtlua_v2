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
#include "usecaseratingdialog.h"
#include "ui_usecaseratingdialog.h"
#include <csu/qt/utils/qt_utils.h>

namespace csu {
namespace qt {
namespace dialog {
namespace usecaserating {


UseCaseRatingDialog::UseCaseRatingDialog(UseCaseRateList * ratingList,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UseCaseRatingDialog)
{
    ui->setupUi(this);
    rateList_=ratingList;

    ui->rateTable->setHorizontalHeaderLabels(QStringList()<<"Date"<<"Time"<<"Identifier"<<"Use Case Played");
    ui->rateTable->setColumnWidth(0,90);
    ui->rateTable->setColumnWidth(1,80);
    ui->rateTable->setColumnWidth(2,166);
    ui->rateTable->setColumnWidth(3,266);


    ui->rateTable->setRowCount(rateList_->size());    

    UseCaseRateList::const_iterator it=rateList_->begin();
    for (int row=0;it!=rateList_->end();it++,row++)
    {        
        ui->rateTable->setItem(row,0,new QTableWidgetItem((*it)->date().c_str()));
        ui->rateTable->setItem(row,1,new QTableWidgetItem((*it)->time().c_str()));
        ui->rateTable->setItem(row,2,new QTableWidgetItem((*it)->userID().c_str()));
        ui->rateTable->setItem(row,3,new QTableWidgetItem((*it)->useCasePlayed().c_str()));
    }

}

UseCaseRatingDialog::~UseCaseRatingDialog()
{
    delete ui;
}

void UseCaseRatingDialog::changeEvent(QEvent *e)
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

void UseCaseRatingDialog::on_closeButton_clicked()
{
    this->close();
}

//Get the Use Case Rate object from a the table widget item at the tree and update graphical widgets
void UseCaseRatingDialog::on_rateTable_itemClicked(QTableWidgetItem* item)
{
    //Look for the selected rate in the rate list
    int row=item->row();


    UseCaseRateList::iterator it=rateList_->begin();
    for (;it!=rateList_->end();it++)
    {        

        std::string date=ui->rateTable->item(row,0)->text().toStdString();
        std::string time=ui->rateTable->item(row,1)->text().toStdString();
        std::string uid=ui->rateTable->item(row,2)->text().toStdString();
        std::string useCase=ui->rateTable->item(row,3)->text().toStdString();
        if (uid==(*it)->userID() && date==(*it)->date() && time==(*it)->time() && useCase==(*it)->useCasePlayed())
        {
            ui->globalRateEdit->setText(QString::number((*it)->globalRate()));

            ui->commentTextEdit->setText((*it)->comment().c_str());
            break;
        }
    }

}

void UseCaseRatingDialog::on_exportButton_clicked()
{
    //Generate a report with all the rating comments
    UseCaseRateList::iterator it=rateList_->begin();
    std::string rateContent;
    rateContent+="<html>"
                       "<head>"
                          "<title>Informe de comentarios. Not Finished!!</title>"
                       "</head>"
                       "<body>"
                       "<h1>TITLE</h1>"
                       "<p>&nbsp;</p>"
                       "<table border=\"4\" cellpadding=\"5\" cellspacing=\"2\" valign=\"top\" align=\"center\">"
                       "<tr>"
                       "<th>Date</th>"
                       "<th>User ID</th>"
                       "<th>Use Case</th>"
                       "<th>Global Rating</th>"
                       "<th>Comments</th>"
                       "</tr>";






    for(;it!=rateList_->end();it++)
    {
        rateContent+="<tr valign=\"top\" align=\"center\">"
                       "<td  align=\"center\">"+(*it)->date()+"</td>"
                       "<td  align=\"center\">"+(*it)->userID()+"</td>"
                       "<td  align=\"center\">"+(*it)->useCasePlayed()+"</td>"
                       "<td  align=\"center\">"+QString::number((*it)->globalRate()).toStdString()+"</td>"
                       "<td  align=\"justify\">"+(*it)->comment().c_str()+"</td>"
                       "</tr>";
    }

          rateContent+="</table>"
                       "</body>"
                       "</html>";

    qt_utils::exportFileDialog("Export Ratings to",rateContent);
}

}
}
}
}




