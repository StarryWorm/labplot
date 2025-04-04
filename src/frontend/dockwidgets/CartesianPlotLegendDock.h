/*
	File                 : CartesianPlotLegendDock.h
	Project              : LabPlot
	Description          : widget for cartesian legend properties
	--------------------------------------------------------------------
	SPDX-FileCopyrightText: 2013-2025 Alexander Semke <alexander.semke@web.de>

	SPDX-License-Identifier: GPL-2.0-or-later
*/

#ifndef CARTESIANPLOTLEGENDDOCK_H
#define CARTESIANPLOTLEGENDDOCK_H

#include "backend/worksheet/plots/cartesian/CartesianPlotLegend.h"
#include "frontend/dockwidgets/BaseDock.h"
#include "ui_cartesianplotlegenddock.ui"

class BackgroundWidget;
class LabelWidget;
class LineWidget;
class KConfig;
class QListWidget;
class QPushButton;

class CartesianPlotLegendDock : public BaseDock {
	Q_OBJECT

public:
	explicit CartesianPlotLegendDock(QWidget*);

	void setLegends(QList<CartesianPlotLegend*>);
	void activateTitleTab() const;
	void updateLocale() override;
	void retranslateUi() override;
	void updateUnits() override;

private:
	Ui::CartesianPlotLegendDock ui;
	BackgroundWidget* backgroundWidget{nullptr};
	LineWidget* borderLineWidget{nullptr};
	LabelWidget* labelWidget{nullptr};
	QList<CartesianPlotLegend*> m_legendList;
	CartesianPlotLegend* m_legend{nullptr};
	
	// For ordering tab
	QListWidget* m_lwLegendItems{nullptr};
	QPushButton* m_btnMoveUp{nullptr};
	QPushButton* m_btnMoveDown{nullptr};
	bool m_isUpdatingLegendItems{false};
	
	void updateLegendItemsList();
	void load();
	void loadConfig(KConfig&);

private Q_SLOTS:
	// SLOTs for changes triggered in CartesianPlotLegendDock
	//"General"-tab
	void lockChanged(bool);
	void labelFontChanged(const QFont&);
	void usePlotColorChanged(bool);
	void labelColorChanged(const QColor&);
	void labelOrderChanged(int);
	void lineSymbolWidthChanged(double);
	void positionXChanged(int);
	void positionYChanged(int);
	void customPositionXChanged(double);
	void customPositionYChanged(double);
	void horizontalAlignmentChanged(int index);
	void verticalAlignmentChanged(int index);
	void rotationChanged(int value);
	void bindingChanged(bool checked);

	// "Background"-tab
	void borderCornerRadiusChanged(double);

	//"Layout"-tab
	void layoutTopMarginChanged(double);
	void layoutBottomMarginChanged(double);
	void layoutRightMarginChanged(double);
	void layoutLeftMarginChanged(double);
	void layoutHorizontalSpacingChanged(double);
	void layoutVerticalSpacingChanged(double);
	void layoutColumnCountChanged(int);
	
	// "Ordering"-tab
	void moveItemUp();
	void moveItemDown();
	void legendItemOrderChanged();
	void legendItemsChanged();

	// SLOTs for changes triggered in CartesianPlotLegend
	void legendLabelFontChanged(QFont&);
	void legendUsePlotColorChanged(bool);
	void legendLabelColorChanged(QColor&);
	void legendLabelOrderChanged(bool);
	void legendLineSymbolWidthChanged(float);
	void legendPositionChanged(const CartesianPlotLegend::PositionWrapper&);
	void legendPositionLogicalChanged(QPointF);
	void legendRotationAngleChanged(qreal);
	void legendLockChanged(bool);
	void legendHorizontalAlignmentChanged(const WorksheetElement::HorizontalAlignment);
	void legendVerticalAlignmentChanged(const WorksheetElement::VerticalAlignment);

	void legendBorderCornerRadiusChanged(float);

	void legendLayoutTopMarginChanged(float);
	void legendLayoutBottomMarginChanged(float);
	void legendLayoutLeftMarginChanged(float);
	void legendLayoutRightMarginChanged(float);
	void legendLayoutVerticalSpacingChanged(float);
	void legendLayoutHorizontalSpacingChanged(float);
	void legendLayoutColumnCountChanged(int);

	// save/load template
	void loadConfigFromTemplate(KConfig&);
	void saveConfigAsTemplate(KConfig&);

Q_SIGNALS:
	void info(const QString&);
};

#endif