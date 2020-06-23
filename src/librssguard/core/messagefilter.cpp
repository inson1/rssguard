// For license of this file, see <project-root-folder>/LICENSE.md.

#include "core/messagefilter.h"

#include "core/message.h"

#include <QJSEngine>

MessageFilter::MessageFilter(QObject* parent) : QObject(parent) {}

FilteringAction MessageFilter::filterMessage(QJSEngine* engine) {
  QJSValue filter_func = engine->evaluate("(function() { "

                                          //"return msg.isDuplicateWithAttribute(4) ? 1 : 2; "
                                          "msg.isImportant = true;"
                                          "return 1;"
                                          "})");
  auto filter_output = filter_func.call().toInt();
  FilteringAction decision = FilteringAction(filter_output);

  return decision;
}

int MessageFilter::id() const {
  return m_id;
}

QString MessageFilter::name() const {
  return m_name;
}

void MessageFilter::setName(const QString& name) {
  m_name = name;
}

QString MessageFilter::script() const {
  return m_script;
}

void MessageFilter::setScript(const QString& script) {
  m_script = script;
}