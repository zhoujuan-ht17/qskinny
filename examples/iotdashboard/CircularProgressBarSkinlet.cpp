/******************************************************************************
 * QSkinny - Copyright (C) 2021 Uwe Rathmann
 * This file may be used under the terms of the QSkinny License, Version 1.0
 *****************************************************************************/

#include "CircularProgressBarSkinlet.h"
#include "CircularProgressBar.h"

#include <QskPaintedNode.h>

#include <QEasingCurve>
#include <QPainter>

CircularProgressBarSkinlet::CircularProgressBarSkinlet( QskSkin* skin )
    : QskSkinlet( skin )
{
    setNodeRoles( { GrooveRole, BarRole } );
}

CircularProgressBarSkinlet::~CircularProgressBarSkinlet()
{
}

QRectF CircularProgressBarSkinlet::subControlRect(
    const QskSkinnable*, const QRectF& contentsRect, QskAspect::Subcontrol ) const
{
    return contentsRect;
}

QSGNode* CircularProgressBarSkinlet::updateSubNode(
    const QskSkinnable* skinnable, quint8 nodeRole, QSGNode* node ) const
{
    switch( nodeRole )
    {
        case GrooveRole:
        {
            return updateArcNode( skinnable, node, CircularProgressBar::Groove );
        }
        case BarRole:
        {
            const qreal startAngle = 90 * 16;
            const auto bar = static_cast< const CircularProgressBar* >( skinnable );
            const qreal spanAngle = bar->valueAsRatio() * -5760;
            return updateArcNode( skinnable, node, startAngle, spanAngle,
                CircularProgressBar::Bar );
        }
    }

    return Inherited::updateSubNode( skinnable, nodeRole, node );
}

#include "moc_CircularProgressBarSkinlet.cpp"
