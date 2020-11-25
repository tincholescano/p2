#include <fstream>
#include <string>

void casos_cui(){
  Casos casos(1000);
  int nCol = 0;
  fstream doc;
  doc.open("Covid19Casos-1000.csv", ios::in);
  string row, col;
  stringstream s;
  getline(doc, row);
  while (getline(doc, row)) {
    Caso c;
    s.str(row);
    while (getline(s, col, ',')) {
      switch (nCol) {
        case 7:
          col = col.substr(1, col.size() - 2);
          c.provincia = col;
          nCol++;
          break;
        case 12:
          col = col.substr(1, col.size() - 2);
          c.intensivo = (!col.compare("SI")) ? true : false;
          nCol++;
          break;
        case 20:
          col = col.substr(1, col.size() - 2);
          c.infectado = col;
        default:
          nCol++;
      }
    }
    nCol = 0;
    s.clear();
    casos.append(c);
  }
  for (int a=0; a<10;a++){
    Caso c;
    c = casos[a];
    cout << c.provincia << " " << c.intensivo << " " <<c.infectado << endl;
  }
}
