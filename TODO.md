Objective: 
  Add legend reordering in the GUI for LabPlot

Steps:
- Identify where the legend data is stored => labplot/src/backend/worksheet/plots/cartesian/CartesianPlotLegendPrivate.h => m_plots
- Add getter method
- Add element swapping method
- Create GUI tab with list => in labplot/src/frontend/ui/dockwidgets/cartesianplotlegenddock.ui
  - Add reordering with up/down arrows --> calls element swapping method
