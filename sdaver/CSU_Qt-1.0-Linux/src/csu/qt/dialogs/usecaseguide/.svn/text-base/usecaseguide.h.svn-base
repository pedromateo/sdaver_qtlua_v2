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
#ifndef USECASEGUIDE_H
#define USECASEGUIDE_H

#include <QDialog>
#include <csu/qt/widgets/shadow_widget/shadowframe.h>

#include <csu/base/usecases/use_case.h>
#include <csu/base/usecases/use_case_rate.h>
#include <csu/base/usecases/use_case_stage.h>
#include <csu/base/usecases/use_case_stage_item.h>

namespace Ui {
    class UseCaseGuide;
}

namespace csu {
namespace qt {
namespace dialog {
namespace usecaseguide {

    using namespace csu::base::usecases;
    using namespace csu::qt::widgets::shadow_frame;

class UseCaseGuide : public QDialog {
    Q_OBJECT
public:

    typedef std::map<std::string,bool> RequirementMap;

    UseCaseGuide(UseCase *,QWidget *parent = 0);
    ~UseCaseGuide();


     const UseCase * useCase();
     void useCase(UseCase *);

     const UseCaseRate * useCaseRate();
     ///
     /// This method is responsible for updating the use case stage (or finishing the use case) automatically
     /// according the user actions
     ///
     void nextStage();
     void paintRequirementMap(RequirementMap &);

protected:
    void changeEvent(QEvent *e);



private:
    Ui::UseCaseGuide *ui;
    UseCase * useCase_;    
    UseCaseRate * useCaseRate_;
    ShadowFrame * shadow_;
    bool hidden_;
    bool helpEnabled_;
    UseCaseStageList::const_iterator currentStage;

private:
    void _hideRateLayer();
    void _showRateLayer();

private slots:    
    void on_helpCheckBox_clicked();
    void on_finishButton_clicked();
    void on_rateButton_clicked();
};

}
}
}
}
#endif // USECASEGUIDE_H
