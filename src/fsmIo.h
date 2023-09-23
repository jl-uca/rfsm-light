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

#ifndef FSM_IO
#define FSM_IO

#include <QString>
#include "stimulus.h"

class FsmIo
{
public:
  enum IoKind { In=0, Out, Var };
  enum IoType { Int=0, Bool, Event};
  QString name;
  IoKind kind;
  IoType type;
  Stimulus stim; // For inputs

  public:
  FsmIo(const QString& name,
        const IoKind& kind,
        const IoType& type,
        const Stimulus& stim):
  name(name), kind(kind), type(type), stim(stim) {};
  ~FsmIo();

  static IoKind ioKindOfString(QString s);
  static IoType ioTypeOfString(QString s);
  static QString stringOfKind(IoKind k);
  static QString stringOfType(IoType t);
  QString toString(bool withStim=true);
  };

#endif
