#include "stateProperties.h"

#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QRegularExpressionValidator>
#include <QMessageBox>

#include "state.h"
#include "model.h"
#include "stateValuations.h"
#include "syntaxChecker.h"

const QRegularExpression StateProperties::re_uid("[A-Z][A-Za-z0-9_]*");

StateProperties::StateProperties(State *state, Model *model, SyntaxChecker *syntaxChecker, QWidget *parent)
  : QDialog(parent)
{
  QString id = state->getId();
  setWindowTitle("State " + id);
  QVBoxLayout *layout = new QVBoxLayout();

  QHBoxLayout *row_layout1 = new QHBoxLayout();
  QLabel* name_label = new QLabel("Name");
  state_name_field = new QLineEdit();
  // state_name_field->setPlaceholderText("State identifier");
  state_name_field->setText(id);
  QRegularExpressionValidator *state_name_validator = new QRegularExpressionValidator(re_uid);
  state_name_field->setValidator(state_name_validator);
  row_layout1->addWidget(name_label);
  row_layout1->addWidget(state_name_field);
  layout->addLayout(row_layout1);

  QStringList valuations = state->getAttrs();
  valuations_panel = new StateValuations("Valuations", valuations);
  layout->addWidget(valuations_panel);
  
  QHBoxLayout *row_layout2 = new QHBoxLayout();
  QPushButton *cancel_button = new QPushButton("Cancel");
  QPushButton *accept_button = new QPushButton("Done");
  cancel_button->setDefault(false);
  accept_button->setDefault(true);
  row_layout2->addWidget(cancel_button);
  row_layout2->addWidget(accept_button);
  layout->addLayout(row_layout2);

  setLayout(layout);

  connect(cancel_button, &QPushButton::clicked, this, &StateProperties::cancel);
  connect(accept_button, &QPushButton::clicked, this, &StateProperties::accept);

  this->state = state;
  this->model = model;
  this->syntaxChecker = syntaxChecker;
}

void StateProperties::accept()
{
  QString id = state_name_field->text();
  state->setId(id);
  QStringList valuations = valuations_panel->retrieve();
  bool ok = true;
  foreach ( QString valuation, valuations) {
    qDebug() << "Syntax checking valuation" << valuation << "with outputs=" << model->getOutpNonEvents();
    QString msg = syntaxChecker->check_valuation(model->getOutpNonEvents(), valuation);
    if ( msg != "Ok" ) {
      QMessageBox::warning(this, "Error", msg);
      ok = false;
      }
    }
  if ( ok ) {
    state->setAttrs(valuations);
    QDialog::accept();
    }
  else {
    // Do not accept and leave dialog opened
  }
}

void StateProperties::cancel()
{
  QDialog::reject();
}

StateProperties::~StateProperties()
{
}