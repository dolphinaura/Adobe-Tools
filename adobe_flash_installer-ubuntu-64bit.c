 
#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>

//gint count = 0;
//char buf[5];


void install_32bit(GtkWidget *widget, gpointer flash) //32 - bit Installation
{
  system("gksudo 'apt-get -y install flashplugin-installer'"); 
  system("zenity --info --text 'Flash Plugin Installed Successfully'");
}
void install_64bit(GtkWidget *widget, gpointer flash) //64 -bit Installation
{
  system("gksudo 'dpkg --purge --force all nspluginwrapper'");
  system("wget -c http://download.macromedia.com/pub/labs/flashplayer10/libflashplayer-10.0.45.2.linux-x86_64.so.tar.gz"); 
  system("tar xvfz libflash*"); 
  system("gksudo 'mv libflashplayer.so /usr/lib/mozilla/plugins/libflashplayer.so'");
  system("rm libflashplayer-10.0.45.2.linux-x86_64.so.tar.gz");
  system("zenity --info --text 'Flash Plugin Installed Successfully'");
}
void install_beta(GtkWidget *widget, gpointer flash)
{
  system("gksudo 'apt-get -y install nspluginwrapper'");
  system("wget -c http://download.macromedia.com/pub/labs/flashplayer10/flashplayer10_1_rc_linux_040510.tar.gz");
  system("tar xvfz flashplayer10_1_rc_linux_*");
  system("gksudo 'mv libflashplayer.so /usr/lib/mozilla/plugins/libflashplayer.so'");
  system("rm flashplayer10_1_rc_linux_*tar.gz");
  system("zenity --info --text 'Flash Player 10.1 Installed Successfully'");
}
void remove_flsh(GtkWidget *widget, gpointer flash)//Flash Removal
{
  system("gksudo 'rm /var/lib/dpkg/info/flashplugin* '");
  system("gksudo 'rm /var/lib/dpkg/info/adobe-flashplugin* '");
  system("gksudo 'dpkg --remove --force-remove-reinstreq adobe-flashplugin '");
  system("gksudo 'apt-get -y purge flashplugin-installer gnash mozilla-swfdec'"); 
  system("gksudo 'rm /usr/lib/mozilla/plugins/libflashplayer.so'"); 
  system("gksudo 'rm ~/.mozilla/plugins/libflash*'"); 
  system("gksudo 'rm /usr/lib/firefox-3*/plugins/libflash*'"); 
  system("gksudo 'apt-get -y remove --purge flashplugin-installer'"); 
  system("gksudo 'apt-get -y remove --purge flashplugin-nonfree gnash gnash-common mozilla-plugin-gnash '");
  system("gksudo 'apt-get -y remove --purge iceweasel-flashplugin mozilla-flashplugin firefox-flashplugin '");
  system("gksudo 'apt-get -y remove --purge swfdec-mozilla libflashsupport nspluginwrapper iceape-flashplugin'");
  system("gksudo 'apt-get -y remove --purge xulrunner-flashplugin midbrowser-flashplugin xulrunner-addons-flashplugin'");
  system("gksudo 'rm -f ~/.mozilla/plugins/libflash* '");
  system("gksudo 'rm -f ~/.mozilla/plugins/ns*flash* '");
  system("gksudo 'rm -f /usr/lib/firefox-addons/plugins/libflash*'");
  system("gksudo 'rm -f /usr/lib/firefox/plugins/libflash*'");
  system("gksudo 'rm -f /usr/lib/iceape/plugins/flashplugin-alternative.so' ");
  system("gksudo 'rm -f /usr/lib/iceweasel/plugins/flashplugin-alternative.so' ");
  system("gksudo 'rm -f /usr/lib/iceweasel/plugins/npwrapper.libflashplayer.so' ");
  system("gksudo 'rm -f /usr/lib/midbrowser/plugins/flashplugin-alternative.so' ");
  system("gksudo 'rm -f /usr/lib/mozilla/plugins/libflash*'");
  system("gksudo 'rm -f /usr/lib/xulrunner-addons/plugins/flashplugin-alternative.so' ");
  system("gksudo 'rm -f /usr/lib/xulrunner/plugins/flashplugin-alternative.so' ");
  system("gksudo 'rm -f /var/lib/flashplugin-nonfree/npwrapper.libflashplayer.so' ");
  system("zenity --info --text 'Flash Plugin Removed'");
}

int main(int argc, char** argv) {
//Widgets
  GtkWidget *flash;
  GtkWidget *window;
  GtkWidget *frame;
  GtkWidget *install_x64;
  GtkWidget *install_x86;
  GtkWidget *remove_flash;
  GtkWidget *label;
  GtkWidget *title1;
  GtkWidget *title2;
  GtkWidget *install_flash_beta;
  
  PangoFontDescription *bold = pango_font_description_from_string ( "Sans Bold 24");//Bold Font Paremeters

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);//Window Position
  gtk_window_set_default_size(GTK_WINDOW(window), 300, 180);//Window Size
  gtk_window_set_title(GTK_WINDOW(window), "Adobe Flash Installer"); //Title

  frame = gtk_fixed_new();
  gtk_container_add(GTK_CONTAINER(window), frame); //Draw Window
   
  install_x86 = gtk_button_new_with_label("Install Flash (x86)"); //32 - bit Flash Button
  gtk_widget_set_size_request(install_x86, 140, 35);
  gtk_fixed_put(GTK_FIXED(frame), install_x86, 77, 90);

  install_x64 = gtk_button_new_with_label("Install Flash (x64)");//64 - bit Flash Button
  gtk_widget_set_size_request(install_x64, 140, 35);
  gtk_fixed_put(GTK_FIXED(frame), install_x64, 77, 135);
  
  install_flash_beta = gtk_button_new_with_label("Install Flash Beta");//Beta Flash Button
  gtk_widget_set_size_request(install_flash_beta, 140, 35);
  gtk_fixed_put(GTK_FIXED(frame), install_flash_beta, 77, 180);

  remove_flash = gtk_button_new_with_label("Remove Flash");//Remove Flash
  gtk_widget_set_size_request(remove_flash, 120, 35);
  gtk_fixed_put(GTK_FIXED(frame), remove_flash, 87, 225);

  label = gtk_label_new("Designed By Gary/Dolphinaura");
  gtk_fixed_put(GTK_FIXED(frame), label, 45, 280); 
  title1 = gtk_label_new("Adobe Flash");//Title (Row 1)
  gtk_fixed_put(GTK_FIXED(frame), title1, 45, 10); 
  gtk_widget_show_all(window);
  title2 = gtk_label_new("Installer");
  gtk_fixed_put(GTK_FIXED(frame), title2, 70, 40); //Title (Row 2)
  gtk_widget_show_all(window);
  gtk_widget_modify_font(GTK_WIDGET(title1),bold);//Make Title (Row 1) Bold
  gtk_widget_modify_font(GTK_WIDGET(title2),bold);//Make TItle (Row 2) Bold


  g_signal_connect(window, "destroy",
      G_CALLBACK (gtk_main_quit), NULL);
  
  g_signal_connect(install_x86, "clicked", 
      G_CALLBACK(install_32bit), flash);
      
  g_signal_connect(install_x64, "clicked", 
      G_CALLBACK(install_64bit), flash);

  g_signal_connect(remove_flash, "clicked", 
      G_CALLBACK(remove_flsh), flash);
      
  g_signal_connect(install_flash_beta, "clicked",
      G_CALLBACK(install_beta), flash);
      
system("echo 'Adobe Flash Tools For Ubuntu'");
system("echo 'Designed By Carlee/Dolphinaura (Ubuntu Forums)'");
system("echo 'Licenced Under GPL v3'");
  gtk_main();

  return 0;
}
