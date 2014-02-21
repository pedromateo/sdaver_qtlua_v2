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

#include "figurepainter.h"

#include <cassert>
#include <iostream>

namespace csu{
namespace qt{
namespace painters{
    ///
    /// FigurePainter
    ///

    ///
    /// highlighter
    ///
    void FigurePainter::highlight(PaintingContext& pc)
    {
        //create pen
        QPen pen(QColor(pc.lineColor.red(),
                        pc.lineColor.green(),
                        pc.lineColor.blue(),
                        pc.transparency),
                 pc.lineWidth,
                 pc.penStyle,
                 pc.capStyle);

        QBrush brush(QColor(pc.backColor.red(),
                            pc.backColor.green(),
                            pc.backColor.blue(),
                            pc.transparency));
        //set canvas
        assert(pc.canvas);
        QPainter painter(pc.canvas);
        painter.setPen(pen);
        painter.setBrush(brush);
        //paint
        painter.drawRect(pc.region);
        painter.end();

    }


    ///
    /// floating message
    ///
    void FigurePainter::floatingMessage(PaintingContext& pc, const QString& message)
    {
        //create background pen
        QPen bpen(QColor(pc.backColor.red(),
                        pc.backColor.green(),
                        pc.backColor.blue(),
                        pc.transparency),
                 pc.lineWidth,
                 pc.penStyle,
                 pc.capStyle);

        QBrush brush(QColor(pc.backColor.red(),
                            pc.backColor.green(),
                            pc.backColor.blue(),
                            pc.transparency));
        //set canvas
        assert(pc.canvas);
        QPainter painter(pc.canvas);
        painter.setPen(bpen);
         painter.setBrush(brush);
        //paint rectangle
        painter.drawRect(pc.region);

        //create text pen
        QPen tpen(QColor(pc.textColor.red(),
                        pc.textColor.green(),
                        pc.textColor.blue(),
                        255/*pc.transparency*/),
                 pc.lineWidth,
                 pc.penStyle,
                 pc.capStyle);
        //set canvas
        painter.setPen(tpen);
        //paint text
        painter.drawText(pc.region, Qt::AlignCenter, message);

        //end
        painter.end();
    }


















    /// //////////////////////////////////////////////////////////////////
    /// old methods
    /// //////////////////////////////////////////////////

    ///
    /// draw titled circle
    ///
    void FigurePainter::drawTitledCircle(int x, int y,
                                         std::string const& text,
                                         QPaintDevice* pd,
                                         PaintingContext& pc)
    {
        drawGradientCircle(pd,x,y,
                           40*pc.sizeRatio,
                           pc.backColor,pc.lineColor,pc.lineWidth);
        drawCenteredText(pd,QString(text.c_str()),
                         x,y,
                         30*pc.sizeRatio,30*pc.sizeRatio,
                         20*pc.sizeRatio,pc.textColor);
    }

    ///
    /// draw titled rectangle
    ///
    void FigurePainter::drawTitledRectangle(int x, int y,
                                            std::string const& text,
                                            QPaintDevice* pd,
                                            PaintingContext& pc)
    {
        drawRectangle(
                x,y,
                40*pc.sizeRatio,
                40*pc.sizeRatio,
                pd,pc);
        drawCenteredText(
                pd,QString(text.c_str()),
                x,y,
                30*pc.sizeRatio,30*pc.sizeRatio,
                20*pc.sizeRatio,pc.textColor);
    }

    ///
    /// draw line
    ///
    void FigurePainter::drawLine(QPaintDevice* pd,
                                 int start_x, int start_y,
                                 int end_x, int end_y,
                                 int width, QColor color)
    {
        ///
        /// tools
        ///
        QBrush lineBrush;
        QPen linePen;

        ///
        /// tools configuration
        ///
        lineBrush = QBrush(color);
        linePen = QPen(color);
        linePen.setWidth(width);

        ///
        /// Painter for painting on the paint device
        ///

        QPainter painter;
        painter.begin(pd);
        painter.setRenderHint(QPainter::Antialiasing);

        ///
        /// painting actions
        ///
        painter.setPen(linePen);
        painter.setBrush(lineBrush);
        painter.drawLine(start_x, start_y, end_x, end_y);

        ///
        /// Ending painting
        ///
        painter.end();
    }

    ///
    /// draw line
    ///
    void FigurePainter::drawLine(int start_x, int start_y,
                                 int end_x, int end_y,
                                 QPaintDevice* pd,
                                 PaintingContext& pc)
    {
        ///
        /// tools
        ///
        QBrush lineBrush;
        QPen linePen;

        ///
        /// tools configuration
        ///
        lineBrush = QBrush(pc.lineColor);
        linePen = QPen(pc.lineColor);
        linePen.setWidth(pc.lineWidth);

        ///
        /// Painter for painting on the paint device
        ///

        QPainter painter;
        painter.begin(pd);
        painter.setRenderHint(QPainter::Antialiasing);

        ///
        /// painting actions
        ///
        painter.setPen(linePen);
        painter.setBrush(lineBrush);
        painter.drawLine(start_x, start_y, end_x, end_y);

        ///
        /// Ending painting
        ///
        painter.end();
    }

    ///
    /// draw path line
    ///

    void FigurePainter::drawPathLine(int start_x, int start_y,
                                 int end_x, int end_y,
                                 QPaintDevice* pd,
                                 PaintingContext& pc)
    {
        ///
        /// tools
        ///
        QBrush lineBrush;
        QPen linePen;

        ///
        /// tools configuration
        ///
        lineBrush = QBrush(pc.lineColor);
        linePen = QPen(pc.lineColor);
        linePen.setWidth(pc.lineWidth);

        ///
        /// path customization
        ///

        //borders
        linePen.setCapStyle(Qt::RoundCap);
        //union style
        linePen.setJoinStyle(Qt::RoundJoin);
        //line style
        linePen.setStyle(Qt::DotLine);

        ///
        /// Painter for painting on the paint device
        ///

        QPainter painter;
        painter.begin(pd);
        painter.setRenderHint(QPainter::Antialiasing);

        ///
        /// painting actions
        ///
        painter.setPen(linePen);
        painter.setBrush(lineBrush);
        painter.drawLine(start_x, start_y, end_x, end_y);

        ///
        /// Ending painting
        ///
        painter.end();
    }

    ///
    /// draw text
    ///
    void FigurePainter::drawText(QPaintDevice* pd, QString const& text, QRect rect, int size, QColor color)
    {
        ///
        /// tools
        ///
        QFont textFont;
        QPen textPen;

        ///
        /// tools configuration
        ///
        textPen = QPen(color);
        textFont.setPixelSize(size);

        ///
        /// Painter for painting on the paint device
        ///
        QPainter painter;
        painter.begin(pd);
        painter.setRenderHint(QPainter::Antialiasing);

        ///
        /// painting actions
        ///
        painter.setPen(textPen);
        painter.setFont(textFont);
        painter.drawText(rect, Qt::AlignCenter, text);
        ///
        /// Ending painting
        ///
        painter.end();
    }

    ///
    /// draw centered text
    ///
    void FigurePainter::drawCenteredText(QPaintDevice* pd, QString const& text,
                                         int center_x, int center_y, int rect_width, int rect_height,
                                         int textSize, QColor color)
    {
        ///
        /// tools
        ///
        QFont textFont;
        QPen textPen;
        QBrush textBrush;

        ///
        /// tools configuration
        ///
        textPen = QPen(color);
        textFont.setPixelSize(textSize);
        textBrush = QBrush(color);

        ///
        /// Painter for painting on the paint device
        ///
        QPainter painter;
        assert(pd);
        painter.begin(pd);
        painter.setRenderHint(QPainter::Antialiasing);

        ///
        /// painting actions
        ///
        painter.setPen(textPen);
        painter.setBrush(textBrush);
        painter.setFont(textFont);
        int start_x = qMax(center_x - rect_width/2,0);
        int start_y = qMax(center_y - rect_height/2,0);
        QRect rect(start_x,
                   start_y,
                   rect_width,
                   rect_height);
        painter.drawText(rect, Qt::AlignCenter, text);

        ///
        /// Ending painting
        ///
        painter.end();
    }

    ///
    /// draw gradient circle
    ///
    void FigurePainter::drawGradientCircle(QPaintDevice *pd, int center_x, int center_y, int circleDiameter,
                                           QColor bg_color, QColor line_color, int line_width)
    {
        ///
        /// tools
        ///
        QBrush circleBrush;
        QPen circlePen;

        ///
        /// tools configuration
        ///
        QLinearGradient gradient(QPointF(50, -20), QPointF(80, 20));
        gradient.setColorAt(0.0, Qt::white);
        gradient.setColorAt(1.0, bg_color);
        circleBrush = QBrush(gradient);
        circlePen = QPen(line_color);
        circlePen.setWidth(line_width);


        ///
        /// Painter for painting on the paint device
        ///
        QPainter painter;
        painter.begin(pd);
        painter.setRenderHint(QPainter::Antialiasing);

        QFont *font = new QFont();
        font->setPixelSize(20);
        painter.setFont(*font);

        ///
        /// painting actions
        ///
        painter.setBrush(circleBrush);
        painter.setPen(circlePen);
        painter.drawEllipse(QRectF(center_x - circleDiameter/2,
                                   center_y - circleDiameter/2,
                                   circleDiameter,
                                   circleDiameter));
        //painter.restore();

        ///
        /// Ending painting
        ///
        painter.end();
    }

    ///
    /// draw circle
    ///
    void FigurePainter::drawCircle(QPaintDevice *pd, int center_x, int center_y, int circleDiameter,
                                   QColor bg_color, QColor line_color, int line_width)
    {
        ///
        /// tools
        ///
        QBrush circleBrush;
        QPen circlePen;

        ///
        /// tools configuration
        ///
        QLinearGradient gradient(QPointF(50, -20), QPointF(80, 20));
        gradient.setColorAt(0.0, Qt::white);
        gradient.setColorAt(1.0, bg_color);
        circleBrush = QBrush(gradient);
        circlePen = QPen(line_color);
        circlePen.setWidth(line_width);

        ///
        /// Painter for painting on the paint device
        ///
        QPainter painter;
        painter.begin(pd);
        painter.setRenderHint(QPainter::Antialiasing);

        ///
        /// painting actions
        ///
        painter.setBrush(circleBrush);
        painter.setPen(circlePen);
        painter.drawEllipse(QRectF(center_x - circleDiameter/2,
                                   center_y - circleDiameter/2,
                                   circleDiameter,
                                   circleDiameter));
        //painter.restore();

        ///
        /// Ending painting
        ///
        painter.end();
    }

    ///
    /// draw rectangule
    ///
    void FigurePainter::drawRectangle(int center_x, int center_y,
                                      int width, int height,
                                      QPaintDevice *pd,
                                      PaintingContext& pc)
    {
        ///
        /// tools
        ///
        QBrush squareBrush;
        QPen squarePen;

        ///
        /// tools configuration
        ///
        squareBrush = QBrush(pc.backColor);
        squarePen = QPen(pc.lineColor);
        squarePen.setWidth(pc.lineWidth);

        ///
        /// Painter for painting on the paint device
        ///
        QPainter painter;
        painter.begin(pd);
        painter.setRenderHint(QPainter::Antialiasing);

        ///
        /// painting actions
        ///
        painter.setBrush(squareBrush);
        painter.setPen(squarePen);
        int start_x = qMax(center_x - width / 2, 0);
        int start_y = qMax(center_y - height / 2, 0);
        painter.drawRect(start_x, start_y,
                         width, height);
        //painter.restore();

        ///
        /// Ending painting
        ///
        painter.end();
    }

    ///
    /// draw rectangule in position
    ///
    void FigurePainter::drawRectangleInPos(int start_x, int start_y,
                                           int width, int height,
                                           QPaintDevice *pd,
                                           PaintingContext& pc)
    {
        ///
        /// tools
        ///
        QBrush squareBrush;
        QPen squarePen;

        ///
        /// tools configuration
        ///
        squareBrush = QBrush(pc.backColor);
        squarePen = QPen(pc.lineColor);
        squarePen.setWidth(pc.lineWidth);

        ///
        /// Painter for painting on the paint device
        ///
        QPainter painter;
        painter.begin(pd);
        painter.setRenderHint(QPainter::Antialiasing);

        ///
        /// painting actions
        ///
        painter.setBrush(squareBrush);
        painter.setPen(squarePen);
        painter.drawRect(start_x, start_y,
                         width, height);
        //painter.restore();

        ///
        /// Ending painting
        ///
        painter.end();
    }

    ///
    ///
    ///
    ///
    ///
    ///
    /// /////////////////////////////////////////////////////////////
    void FigurePainter::test(QString const& path)
    {
        std::cout << "(FigurePainter::drawCircle) open: "
                << path.toStdString() << std::endl;
        QImage img(path);

        std::cout << "(FigurePainter::drawCircle) Configuring" << std::endl;

        PaintingContext pc;
        pc.backColor = QColor(0xa6, 0xce, 0x39);
        pc.lineColor = Qt::black;
        pc.lineWidth = 5;
        pc.sizeRatio = 1;
        pc.textColor = Qt::black;

        std::cout << "(FigurePainter::drawCircle) drawing" << std::endl;

        drawTitledCircle(500,500,"99",&img,pc);
        drawTitledRectangle(250,250,"100",&img,pc);

        /*QColor lineColor = Qt::black;
             QColor circleColor = QColor(0xa6, 0xce, 0x39);
             QColor textColor = Qt::black;
             int lineWidth = 5;
//drawCenteredText(&img,"99",500,500,30,30,20,Qt::black);



             drawGradientCircle(&img,50,50,40,circleColor,lineColor,lineWidth);
             drawLine(&img,50,50,500,500,lineWidth,lineColor);
             drawGradientCircle(&img,500,500,40,circleColor,lineColor,lineWidth);
             drawCenteredText(&img,"99",500,500,30,30,20,Qt::black);
             //drawText(&img,"99", QRect(0,0,100,100),40,Qt::white);*/

             /*
///
/// tools
///

///line
QBrush lineBrush;
QPen linePen;
///circle
QBrush circleBrush;
QPen circlePen;
//text
QFont textFont;
QPen textPen;

///
/// tools configuration
///

///line
lineBrush = QBrush(QColor(64, 32, 64));
linePen = QPen(Qt::black);
linePen.setWidth(3);

///circle
QLinearGradient gradient(QPointF(50, -20), QPointF(80, 20));
gradient.setColorAt(0.0, Qt::white);
gradient.setColorAt(1.0, QColor(0xa6, 0xce, 0x39));
circleBrush = QBrush(gradient);
circlePen = QPen(Qt::black);
circlePen.setWidth(3);

//text
textPen = QPen(Qt::white);
textFont.setPixelSize(50);

///
/// Image to paint on
///

QImage img("/home/pedro/Desktop/Pantallazo.png");

///
/// Painter for painting on the image
///

QPainter painter;
painter.begin(&img);
painter.setRenderHint(QPainter::Antialiasing);

///
/// painting actions
///

///line

///circle
painter.setBrush(circleBrush);
painter.setPen(circlePen);
//painter->rotate(elapsed * 0.03);

//qreal r = elapsed/1000.0;
//int n = 30;
//for (int i = 0; i < n; ++i) {
// painter->rotate(30);
qreal center_x = 70;//0 + 120.0*((i+r)/n);
qreal center_y = 70;//0 + 120.0*((i+r)/n);
qreal circleDiameter = 70;// 1 + ((i+r)/n)*20;
painter.drawEllipse(QRectF(center_x - circleDiameter, center_y - circleDiameter,
                         circleDiameter*2, circleDiameter*2));
//}
//painter.restore();

///text
painter.setPen(textPen);
painter.setFont(textFont);
painter.drawText(QRect(0, 0, 100, 100), Qt::AlignCenter, "Qt");

///
/// Ending painting
///
painter.end();
*/


             ///
             /// save result
             ///
             std::cout << "(FigurePainter::drawCircle) Saving" << std::endl;
             img.save(path + ".map.png");
             //QByteArray ba;
             //QBuffer buffer(&ba);
             //buffer.open(QIODevice::WriteOnly);
             //img.save(&buffer, "PNG"); // writes image into ba in PNG format





             std::cout << "(FigurePainter::drawCircle) Done" << std::endl;
         }

}//painters
}//qt
}//csu

