/////////////////////////////////////////////////////////////////////////////
// Name:    multipleaxisdemos.cpp
// Purpose: This file contains source code, that demonstrates how to
//          multiple axis charts.
// Author:    Daniel Sucupira Lima
// Created:    18/08/17
/////////////////////////////////////////////////////////////////////////////


#include "democollection.h"

#include <wx/xy/xyplot.h>
#include <wx/xy/xysimpledataset.h>
#include <wx/xy/xylinerenderer.h>

#include <wx/axis/numberaxis.h>

// for area demo
#include <wx/xy/xyarearenderer.h>

#include <wx/xy/xyhistorenderer.h>
#include <wx/category/categorysimpledataset.h>

#include <wx/bars/barplot.h>
#include <wx/axis/categoryaxis.h>

/**
 * SigaDemo2: Multiple axis demo.
 */
//class MultipleAxisDemo2 : public ChartDemo
class SigaDemo2A : public ChartDemo
{
public:
	SigaDemo2A()
    : ChartDemo(wxT("Siga Demo 2 - Multiple axis 1"))
    {
    }

    virtual Chart *Create()
    {
        // first dataset values
        double values1[][2] = {
                { 1, 1 },
                { 2, 3 },
                { 5, 4 },
                { 6, 3 },
                { 7, 6 },
                { 8, 6 },
                { 9, 4 },
        };

        // second dataset values
        /*double values2[][2] = {
                { 0, 0 },
                { 2, -1 },
                { 4, 6 },
                { 5, 2 },
                { 7, 8 },
                { 8, 4 },
                { 9, -2 },
        };*/

		double values2[][2] = {
			{ 0, 0 },
			{ 2, -1 },
			{ 4, 6 },
			{ 5, 2 },
			{ 7, 8 },
			{ 8, 4 },
			{ 9, -2 },
			{ 10, 10 },
			{ 12, 12 },
			{ 19, 7 },
			{ 27, 70 },
			{ 40, 25 },
			{ 51, 12 },
		};

        // colors for first and second datasets
        wxColour color1 = wxColour(255, 0, 0);
        wxColour color2 = wxColour(0, 0, 255);

        // create xy plot
        XYPlot *plot = new XYPlot();

        // create first dataset
        XYSimpleDataset *dataset1 = new XYSimpleDataset();
        // add serie to it
        dataset1->AddSerie((double *) values1, WXSIZEOF(values1));

        // create second dataset
        XYSimpleDataset *dataset2 = new XYSimpleDataset();
        // add serie to it
        dataset2->AddSerie((double *) values2, WXSIZEOF(values2));

        // create renderer for first dataset
        XYLineRenderer *renderer1 = new XYLineRenderer(true); //Desenha apenas as linhas de dados
        renderer1->SetSerieColour(0, &color1);

        // add first dataset to plot
        plot->AddDataset(dataset1);

        // set it to first dataset
        dataset1->SetRenderer(renderer1);

        // create renderer for second dataset
        XYLineRenderer *renderer2 = new XYLineRenderer(true); //Desenha apenas as linhas de dados
        renderer2->SetSerieColour(0, &color2);

        // set it to second dataset
        dataset2->SetRenderer(renderer2);

        // add second dataset to plot
        plot->AddDataset(dataset2);

        // create left axis for first dataset
		//Desenha os n�meros nos eixos, os seus marcadores e o titulo de cada eixo
        NumberAxis *leftAxis = new NumberAxis(AXIS_LEFT, true);
        leftAxis->SetLabelTextColour(color1);
        leftAxis->SetTitle("Left Axis");
        plot->AddAxis(leftAxis);

        // create left axis for second dataset
        NumberAxis *rightAxis = new NumberAxis(AXIS_RIGHT, true);
        rightAxis->SetLabelTextColour(color2);
        rightAxis->SetTitle("Right Axis");
        plot->AddAxis(rightAxis);

        // create top axis for first dataset
        NumberAxis *topAxis = new NumberAxis(AXIS_TOP, true);
        topAxis->SetLabelTextColour(color1);
        topAxis->SetTitle("Top Axis");
        plot->AddAxis(topAxis);

        // create bottom axis for second dataset
        NumberAxis *bottomAxis = new NumberAxis(AXIS_BOTTOM, true);
        bottomAxis->SetLabelTextColour(color2);
        bottomAxis->SetTitle("Bottom Axis");
        plot->AddAxis(bottomAxis);

        // link first dataset with left axis
        plot->LinkDataVerticalAxis(0, 0);
        // link second dataset with right axis
        plot->LinkDataVerticalAxis(1, 1);

        // link first dataset with top axis
        plot->LinkDataHorizontalAxis(0, 0);

        // link second dataset with bottom axis
        plot->LinkDataHorizontalAxis(1, 1);

        return new Chart(plot, GetName());
    }
};

class SigaDemo2B : public ChartDemo
{
public:
	SigaDemo2B()
		: ChartDemo(wxT("XY Demo - areas"))
	{
	}

	virtual Chart *Create()
	{

		// XY data for first series
		wxVector<wxRealPoint> data1;

		data1.push_back(wxRealPoint(0, 2));
		data1.push_back(wxRealPoint(1, 2));
		data1.push_back(wxRealPoint(2, 4));
		data1.push_back(wxRealPoint(3, 3));
		data1.push_back(wxRealPoint(4, 5));
		data1.push_back(wxRealPoint(5, 5));
		data1.push_back(wxRealPoint(6, 7));
		data1.push_back(wxRealPoint(7, 6));
		data1.push_back(wxRealPoint(8, 5));
		data1.push_back(wxRealPoint(9, 6));
		data1.push_back(wxRealPoint(10, 6));

		// XY data for second series
		wxVector<wxRealPoint> data2;

		data2.push_back(wxRealPoint(0, 1));
		data2.push_back(wxRealPoint(1, 1));
		data2.push_back(wxRealPoint(2, 2));
		data2.push_back(wxRealPoint(3, 4));
		data2.push_back(wxRealPoint(4, 3));
		data2.push_back(wxRealPoint(5, 2));
		data2.push_back(wxRealPoint(6, 3));
		data2.push_back(wxRealPoint(7, 6));
		data2.push_back(wxRealPoint(8, 3));
		data2.push_back(wxRealPoint(9, 4));
		data2.push_back(wxRealPoint(10, 3));

		// First step: create the plot.
		XYPlot *plot = new XYPlot();

		// Second step: create the dataset.
		XYSimpleDataset *dataset = new XYSimpleDataset();

		// Third step: add the two series to it.
		dataset->AddSerie(new XYSerie(data1));
		dataset->AddSerie(new XYSerie(data2));

		// create area renderer and set it to dataset
		XYAreaRenderer *renderer = new XYAreaRenderer(true);
		dataset->SetRenderer(renderer);

		// add our dataset to plot
		plot->AddDataset(dataset);

		// create left and bottom number axes
		NumberAxis *leftAxis = new NumberAxis(AXIS_LEFT, true);
		NumberAxis *bottomAxis = new NumberAxis(AXIS_BOTTOM, true);

		// add axes to plot
		plot->AddAxis(leftAxis);
		plot->AddAxis(bottomAxis);

		// link axes and dataset
		plot->LinkDataVerticalAxis(0, 0);
		plot->LinkDataHorizontalAxis(0, 0);

		// set serie names to be displayed on legend
		dataset->SetSerieName(0, wxT("Serie 0"));
		dataset->SetSerieName(1, wxT("Serie 1"));

		// set legend
		plot->SetLegend(new Legend(wxCENTER, wxRIGHT));

		// and finally create chart
		Chart *chart = new Chart(plot, GetName());
		return chart;
	}
};

/**
* Simple demo with one dataset, and left and bottom axes.
*/
class SigaDemo2C : public ChartDemo
{
public:
	SigaDemo2C()
		: ChartDemo(wxT("Bar demo 1 - Single Series"))
	{
	}

	virtual Chart *Create()
	{
		wxString names[] = { // category names
			wxT("Cat 1"),
			wxT("Cat 2"),
			wxT("Cat 3"),
			wxT("Cat 4"),
			wxT("Cat 5"),
		};
		// serie 1 values - we have only one serie
		double values[] = {
			10.0,
			20.0,
			5.0,
			50.0,
			25.0,
		};

		// Create dataset
		CategorySimpleDataset *dataset = new CategorySimpleDataset(names, WXSIZEOF(names));

		// add serie to it
		dataset->AddSerie(wxT("Serie 0"), values, WXSIZEOF(values));

		// create normal bar type with bar width = 10
		BarType *barType = new NormalBarType(30); //Deve dizer se inverte ou n�o aqui
		barType->setOriented(true);

		// Set bar renderer for it
		dataset->SetRenderer(new BarRenderer(barType, true));

		// Create bar plot
		BarPlot *plot = new BarPlot();

		// Create left number axis, set it's margins, and add it to plot
		NumberAxis *leftAxis = new NumberAxis(AXIS_LEFT, true);
		leftAxis->SetMargins(5, 0);
		plot->AddAxis(leftAxis);

		// Create bottom axis, set it's margins, and add it to plot
		CategoryAxis *bottomAxis = new CategoryAxis(AXIS_BOTTOM, true);
		bottomAxis->SetMargins(20, 20);
		plot->AddAxis(bottomAxis);

		// Add dataset to plot
		plot->AddDataset(dataset);

		plot->SetBackground(new FillAreaDraw(*wxTRANSPARENT_PEN, *wxTRANSPARENT_BRUSH));

		// Link first dataset with horizontal axis
		plot->LinkDataHorizontalAxis(0, 0);

		// Link first dataset with vertical axis
		plot->LinkDataVerticalAxis(0, 0);

		// Show a legend at the centre-right position.
		Legend* legend = new Legend(wxCENTER, wxRIGHT, new FillAreaDraw(*wxTRANSPARENT_PEN, *wxTRANSPARENT_BRUSH));
		plot->SetLegend(legend);

		// Create a custom title.
		TextElement title(GetName());

		// and finally construct and return chart
		Chart* chart = new Chart(plot, new Header(title));

		return chart;
	}
};

ChartDemo *sigaDemos2[] = {
		new SigaDemo2A(),
		new SigaDemo2B(),
		new SigaDemo2C()
};

int sigaDemos2Count = WXSIZEOF(sigaDemos2);
