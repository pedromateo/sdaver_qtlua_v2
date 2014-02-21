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

#include "usecaseguide.h"
#include "ui_usecaseguide.h"

#include <csu/qt/painters/rectangle.h>

#include <QStringList>
#include <QTableWidgetItem>
#include <QDateTime>



namespace csu {
namespace qt {
namespace dialog {
namespace usecaseguide {

UseCaseGuide::UseCaseGuide(UseCase * usecase,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UseCaseGuide)
{
    ui->setupUi(this);

    //FIXME Watch this, it's a bit tricky and im not sure about its behaviour in some situations
    //Positioning windows in the screen
    parent->move(QPoint(0,0));
    this->move(QPoint(parent->width()+5,0));

    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"Use Case"<<"Stages");
    ui->tableWidget->setColumnWidth(0,100);
    ui->tableWidget->setColumnWidth(1,200);

    shadow_=new ShadowFrame(parent,0,0,false);
    useCase_=usecase;    
    _hideRateLayer();

    this->on_helpCheckBox_clicked();

    if (useCase_)
    {        

        //Filling the table with the information and stage items of the use case
        ui->tableWidget->setRowCount(useCase_->getUseCaseStages().size()+1);

        ui->tableWidget->setItem(0,0,new QTableWidgetItem(useCase_->name().c_str()));

        UseCaseStageList::const_iterator it=useCase_->getUseCaseStages().begin();

        for (int row=1;it!=useCase_->getUseCaseStages().end();it++,row++)
        {
            ui->tableWidget->setItem(row,1,new QTableWidgetItem((*it)->name().c_str()));            
        }

        currentStage=useCase_->getUseCaseStages().begin();

        if (ui->tableWidget->rowCount()>1){
            ui->tableWidget->selectRow(1);
            ui->descTextEdit->setText((*currentStage)->longDesc().c_str());
        }

    }

    useCaseRate_=new UseCaseRate();


}

UseCaseGuide::~UseCaseGuide()
{

    //_ilog::extractor <<"(UseCaseGuide::~UseCaseGuide) Deleting Use Case Guide Window"<<std::endl;
    delete shadow_;
    delete ui;
}

void UseCaseGuide::changeEvent(QEvent *e)
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

const UseCase * UseCaseGuide::useCase()
{
    return useCase_;
}

void UseCaseGuide::useCase(UseCase * usecase)
{
    useCase_=usecase;
}

void UseCaseGuide::_hideRateLayer()
{
    ui->commentsEdit->hide();
    ui->commentsLabel->hide();
    ui->globalRateLabel->hide();
    ui->rateSpinBox->hide();
    hidden_=true;
    ui->rateButton->setText("Show Rating");
    ui->descTextEdit->show();

    this->update();
}

void UseCaseGuide::_showRateLayer()
{
    ui->commentsEdit->show();
    ui->commentsLabel->show();
    ui->globalRateLabel->show();
    ui->rateSpinBox->show();
    ui->descTextEdit->hide();
    hidden_=false;
    ui->rateButton->setText("Hide Rating");

    this->update();
}

void UseCaseGuide::on_rateButton_clicked()
{
    if (hidden_)
        _showRateLayer();
    else
        _hideRateLayer();
}

void UseCaseGuide::on_finishButton_clicked()
{
    this->hide();
}

void UseCaseGuide::on_helpCheckBox_clicked()
{
    helpEnabled_=ui->helpCheckBox->isChecked();

    shadow_->enablePainting(helpEnabled_);

    shadow_->update();

}

///
/// This method is responsible for updating the use case stage (or finishing the use case) automatically
/// according the user actions
///
void UseCaseGuide::nextStage()
{

    //Clear the stage item shadow
    shadow_->clear();

    //Changing to the next step of the use case, if not finished
    int nextRow=ui->tableWidget->currentRow();


    ((nextRow=ui->tableWidget->currentRow()+1)!=ui->tableWidget->rowCount())?
            ui->tableWidget->selectRow(nextRow):
            ui->tableWidget->selectRow(0);

    //Finished, showing the rate layer and cleaning the shadow
    if (ui->tableWidget->currentRow()==0)
    {    
        _showRateLayer();
        shadow_->clear();
        shadow_->update();
    }else{
        //Changing to the next stage
        currentStage++;
        ui->descTextEdit->setText((*currentStage)->longDesc().c_str());
    }

}

///
/// This method paints the widgets needed in this step. The ones that the user havent interact
///  with them will be marked in red otherwise in a green color.
///
void UseCaseGuide::paintRequirementMap(RequirementMap & map)
{
    if (!helpEnabled_)
        return;


    RequirementMap::iterator it=map.begin();

    Figure::PaintingContext * reqDone= new Figure::PaintingContext();
    Figure::PaintingContext * reqIncomplete= new Figure::PaintingContext();

    reqDone->lineColor=Qt::green;
    reqDone->lineWidth=3;
    reqIncomplete->lineColor=Qt::red;
    reqIncomplete->lineWidth=3;

    //Painting the rectangle surrounding the widgets of the current stage
    for (;it!=map.end();it++)
    {
        QWidget * w=this->parentWidget()->findChild<QWidget *>(it->first.c_str());
        Figure::PaintingContext * req;

        it->second?req=reqDone:req=reqIncomplete;

        shadow_->paintFigure(it->first,new Rectangle(w->mapTo(this->parentWidget(),shadow_->pos()).x(),
                                                    w->mapTo(this->parentWidget(),shadow_->pos()).y(),
                                                    w->width(),
                                                    w->height(),req));


    }

    shadow_->update();

}

/// Construct a Use Case Rate object from the graphical widget information
const UseCaseRate * UseCaseGuide::useCaseRate(void)
{
    QDateTime dateTime=QDateTime::currentDateTime();
    useCaseRate_->date(dateTime.date().toString("dd.MM.yyyy").toStdString());
    useCaseRate_->time(dateTime.time().toString().toStdString());

    useCaseRate_->comment(this->ui->commentsEdit->toPlainText().toStdString());
    useCaseRate_->globalRate(this->ui->rateSpinBox->value());

    return useCaseRate_;
}

}
}
}
}







