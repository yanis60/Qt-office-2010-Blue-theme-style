#pragma once

#include "qdatetimeedit.h"
#include "qdebug.h"
#include "qgraphicseffect.h"
#include "qgroupbox.h"
#include "qheaderview.h"
#include "qlayoutitem.h"
#include "qlistview.h"
#include "qmainwindow.h"
#include "qpushbutton.h"
#include "qscroller.h"
#include "qspinbox.h"
#include "qtableview.h"
#include "qtreeview.h"
#include <QProxyStyle>
#include <QPainter>
#include <QPainterPath>
#include <QStyleOption>
#include <QStyleOptionGroupBox>
#include <QApplication>
#include <QPalette>
#include <QStyleFactory>
#include <QComboBox>
#include <QLineEdit>
#include <QMenu>
#include <QLayout>
#include <QDialog>
#include <QScrollBar>
// ============================================================
//  LightBlueStyle  –  Office 2010 Blue theme for Qt 5.15
//
//  Usage:
//      qApp->setStyle(new LightBlueStyle);
//      qApp->setPalette(LightBlueStyle::palette());
// ============================================================

class LightBlueStyle : public QProxyStyle
{
    Q_OBJECT

public:
    void setTouchMode(bool t)
    {
        touchMode = t;
        for (QWidget *w : qApp->allWidgets()) {
            w->style()->polish(w);
            w->updateGeometry();
            w->update();
        }
    }
    // ── Colour tokens ────────────────────────────────────────
    struct Colors {
        // Backgrounds
        static constexpr QRgb windowBg          = 0xFFCFDDEE;
        static constexpr QRgb inputBg           = 0xFFFFFFFF;
        static constexpr QRgb menuBg            = 0xFFBCCEE7;
        static constexpr QRgb tabSelectedBg     = 0xFFFFFFFF;
        static constexpr QRgb tabUnselectedBg   = 0xFFAFC6DF;
        static constexpr QRgb readOnlyInputBg   = 0xFFCFDDEE;
        static constexpr QRgb headerBgStart     = 0xFFE2EDFA;
        static constexpr QRgb headerBgEnd       = 0xFFEEF5FB;
        static constexpr QRgb buttonBgStart     = 0xFFD0DFEE;  // plus sombre
        static constexpr QRgb buttonBgEnd       = 0xFFE0EDF9;  // plus clair
        static constexpr QRgb buttonHoverBg     = 0xFFFBF2C9;
        static constexpr QRgb buttonPressedTop  = 0xFFFFF29D;  // clair
        static constexpr QRgb buttonPressedBot  = 0xFFF9D799;  // fonce
        static constexpr QRgb hoverHighlight    = 0xFFCEEBFF;
        static constexpr QRgb selectionBg       = 0xFFA7D5F5;
        static constexpr QRgb toolTipBgStart    = 0xFFBCCEE7;
        static constexpr QRgb toolTipBgEnd      = 0xFFA8BFD9;
        // GroupBox title - Office 2010 Blue
        static constexpr QRgb groupTitleTop     = 0xFFD4E4F7;
        static constexpr QRgb groupTitleBot     = 0xFFC6DAF0;
        static constexpr QRgb groupTitleBorder  = 0xFFB1C8E1;

        // Borders
        static constexpr QRgb border            = 0xFF8BA0BC;
        static constexpr QRgb borderLight       = 0xFFABBAD0;
        static constexpr QRgb borderHover       = 0xFFF9D799;
        static constexpr QRgb groupBoxBorder    = 0xFF859EBF;

        // Text
        static constexpr QRgb text              = 0xFF1E395B;
        static constexpr QRgb textDisabled      = 0xFF859EBF;
        static constexpr QRgb selectionText     = 0xffffffff;
        static constexpr QRgb groupBoxTitle     = 0xFF122034;

        // Scrollbar
        static constexpr QRgb scrollHandle      = 0xFFDEE8F4;
        static constexpr QRgb scrollHandleBorder= 0xFF94ADCC;
        static constexpr QRgb scrollHandleHover = 0xFFC6DAF0;

        // Splitter
        static constexpr QRgb splitterStart     = 0xFFDCEEFE;
        static constexpr QRgb splitterEnd       = 0xFFB5D4F5;
        static constexpr QRgb splitterBorder    = 0xFF8AB5E0;
    };

    // ── Constructor ──────────────────────────────────────────
    explicit LightBlueStyle()
        : QProxyStyle(QStyleFactory::create("Fusion"))
    {}

    // ── Static palette factory ───────────────────────────────
    static QPalette palette()
    {
        QPalette pal;

        const QColor bg(Colors::windowBg);
        const QColor text(Colors::text);
        const QColor selBg(Colors::selectionBg);
        const QColor selText(Colors::selectionText);
        const QColor inputBg(Colors::inputBg);
        const QColor border(Colors::border);

        // Active / Inactive identiques
        for (auto group : {QPalette::Active, QPalette::Inactive}) {
            pal.setColor(group, QPalette::Window, bg);
            pal.setColor(group, QPalette::WindowText, text);
            pal.setColor(group, QPalette::Base, inputBg);
            pal.setColor(group, QPalette::AlternateBase, inputBg);
            pal.setColor(group, QPalette::Text, text);
            pal.setColor(group, QPalette::Button, QColor(Colors::buttonBgStart));
            pal.setColor(group, QPalette::ButtonText, text);

            // 🔥 IMPORTANT
            pal.setColor(group, QPalette::Highlight, selBg);
            pal.setColor(group, QPalette::HighlightedText, text);
        }

        // Disabled
        pal.setColor(QPalette::Disabled, QPalette::Window,     QColor(Colors::windowBg));
        pal.setColor(QPalette::Disabled, QPalette::WindowText, QColor(Colors::textDisabled));
        pal.setColor(QPalette::Disabled, QPalette::Text,       QColor(Colors::textDisabled));
        pal.setColor(QPalette::Disabled, QPalette::ButtonText, QColor(Colors::textDisabled));
        pal.setColor(QPalette::Disabled, QPalette::Base,       QColor(Colors::readOnlyInputBg));
        pal.setColor(QPalette::Disabled, QPalette::Button,     QColor(Colors::readOnlyInputBg));
        pal.setColor(QPalette::Disabled, QPalette::Highlight,  QColor(Colors::borderLight));
        pal.setColor(QPalette::Disabled, QPalette::Mid,        QColor(Colors::borderLight));
        pal.setColor(QPalette::Disabled, QPalette::Dark,       QColor(Colors::borderLight));

        // Extras
        pal.setColor(QPalette::ToolTipBase, QColor(Colors::toolTipBgStart));
        pal.setColor(QPalette::ToolTipText, text);
        pal.setColor(QPalette::Mid, border);
        pal.setColor(QPalette::Dark, border);
        pal.setColor(QPalette::Light, QColor(Colors::headerBgEnd));

        return pal;
    }

    // =========================================================
    //  drawPrimitive
    // =========================================================
    void drawPrimitive(PrimitiveElement pe,
                       const QStyleOption *opt,
                       QPainter *p,
                       const QWidget *w = nullptr) const override
    {


        switch (pe) {

        // ── Input field panel ─────────────────────────────────
        case PE_PanelLineEdit: {
            if (hasStyleSheet(w)){
                QProxyStyle::drawPrimitive(pe, opt, p, w);
                return;
            }
            bool DoubleBorder = false;
            if (w && w->parentWidget() &&
                (qobject_cast<const QComboBox*>(w->parentWidget())
                 || qobject_cast<const QSpinBox*>(w->parentWidget())
                 || qobject_cast<const QDoubleSpinBox*>(w->parentWidget())
                 || qobject_cast<const QDateEdit*>(w->parentWidget())
                 || qobject_cast<const QDateTimeEdit*>(w->parentWidget()))
                ) {
                DoubleBorder = true;
            }


            p->save();
            bool readOnly = false;

            if (auto le = qobject_cast<const QLineEdit*>(w->parentWidget()))
                readOnly = le->isReadOnly();
            else if (auto sb = qobject_cast<const QAbstractSpinBox*>(w->parentWidget()))
                readOnly = sb->isReadOnly();
            else if (auto de = qobject_cast<const QDateEdit*>(w->parentWidget()))
                readOnly = de->isReadOnly();
            else if (auto dte = qobject_cast<const QDateTimeEdit*>(w->parentWidget()))
                readOnly = dte->isReadOnly();
            const bool focus    = opt->state & State_HasFocus;
            const bool hover    = w && w->underMouse();
            bool enabled = w->isEnabled();
            if(!enabled)
            {
                p->setPen(Qt::NoPen);
                p->setBrush(QColor(Colors::readOnlyInputBg));
                p->drawRect(opt->rect.adjusted(0, 0, -1, -1));
                return;
            }
            bool isDefaultButton = w && qobject_cast<const QPushButton*>(w) && qobject_cast<const QPushButton*>(w)->isDefault();
            QColor bgColor = readOnly
                                 ? QColor(Colors::readOnlyInputBg)
                                 : (hover || focus) ? QColor(0xFFFFD92B)
                                                    : QColor(Colors::inputBg);

            QColor borderColor = readOnly
                                     ? QColor(Colors::borderLight)
                                     : (w && (qobject_cast<const QHeaderView*>(w->parentWidget()) ||
                                              (w->parentWidget() &&
                                               qobject_cast<const QHeaderView*>(w->parentWidget()->parentWidget()))))
                                           ? QColor(0xFFC4D9F6)   // même couleur que gridline-color
                                           : QColor(Colors::border);
            if(isDefaultButton)
            {
                borderColor = QColor(Qt::white);
            }
            p->setPen(borderColor);

            p->fillRect(opt->rect,bgColor);
            const bool inHeader = w && (
                                      qobject_cast<const QHeaderView*>(w->parentWidget()) ||
                                      (w->parentWidget() &&
                                       qobject_cast<const QHeaderView*>(w->parentWidget()->parentWidget())));
            if(!DoubleBorder)
                p->drawRect(inHeader ? opt->rect.adjusted(-1, -1, -1, -1)
                                     : opt->rect.adjusted(0, 0, -1, -1));
            p->restore();
            return;
        }
        case PE_PanelMenu: {
            p->save();

            // Fond du menu

            // Bordure
            p->setPen(QColor(Colors::border));
            p->setBrush(Qt::NoBrush);
            p->drawRect(opt->rect.adjusted(0, 0, -1, -1));

            p->restore();
            return;
        }
        case PE_PanelTipLabel:
        {
            p->save();

            // Background
            QLinearGradient g(opt->rect.topLeft(), opt->rect.bottomLeft());
            g.setColorAt(0, QColor(Colors::toolTipBgStart));
            g.setColorAt(1, QColor(Colors::toolTipBgEnd));
            p->setBrush(g);
            // Border : 1px solid #1e395b
            p->setPen(QPen(QColor("#1e395b"), 1));

            p->drawRect(opt->rect.adjusted(0, 0, -1, -1));

            p->restore();
            return;
        }
        // ── Buttons ───────────────────────────────────────────
        case PE_PanelButtonCommand:
        case PE_PanelButtonTool: {
            if (!w->styleSheet().isEmpty()){
                QProxyStyle::drawPrimitive(pe, opt, p, w);
                return;
            }

            p->save();
            const bool hover   = opt->state & State_MouseOver;
            const bool pressed = opt->state & State_Sunken;
            const bool checked = opt->state & State_On;
            const bool enabled = w->isEnabled();
            const QRect r      = opt->rect;
            if(enabled)
            {
                // Normal: clair en haut, sombre en bas
                QLinearGradient g(r.topLeft(), r.bottomLeft());
                g.setColorAt(0, QColor(Colors::buttonBgEnd));
                g.setColorAt(1, QColor(Colors::buttonBgStart));
                p->setBrush(g);
                p->setPen(QColor(Colors::borderLight));
                p->drawRoundedRect(r.adjusted(1, 1, -1, -1), 3,3);
                if (pressed) {
                    QLinearGradient g(r.topLeft(), r.bottomLeft());
                    g.setColorAt(0, QColor(Colors::buttonPressedBot));
                    g.setColorAt(1, QColor(Colors::buttonPressedTop));
                    p->setBrush(g);
                     p->setPen(QPen(QColor(240, 190, 90), 1));
                    p->drawRoundedRect(r.adjusted(0,0,-1,-1), 2, 2);

                } else if (checked) {
                    QLinearGradient g(r.topLeft(), r.bottomLeft());
                    g.setColorAt(0, QColor(0xFFA8BFD9));
                    g.setColorAt(1, QColor(0xFFBCCEE7));
                    p->setBrush(g);
                    p->setPen(QColor(Colors::borderLight));
                    p->drawRoundedRect(r, 3, 3);

                } else if (hover) {
                    QRectF rect = r.adjusted(1,1,-1,-1);

                    // Rayon très faible (presque rectangle)
                    qreal radius = 2;

                    // Activer AA


                    // 1. Fond dégradé doux (aspect glass)
                    QLinearGradient bg(rect.topLeft(), rect.bottomLeft());
                    bg.setColorAt(0.0, QColor(255, 245, 200));   // haut clair
                    bg.setColorAt(1.0, QColor(240, 220, 150));   // bas un peu plus foncé

                    p->setPen(Qt::NoPen);
                    p->setBrush(bg);
                    p->drawRoundedRect(rect, radius, radius);

                    // 2. Reflet en haut (RECTANGULAIRE, pas arrondi)
                    QRectF highlight = rect.adjusted(2, 2, -2, -rect.height()/2);

                    QLinearGradient hl(highlight.topLeft(), highlight.bottomLeft());
                    hl.setColorAt(0.0, QColor(255,255,255,180));
                    hl.setColorAt(1.0, QColor(255,255,255,0));

                    p->fillRect(highlight, hl);  // <-- important : PAS rounded

                    // 3. Bordure extérieure
                    p->setPen(QPen(QColor(240, 190, 90), 1));
                    p->setBrush(Qt::NoBrush);
                    p->drawRoundedRect(rect, radius, radius);

                    // 4. Bordure intérieure (effet double bord comme image)
                    QRectF inner = rect.adjusted(2, 2, -2, -2);
                    p->setPen(QPen(QColor(255, 255, 255, 120), 1));
                    p->drawRoundedRect(inner, radius, radius);

                }
            }
            else
            {
                p->setPen(QColor(Colors::borderLight));
                p->setBrush(QColor(Colors::readOnlyInputBg));

                p->drawRoundedRect(r.adjusted(0, 0, -1, -1), 2,2);
            }

            p->restore();
            return;
        }

        // ── GroupBox frame ────────────────────────────────────
        case PE_FrameGroupBox: {
            p->save();
            p->setPen(QColor(Colors::groupBoxBorder));
            p->setBrush(QColor(Colors::windowBg));
            p->drawRoundedRect(opt->rect.adjusted(0, 0, -1, -1), 1,1);
            p->restore();
            return;
        }
        case PE_Widget:
        {

            if (!w) break;
            if(hasStyleSheet(w))
            {
                QProxyStyle::drawPrimitive(pe, opt, p, w);
                return;
            }
            bool isTable = qobject_cast<const QTableView*>(w)
                           || qobject_cast<const QTreeView*>(w)
                           || qobject_cast<const QListView*>(w);

            const bool enabled = w->isEnabled();

            p->save();

            if (!enabled && !isTable) {  // ✅ les tables sont exclues du fond gris
                p->setPen(Qt::NoPen);
                p->setBrush(QColor(Colors::menuBg));
                p->drawRect(opt->rect.adjusted(0, 0, -1, -1));
                p->restore();
                return;
            }
            if(isTable)
            {

                p->setBrush(QColor(Qt::white));

                p->restore();
            }

        }
        // ── QTabWidget pane: fond blanc ───────────────────────
        case PE_FrameTabWidget: {
            p->save();
            p->fillRect(opt->rect,Qt::white);
            p->setPen(QColor(Colors::groupBoxBorder));
            p->drawRect(opt->rect.adjusted(0, 0, -1, -1));
            p->restore();
            return;
        }

            // ── Generic frames ────────────────────────────────────
        case PE_Frame:
        {
            bool isTable = qobject_cast<const QTableView*>(w) || qobject_cast<const QTreeView*>(w) || qobject_cast<const QListView*>(w);
            if(!isTable)
            {
                return;
            }
            else
            {
                p->save();

                p->setBrush(Qt::NoBrush);
                p->drawRect(opt->rect.adjusted(0, 0, -1, -1));
                p->restore();
            }
        }
        case PE_FrameLineEdit: {
            if (hasStyleSheet(w)){
                QProxyStyle::drawPrimitive(pe, opt, p, w);
                return;
            }
            if (w && qobject_cast<const QGroupBox*>(w) && qobject_cast<const QGroupBox*>(w)->isFlat()) {
                return;
            }
            bool enabled = w->isEnabled();
            bool readOnly = false;
            if (auto le = qobject_cast<const QLineEdit*>(w))
                readOnly = le->isReadOnly();
            else if (auto sb = qobject_cast<const QAbstractSpinBox*>(w))
                readOnly = sb->isReadOnly();
            if(readOnly)
            {
                p->setPen(QColor(Colors::borderLight));
                p->setBrush(QColor(Colors::readOnlyInputBg));
                p->drawRect(opt->rect.adjusted(0, 0, -1, -1));
                return;
            }
            p->save();

            p->setPen(QColor(Colors::border));
            if(!enabled)
            {
                p->setPen(QColor(Colors::borderLight));
                p->setBrush(QColor(Colors::readOnlyInputBg));
            }
            p->drawRect(opt->rect.adjusted(0, 0, -1, -1));
            p->restore();
            return;
        }


        case PE_FrameFocusRect:
        {
            p->save();
            QPen focusPen((QColor(Colors::borderHover)));
            focusPen.setStyle(Qt::DashLine);
            p->setPen(focusPen);
            p->restore();
            return;
        }

        case PE_PanelItemViewItem: {
            return;
        }

        case PE_IndicatorMenuCheckMark: {

            p->save();


            QRect r = opt->rect;

            const bool checked = (opt->state & State_On);

            if (checked) {
                p->setPen(QPen(QColor(Colors::text), 2));

                p->drawLine(r.left() + 2,  r.center().y(),
                            r.center().x(), r.bottom() - 2);

                p->drawLine(r.center().x(), r.bottom() - 2,
                            r.right() - 2,  r.top() + 2);
            }

            p->restore();
            return;
        }
        case PE_IndicatorCheckBox: {
            p->save();
            p->setRenderHint(QPainter::Antialiasing, true);
            const bool checked       = (opt->state & State_On) || (opt->state & State_Sunken);
            const bool indeterminate = opt->state & State_NoChange;
            const bool enabled       = w->isEnabled();
            bool hover = opt->state & State_MouseOver;
            QRect r = opt->rect.adjusted(1, 1, -1, -1);

            const bool inMenu = w && qobject_cast<const QMenu*>(w);

            if (!inMenu) {
                // Fond + bordure uniquement hors menu
                p->setBrush(enabled ?hover?QColor(Colors::buttonHoverBg):  QColor(Qt::transparent) :QColor(Colors::readOnlyInputBg));
                p->setPen(QColor(enabled ? Colors::border : Colors::borderLight));
                p->drawRect(r);
            }

            // Coche
            if (checked) {
                p->setPen(QPen(QColor(Colors::text), 2));
                p->drawLine(r.left() + 2,  r.center().y(),
                            r.center().x(), r.bottom() - 2);
                p->drawLine(r.center().x(), r.bottom() - 2,
                            r.right() - 1,  r.top() + 2);
            } else if (indeterminate) {
                p->setPen(QPen(QColor(Colors::text), 2));
                p->drawLine(r.left() + 2,  r.center().y(),
                            r.right() - 2, r.center().y());
            }
            p->restore();
            return;
        }
        case PE_IndicatorRadioButton: {
            p->save();


            const bool checked = opt->state & State_On;
            const bool enabled = w->isEnabled();

            QRect r = opt->rect.adjusted(1, 1, -1, -1);

            // Cercle extérieur
            p->setBrush(enabled ? Qt::white : QColor(Colors::readOnlyInputBg));
            p->setPen(QColor(enabled ? Colors::border : Colors::borderLight));
            p->drawEllipse(r);

            // Point intérieur si coché
            if (checked) {
                p->setBrush(QColor(Colors::text));
                p->setPen(Qt::NoPen);
                p->drawEllipse(r.adjusted(3, 3, -3, -3));
            }

            p->restore();
            return;
        }

        default:
            break;
        }
        QProxyStyle::drawPrimitive(pe, opt, p, w);
    }
    int styleHint(StyleHint sh,
                  const QStyleOption *opt = nullptr,
                  const QWidget *w = nullptr,
                  QStyleHintReturn *shret = nullptr) const override
    {
        if(touchMode)
        {
            switch (sh)
            {
            // ComboBox
            case QStyle::SH_ComboBox_UseNativePopup:
                return 0; // Qt popup (plus contrôlable et plus grand)

            case QStyle::SH_ComboBox_Popup:
                return 0; // force mode popup

            case QStyle::SH_ComboBox_ListMouseTracking:
                return 1; // hover direct



            case QStyle::SH_ItemView_ShowDecorationSelected:
                return 1;

            // Menus
            case QStyle::SH_Menu_MouseTracking:
                return 1;

            case QStyle::SH_Menu_SubMenuPopupDelay:
                return 0; // ouverture immédiate

            case QStyle::SH_Menu_Scrollable:
                return 1;

            // Scrollbar
            case QStyle::SH_ScrollBar_MiddleClickAbsolutePosition:
                return 1;



            case QStyle::SH_EtchDisabledText:
            case QStyle::SH_DitherDisabledText:
            case QStyle::SH_ScrollBar_ScrollWhenPointerLeavesControl:
            case QStyle::SH_TabBar_SelectMouseType:
            case QStyle::SH_TabBar_Alignment:
            case QStyle::SH_Header_ArrowAlignment:
            case QStyle::SH_Slider_SnapToValue:
            case QStyle::SH_Slider_SloppyKeyEvents:
            case QStyle::SH_ProgressDialog_CenterCancelButton:
            case QStyle::SH_ProgressDialog_TextLabelAlignment:
            case QStyle::SH_PrintDialog_RightAlignButtons:
            case QStyle::SH_MainWindow_SpaceBelowMenuBar:
            case QStyle::SH_FontDialog_SelectAssociatedText:
            case QStyle::SH_Menu_AllowActiveAndDisabled:
            case QStyle::SH_Menu_SpaceActivatesItem:
            case QStyle::SH_ScrollView_FrameOnlyAroundContents:
            case QStyle::SH_MenuBar_AltKeyNavigation:
            case QStyle::SH_MenuBar_MouseTracking:
            case QStyle::SH_ItemView_ChangeHighlightOnFocus:
            case QStyle::SH_Widget_ShareActivation:
            case QStyle::SH_Workspace_FillSpaceOnMaximize:
            case QStyle::SH_TitleBar_NoBorder:
            case QStyle::SH_Slider_StopMouseOverSlider:
            case QStyle::SH_BlinkCursorWhenTextSelected:
            case QStyle::SH_RichText_FullWidthSelection:
            case QStyle::SH_GroupBox_TextLabelVerticalAlignment:
            case QStyle::SH_GroupBox_TextLabelColor:
            case QStyle::SH_Menu_SloppySubMenus:
            case QStyle::SH_Table_GridLineColor:
            case QStyle::SH_LineEdit_PasswordCharacter:
            case QStyle::SH_DialogButtons_DefaultButton:
            case QStyle::SH_ToolBox_SelectedPageTitleBold:
            case QStyle::SH_TabBar_PreferNoArrows:
            case QStyle::SH_ScrollBar_LeftClickAbsolutePosition:
            case QStyle::SH_ListViewExpand_SelectMouseType:
            case QStyle::SH_UnderlineShortcut: return 0;
            case QStyle::SH_SpinBox_AnimateButton:
            case QStyle::SH_SpinBox_KeyPressAutoRepeatRate:
            case QStyle::SH_SpinBox_ClickAutoRepeatRate:
            case QStyle::SH_Menu_FillScreenWithScroll:
            case QStyle::SH_ToolTipLabel_Opacity:
            case QStyle::SH_DrawMenuBarSeparator:
            case QStyle::SH_TitleBar_ModifyNotification:
            case QStyle::SH_Button_FocusPolicy:
            case QStyle::SH_MessageBox_UseBorderForButtonSpacing:
            case QStyle::SH_TitleBar_AutoRaise:
            case QStyle::SH_ToolButton_PopupDelay:
            case QStyle::SH_FocusFrame_Mask:
            case QStyle::SH_RubberBand_Mask:
            case QStyle::SH_WindowFrame_Mask:
            case QStyle::SH_SpinControls_DisableOnBounds:
            case QStyle::SH_Dial_BackgroundRole:
            case QStyle::SH_ComboBox_LayoutDirection:
            case QStyle::SH_ItemView_EllipsisLocation:
            case QStyle::SH_ScrollBar_ContextMenu:
            case QStyle::SH_ScrollBar_RollBetweenButtons:
            case QStyle::SH_Slider_AbsoluteSetButtons:
            case QStyle::SH_Slider_PageSetButtons:
            case QStyle::SH_Menu_KeyboardSearch:
            case QStyle::SH_TabBar_ElideMode:
            case QStyle::SH_DialogButtonLayout:
            case QStyle::SH_ComboBox_PopupFrameStyle:
            case QStyle::SH_MessageBox_TextInteractionFlags:
            case QStyle::SH_DialogButtonBox_ButtonsHaveIcons:
            case QStyle::SH_SpellCheckUnderlineStyle:
            case QStyle::SH_MessageBox_CenterButtons:
            case QStyle::SH_Menu_SelectionWrap:
            case QStyle::SH_ItemView_MovementWithoutUpdatingSelection:
            case QStyle::SH_ToolTip_Mask:
            case QStyle::SH_FocusFrame_AboveWidget:
            case QStyle::SH_TextControl_FocusIndicatorTextCharFormat:
            case QStyle::SH_WizardStyle:
            case QStyle::SH_ItemView_ArrowKeysNavigateIntoChildren:
            case QStyle::SH_Menu_Mask:
            case QStyle::SH_Menu_FlashTriggeredItem:
            case QStyle::SH_Menu_FadeOutOnHide:
            case QStyle::SH_SpinBox_ClickAutoRepeatThreshold:
            case QStyle::SH_ItemView_PaintAlternatingRowColorsForEmptyArea:
            case QStyle::SH_FormLayoutWrapPolicy:
            case QStyle::SH_TabWidget_DefaultTabPosition:
            case QStyle::SH_ToolBar_Movable:
            case QStyle::SH_FormLayoutFieldGrowthPolicy:
            case QStyle::SH_FormLayoutFormAlignment:
            case QStyle::SH_FormLayoutLabelAlignment:
            case QStyle::SH_ItemView_DrawDelegateFrame:
            case QStyle::SH_TabBar_CloseButtonPosition:
            case QStyle::SH_DockWidget_ButtonsHaveFrame:
            case QStyle::SH_ToolButtonStyle:
            case QStyle::SH_RequestSoftwareInputPanel:
            case QStyle::SH_Menu_SupportsSections:
            case QStyle::SH_ToolTip_WakeUpDelay:
            case QStyle::SH_ToolTip_FallAsleepDelay:
            case QStyle::SH_Splitter_OpaqueResize:
            case QStyle::SH_LineEdit_PasswordMaskDelay:
            case QStyle::SH_TabBar_ChangeCurrentDelay:
            case QStyle::SH_Menu_SubMenuUniDirection:
            case QStyle::SH_Menu_SubMenuUniDirectionFailCount:
            case QStyle::SH_Menu_SubMenuSloppySelectOtherActions:
            case QStyle::SH_Menu_SubMenuSloppyCloseTimeout:
            case QStyle::SH_Menu_SubMenuResetWhenReenteringParent:
            case QStyle::SH_Menu_SubMenuDontStartSloppyOnLeave:
            case QStyle::SH_ItemView_ScrollMode:
            case QStyle::SH_TitleBar_ShowToolTipsOnButtons:
            case QStyle::SH_Widget_Animation_Duration:
            case QStyle::SH_ComboBox_AllowWheelScrolling:
            case QStyle::SH_SpinBox_ButtonsInsideFrame:
            case QStyle::SH_SpinBox_StepModifier:
            case QStyle::SH_CustomBase:
                break;
            case QStyle::SH_Widget_Animate:
                break;
            case QStyle::SH_ItemView_ActivateItemOnSingleClick:
            case QStyle::SH_ScrollBar_Transient:
                break;
            }
        }

        if (sh == SH_Table_GridLineColor) {
            return static_cast<int>(QColor(0xFFC4D9F6).rgba());
        }
        if (sh == SH_ComboBox_Popup)
            return 0;  // ajouter cette ligne
        if(sh == SH_UnderlineShortcut)
            return QProxyStyle::styleHint(SH_UnderlineShortcut, opt, w, shret);

        return QProxyStyle::styleHint(sh, opt, w, shret);
    }
    void polish(QWidget *w) override
    {
        if (qobject_cast<QLineEdit*>(w)) {
            w->setAttribute(Qt::WA_Hover);
        }

        if (auto v = qobject_cast<QAbstractItemView*>(w)) {
            v->setMouseTracking(true);
            v->viewport()->setMouseTracking(true); // TRÈS IMPORTANT
            v->viewport()->setAttribute(Qt::WA_Hover);
        }
        // Dans polish()
        if (touchMode) {
            if (auto *sa = qobject_cast<QAbstractScrollArea*>(w)) {
                QScroller::grabGesture(sa->viewport(), QScroller::TouchGesture);
            }
        }

        QProxyStyle::polish(w);


    }
    bool hasStyleSheet(const QWidget *w) const {
        // Vérifier la stylesheet globale de l'application
        if (!qApp->styleSheet().isEmpty())
            return true;

        // Remonter la hiérarchie des widgets
        while (w) {
            if (!w->styleSheet().isEmpty()) return true;
            w = w->parentWidget();
        }
        return false;
    }
    // =========================================================
    //  drawControl
    // =========================================================
    void drawControl(ControlElement ce,
                     const QStyleOption *opt,
                     QPainter *p,
                     const QWidget *w = nullptr) const override
    {

        switch (ce) {

        case CE_TabBarTab: {
            if (auto *tab = qstyleoption_cast<const QStyleOptionTab*>(opt)) {
                p->save();
                const bool selected = tab->state & State_Selected;
                QColor bg = selected ? QColor(Colors::tabSelectedBg)
                                     : QColor(Colors::tabUnselectedBg);
                p->setBrush(bg);
                p->setPen(QColor(Colors::groupBoxBorder));

                if (selected) {
                    p->drawRect(opt->rect.adjusted(0, 0, -1, 0));

                    if (tab->shape == QTabBar::RoundedNorth ||
                        tab->shape == QTabBar::TriangularNorth) {
                        p->setPen(QPen(QColor(Colors::text), 2));
                    } else if (tab->shape == QTabBar::RoundedSouth ||
                               tab->shape == QTabBar::TriangularSouth) {
                        p->setPen(QPen(QColor(Colors::text)));
                        p->drawLine(opt->rect.bottomLeft(), opt->rect.bottomRight());
                    }
                }
                else
                {   p->setPen(QPen(QColor(Colors::border)));
                    p->drawRect(opt->rect.adjusted(0, 0, -1, -1));

                    p->drawLine(opt->rect.bottomLeft(), opt->rect.bottomRight());
                }

                p->restore();
                QProxyStyle::drawControl(CE_TabBarTabLabel, opt, p, w);
                return;
            }
            break;
        }

        case CE_MenuItem: {
            if (auto *mi = qstyleoption_cast<const QStyleOptionMenuItem*>(opt)) {
                p->save();

                // Fond blanc

                // Bandeau bleu vertical gauche (largeur 22px)
                QRect band(opt->rect.left(), opt->rect.top(), 22, opt->rect.height());
                p->setPen(QPen(QColor("#e0e0e0"), 1));
                p->drawLine(band.topRight(), band.bottomRight());
                p->fillRect(band, QColor(Qt::transparent));

                if (mi->menuItemType == QStyleOptionMenuItem::Separator) {
                    // Trait séparateur — après le bandeau
                    p->setPen(QColor(Colors::borderLight));
                    int y = opt->rect.center().y();
                    p->drawLine(opt->rect.left() + 32, y, opt->rect.right(), y);
                    p->restore();
                    return;
                }

                const bool selected = opt->state & State_Selected;
                const bool hover    = opt->state & State_MouseOver;
                if (selected || hover) {
                    // Hover jaune avec bordure dorée
                    QRect hoverRect = opt->rect.adjusted(1, 1, -2, -1);
                    p->fillRect(hoverRect, QColor(Colors::buttonHoverBg));
                    p->setPen(QColor(Colors::borderHover));
                    p->drawRect(hoverRect);
                }


                if (!mi->icon.isNull()) {
                    QRect iconRect(opt->rect.left() + 3,
                                   opt->rect.center().y() - 8,
                                   16, 16);
                    mi->icon.paint(p, iconRect, Qt::AlignCenter,
                                   (w->isEnabled()) ? QIcon::Normal : QIcon::Disabled,
                                   (opt->state & State_Selected) ? QIcon::On : QIcon::Off);
                }

                // Texte + raccourci manuellement (sans appeler Fusion)
                p->setPen((w->isEnabled()) ? QColor(Colors::text)
                                                       : QColor(Colors::textDisabled));
                QRect textRect = opt->rect.adjusted(28, 0, -10, 0);
                p->drawText(textRect, Qt::AlignVCenter | Qt::AlignLeft | Qt::TextSingleLine,
                            mi->text.section('\t', 0, 0).remove('&'));
                QString shortcut = mi->text.section('\t', 1).remove('&');
                if (!shortcut.isEmpty()) {
                    p->drawText(textRect, Qt::AlignVCenter | Qt::AlignRight | Qt::TextSingleLine,
                                shortcut);
                }
                p->restore();
                // Flèche sous-menu (arrow à droite)
                if (mi->menuItemType == QStyleOptionMenuItem::SubMenu) {
                    QRect arrowRect(opt->rect.right() - 12,
                                    opt->rect.center().y() - 4,
                                    10, 10);
                    drawArrow(p, arrowRect, QColor(Colors::text), Qt::RightArrow);
                }
                // Indicateur checkbox/radio dans le bandeau
                if (mi->checkType == QStyleOptionMenuItem::Exclusive) {
                    // Radio button
                    QRect checkRect(opt->rect.left() + 3, opt->rect.center().y() - 6, 13, 13);
                    QStyleOptionMenuItem checkOpt = *mi;
                    checkOpt.rect = checkRect;
                    drawPrimitive(PE_IndicatorRadioButton, &checkOpt, p, w);

                } else if (mi->checkType == QStyleOptionMenuItem::NonExclusive) {
                    // Checkbox
                    QRect checkRect(opt->rect.left() + 3, opt->rect.center().y() - 6, 13, 13);
                    QStyleOption checkOpt;
                    checkOpt.rect = checkRect;
                    checkOpt.state = mi->state;

                    if (mi->checked)
                        checkOpt.state |= State_On;
                    else
                        checkOpt.state |= State_Off;

                    drawPrimitive(PE_IndicatorMenuCheckMark, &checkOpt, p, w);
                }
                return;
            }
            break;
        }

        case CE_Header: {
            bool enabled = w->isEnabled();

            p->save();
            // Dégradé vertical : clair en haut → sombre en bas
            if(enabled)
            {
                QLinearGradient g(opt->rect.topLeft(), opt->rect.bottomLeft());
                g.setColorAt(0, QColor(Colors::headerBgEnd));
                g.setColorAt(1, QColor(Colors::headerBgStart));
                p->fillRect(opt->rect, g);
                p->setPen(QColor(Colors::groupBoxBorder));
                p->fillRect(opt->rect.adjusted(-1, -1, -1, -1), g);
                p->setPen(QColor(Colors::groupBoxBorder));
                p->drawRect(opt->rect.adjusted(-1, 0, -1, -1));
            }
            else
            {
                //p->fillRect(opt->rect, QColor(Colors::headerBgStart));
                p->setPen(QColor(Colors::textDisabled));
                p->drawRect(opt->rect.adjusted(-1, 0, -1, -1));
            }
            p->restore();

            drawControl(CE_HeaderLabel, opt, p, w);
            return;
        }
        case CE_ItemViewItem: {


            if (auto *iv = qstyleoption_cast<const QStyleOptionViewItem*>(opt)) {
                QStyleOptionViewItem vopt = *iv;
                p->save();

                const bool hover    = vopt.state & State_MouseOver;
                const bool selected = vopt.state & State_Selected;
                const bool focus    = vopt.state & State_HasFocus;

                // 1. On dessine notre propre fond
                if (selected) {
                    p->fillRect(vopt.rect, QColor(Colors::selectionBg));
                } else if (hover) {
                    p->fillRect(vopt.rect, QColor(Colors::hoverHighlight));
                } else if (focus) {
                    p->fillRect(vopt.rect, QColor(Colors::hoverHighlight));
                }

                p->restore();

                // 2. On retire les flags d'état pour que le style de base
                // ne dessine pas son propre background par-dessus le nôtre
                vopt.state &= ~(State_Selected | State_MouseOver | State_HasFocus);

                QProxyStyle::drawControl(CE_ItemViewItem, &vopt, p, w);
                return;
            }
            break;
        }
        case CE_HeaderLabel: {
            if (auto *headerOpt = qstyleoption_cast<const QStyleOptionHeader*>(opt)) {
                p->save();
                QRect r = headerOpt->rect.adjusted(4, 0, 0, 0);
                p->drawText(r, Qt::AlignVCenter | Qt::AlignLeft | Qt::TextSingleLine,
                            headerOpt->text);
                p->restore();
                return;
            }
            break;
        }
        case CE_ToolBar: {
            p->save();
            QLinearGradient g(opt->rect.topLeft(), opt->rect.bottomLeft());
            g.setColorAt(0, QColor(Colors::buttonBgEnd));
            g.setColorAt(1, QColor(Colors::buttonBgStart));
            p->fillRect(opt->rect, g);
            p->setPen(QColor(Colors::border));
            p->drawLine(opt->rect.bottomLeft(), opt->rect.bottomRight());
            p->restore();
            return;
        }
        case CE_MenuBarEmptyArea: {
            p->save();
            p->fillRect(opt->rect, QColor(Qt::transparent)); // bleu clair Office 2010
            p->setPen(QColor(Colors::border));
            p->drawLine(opt->rect.bottomLeft(), opt->rect.bottomRight());
            p->restore();
            return;
        }

        case CE_MenuBarItem: {
            p->save();
            const bool selected = opt->state & State_Selected;
            const bool pressed  = opt->state & State_Sunken;
            bool hover = opt->state & State_MouseOver;

            if (pressed || selected) {
                p->fillRect(opt->rect, QColor(Colors::buttonHoverBg));
                p->setPen(QColor(Colors::border));
                p->drawRect(opt->rect.adjusted(0, 0, -1, -1));
            }
            else if(hover)
            {
                p->fillRect(opt->rect, QColor(Colors::hoverHighlight));
                p->setPen(QColor(Colors::borderHover));
                p->drawRect(opt->rect.adjusted(0, 0, -1, -1));
            }
            else {
                QLinearGradient bg(opt->rect.topLeft(), opt->rect.bottomLeft());
                bg.setColorAt(0.0, QColor(255, 245, 200));   // haut clair
                bg.setColorAt(1.0, QColor(240, 220, 150));   // bas un peu plus foncé
                p->fillRect(opt->rect, bg);
            }
            p->restore();
            QProxyStyle::drawControl(CE_MenuBarItem, opt, p, w);
            return;
        }

        case QStyle::CE_PushButton:
        case QStyle::CE_PushButtonBevel:
        case QStyle::CE_PushButtonLabel:
        case QStyle::CE_CheckBox:
        case QStyle::CE_CheckBoxLabel:
        case QStyle::CE_RadioButton:
        case QStyle::CE_RadioButtonLabel:
        case QStyle::CE_TabBarTabShape:
        case QStyle::CE_TabBarTabLabel:
        case QStyle::CE_ProgressBar:
        case QStyle::CE_ProgressBarGroove:
        case QStyle::CE_ProgressBarContents:
        case QStyle::CE_ProgressBarLabel:
        case QStyle::CE_MenuScroller:
        case QStyle::CE_MenuVMargin:
        case QStyle::CE_MenuHMargin:
        case QStyle::CE_MenuTearoff:
        case QStyle::CE_MenuEmptyArea:
        case QStyle::CE_ToolButtonLabel:
        case QStyle::CE_HeaderSection:
        case QStyle::CE_ToolBoxTab:
        case QStyle::CE_SizeGrip:
        case QStyle::CE_Splitter:
        case QStyle::CE_RubberBand:
        case QStyle::CE_DockWidgetTitle:
        case QStyle::CE_ScrollBarAddLine:
        case QStyle::CE_ScrollBarSubLine:
        case QStyle::CE_ScrollBarAddPage:
        case QStyle::CE_ScrollBarSubPage:
        case QStyle::CE_ScrollBarSlider:
        case QStyle::CE_ScrollBarFirst:
        case QStyle::CE_ScrollBarLast:
        case QStyle::CE_FocusFrame:
        case QStyle::CE_ComboBoxLabel:
        case QStyle::CE_ToolBoxTabShape:
        case QStyle::CE_ToolBoxTabLabel:
        case QStyle::CE_ColumnViewGrip:
        case QStyle::CE_ShapedFrame:
        case QStyle::CE_CustomBase:



            break;
        case CE_HeaderEmptyArea: {
            p->save();
            QLinearGradient g(opt->rect.topLeft(), opt->rect.bottomLeft());
            g.setColorAt(0, QColor(Colors::headerBgEnd));
            g.setColorAt(1, QColor(Colors::headerBgStart));
            p->fillRect(opt->rect, g);
            p->setPen(QColor(Colors::groupBoxBorder));
            // Bordure basse uniquement
            p->drawRect(opt->rect.adjusted(-1, 0, 0, -1));
            p->restore();
            return;
        }
        break;
        }
        QProxyStyle::drawControl(ce, opt, p, w);
    }
    QSize sizeFromContents(ContentsType type,
                           const QStyleOption *opt,
                           const QSize &size,
                           const QWidget *widget) const override
    {
        QSize s = QProxyStyle::sizeFromContents(type, opt, size, widget);

        if (type == CT_ItemViewItem) {
            // Ne pas forcer de hauteur fixe, laisser Qt calculer
            s.setHeight(s.height() + 6);
        }
        if (touchMode && type == CT_ItemViewItem) {
            s.setHeight(qMax(s.height(), 44)); // hauteur minimum doigt (Apple HIG)
        }
        if (type == CT_ComboBox) {
            s.setHeight(qMax(s.height(), 24)); // hauteur minimale
        }
        if (touchMode && type == CT_MenuItem) {
            s.setHeight(qMax(s.height(), 40));
        }

        return s;
    }
    // =========================================================
    //  drawComplexControl
    // =========================================================
    void drawComplexControl(ComplexControl cc,
                            const QStyleOptionComplex *opt,
                            QPainter *p,
                            const QWidget *w = nullptr) const override
    {

        switch (cc) {

        // ── GroupBox – bande titre Office 2010 Blue ───────────
        case CC_GroupBox: {
            if (auto *gb = qstyleoption_cast<const QStyleOptionGroupBox*>(opt)) {
                p->save();

                // 1. Cadre uniquement si PAS flat
                if (!(gb->features & QStyleOptionFrame::Flat)) {
                    QStyleOptionGroupBox frameOpt = *gb;
                    frameOpt.subControls = QStyle::SC_GroupBoxFrame;
                    QProxyStyle::drawComplexControl(CC_GroupBox, &frameOpt, p, w);
                }

                // 2. Bande titre pleine largeur
                if (!gb->text.isEmpty()) {
                    QRect labelRect = subControlRect(CC_GroupBox, gb,
                                                     QStyle::SC_GroupBoxLabel, w);
                    QRect titleRect(gb->rect.left() + 1,
                                    labelRect.top(),
                                    gb->rect.width() - 2,
                                    labelRect.height()+2);

                    // Degrade bleu clair Office 2010
                    QLinearGradient g(titleRect.topLeft(), titleRect.bottomLeft());
                    g.setColorAt(0, QColor(Colors::groupTitleTop));
                    g.setColorAt(1, QColor(Colors::groupTitleBot));
                    p->fillRect(titleRect, g);

                    // Separateur bas
                    p->setPen(QColor(Colors::groupTitleBorder));
                    p->drawLine(titleRect.bottomLeft(), titleRect.bottomRight());

                    bool checkable = w && qobject_cast<const QGroupBox*>(w) && qobject_cast<const QGroupBox*>(w)->isCheckable();
                    if(checkable)
                        if (gb->subControls & SC_GroupBoxCheckBox) {
                            QRect checkRect = subControlRect(CC_GroupBox, gb, SC_GroupBoxCheckBox, w);
                            QStyleOptionGroupBox checkOpt = *gb;
                            checkOpt.rect = checkRect;
                            // Transférer l'état checked
                            if (gb->state & State_On)
                                checkOpt.state |= State_On;
                            else
                                checkOpt.state &= ~State_On;


                            drawPrimitive(PE_IndicatorCheckBox, &checkOpt, p, w);
                        }

                    // Texte decale a gauche
                    p->setPen(QColor(Colors::groupBoxTitle));
                    if(checkable)
                        p->drawText(titleRect.adjusted(18, 0, -4, 0),
                                    Qt::AlignVCenter | Qt::AlignLeft,
                                    gb->text);
                    else
                        p->drawText(titleRect.adjusted(8, 0, -4, 0),
                                    Qt::AlignVCenter | Qt::AlignLeft,
                                    gb->text);
                }
                // Checkbox du GroupBox (si checkable)

                p->restore();
                return;
            }

        }

        // ── ComboBox ──────────────────────────────────────────
        case CC_ComboBox: {
            if (auto *cb = qstyleoption_cast<const QStyleOptionComboBox*>(opt)) {
                p->save();
                const bool hover = cb->state & State_MouseOver;
                const bool focus = cb->state & State_HasFocus;
                bool enabled = w->isEnabled();
                QColor bg = enabled?(hover || focus) ? QColor(0xFFFFD92B)
                                             : QColor(Colors::inputBg) : QColor(Colors::readOnlyInputBg);

                // Fond + bordure extérieure
                p->setBrush(bg);

                p->setPen(QColor(enabled?Colors::border : Colors::borderLight));
                p->drawRect(cb->rect.adjusted(0, 0, -2, -1));

                // Zone flèche
                QRect arrowRect = subControlRect(CC_ComboBox, opt, SC_ComboBoxArrow, w);

                // Alignement pixel perfect
                QRectF r = arrowRect.adjusted(0,0,0, -1);

                // Dégradé
                QLinearGradient grad(r.topLeft(), r.bottomLeft());
                grad.setColorAt(0, QColor(Colors::buttonBgEnd));
                grad.setColorAt(1, QColor(Colors::buttonBgStart));

                // 1. Remplissage
                p->setPen(Qt::NoPen);
                if(enabled)
                p->setBrush(grad);
                else
                    p->setBrush(QColor(Colors::readOnlyInputBg));
                p->drawRect(r);

                // 2. Bordure (après !)
                p->setBrush(Qt::NoBrush);
                p->setPen(QPen(QColor(Colors::border), 1));
                p->drawRect(r);

                // Flèche centrée
                int aw = 14;
                int ah = 14;
                QRect arrowGlyph(0, 0, aw, ah);
                arrowGlyph.moveCenter(QPoint(arrowRect.center().x(),
                                             cb->rect.center().y())); // centré sur cb->rect
                drawArrow(p, arrowGlyph, QColor(Colors::text), Qt::DownArrow);

                p->restore();
                return;
            }
            break;
        }

        // ── ScrollBar ─────────────────────────────────────────
        case CC_ScrollBar: {
            if (auto *sb = qstyleoption_cast<const QStyleOptionSlider*>(opt)) {
                p->save();
                const bool vertical = sb->orientation == Qt::Vertical;
                bool enabled = sb->state & State_Enabled;
                p->setRenderHint(QPainter::Antialiasing, true);
                // 1. Track
                QLinearGradient trackGrad;
                if(vertical)
                {
                    trackGrad = QLinearGradient(0, 0, sb->rect.width(), 0);
                    trackGrad.setColorAt(0.0, QColor(0xFFCCDBEB));
                    trackGrad.setColorAt(0.5, QColor(0xFFD4E1F0));
                    trackGrad.setColorAt(1.0, QColor(0xFFDCE7F3));
                }
                else
                {
                    trackGrad = QLinearGradient(0, 0, 0, sb->rect.height());
                    trackGrad.setColorAt(0.0, QColor(0xFFCBDAEB));
                    trackGrad.setColorAt(0.5, QColor(0xFFD5E2F0));
                    trackGrad.setColorAt(1.0, QColor(0xFFDCE7F3));
                }

                p->fillRect(sb->rect, trackGrad);

                // 2. Récupérer tous les rects d'abord
                QRect handleRect = subControlRect(CC_ScrollBar, opt, SC_ScrollBarSlider,  w);
                QRect subLine    = subControlRect(CC_ScrollBar, opt, SC_ScrollBarSubLine, w);
                QRect addLine    = subControlRect(CC_ScrollBar, opt, SC_ScrollBarAddLine, w);

                // 3. Lambda flèche avec fond
                auto drawScrollArrowBtn = [&](const QRect &btnRect, Qt::ArrowType dir) {

                    if (btnRect.isEmpty()) return;
                    QLinearGradient g(btnRect.topLeft(), btnRect.bottomLeft());
                    g.setColorAt(0, QColor(Colors::buttonBgEnd));
                    g.setColorAt(1, QColor(Colors::buttonBgStart));
                    bool hovered = sb->activeSubControls & (dir == Qt::UpArrow || dir == Qt::LeftArrow
                                                                ? SC_ScrollBarSubLine : SC_ScrollBarAddLine);
                    bool pressed = (sb->state & State_Sunken) && hovered;
                    if (pressed) {
                        // Enfoncé: gradient inversé + offset
                        g.setColorAt(0, QColor(Colors::buttonPressedBot));
                        g.setColorAt(1, QColor(Colors::buttonPressedTop));
                        p->setBrush(g);
                        p->setPen(QColor(Colors::borderHover));
                        p->drawRect(btnRect.adjusted(0, 0, -1, -1));
                        // Flèche décalée d'1px vers le bas/droite
                        drawArrow(p, btnRect.adjusted(1, 1, 1, 1), QColor(Colors::text), dir);
                    } else if (hovered) {
                        p->setBrush(g);
                        p->setPen(QColor(Colors::scrollHandleBorder));
                        p->drawRect(btnRect.adjusted(0, 0, -1, -1));
                        drawArrow(p, btnRect, QColor(Colors::text), dir);
                    }
                    QColor arrowColor = enabled ? QColor(Colors::text)
                                                : QColor(Colors::textDisabled);

                    if (!enabled) {
                        p->setBrush(QColor(Colors::windowBg));
                        //p->setPen(QColor(Colors::borderLight));
                        //p->drawRect(btnRect.adjusted(0, 0, -1, -1));
                        drawArrow(p, btnRect, QColor(Colors::textDisabled), dir);
                        return;
                    }
                    drawArrow(p, btnRect, arrowColor, dir);

                };

                drawScrollArrowBtn(subLine, vertical ? Qt::UpArrow   : Qt::LeftArrow);
                drawScrollArrowBtn(addLine, vertical ? Qt::DownArrow : Qt::RightArrow);

                // 4. Handle
                const bool hovered = sb->activeSubControls & SC_ScrollBarSlider;
                QColor handleColor = hovered ? QColor(Colors::scrollHandleHover)
                                             : QColor(Colors::scrollHandle);
                if(enabled)
                {
                    p->setBrush(handleColor);
                    p->setPen(QColor(Colors::scrollHandleBorder));
                    p->drawRoundedRect(handleRect.adjusted(0, 0, -1, -1), 2, 2);
                }
                else
                {
                    p->setBrush(QColor(Colors::readOnlyInputBg));
                    p->setPen(QColor(Colors::borderLight));
                    p->drawRoundedRect(handleRect.adjusted(0, 0, -1, -1), 2, 2);

                }

                if ((handleRect.height() > 12 && handleRect.width() > 12) &&
                    enabled) {

                    int cx = handleRect.center().x();
                    int cy = handleRect.center().y();

                    p->setPen(QPen(QColor(Colors::scrollHandleBorder), 1));

                    if (vertical) {
                        for (int i = -3; i <= 3; i += 3)
                            p->drawLine(cx - 4, cy + i, cx + 4, cy + i);
                    } else {
                        for (int i = -3; i <= 3; i += 3)
                            p->drawLine(cx + i, cy - 4, cx + i, cy + 4);
                    }
                }

                p->restore();
                return;
            }
            break;
        }

        // ── SpinBox / DoubleSpinBox ───────────────────────────
        case CC_SpinBox:
        {
            if (auto *sb = qstyleoption_cast<const QStyleOptionSpinBox*>(opt)) {
                p->save();
                bool readOnly = qobject_cast<const QAbstractSpinBox*>(w) && qobject_cast<const QAbstractSpinBox*>(w)->isReadOnly();
                const bool hover = sb->state & State_MouseOver;
                const bool focus = sb->state & State_HasFocus;
                bool enabled = w->isEnabled();
                if(!enabled)
                {
                    p->setPen(QColor(Colors::borderLight));
                    p->setBrush(QColor(Colors::readOnlyInputBg));
                    p->fillRect(opt->rect,Colors::readOnlyInputBg);
                    p->drawRect(opt->rect.adjusted(0, 0, -1, -1));
                    return;
                }
                QColor bg =readOnly? QColor(Colors::readOnlyInputBg) : (hover || focus) ? QColor(0xFFFFD92B)
                                                                                          : QColor(Colors::inputBg);

                // Fond uniforme sans bordure interne
                p->setBrush(bg);
                p->setPen(Qt::NoPen);
                p->drawRect(sb->rect.adjusted(0, 0, -1, -1));

                // Fleches sans cadre
                QRect upRect   = subControlRect(CC_SpinBox, opt, SC_SpinBoxUp,   w);
                QRect downRect = subControlRect(CC_SpinBox, opt, SC_SpinBoxDown, w);
                drawArrow(p, upRect,   QColor(Colors::text), Qt::UpArrow);
                drawArrow(p, downRect, QColor(Colors::text), Qt::DownArrow);

                // Bordure exterieure unique
                p->setBrush(Qt::NoBrush);
                p->setPen(QColor(readOnly?Colors::borderLight : Colors::border));
                p->drawRect(sb->rect.adjusted(0, 0, -1, -1));

                p->restore();
                return;
            }
            break;
        }

        // ── Slider ────────────────────────────────────────────
        case CC_Slider: {
            if (auto *sl = qstyleoption_cast<const QStyleOptionSlider*>(opt)) {
                p->save();
                const bool horizontal = sl->orientation == Qt::Horizontal;
                QRect groove = subControlRect(CC_Slider, opt, SC_SliderGroove, w);
                QRect handle = subControlRect(CC_Slider, opt, SC_SliderHandle, w);

                p->setBrush(QColor(Colors::menuBg));
                p->setPen(Qt::NoPen);
                p->drawRoundedRect(groove, 4, 4);

                QRect filled = groove;
                if (horizontal) filled.setRight(handle.center().x());
                else            filled.setTop(handle.center().y());
                p->setBrush(QColor(Colors::border));
                p->drawRoundedRect(filled, 4, 4);

                QRadialGradient rg(handle.center(), handle.width() / 2.0);
                rg.setColorAt(0.6, QColor(Colors::windowBg));
                rg.setColorAt(0.8, QColor(Colors::border));
                p->setBrush(rg);
                p->setPen(Qt::NoPen);
                p->drawEllipse(handle);
                p->restore();
                return;
            }
            break;
        }

        default:
            break;
        }
        QProxyStyle::drawComplexControl(cc, opt, p, w);
    }

    // ── Pixel metrics ─────────────────────────────────────────
    int pixelMetric(PixelMetric pm,
                    const QStyleOption *opt = nullptr,
                    const QWidget *w = nullptr) const override
    {
        if(touchMode)
        {
            switch (pm)
            {
            case QStyle::PM_ScrollBarExtent:
                return 25; // scrollbar large (doigt)

            case QStyle::PM_ScrollBarSliderMin:
                return 40; // handle facile à attraper

            case QStyle::PM_ButtonMargin:
                return 20; // gros boutons

            case QStyle::PM_LayoutHorizontalSpacing:
            case QStyle::PM_LayoutVerticalSpacing:
                return 10;

            case QStyle::PM_FocusFrameVMargin:
            case QStyle::PM_FocusFrameHMargin:
                return 6;
            case PM_ButtonDefaultIndicator: return 0;
            case PM_ComboBoxFrameWidth:     return 4;
            case PM_TabBarTabHSpace: return 30;
            case PM_TabBarTabVSpace: return 16;


            default: break;
            }
        }
        else
        {
            switch (pm) {
            case PM_ButtonIconSize:    return 16;
            case PM_ScrollBarExtent:        return 18;
            case PM_ScrollBarSliderMin:     return 20;
            case PM_SliderThickness:        return 13;
            case PM_SliderLength:           return 13;
            case PM_TabBarTabHSpace:        return 16;
            case PM_TabBarTabVSpace:        return 10;
            case PM_ToolTipLabelFrameWidth: return 1;
            case PM_HeaderMarkSize:    return 16;
            case PM_HeaderMargin:      return 4;
            case PM_HeaderGripMargin:  return 4;
            case PM_HeaderDefaultSectionSizeVertical: return 16;
            case PM_ButtonDefaultIndicator: return touchMode ? 0 : 2;
            case PM_ComboBoxFrameWidth:     return touchMode ? 4 : 2;
            default: break;
            }


        }
        return QProxyStyle::pixelMetric(pm, opt, w);
    }

private:
    // ── Triangle directionnel ─────────────────────────────────
    static void drawArrow(QPainter *p,
                          const QRect &rect,
                          const QColor &color,
                          Qt::ArrowType direction)
    {
        if (rect.isEmpty()) return;
        p->save();

        p->setPen(Qt::NoPen);
        p->setBrush(color);

        const int aw = rect.width()  / 3.5;
        const int ah = rect.height() / 4;
        const QPoint c = rect.center();

        QPolygon arrow;
        switch (direction) {
        case Qt::UpArrow:
            arrow << QPoint(c.x(),      c.y() - ah)
                  << QPoint(c.x() - aw, c.y() + ah)
                  << QPoint(c.x() + aw, c.y() + ah);
            break;
        case Qt::DownArrow:
            arrow << QPoint(c.x(),      c.y() + ah)
                  << QPoint(c.x() - aw, c.y() - ah)
                  << QPoint(c.x() + aw, c.y() - ah);
            break;
        case Qt::LeftArrow:
            arrow << QPoint(c.x() - aw, c.y())
                  << QPoint(c.x() + aw, c.y() - ah)
                  << QPoint(c.x() + aw, c.y() + ah);
            break;
        case Qt::RightArrow:
            arrow << QPoint(c.x() + aw, c.y())
                  << QPoint(c.x() - aw, c.y() - ah)
                  << QPoint(c.x() - aw, c.y() + ah);
            break;
        default: break;
        }
        p->drawPolygon(arrow);
        p->restore();
    }
private:
    bool touchMode = false;
};
