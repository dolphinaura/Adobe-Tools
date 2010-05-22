/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name: Adobe Tools                                                                                                               //
//                                                                                                                                       //
// Author: Dolphinaura <garytang@dolphinaura.com>                                                                                      //
//                                                                                                                                       // 
// Description: This tool allows you to install and uninstall adobe flash player on linux systems.                                       //
//                                                                                                                                       //
// Last Revised: Saturday May 22d, 2010                                                                                              //
//                                                                                                                                       //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                                                       //
// Website: http://dolphinaura.co.cc/programming/adobe-flash-player-installer-uninstaller/adobe-flash-plugin-installer-uninstaller-linux //
//                                                                                                                                       //
// Ubuntu Forums Topic:http://ubuntuforums.org/showthread.php?t=1414595                                                                  //
//                                                                                                                                       //
// Github: http://github.com/dolphinaura/Flash-Plugin-Tools                                                                              //
//                                                                                                                                       //
// Binaries: http://github.com/dolphinaura/Flash-Plugin-Tools/downloads                                                                  //
//                                                                                                                                       //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                                                       //
// Dedicated to Logan Kazman <logankazman316@hotmail.com>, who made my life absolutely amazing.                                         //
//                                                                                                                                       //
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
*/ 
#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>


void install_32bit(GtkWidget *widget, gpointer adobe)
{
  system("kdesudo 'apt-get -y install flashplugin-installer'"); 
  system("zenity --info --text 'Flash Plugin Installed Successfully'");
}
void install_64bit(GtkWidget *widget, gpointer adobe)
{
  system("kdesudo 'dpkg --purge --force all nspluginwrapper'");
  system("wget -c http://download.macromedia.com/pub/labs/flashplayer10/libflashplayer-10.0.45.2.linux-x86_64.so.tar.gz"); 
  system("tar xvfz libflashplayer-10.0.45.2.linux-x86_64.so.tar.gz"); 
  system("kdesudo 'mv libflashplayer.so /usr/lib/mozilla/plugins/libflashplayer.so'");
  system("rm libflashplayer-10.0.45.2.linux-x86_64.so.tar.gz");
  system("zenity --info --text 'Flash Plugin Installed Successfully'");
}
void install_beta(GtkWidget *widget, gpointer adobe)
{
  system("kdesudo 'apt-get -y install nspluginwrapper'");
  system("nspluginwrapper -i /usr/lib/mozilla/plugins/libflashplayer.so");
  system("nspluginwrapper -u /usr/lib/mozilla/plugins/libflashplayer.so");
  system("wget -c http://download.macromedia.com/pub/labs/flashplayer10/flashplayer10_1_rc4_linux_050510.tar.gz");
  system("tar xvfz flashplayer10_1_rc4_linux_050510.tar.gz");
  system("kdesudo 'mv libflashplayer.so /usr/lib/mozilla/plugins/libflashplayer.so'");
  system("rm flashplayer10_1_rc4_linux_050510.tar.gz");
  system("nspluginwrapper -i /usr/lib/mozilla/plugins/libflashplayer.so");
  system("zenity --info --text 'Flash Player 10.1 Installed Successfully'");
}
void install_air(GtkWidget *widget, gpointer adobe)
{
  system("wget -c 'http://dl.dropbox.com/u/3593659/adobe_air/adobe_air64.sh'");
  system("chmod 667 adobe_air64.sh");
  system("sh ./adobe_air64.sh");
}
void remove_flsh(GtkWidget *widget, gpointer adobe)
{
  system("kdesudo 'rm /var/lib/dpkg/info/flashplugin* '");
  system("kdesudo 'rm /var/lib/dpkg/info/adobe-flashplugin* '");
  system("kdesudo 'dpkg --remove --force-remove-reinstreq adobe-flashplugin '");
  system("kdesudo 'apt-get -y purge flashplugin-installer gnash mozilla-swfdec'"); 
  system("kdesudo 'rm /usr/lib/mozilla/plugins/libflashplayer.so'"); 
  system("kdesudo 'rm ~/.mozilla/plugins/libflash*'"); 
  system("kdesudo 'rm /usr/lib/firefox-3*/plugins/libflash*'"); 
  system("kdesudo 'apt-get -y remove --purge flashplugin-installer'"); 
  system("kdesudo 'apt-get -y remove --purge flashplugin-nonfree gnash gnash-common mozilla-plugin-gnash '");
  system("kdesudo 'apt-get -y remove --purge iceweasel-flashplugin mozilla-flashplugin firefox-flashplugin '");
  system("kdesudo 'apt-get -y remove --purge swfdec-mozilla libflashsupport nspluginwrapper iceape-flashplugin'");
  system("kdesudo 'apt-get -y remove --purge xulrunner-flashplugin midbrowser-flashplugin xulrunner-addons-flashplugin'");
  system("kdesudo 'rm -f ~/.mozilla/plugins/libflash* '");
  system("kdesudo 'rm -f ~/.mozilla/plugins/ns*flash* '");
  system("kdesudo 'rm -f /usr/lib/firefox-addons/plugins/libflash*'");
  system("kdesudo 'rm -f /usr/lib/firefox/plugins/libflash*'");
  system("kdesudo 'rm -f /usr/lib/iceape/plugins/flashplugin-alternative.so' ");
  system("kdesudo 'rm -f /usr/lib/iceweasel/plugins/flashplugin-alternative.so' ");
  system("kdesudo 'rm -f /usr/lib/iceweasel/plugins/npwrapper.libflashplayer.so' ");
  system("kdesudo 'rm -f /usr/lib/midbrowser/plugins/flashplugin-alternative.so' ");
  system("kdesudo 'rm -f /usr/lib/mozilla/plugins/libflash*'");
  system("kdesudo 'rm -f /usr/lib/xulrunner-addons/plugins/flashplugin-alternative.so' ");
  system("kdesudo 'rm -f /usr/lib/xulrunner/plugins/flashplugin-alternative.so' ");
  system("kdesudo 'rm -f /var/lib/flashplugin-nonfree/npwrapper.libflashplayer.so' ");
  system("zenity --info --text 'Flash Plugin Removed'");
}

int main(int argc, char** argv) {
  GtkWidget *adobe;
  GtkWidget *window;
  GtkWidget *frame;
  GtkWidget *install_x64;
  GtkWidget *install_x86;
  GtkWidget *remove_flash;
  GtkWidget *label;
  GtkWidget *title1;
  GtkWidget *title2;
  GtkWidget *install_flash_beta;
  GtkWidget *install_air_64;
  
  PangoFontDescription *bold = pango_font_description_from_string ( "Sans Bold 24");

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 300, 180);
  gtk_window_set_title(GTK_WINDOW(window), "Adobe Tools");

  frame = gtk_fixed_new();
  gtk_container_add(GTK_CONTAINER(window), frame);
   
  install_x86 = gtk_button_new_with_label("Install Flash (x86)");
  gtk_widget_set_size_request(install_x86, 140, 35);
  gtk_fixed_put(GTK_FIXED(frame), install_x86, 77, 90);

  install_x64 = gtk_button_new_with_label("Install Flash (x64)");
  gtk_widget_set_size_request(install_x64, 140, 35);
  gtk_fixed_put(GTK_FIXED(frame), install_x64, 77, 135);
  
  install_flash_beta = gtk_button_new_with_label("Install Flash Beta");
  gtk_widget_set_size_request(install_flash_beta, 140, 35);
  gtk_fixed_put(GTK_FIXED(frame), install_flash_beta, 77, 180);

  install_air_64 = gtk_button_new_with_label("Install Adobe Air");
  gtk_widget_set_size_request(install_air_64, 140, 35);
  gtk_fixed_put(GTK_FIXED(frame), install_air_64, 77, 225);
  
  remove_flash = gtk_button_new_with_label("Remove Flash");
  gtk_widget_set_size_request(remove_flash, 120, 35);
  gtk_fixed_put(GTK_FIXED(frame), remove_flash, 87, 270);

  label = gtk_label_new("Designed By Gary/Dolphinaura");
  gtk_fixed_put(GTK_FIXED(frame), label, 45, 320); 
  title1 = gtk_label_new("Adobe");
  gtk_fixed_put(GTK_FIXED(frame), title1, 85, 10); 
  gtk_widget_show_all(window);
  title2 = gtk_label_new("Tools");
  gtk_fixed_put(GTK_FIXED(frame), title2, 97, 40);
  gtk_widget_show_all(window);
  gtk_widget_modify_font(GTK_WIDGET(title1),bold);
  gtk_widget_modify_font(GTK_WIDGET(title2),bold);


  g_signal_connect(window, "destroy",
      G_CALLBACK (gtk_main_quit), NULL);
  
  g_signal_connect(install_x86, "clicked", 
      G_CALLBACK(install_32bit), adobe);
      
  g_signal_connect(install_x64, "clicked", 
      G_CALLBACK(install_64bit), adobe);
      
  g_signal_connect(install_air_64, "clicked",
      G_CALLBACK(install_air), adobe);

  g_signal_connect(remove_flash, "clicked", 
      G_CALLBACK(remove_flsh), adobe);
      
  g_signal_connect(install_flash_beta, "clicked",
      G_CALLBACK(install_beta), adobe);
      
system("echo 'Adobe Tools For Ubuntu'");
system("echo 'Developed By Dolphinaura (Gary Tang) <garytang@dolphinaura.com>'");
system("echo 'Please see http://ubuntuforums.org/showthread.php?t=1414595 before using'");
system("echo 'Licenced Under GPL v3'");
system("echo 'Dedicated to Logan Kazman <logankazman316@hotmail.com>, who made my life absolutely amazing.'");
system("echo '--------------------------------------------------------------------------------------------'");
  gtk_main();

  return 0;
}
