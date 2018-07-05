#include <vector>
#include <sstream>

using std::vector;
using std::string;
using std::stringstream;

namespace oko
{
  enum {srdce = 3, gula, zalud, zelen};
  const unsigned int poc_hodnot = 13;
  const unsigned int poc_kariet = 52;
  const char farby[] = {srdce, gula, zalud, zelen};
  const char hodnoty[poc_hodnot] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'X', 'J', 'Q', 'K'};

  class karta
  {
    private:
      unsigned int indexKarty;
      unsigned int hodnotaKarty;
      char znakKarty;
    public:
      karta();
      karta(unsigned int card);
      char vratFarbu();
      int vratHodnotu();
      char vratZnak();
      string VypisKartu();
  };

  class balicek
  {
    private:
      vector <karta> karty;
    public:
      balicek();
      bool Prazdny();
      karta DalsiaKarta();
      string VypisBalicek();
  };

  class hrac
  {
    private:
      string meno;
      vector <karta> karty;
      unsigned int skore;
    public:
      hrac(string m_meno);
      unsigned int VratSkore();
      void PrijataKarta(karta nova);
      string VypisHraca();
      hrac operator < (hrac & h);
  };
}
