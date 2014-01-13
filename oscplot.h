/**
 * Copyright (C) 2012-2013 Analog Devices, Inc.
 *
 * Licensed under the GPL-2.
 *
 **/
#ifndef __OSC_PLOT__
#define __OSC_PLOT__

#include <glib.h>
#include <glib-object.h>
#include <gtk/gtkwindow.h>

G_BEGIN_DECLS

#define OSC_PLOT_TYPE              (osc_plot_get_type())
#define OSC_PLOT(obj)              (G_TYPE_CHECK_INSTANCE_CAST((obj), OSC_PLOT_TYPE, OscPlot))
#define OSC_PLOT_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST((klass), OSC_PLOT_TYPE, OscPlotClass))
#define IS_OSC_PLOT(obj)           (G_TYPE_CHECK_INSTANCE_TYPE((obj), OSC_PLOT_TYPE))
#define IS_OSC_PLOT_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE((klass), OSC_PLOT_TYPE))

typedef struct _OscPlot            OscPlot;
typedef struct _OscPlotPrivate     OscPlotPrivate;
typedef struct _OscPlotClass       OscPlotClass;

struct _OscPlot
{
	GtkWidget widget;
	OscPlotPrivate *priv;
};

struct _OscPlotClass
{
	GtkWidgetClass parent_class;
	
	void (* capture_event) (OscPlot *plot, gboolean start_event);
	void (* destroy_event) (OscPlot *plot);
};

GType         osc_plot_get_type         (void);
GtkWidget*    osc_plot_new              (void);
void          osc_plot_destroy          (OscPlot *plot);
void          osc_plot_data_update      (OscPlot *plot);
void          osc_plot_update_rx_lbl    (OscPlot *plot);
void          osc_plot_restart          (OscPlot *plot);
void          osc_plot_draw_stop        (OscPlot *plot);
void          osc_plot_save_to_ini      (OscPlot *plot, char *filename);
void          osc_plot_load_ini_section (OscPlot *plot, char *filename, char *section);
void          osc_plot_save_as          (OscPlot *plot, char *filename, int type);

G_END_DECLS

#endif /* __OSC_PLOT__ */
