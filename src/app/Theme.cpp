//
//          Copyright (c) 2016, Scientific Toolworks, Inc.
//
// This software is licensed under the MIT License. The LICENSE.md file
// describes the conditions under which this software may be distributed.
//
// Author: Shane Gramlich
//

#include "Theme.h"
#include "CustomTheme.h"
#include "conf/Settings.h"
#include "dialogs/ThemeDialog.h"
#include <QPainter>
#include <QProxyStyle>
#include <QStyleOption>
#include <QWidget>

namespace {

class Style : public QProxyStyle
{
public:
  void drawPrimitive(
    PrimitiveElement elem,
    const QStyleOption *option,
    QPainter *painter,
    const QWidget *widget) const override
  {
    switch (elem) {
      case PE_IndicatorTabClose:
        Theme::drawCloseButton(option, painter);
        break;

      default:
        baseStyle()->drawPrimitive(elem, option, painter, widget);
        break;
    }
  }
};

} // anon. namespace

QDir Theme::dir() const
{
  QDir dir = Settings::confDir();
  dir.cd("themes");
  return dir;
}

QString Theme::name() const
{
  return "Default";
}

QStyle *Theme::style() const
{
  return new Style;
}

QPalette Theme::palette() const
{
  QPalette palette;
  palette.setColor(QPalette::Light, "#E6E6E6");
  palette.setColor(QPalette::BrightText, "#808080");
  palette.setColor(QPalette::Shadow, palette.color(QPalette::Mid));
  return palette;
}

QString Theme::styleSheet() const
{
  QString styleSheet =
    "AdvancedSearchWidget QLabel {"
    "  color: #646464"
    "}"

    "ColumnView, ColumnView QAbstractItemView {"
    "  background: palette(base);"
    "  border-right: 1px solid #E6E6E6"
    "}"

    "DetailView QStackedWidget {"
    "  background: palette(base)"
    "}"
    "DetailView #separator {"
    "  border-top: 1px solid #E6E6E6"
    "}"

    "DiffView {"
    "  background-color: palette(dark)"
    "}"
    "DiffView .QFrame {"
    "  background-color: #E4E8EE"
    "}"
    "DiffView .QFrame:disabled {"
    "  background-color: #BEC2C7"
    "}"
    "DiffView HunkWidget {"
    "  background-color: #FFFFFF"
    "}"
    "DiffView HunkWidget:disabled {"
    "  background-color: #D5D5D5"
    "}"
    "DiffView HunkWidget QLabel {"
    "  color: #4F4F4F"
    "}"

    "FileList {"
    "  border-top: 1px solid #E6E6E6"
    "}"
    "FileList QToolButton:active {"
    "  color: #939292"
    "}"
    "FileList QToolButton:pressed {"
    "  background: #E2E2E2"
    "}"

    "FindWidget {"
    "  background: qlineargradient("
    "    x1: 0, y1: 0, x2: 0, y2: 1,"
    "    stop: 0 #EEEEEE, stop: 1 #DADADA)"
    "}"
    "FindWidget QToolButton {"
    "  border: 1px solid #A2A2A2;"
    "  border-radius: 4px"
    "}"
    "FindWidget QToolButton:pressed {"
    "  background: rgba(0, 0, 0, 20%)"
    "}"
    "FindWidget QLineEdit {"
    "  border: 1px solid #A2A2A2"
    "}"

    "Footer {"
    "  background-color: qlineargradient("
    "    x1:0, y1: 0, x2: 0, y2: 1, stop: 0 #FCFCFC, stop: 1 #F4F4F4);"
    "  border: 1px solid #A6A6A6;"
    "  border-top-width: 0px"
    "}"
    "Footer QToolButton {"
    "  background-color: qlineargradient("
    "    x1:0, y1: 0, x2: 0, y2: 1, stop: 0 #FCFCFC, stop: 1 #F4F4F4);"
    "  margin-left: 1px;"
    "  border: 1px solid #A6A6A6;"
    "  border-width: 0 1px 1px 0"
    "}"
    "Footer QToolButton:pressed {"
    "  background-color: qlineargradient("
    "    x1:0, y1: 0, x2: 0, y2: 1, stop: 0 #BCBCBC, stop: 1 #B4B4B4);"
    "  margin-left: -1px;"
    "  border: 1px solid #A6A6A6;"
    "  border-width: 0 1px 1px 0"
    "}"

    "ExpandButton {"
    "  background: palette(base);"
    "  border: 1px solid palette(dark);"
    "  border-radius: 4px;"
    "  padding: 0px 4px 0px 4px"
    "}"
    "ExpandButton:pressed {"
    "  background: palette(light)"
    "}"

    "PathspecWidget ExpandButton, ReferenceWidget ExpandButton {"
    "  background-color: qlineargradient("
    "    x1:0, y1: 0, x2: 0, y2: 1, stop: 0 #FCFCFC, stop: 1 #F4F4F4);"
    "  border-radius: 0px;"
    "  padding: 0px 0px 0px 0px"
    "}"
    "PathspecWidget ExpandButton:pressed, ReferenceWidget ExpandButton:pressed {"
    "  background-color: qlineargradient("
    "    x1:0, y1: 0, x2: 0, y2: 1, stop: 0 #BCBCBC, stop: 1 #B4B4B4)"
    "}"

    "TabBar::tab {"
    "  border-top: 1px solid #DBDBDB;"
    "  border-left: 1px solid #DBDBDB;"
    "  border-bottom: 1px solid #D2D2D2;"
    "  background: #ECECEC"
    "}"
    "TabBar::tab:active {"
    "  border-top: 1px solid #A0A0A0;"
    "  border-left: 1px solid #A0A0A0;"
    "  border-bottom: 1px solid #9C9C9C;"
    "  background: qlineargradient("
    "    x1:0, y1:0, x2:0, y2:1,"
    "    stop:0 #BBBBBB, stop:1 #B3B3B3)"
    "}"
    "TabBar::tab:selected {"
    "  background: #F6F6F6"
    "}"
    "TabBar::tab:active:selected {"
    "  border-top: 1px solid #B9B9B9;"
    "  background: qlineargradient("
    "    x1:0, y1:0, x2:0, y2:1,"
    "    stop:0 #D7D7D7, stop:1 #CFCFCF)"
    "}"
    "TabBar::tab:first {"
    "  border-left: none"
    "}"

    "TreeWidget QColumnView {"
    "  border-top: 1px solid #E6E6E6;"
    "  border-bottom: 1px solid #E6E6E6"
    "}"

    "QToolButton {"
    "  color: #C0C0C0"
    "}"
    "QToolButton:active {"
    "  color: #686868"
    "}"
    "QToolButton:disabled {"
    "  color: #C6C6C6"
    "}"

    "ToolBar QToolButton {"
    "  background: palette(base);"
    "  border: 1px solid #DCDCDC"
    "}"
    "ToolBar QToolButton:active {"
    "  border: 1px solid #CCCCCC"
    "}"
    "ToolBar QToolButton:pressed {"
    "  background: #E2E2E2"
    "}"
    "ToolBar QLineEdit {"
    "  border: 1px solid #DCDCDC"
    "}"
    "ToolBar QLineEdit:active {"
    "  border: 1px solid #CCCCCC"
    "}"

    "CommitDetail QToolButton,"
    "HunkWidget QToolButton,"
    "FileWidget QToolButton {"
    "  border: 1px solid #DCDCDC;"
    "  border-radius: 4px;"
    "  background: white"
    "}"
    "CommitDetail QToolButton:pressed,"
    "HunkWidget QToolButton:pressed,"
    "FileWidget QToolButton:pressed {"
    "  background: #E2E2E2"
    "}"

    "CommitToolBar QToolButton:pressed {"
    "  background: #6C6C6C;"
    "  color: white"
    "}";

#ifndef Q_OS_WIN
  styleSheet +=
    "QAbstractItemView {"
    "  selection-background-color: #D4D4D4;"
    "}"
    "QAbstractItemView:active {"
    "  selection-background-color: #6C6C6C;"
    "  selection-color: white"
    "}"

    "QMenu::item {"
    "  background: #6C6C6C"
    "}"
    "QMenu::item:selected {"
    "  color: white"
    "}";
#endif

#ifdef Q_OS_MAC
  if (QSysInfo::macVersion() >= QSysInfo::MV_YOSEMITE)
    styleSheet +=
      "QToolTip {"
      "  opacity: 255;"
      "  background-color: #F0F0F0"
      "}";
#endif

  return styleSheet;
}

QColor Theme::badge(BadgeRole role, BadgeState state)
{
  switch (role) {
    case BadgeRole::Foreground:
      switch (state) {
        case BadgeState::Selected:
          return "#6C6C6C";

        default:
          return Qt::white;
      }

    case BadgeRole::Background:
      switch (state) {
        case BadgeState::Normal:
          return "#A6ACB6";

        case BadgeState::Selected:
          return Qt::white;

        case BadgeState::Conflicted:
          return "#D22222";

        case BadgeState::Head:
          return QColor("#A6ACB6").darker(150);

        case BadgeState::Notification:
          return Qt::red;
      }
  }
}

QList<QColor> Theme::branchTopologyEdges()
{
  return {"steelblue", "crimson", "forestgreen", "goldenrod",
          "darkviolet", "darkcyan", "orange", "cornflowerblue",
          "tomato", "darkturquoise", "palevioletred", "sandybrown"};
}

QColor Theme::buttonChecked()
{
  return QColor("#0086F3");
}

QPalette Theme::commitList()
{
  QPalette palette;
  QString bright = "#808080";
  palette.setColor(QPalette::BrightText, bright);

  // highlight
#ifdef Q_OS_WIN
  palette.setColor(QPalette::Active, QPalette::HighlightedText, Qt::black);
  palette.setColor(QPalette::Inactive, QPalette::HighlightedText, Qt::black);
  palette.setColor(QPalette::Active, QPalette::WindowText, bright);
  palette.setColor(QPalette::Inactive, QPalette::WindowText, bright);
#else
  palette.setColor(QPalette::Active, QPalette::HighlightedText, Qt::white);
  palette.setColor(QPalette::Inactive, QPalette::HighlightedText, Qt::black);
  palette.setColor(QPalette::Active, QPalette::WindowText, "#C0C0C0");
  palette.setColor(QPalette::Inactive, QPalette::WindowText, bright);
#endif

  return palette;
}

QColor Theme::diff(Diff color)
{
  switch (color) {
    case Diff::Ours:         return "#DCFFFF";
    case Diff::Theirs:       return "#FFDCFF";
    case Diff::Addition:     return "#DCFFDC";
    case Diff::Deletion:     return "#FFDCDC";
    case Diff::WordAddition: return "#B0F2B0";
    case Diff::WordDeletion: return "#F2B0B0";
    case Diff::Plus:         return "#45CC45";
    case Diff::Minus:        return "#F28080";
    case Diff::Note:         return Qt::black;
    case Diff::Warning:      return Qt::yellow;
    case Diff::Error:        return Qt::red;
  }
}

QPalette Theme::footer()
{
  QPalette palette;
  palette.setColor(QPalette::Normal, QPalette::ButtonText, "#525252");
  palette.setColor(QPalette::Disabled, QPalette::ButtonText, "#909090");
  return palette;
}

QPalette Theme::fileList()
{
  return QPalette();
}

QColor Theme::heatMap(HeatMap color)
{
  switch (color) {
    case HeatMap::Hot:  return "#FFC0C0";
    case HeatMap::Cold: return "#C0C0FF";
  }
}

QColor Theme::remoteComment(Comment color)
{
  switch (color) {
    case Comment::Background: return palette().color(QPalette::Base);
    case Comment::Body:       return "#383838";
    case Comment::Author:     return "#1A76F4";
    case Comment::Timestamp:  return "#6C6C6C";
  }
}

QPalette Theme::stars()
{
  QPalette palette;
  palette.setColor(QPalette::Base, "#FFCE6D");
  return palette;
}

void Theme::drawCloseButton(
  const QStyleOption *option,
  QPainter *painter)
{
  qreal in = 3.5;
  qreal out = 6.0;
  QRect rect = option->rect;
  qreal x = rect.x() + (rect.width() / 2);
  qreal y = rect.y() + (rect.height() / 2);

  painter->save();
  painter->setRenderHints(QPainter::Antialiasing);

  // Draw background.
  if (option->state & QStyle::State_MouseOver) {
    painter->save();
    painter->setPen(Qt::NoPen);
    bool selected = (option->state & QStyle::State_Selected);
    painter->setBrush(QColor(selected ? "#BEBEBE" : "#9A9A9A"));
    QRectF background(x - out, y - out, 2 * out, 2 * out);
    painter->drawRoundedRect(background, 2.0, 2.0);
    painter->restore();
  }

  // Draw x.
  painter->setPen(QPen(QColor("#646464"), 1.5));
  painter->drawLine(QPointF(x - in, y - in), QPointF(x + in, y + in));
  painter->drawLine(QPointF(x - in, y + in), QPointF(x + in, y - in));
  painter->restore();
}

QColor Theme::windowBrightText()
{
  return QColor("#808080");
}

Theme *Theme::create(const QString &defaultName)
{
  // Upgrade theme key to capital case.
  Settings *settings = Settings::instance();
  QString key = settings->value("window/theme").toString();
  if (key == "default" || key == "dark") {
    key[0] = key.at(0).toUpper();
    settings->setValue("window/theme", key);
  }

  QString name = !defaultName.isEmpty() ? defaultName : key;
  if (name.isEmpty()) {
    ThemeDialog dialog;
    dialog.exec();
    name = settings->value("window/theme").toString();
  }

  if (CustomTheme::isValid(name) && name != "Default")
    return new CustomTheme(name);

  return new Theme;
}
