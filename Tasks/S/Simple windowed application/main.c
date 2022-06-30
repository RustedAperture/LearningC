#include <gtk/gtk.h>
#include <string.h>

int clicks = 0;

static void update_label(GtkWidget *widget, gpointer *data)
{
    char text[20];
    char main[40] = "There have been ";
    char end[] = " clicks";
    sprintf(text, "%d", clicks);
    strcat(main, text);
    strcat(main, end);
    clicks++;
    gtk_label_set_label(data, main);
}

static void activate(GtkApplication *app, gpointer user_data)
{
    GtkWidget *window;
    GtkWidget *box;
    GtkWidget *button;
    GtkWidget *label;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Simple Windowed App");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 300);

    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_window_set_child(GTK_WINDOW(window), box);
    gtk_widget_set_halign(box, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(box, GTK_ALIGN_CENTER);
    gtk_box_set_spacing(GTK_BOX(box), 20);

    label = gtk_label_new("There have been no clicks yet");
    gtk_box_append(GTK_BOX(box), label);

    button = gtk_button_new_with_label("Click Me");
    g_signal_connect(button, "clicked", G_CALLBACK(update_label), label);
    gtk_box_append(GTK_BOX(box), button);

    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char **argv)
{
    GtkApplication *app;
    int status;

    app = gtk_application_new("org.rustedaperture.swa", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}