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
 */

#include "sw_slidemessage.h"
#include <iostream>
#include <QApplication>

//FIXME delete
#include <QDir>

//FIXME UNDER DEVELOPMENT
namespace csu {
namespace qt {
namespace widgets {
namespace shadow_frame {

using namespace csu::qt::painters;


SlideMessage::SlideMessage(const QStringList * message,ShadowFrame* parent,QWidget *decorated)
:ShadowWidget(parent, decorated)
{
    foreach(QString aux,*message)
    {
        messageList_.push_back(aux.toStdString());
    }
    //customize the painting context
    pcontext_.backColor = QColor(112,179,248);
    pcontext_.lineColor = QColor(9,95,184);
    pcontext_.transparency = 215;
    pcontext_.penStyle = Qt::SolidLine;
    pcontext_.capStyle = Qt::RoundCap;
    pcontext_.canvas = this;
    pcontext_.region = QRect(0,0,this->width()-1,this->height()-1);


    message_=messageList_.begin();

    centerFrame_= new QFrame(this);
    centerFrame_->setVisible(true);
    centerFrame_->resize(200,100);

    //fill text box    
    textBox_.reset(new QTextEdit(centerFrame_));
    textBox_->setVisible(true);

    //Interpret linebreaks
    textBox_->setLineWrapMode(QTextEdit::NoWrap);

    //Text Alignment
    textBox_->setAlignment(Qt::AlignLeft|Qt::AlignHCenter);

    //No scrollbars
    textBox_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    textBox_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    textBox_->resize(200,100);



    leftFrame_= new QFrame(this);
    leftFrame_->setVisible(true);
    leftFrame_->resize(40,100);

    backButton_=new QPushButton(leftFrame_);
    backButton_->resize(30,30);
    backButton_->setVisible(true);
    int w=leftFrame_->width()-backButton_->width();
    backButton_->move(w/2,0);


    rightFrame_= new QFrame(this);
    rightFrame_->setVisible(true);
    rightFrame_->resize(40,100);

    nextButton_=new QPushButton(rightFrame_);
    nextButton_->resize(30,30);
    nextButton_->setVisible(true);
    w=rightFrame_->width()-nextButton_->width();
    nextButton_->move(w/2,0);


    leftFrame_->move(QPoint(0,0));
    centerFrame_->move(QPoint(leftFrame_->width(),0));
    rightFrame_->move(QPoint(leftFrame_->width()+centerFrame_->width(),0));

    //std::string s=dynamic_cast<std::string *>(pcontext_.backColor.red());

    int r=pcontext_.backColor.red();

    QString backColor="background-color: rgb("+QString::number(pcontext_.backColor.red())+","+
                      QString::number(pcontext_.backColor.green())+","+QString::number(pcontext_.backColor.blue())+","+
                      QString::number(pcontext_.transparency)+");";


    centerFrame_->setStyleSheet("QFrame {border-top: 2px solid "+pcontext_.lineColor.name()+
                                "; border-bottom: 2px solid"+pcontext_.lineColor.name()+";"+
                                backColor+";} QTextEdit { border: 0px;background-color: transparent;}");

    leftFrame_->setStyleSheet("QFrame { border-top-left-radius: 10px; "
                              "border-bottom-left-radius: 10px; border: 2px solid "+
                              pcontext_.lineColor.name()+";border-right: 0px;"+backColor+"} "
                              " QPushButton { background: transparent; border: 0px; }");



    //nextButton_->setIcon();

    rightFrame_->setStyleSheet("QFrame { border-top-right-radius: 10px;"
                               "border: 2px solid "+pcontext_.lineColor.name()+
                               ";border-left: 0px; border-bottom-right-radius: 10px;"+backColor+"} "
                               " QPushButton { background: transparent; border: 0px; }");

    //FIXME THERE IS A PORLBME QITH IMAGE LOCATION, CREATE A QTRESOURCE  OR GET THE IMAGE FROM THE
    //PROPER LOCATION
    backButton_->setIcon(QIcon("arrowback.png"));
    nextButton_->setIcon(QIcon("arrownext.png"));


    this->resize(leftFrame_->width()+centerFrame_->width()+rightFrame_->width(),centerFrame_->height());

    hasChanged=true;

    qApp->installEventFilter(this);

}

bool SlideMessage::eventFilter ( QObject * obj, QEvent * e )
{
    if (e->type()==QEvent::MouseButtonPress){
        std::cout<<"Evento en BOTONES "<<e->type()<<" sobre objeto "<<obj->objectName().toStdString()<<std::endl;
        QMouseEvent * me = static_cast<QMouseEvent *>(e);
        QPoint bt1Pos=backButton_->mapFromGlobal(me->globalPos());
        QPoint bt2Pos=nextButton_->mapFromGlobal(me->globalPos());

        //Clicked Pos is above or below the widget we let the event continue
        if (bt1Pos.y()<0 || bt1Pos.y()>backButton_->height())
            return false;


        if (bt1Pos.x()>=0 && bt1Pos.x()<=backButton_->width()){
            std::cout<<"Has Pulsado sobre el boton izq"<<std::endl;
            buttonBackClicked();
            return true;
        }else if (bt2Pos.x()>=0 && bt2Pos.x()<=nextButton_->width()){
            std::cout<<"Has Pulsado sobre el boton derecho"<<std::endl;
            buttonNextClicked();
            return true;
        }
    }

    return false;
}

void SlideMessage::buttonBackClicked()
{
     if (message_!=messageList_.begin()){
         message_--;
         hasChanged=true;
         this->update();
    }

}

void SlideMessage::buttonNextClicked()
{
    MessageList::iterator aux;

    aux=message_;
    aux++;

    if (aux!=messageList_.end()){
         message_++;
         hasChanged=true;
         this->update();
    }

}


void SlideMessage::locate(void)
{
    //do not locate if textBox does not exists
    if (textBox_.get() == NULL) return;

    //First we get the point (0,0) of the decorated widget
    QPoint p = decorated_->mapTo(parentWidget()->parentWidget(),
                                 QPoint(0,0));
    //FIXME lo de parent->parent no se puede quedar así
    // hay que buscar lo que hay que poner exactamente:
    // el main window, el top level window, ...

    /// Then we move the decoration widget wherever we want,
    /// using the decorated widget origins point as reference
    assert(parentWidget()->parentWidget());
    QRect gcont = parentWidget()->parentWidget()->geometry();
    QPoint pbase = p;
    QRect gbase = decorated_->geometry();
    QRect gobject = textBox_->geometry();

    //separation
    int sep = 5;

    //points
    int top_y = pbase.y() - sep - gobject.height();
    int bottom_y = pbase.y() + gbase.height() + sep + gobject.height();
    int left_x = pbase.x() - sep - gobject.width();
    int right_x = pbase.x() + gbase.width() + sep + gobject.width();

    int xoffset = 0;
    int yoffset = 0;

    /// check positions
    bool top = true;
    bool right = true;
    //check top
    if (top_y >= 0) top = true;
    else if (bottom_y > gcont.height()) top = true;
    else top = false;
    //check right
    if (right_x <= gcont.width()) right = true;
    else if (left_x < 0) right = true;
    else right = false;

    //std::cout << "top " << top << " right " << right << std::endl;

    //if top-right
    if(top && right)
    {
        xoffset = pbase.x() + gbase.width() + sep;
        yoffset = pbase.y() - sep - gobject.height();
    }
    //else if bottom-right
    else if(!top && right)
    {
        xoffset = pbase.x() + gbase.width() + sep;
        yoffset = pbase.y() + gbase.height() + sep;
    }
    //else if top-left
    else if(top && !right)
    {
        xoffset = pbase.x() - sep - gobject.width();
        yoffset = pbase.y() - sep - gobject.height();
    }
    //else if bottom-left
    else if(!top && !right)
    {
        xoffset = pbase.x() - sep - gobject.width();
        yoffset = pbase.y() + gbase.height() + sep;
    }
    //else (top-right)
    else
    {
        xoffset = pbase.x() + gbase.width() + sep;
        yoffset = pbase.y() - sep;
    }

    move (xoffset, yoffset);
}

void SlideMessage::paintEvent( QPaintEvent * event )
{
    if (hasChanged && messageList_.size()>0)
    {
        QString text;
        text.append(static_cast<std::string>(*message_).c_str());
        text.append("\n");
        textBox_->setText(text);

        QSize fsize=textBox_->fontMetrics().size(0,text);
        textBox_->resize(fsize.width()+(textBox_->document()->documentMargin()*2)+5,fsize.height());

        if (textBox_->geometry().height()<backButton_->height())
        {
            centerFrame_->resize(textBox_->geometry().width(),backButton_->height());
        }else{
            centerFrame_->resize(textBox_->geometry().width(),textBox_->geometry().height());
        }

        leftFrame_->resize(40,centerFrame_->height());
        rightFrame_->resize(40,centerFrame_->height());

        int h=backButton_->parentWidget()->height()-backButton_->height();
        backButton_->move(backButton_->pos().x(),h/2);
        nextButton_->move(backButton_->pos().x(),h/2);

        leftFrame_->move(QPoint(0,0));
        centerFrame_->move(QPoint(leftFrame_->width(),0));
        rightFrame_->move(QPoint(leftFrame_->width()+centerFrame_->width(),0));

        this->resize(leftFrame_->width()+centerFrame_->width()+rightFrame_->width(),centerFrame_->height());

        //FIXME DELETE
        //message_=messageList_.end();
        hasChanged=false;
    }

    locate();
}

} //shadow_frame
} //widgets
} //qt
} //csu
