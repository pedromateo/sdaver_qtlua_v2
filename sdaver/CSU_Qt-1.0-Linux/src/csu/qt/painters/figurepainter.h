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

#ifndef FIGUREPAINTER_H
#define FIGUREPAINTER_H

#include <QImage>
#include <QBrush>
#include <QFont>
#include <QPen>
#include <QPainter>
#include <QBuffer>

namespace csu{
    namespace qt{
        namespace painters{
            ///
            /// FigurePainter
            ///
            class FigurePainter
            {
            public:

                ///
                /// painting context
                ///
                struct PaintingContext
                {
                    ///
                    /// colors
                    ///
                    QColor lineColor;
                    QColor backColor;
                    QColor textColor;
                    int transparency; //0-255: 0 = transparent
                    ///
                    /// canvas
                    ///
                    QPaintDevice* canvas;
                    ///
                    /// pen
                    ///
                    Qt::PenStyle penStyle;
                    long lineWidth;
                    Qt::PenCapStyle capStyle;
                    ///
                    /// size
                    ///
                    QRect region;
                    int gridSize;
                    double sizeRatio;
                    ///
                    /// style
                    ///
                    QString styleSheet;
                    ///
                    /// other
                    ///
                    int maskScope;

                    ///
                    /// default values
                    ///
                    PaintingContext()
                    {
                        /// colors
                        lineColor = Qt::black;
                        backColor = Qt::white;
                        textColor = Qt::black;
                        transparency = 255; //0-255: 0 = transparent
                        /// canvas
                        canvas = NULL;
                        /// pen
                        penStyle = Qt::SolidLine;
                        lineWidth = 3;
                        capStyle = Qt::RoundCap;
                        /// size
                        region = QRect(0,0,0,0);
                        gridSize = 1;
                        sizeRatio = 100;
                        /// style
                        styleSheet = "";
                        /// other
                        maskScope = 1;
                    }
                };

                /// //////////////////////////////////////////////////
                /// new painting methods
                /// //////////////////////////////////////////////////

                ///
                /// highlighter
                ///
                static void highlight(PaintingContext& pc);

                ///
                /// floating message
                ///
                static void floatingMessage(PaintingContext& pc, const QString& message);


                /// //////////////////////////////////////////////////
                /// old methods
                /// //////////////////////////////////////////////////


                ///
                /// draw titled circle
                ///
                static void drawTitledCircle(int x, int y,
                                             std::string const& text,
                                             QPaintDevice* pd,
                                             PaintingContext& pc);

                ///
                /// draw titled rectangle
                ///
                static void drawTitledRectangle(int x, int y,
                                                std::string  const& text,
                                                QPaintDevice* pd,
                                                PaintingContext& pc);

                ///
                /// draw line
                ///
                static void drawLine(QPaintDevice* pd,
                                     int start_x, int start_y,
                                     int end_x, int end_y,
                                     int width, QColor color);

                ///
                /// draw line
                ///
                static void drawLine(int start_x, int start_y,
                                     int end_x, int end_y,
                                     QPaintDevice* pd,
                                     PaintingContext& pc);

                ///
                /// draw path line
                ///
                static void drawPathLine(int start_x, int start_y,
                                         int end_x, int end_y,
                                         QPaintDevice* pd,
                                         PaintingContext& pc);

                ///
                /// draw text
                ///
                static void drawText(QPaintDevice* pd, QString const& text, QRect rect, int size, QColor color);

                ///
                /// draw centered text
                ///
                static void drawCenteredText(QPaintDevice* pd, QString const& text,
                                             int center_x, int center_y, int rect_width, int rect_height,
                                             int textSize, QColor color);

                ///
                /// draw gradient circle
                ///
                static void drawGradientCircle(QPaintDevice *pd, int center_x, int center_y, int circleDiameter,
                                               QColor bg_color, QColor line_color, int line_width);

                ///
                /// draw circle
                ///
                static void drawCircle(QPaintDevice *pd, int center_x, int center_y, int circleDiameter,
                                       QColor bg_color, QColor line_color, int line_width);

                ///
                /// draw rectangule
                ///
                static void drawRectangle(int center_x, int center_y,
                                          int width, int height,
                                          QPaintDevice *pd,
                                          PaintingContext& pc);

                ///
                /// draw rectangule in position
                ///
                static void drawRectangleInPos(int start_x, int start_y,
                                               int width, int height,
                                               QPaintDevice *pd,
                                               PaintingContext& pc);

                ///
                ///
                ///
                ///
                ///
                ///
                /// /////////////////////////////////////////////////////////////
                static void test(QString const&  path);

            };

        }//painters
    }//qt
}//csu

#endif //FIGUREPAINTER_H
