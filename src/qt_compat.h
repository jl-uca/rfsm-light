/***********************************************************************/
/*                                                                     */
/*       This file is part of the RFSM Light software package          */
/*                                                                     */
/*  Copyright (c) 2019-present, Jocelyn SEROT (jocelyn.serot@uca.fr)   */
/*                       All rights reserved.                          */
/*                                                                     */
/*    This source code is licensed under the license found in the      */
/*      LICENSE file in the root directory of this source tree.        */
/*                                                                     */
/***********************************************************************/

#pragma once

#if QT_VERSION >= 0x060000
#define QT_ENDL Qt::endl
#define PIXMAP_SIZE(image) (image->pixmap().size())
#define QCOMBOBOX_INDEX_CHANGED (&QComboBox::currentIndexChanged)
#define QCOMBOBOX_ACTIVATED (&QComboBox::activated)
#define POLYLINE_INTERSECT polyLine.intersects
#define QSET_FROM_LIST(type,qlist) (QSet<type> (qlist.constBegin(), qlist.constEnd()))
#else
#define QT_ENDL endl
#define PIXMAP_SIZE(image) (image->pixmap()->size())
#define QCOMBOBOX_INDEX_CHANGED (QOverload<int>::of(&QComboBox::currentIndexChanged))
#define QCOMBOBOX_ACTIVATED (QOverload<int>::of(&QComboBox::activated))
#defined POLYLINE_INTERSECT polyLine.intersect
#define QSET_FROM_LIST(type,qlist) (QSet<type>::fromList(qlist))
#endif
